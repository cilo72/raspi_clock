#include "guihelper.h"
#include "globals.h"

void GuiHelper::showModal(QWidget * w)
{
    w->setWindowFlag(Qt::Window);
    w->setWindowModality(Qt::ApplicationModal);
    w->setAttribute(Qt::WA_DeleteOnClose);
    if(Globals::isFullScreen())
    {
    //    w->setWindowFlags(Qt::FramelessWindowHint);
        w->showFullScreen();
    }
    else
    {
        w->show();
    }
}
