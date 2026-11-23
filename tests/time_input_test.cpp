#include "dialogsettimeoralarm.h"
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QtTest>

class TimeInputTest : public QObject
{
    Q_OBJECT

    QTime displayedTime(DialogSetTimeOrAlarm &dialog)
    {
        auto value = [&dialog](const char *name) {
            return dialog.findChild<QLabel *>(name)->text().toInt();
        };
        return QTime(value("label_Hh_mm") * 10 + value("label_hH_mm"),
                     value("label_hh_Mm") * 10 + value("label_hh_mM"));
    }

    void drag(QWidget *digit, int distance)
    {
        const QPoint start = digit->rect().center();
        const QPoint end = start + QPoint(0, distance);
        QTest::mousePress(digit, Qt::LeftButton, Qt::NoModifier, start);
        QMouseEvent move(QEvent::MouseMove, end, digit->mapToGlobal(end),
                         Qt::NoButton, Qt::LeftButton, Qt::NoModifier);
        QApplication::sendEvent(digit, &move);
        QTest::mouseRelease(digit, Qt::LeftButton, Qt::NoModifier, end);
    }

private slots:
    void mouseDrag_data()
    {
        QTest::addColumn<QString>("digit");
        QTest::addColumn<int>("step");
        QTest::newRow("tens-of-hours") << "label_Hh_mm" << 36000;
        QTest::newRow("hours") << "label_hH_mm" << 3600;
        QTest::newRow("tens-of-minutes") << "label_hh_Mm" << 600;
        QTest::newRow("minutes") << "label_hh_mM" << 60;
    }

    void mouseDrag()
    {
        QFETCH(QString, digit);
        QFETCH(int, step);
        const QTime start(23, 59);
        DialogSetTimeOrAlarm dialog(start);
        auto *label = dialog.findChild<QLabel *>(digit);
        drag(label, -64);
        QCOMPARE(displayedTime(dialog), start.addSecs(2 * step));
        drag(label, 32);
        QCOMPARE(displayedTime(dialog), start.addSecs(step));
        drag(label, 8); // A tap or a shaky finger must not change the time.
        QCOMPARE(displayedTime(dialog), start.addSecs(step));
        drag(label, 32);
        QCOMPARE(displayedTime(dialog), start);
    }

    void doubleClickThenDrag()
    {
        DialogSetTimeOrAlarm dialog(QTime(6, 30));
        dialog.show();
        QVERIFY(QTest::qWaitForWindowExposed(&dialog));
        auto *digit = dialog.findChild<QLabel *>("label_hh_mM");
        const QPoint start = digit->rect().center();
        const QPoint end = start - QPoint(0, 32);
        QTest::mouseClick(digit, Qt::LeftButton, Qt::NoModifier, start);
        QTest::mouseDClick(digit, Qt::LeftButton, Qt::NoModifier, start);
        QMouseEvent move(QEvent::MouseMove, end, digit->mapToGlobal(end),
                         Qt::NoButton, Qt::LeftButton, Qt::NoModifier);
        QApplication::sendEvent(digit, &move);
        QTest::mouseRelease(digit, Qt::LeftButton, Qt::NoModifier, end);
        QCOMPARE(displayedTime(dialog), QTime(6, 31));

        // Releasing the second press must also end this drag normally.
        drag(digit, 32);
        QCOMPARE(displayedTime(dialog), QTime(6, 30));
    }

    void touchDrag()
    {
        DialogSetTimeOrAlarm dialog(QTime(23, 59));
        dialog.show();
        QVERIFY(QTest::qWaitForWindowExposed(&dialog));
        auto *digit = dialog.findChild<QLabel *>("label_hh_mM");
        auto *device = QTest::createTouchDevice();
        const QPoint start = digit->rect().center();
        QTest::touchEvent(digit, device).press(0, start, digit);
        QTest::touchEvent(digit, device).move(0, start - QPoint(0, 20), digit);
        QCOMPARE(displayedTime(dialog), QTime(23, 59));
        QTest::touchEvent(digit, device).move(0, start - QPoint(0, 70), digit);
        QCOMPARE(displayedTime(dialog), QTime(0, 1));
        QTest::touchEvent(digit, device).release(0, start - QPoint(0, 70), digit);
        QCOMPARE(displayedTime(dialog), QTime(0, 1));

        // A new gesture starts from its own position, including after release.
        QTest::touchEvent(digit, device).press(0, start, digit);
        QTest::touchEvent(digit, device).move(0, start + QPoint(0, 32), digit);
        QTest::touchEvent(digit, device).release(0, start + QPoint(0, 32), digit);
        QCOMPARE(displayedTime(dialog), QTime(0, 0));
        QSignalSpy changed(&dialog, &DialogSetTimeOrAlarm::timeChanged);
        dialog.findChild<QPushButton *>("pushButtonDone")->click();
        QCOMPARE(changed.count(), 1);
        QCOMPARE(changed.first().first().toTime(), QTime(0, 0));
    }

    void cancelDoesNotSave()
    {
        DialogSetTimeOrAlarm dialog(QTime(6, 30));
        QSignalSpy changed(&dialog, &DialogSetTimeOrAlarm::timeChanged);
        drag(dialog.findChild<QLabel *>("label_hh_mM"), -32);
        dialog.findChild<QPushButton *>("pushButtonExit")->click();
        QCOMPARE(changed.count(), 0);
    }
};

QTEST_MAIN(TimeInputTest)
#include "time_input_test.moc"
