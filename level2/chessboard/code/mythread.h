#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QProcess>
#include <chessboard.h>
#include "playerbar.h"
#include "counttimer.h"
#include "program.h"
#include <QThread>
#include <QStringList>
#include <QString>
class ChessBoard;
class CountTimer;
class PlayerBar;
class MyThread : public QObject
{
    Q_OBJECT //重新添加后要重新qmake一下,这个告诉编译器扫描slots和signals
protected:
    void run();
public:
    MyThread(PlayerBar * playbar);
    void startrun(bool sig);
    void init();
    int len=40;
    QProcess * process;
    QString filename,input;
    QThread * thread;
    CountTimer * counttimer;
    Program * program;
    int x[2];
    bool isAI,iswaiting;
    void setfilename(QString* filename);
    void setchessboard(ChessBoard*chessboard);
    void startprogram();
    void starthuman();
    void gethumanstep(QPoint pos);
signals:
    void stepfinished();
    void stpro(QString input,QString filename);
private:
public slots:
    void stop();
    void getstep(QStringList temp);
};

#endif // MYTHREAD_H
