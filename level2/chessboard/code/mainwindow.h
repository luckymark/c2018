#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chessboard.h"
#include "playerbar.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "winbar.h"
class ChessBoard;
class PlayerBar;
class WinBar;
//class TitleBar;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ChessBoard * chessboard;
    PlayerBar * playerbarl;
    PlayerBar * playerbarr;
    void mainWindowInit();
signals:
    void stoptimel();
    void stoptimer();
protected:
private:
    Ui::MainWindow *ui;
    int all;
    QPushButton * stb;
    WinBar * winbar;
    QLabel * winbartext;
    QPushButton * winbarrestart;
    QPushButton * winbarclose;
public slots:
    void showstb();
    void playing();
    void playerlstart();
    void playerrstart();
    void restart();
    void timeoverl();
    void timeoverr();
    void setchessboard();
    void openwinbar();
    void divide(QPoint step);
};

#endif // MAINWINDOW_H
