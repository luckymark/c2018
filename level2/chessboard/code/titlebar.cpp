#include "titlebar.h"

TitleBar::TitleBar(MainWindow * parent)
{
    setFixedHeight(1);
    this->setWindowTitle("chess game");
    this->setGeometry(100,300,1000,30);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{

}
