#pragma once

#include <QWidget>
#include <QTime>

namespace Ui
{
class WidgetSetTime;
}

class WidgetSetTime : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSetTime(QWidget *parent = nullptr);
    ~WidgetSetTime();

    void setTime(const QTime & time);

signals:
    void timeChanged(QTime time);

private:
    Ui::WidgetSetTime *ui;

    void updateTime(const QTime &time);

    QTime time_;

private slots:
    void on_pushButton_Hh_mm_plus_clicked();

    void on_pushButton_Hh_mm_minus_clicked();

    void on_pushButton_hH_mm_plus_clicked();

    void on_pushButton_hH_mm_minus_clicked();

    void on_pushButton_hh_Mm_plus_clicked();

    void on_pushButton_hh_Mm_minus_clicked();

    void on_pushButton_hh_mM_plus_clicked();

    void on_pushButton_hh_mM_minus_clicked();


};
