#include "dialogsettimeoralarm.h"
#include "ui_dialogsettimeoralarm.h"
#include <QMouseEvent>
#include <QTouchEvent>

DialogSetTimeOrAlarm::DialogSetTimeOrAlarm(const QTime & time, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DialogSetTimeOrAlarm)
    , time_(time)
{
    ui->setupUi(this);
    swipeSteps_ = {{ui->label_Hh_mm, 10 * 3600},
                   {ui->label_hH_mm, 3600},
                   {ui->label_hh_Mm, 600},
                   {ui->label_hh_mM, 60}};
    for (auto it = swipeSteps_.cbegin(); it != swipeSteps_.cend(); ++it)
    {
        auto *digit = qobject_cast<QWidget *>(it.key());
        digit->setAttribute(Qt::WA_AcceptTouchEvents);
        digit->setCursor(Qt::SizeVerCursor);
        digit->installEventFilter(this);
    }
    updateTime(time);
}

void DialogSetTimeOrAlarm::swipeTo(qreal y)
{
    // Keep the remainder so small movements accumulate; longer drags can
    // change several steps without lifting the finger.
    constexpr qreal pixelsPerStep = 32;
    const int steps = int((swipeY_ - y) / pixelsPerStep);
    if (steps != 0)
    {
        updateTime(time_.addSecs(steps * swipeSteps_.value(swipeTarget_)));
        swipeY_ -= steps * pixelsPerStep;
    }
}

bool DialogSetTimeOrAlarm::eventFilter(QObject *watched, QEvent *event)
{
    if (!swipeSteps_.contains(watched))
        return QWidget::eventFilter(watched, event);

    switch (event->type())
    {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    {
        auto *touch = static_cast<QTouchEvent *>(event);
        if (event->type() == QEvent::TouchBegin && !touch->touchPoints().isEmpty()
            && !swipeTarget_)
        {
            const auto &point = touch->touchPoints().first();
            swipeTarget_ = watched;
            touchPointId_ = point.id();
            swipeY_ = point.screenPos().y();
        }
        if (swipeTarget_ == watched && touchPointId_ >= 0)
        {
            for (const auto &point : touch->touchPoints())
            {
                if (point.id() == touchPointId_)
                {
                    swipeTo(point.screenPos().y());
                    if (point.state() == Qt::TouchPointReleased)
                        swipeTarget_ = nullptr;
                    break;
                }
            }
            if (event->type() == QEvent::TouchEnd)
                swipeTarget_ = nullptr;
        }
        touch->accept();
        return true;
    }
    case QEvent::TouchCancel:
    case QEvent::Hide:
        if (swipeTarget_ == watched)
            swipeTarget_ = nullptr;
        break;
    case QEvent::MouseButtonPress:
    {
        auto *mouse = static_cast<QMouseEvent *>(event);
        if (mouse->button() == Qt::LeftButton && !swipeTarget_)
        {
            swipeTarget_ = watched;
            touchPointId_ = -1;
            swipeY_ = mouse->screenPos().y();
            return true;
        }
        break;
    }
    case QEvent::MouseMove:
    case QEvent::MouseButtonRelease:
    {
        auto *mouse = static_cast<QMouseEvent *>(event);
        if (swipeTarget_ == watched && touchPointId_ == -1)
        {
            swipeTo(mouse->screenPos().y());
            if (event->type() == QEvent::MouseButtonRelease
                && mouse->button() == Qt::LeftButton)
                swipeTarget_ = nullptr;
            return true;
        }
        break;
    }
    default:
        break;
    }
    return QWidget::eventFilter(watched, event);
}

DialogSetTimeOrAlarm::~DialogSetTimeOrAlarm()
{
    delete ui;
}

void DialogSetTimeOrAlarm::updateTime(const QTime &time)
{
    time_ = time;
    ui->label_Hh_mm->setText(QString("%1").arg(time.hour() / 10));
    ui->label_hH_mm->setText(QString("%1").arg(time.hour() % 10));

    ui->label_hh_Mm->setText(QString("%1").arg(time.minute() / 10));
    ui->label_hh_mM->setText(QString("%1").arg(time.minute() % 10));
}

void DialogSetTimeOrAlarm::on_pushButtonExit_clicked()
{
    close();
}

void DialogSetTimeOrAlarm::on_pushButtonDone_clicked()
{
    emit timeChanged(time_);
    close();
}
