#include "winbar.h"
void WinBar::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

WinBar::WinBar(QWidget *parent) : QMainWindow(parent)
{ 
}
