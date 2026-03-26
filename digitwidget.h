#ifndef DIGITWIDGET_H
#define DIGITWIDGET_H

#include <QWidget>
#include <QPointF>

class DigitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DigitWidget(int min, int max, QWidget *parent = nullptr);

    int value() const;
    void setValue(int v);

signals:
    void valueChanged(int value);

protected:
    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    int m_value;
    int m_min;
    int m_max;

    QPointF startPos;

    void increment();
    void decrement();
};

#endif
