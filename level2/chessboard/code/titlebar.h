#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "mainwindow.h"

class MainWindow;
class TitleBar : public QWidget
{
    Q_OBJECT
public:
    TitleBar(MainWindow * parent=0);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // TITLEBAR_H
