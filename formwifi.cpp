#include "formwifi.h"
#include "ui_formwifi.h"
#include <QtWidgets>

FormWifi::FormWifi(WifiManager *manager, QWidget *parent)
    : QWidget(parent), ui(new Ui::FormWifi), manager_(manager)
{
    ui->setupUi(this);
    setStyleSheet("QWidget { background-color: #63452c; color: #e6e1c9; font-size: 18px; }"
                  "QPushButton, QLineEdit, QListWidget { border: 2px solid #e6e1c9; border-radius: 6px; padding: 4px; }"
                  "QPushButton { min-height: 30px; } QPushButton:pressed { background: #ac9362; }"
                  "QPushButton:disabled { color: #ac9362; border-color: #ac9362; }"
                  "QListWidget::item { min-height: 44px; } QListWidget::item:selected { background: #ac9362; color: #302014; }");
    ui->verticalLayout->setContentsMargins(6, 6, 6, 6);
    ui->verticalLayout->setSpacing(4);
    auto header = new QHBoxLayout;
    auto back = new QPushButton(tr("Zurück"));
    header->addWidget(back);
    status_ = new QLabel;
    status_->setWordWrap(true);
    status_->setTextFormat(Qt::PlainText);
    status_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
    header->addWidget(status_, 1);
    ui->verticalLayout->addLayout(header);
    pages_ = new QStackedWidget;
    ui->verticalLayout->addWidget(pages_, 1);
    auto listPage = new QWidget;
    auto listLayout = new QVBoxLayout(listPage);
    listLayout->setContentsMargins(0, 0, 0, 0);
    networks_ = new QListWidget;
    QScroller::grabGesture(networks_->viewport(), QScroller::LeftMouseButtonGesture);
    listLayout->addWidget(networks_);
    auto actions = new QHBoxLayout;
    scan_ = new QPushButton(tr("Suchen"));
    disconnect_ = new QPushButton(tr("Trennen"));
    auto select = new QPushButton(tr("Auswählen"));
    auto enable = new QPushButton(tr("WLAN ein"));
    actions->addWidget(enable); actions->addWidget(scan_); actions->addWidget(disconnect_); actions->addWidget(select);
    listLayout->addLayout(actions);
    pages_->addWidget(listPage);
    auto entry = new QWidget;
    auto entryLayout = new QVBoxLayout(entry);
    entryLayout->setContentsMargins(0, 0, 0, 0);
    entryLayout->setSpacing(3);
    selected_ = new QLabel;
    selected_->setTextFormat(Qt::PlainText);
    selected_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
    entryLayout->addWidget(selected_);
    auto passwordRow = new QHBoxLayout;
    password_ = new QLineEdit;
    password_->setEchoMode(QLineEdit::Password);
    password_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    password_->setPlaceholderText(tr("Passwort · leer = gespeichertes verwenden"));
    auto show = new QPushButton(tr("Anzeigen"));
    show->setCheckable(true);
    passwordRow->addWidget(password_, 1); passwordRow->addWidget(show);
    entryLayout->addLayout(passwordRow);
    auto keyboard = new QStackedWidget;
    const QStringList lower = {"1234567890", "qwertzuiop", "asdfghjkl", "yxcvbnm,."};
    const QStringList upper = {"1234567890", "QWERTZUIOP", "ASDFGHJKL", "YXCVBNM;:"};
    const QStringList symbols = {"!@#$%^&*()", "[]{}<>/\\|=", "+-_\"'`~?", "äöüÄÖÜß€"};
    for (const auto &rows : {lower, upper, symbols}) {
        auto page = new QWidget;
        auto layout = new QVBoxLayout(page);
        layout->setContentsMargins(0, 0, 0, 0); layout->setSpacing(3);
        for (const auto &row : rows) {
            auto line = new QHBoxLayout; line->setSpacing(3);
            for (const auto character : row) {
                const QString text(character);
                auto key = new QPushButton(text == "&" ? "&&" : text);
                key->setStyleSheet("min-height: 26px; padding: 2px;");
                key->setFocusPolicy(Qt::NoFocus);
                key->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
                line->addWidget(key);
                connect(key, &QPushButton::clicked, this, [this, text] { password_->insert(text); });
            }
            layout->addLayout(line);
        }
        keyboard->addWidget(page);
    }
    entryLayout->addWidget(keyboard, 1);
    auto bottom = new QHBoxLayout;
    auto shift = new QPushButton("ABC"); auto special = new QPushButton("#+=");
    auto space = new QPushButton(tr("Leerzeichen")); auto erase = new QPushButton(tr("Löschen"));
    connect_ = new QPushButton(tr("Verbinden"));
    for (auto button : {shift, special, space, erase, connect_}) { bottom->addWidget(button); button->setFocusPolicy(Qt::NoFocus); }
    entryLayout->addLayout(bottom);
    pages_->addWidget(entry);
    message_ = new QLabel; message_->setWordWrap(true);
    message_->setTextFormat(Qt::PlainText);
    message_->setFixedHeight(42);
    message_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    ui->verticalLayout->addWidget(message_);
    connect(back, &QPushButton::clicked, this, [this, show] {
        password_->clear(); show->setChecked(false);
        if (pages_->currentIndex() == 1) pages_->setCurrentIndex(0); else emit onWifiExit();
    });
    connect(show, &QPushButton::toggled, this, [this](bool checked) { password_->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password); });
    connect(shift, &QPushButton::clicked, this, [keyboard, shift] {
        keyboard->setCurrentIndex(keyboard->currentIndex() == 1 ? 0 : 1);
        shift->setText(keyboard->currentIndex() == 1 ? "abc" : "ABC");
    });
    connect(special, &QPushButton::clicked, this, [keyboard] { keyboard->setCurrentIndex(keyboard->currentIndex() == 2 ? 0 : 2); });
    connect(space, &QPushButton::clicked, this, [this] { password_->insert(" "); });
    connect(erase, &QPushButton::clicked, password_, &QLineEdit::backspace);
    connect(enable, &QPushButton::clicked, manager_, &WifiManager::enableWifi);
    connect(scan_, &QPushButton::clicked, manager_, &WifiManager::scan);
    connect(disconnect_, &QPushButton::clicked, manager_, &WifiManager::disconnectNetwork);
    connect(select, &QPushButton::clicked, this, &FormWifi::selectNetwork);
    connect(networks_, &QListWidget::itemActivated, this, [this] { selectNetwork(); });
    connect(connect_, &QPushButton::clicked, this, [this, show] {
        manager_->connectNetwork(network_, password_->text());
        password_->clear(); show->setChecked(false); pages_->setCurrentIndex(0);
    });
    connect(password_, &QLineEdit::returnPressed, connect_, &QPushButton::click);
    connect(manager_, &WifiManager::changed, this, &FormWifi::updateStatus);
    connect(manager_, &WifiManager::message, message_, &QLabel::setText);
    updateStatus();
}
FormWifi::~FormWifi() { delete ui; }
void FormWifi::init()
{
    password_->clear(); password_->setEchoMode(QLineEdit::Password);
    pages_->setCurrentIndex(0); message_->clear(); manager_->refresh(); updateStatus();
}
void FormWifi::updateStatus()
{
    status_->setText(manager_->status());
    scan_->setEnabled(!manager_->busy());
    connect_->setEnabled(!manager_->busy());
    disconnect_->setEnabled(!manager_->busy() && manager_->strength() >= 0);
    updateNetworks();
}
void FormWifi::updateNetworks()
{
    QString selectedPath;
    if (networks_->currentRow() >= 0 && networks_->currentRow() < displayed_.size()) selectedPath = displayed_.at(networks_->currentRow()).path;
    displayed_ = manager_->networks(); networks_->clear();
    for (const auto &n : displayed_) {
        networks_->addItem(QString("%1    %2 %    %3").arg(QString::fromUtf8(n.ssid)).arg(n.strength)
                           .arg(n.security == "open" ? tr("offen") : n.security == "unsupported" ? tr("nicht unterstützt") : tr("verschlüsselt")));
        if (n.path == selectedPath) networks_->setCurrentRow(networks_->count() - 1);
    }
}
void FormWifi::selectNetwork()
{
    const int row = networks_->currentRow();
    if (manager_->busy() || row < 0 || row >= displayed_.size()) return;
    network_ = displayed_.at(row);
    if (network_.security == "unsupported") { message_->setText(tr("WEP und Unternehmens-WLAN werden nicht unterstützt.")); return; }
    selected_->setText(tr("Verbinden mit %1").arg(QString::fromUtf8(network_.ssid)));
    password_->clear(); pages_->setCurrentIndex(1); password_->setFocus();
}
