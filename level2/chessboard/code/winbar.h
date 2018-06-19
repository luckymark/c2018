#ifndef WINBAR_H
#define WINBAR_H

#include <QMainWindow>
#include <QCloseEvent>
class QMainWindow;
class WinBar : public QMainWindow
{
    Q_OBJECT
public:
    explicit WinBar(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
signals:

public slots:
};

#endif // WINBAR_H
