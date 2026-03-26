#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLineParser parser;

    QCommandLineOption fullscreenOption("fullscreen", "Fullscreen");
    parser.addOption(fullscreenOption);

    parser.process(a);

    MainWindow w;

    if(parser.isSet(fullscreenOption))
    {
        w.setWindowFlags(Qt::FramelessWindowHint);
        w.showFullScreen();
    }
    else
    {
        w.show();
    }

    w.show();
    return a.exec();
}
