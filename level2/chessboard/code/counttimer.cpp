#include "counttimer.h"
#include <QDebug>
CountTimer::CountTimer(QWidget *parent) : QWidget(parent)
{
    lcdnumber = new QLCDNumber(parent);
    lcdnumber->setGeometry(0,50,200,100);
    lcdnumber->display(standardtime.toString("ss:zz"));
    times=standardtime;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(countTimerUpdate()));
    connect(this,SIGNAL(timerstopsig()),timer,SLOT(stop()));
    countTimeInit();
}

void CountTimer::countTimerUpdate()
{
    emit timerstopsig();
    //qDebug()<<times;
    if (times<=QTime(0,0,0,timelen)){
        lcdnumber->display("00:00");
        return;
    }
    times=times.addMSecs(-timelen);
    QString text = times.addSecs(1).toString("mm:ss");
    lcdnumber->display(text);
    timer->start(timelen);
    return;
}

void CountTimer::countTimerStart()
{
    timer->start(timelen);
}

void CountTimer::countTimeInit()
{
    times=standardtime;
    QString text = standardtime.toString("mm:ss");
    lcdnumber->display(text);
}

bool CountTimer::countTimerRemainupdate()
{
    emit timerstopsig();
    int diff=timelen-timer->remainingTime();
    if (times<=QTime(0,0,0,diff)){
        lcdnumber->display("00:00");
        emit counttimeout();
        return 0;
    }
    times=times.addMSecs(-diff);
    QString text = times.addSecs(1).toString("mm:ss");
    lcdnumber->display(text);
    return 1;
}

void CountTimer::stoptimer()
{
    timer->stop();
}
