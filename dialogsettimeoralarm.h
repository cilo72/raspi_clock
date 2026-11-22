#pragma once

#include <QWidget>
#include <QTime>
#include <QHash>

namespace Ui
{
class DialogSetTimeOrAlarm;
}

class DialogSetTimeOrAlarm : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSetTimeOrAlarm(const QTime &time, QWidget *parent = nullptr);
    ~DialogSetTimeOrAlarm();

signals:
    void timeChanged(QTime time);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::DialogSetTimeOrAlarm *ui;

    void updateTime(const QTime &time);

    QTime time_;
    QHash<QObject *, int> swipeSteps_;
    QObject *swipeTarget_ = nullptr;
    qreal swipeY_ = 0;
    int touchPointId_ = -1;
    void swipeTo(qreal y);

private slots:
    void on_pushButtonExit_clicked();
    void on_pushButtonDone_clicked();
};
