#include "digitwidget.h"
#include <QPainter>
#include <QTouchEvent>
#include <QEvent>

DigitWidget::DigitWidget(int min, int max, QWidget *parent)
    : QWidget(parent), m_value(min), m_min(min), m_max(max)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    setMinimumSize(50, 80);
}

int DigitWidget::value() const {
    return m_value;
}

void DigitWidget::setValue(int v)
{
    if (v > m_max) v = m_min;
    if (v < m_min) v = m_max;

    if (m_value == v)
        return;

    m_value = v;
    update();
    emit valueChanged(m_value);
}

void DigitWidget::increment() {
    setValue(m_value + 1);
}

void DigitWidget::decrement() {
    setValue(m_value - 1);
}

bool DigitWidget::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::TouchBegin:
    {
        QTouchEvent *touch = static_cast<QTouchEvent *>(event);
        if (!touch->touchPoints().isEmpty())
            startPos = touch->touchPoints().first().pos();
        return true;
    }

    case QEvent::TouchEnd:
    {
        QTouchEvent *touch = static_cast<QTouchEvent *>(event);
        if (!touch->touchPoints().isEmpty())
        {
            QPointF endPos = touch->touchPoints().first().pos();
            QPointF delta = endPos - startPos;

            if (delta.y() < -30)
                increment();   // Swipe UP
            else if (delta.y() > 30)
                decrement();   // Swipe DOWN
        }
        return true;
    }

    default:
        break;
    }

    return QWidget::event(event);
}

void DigitWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QFont f = p.font();
    f.setPointSize(28);
    f.setBold(true);
    p.setFont(f);

    p.drawText(rect(), Qt::AlignCenter, QString::number(m_value));
}
