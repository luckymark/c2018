#include "mythread.h"
#include <QDebug>
#include <QString>
void MyThread::startrun(bool sig)
{
    if (sig){
        iswaiting=0;
        counttimer->countTimeInit();
    }
    if (isAI)
        startprogram();
    else
        starthuman();
}

void MyThread::init()
{
    iswaiting=0;
    counttimer->standardtime=QTime(0,0,10,0);
    counttimer->lcdnumber->hide();
}

MyThread::MyThread(PlayerBar * playbar)
{
    iswaiting=0;
    thread = new QThread();
    thread->start();
    counttimer = new CountTimer(playbar);
    counttimer->hide();
    connect(counttimer,SIGNAL(counttimeout()),this,SLOT(stop()));
}

void MyThread::stop()
{
    if (isAI){
        iswaiting=0;
        disconnect(program,SIGNAL(stepfinished(QStringList)),this,SLOT(getstep(QStringList)));
    }else{
        iswaiting=0;
    }
}

void MyThread::startprogram()
{
    iswaiting=1;
    program=new Program();
    connect(program,SIGNAL(stepfinished(QStringList)),this,SLOT(getstep(QStringList)));
    connect(this,SIGNAL(stpro(QString,QString)),program,SLOT(run(QString,QString)));
    program->moveToThread(thread);
    counttimer->countTimerStart();
    emit stpro(input,filename);
    disconnect(this,SIGNAL(stpro(QString,QString)),program,SLOT(run(QString,QString)));//防止原来进程没被杀掉时被触发
}

void MyThread::starthuman()
{
    counttimer->countTimerStart();
    iswaiting=1;
}


void MyThread::getstep(QStringList temp)
{
    if (!iswaiting)return;
    disconnect(program,SIGNAL(stepfinished(QStringList)),this,SLOT(getstep(QStringList)));
    x[0]=temp[0].toInt();
    x[1]=temp[1].toInt();
    emit stepfinished();
}

void MyThread::gethumanstep(QPoint pos)
{
    if (!iswaiting)return;
    x[0]=pos.x()/len;
    x[1]=pos.y()/len;
    emit stepfinished();
}

void MyThread::setfilename(QString *filename1)
{
    filename="";
    filename+=filename1;
}

void MyThread::setchessboard(ChessBoard *chessboard)
{
    input="";
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
            switch(chessboard->key[i][j]){
                case 0:
                input+="0 ";
                break;
                case 1:
                input+="1 ";
                break;
                case 2:
                input+="2 ";
            }
    input+="\n";

}

