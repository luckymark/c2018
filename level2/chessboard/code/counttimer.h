#ifndef COUNTTIMER_H
#define COUNTTIMER_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
class CountTimer : public QWidget
{
    Q_OBJECT
public:
    explicit CountTimer(QWidget *parent = nullptr);
    QTime times;
    QTime standardtime=QTime(0,0,10,0);
    QTimer * timer;
    QLCDNumber * lcdnumber;
    int timelen=100;
    void countTimerStart();
signals:
    void counttimeout();
    void timerstopsig();
public slots:
    void countTimerUpdate();
    void countTimeInit();
    bool countTimerRemainupdate();
    void stoptimer();
};

#endif // COUNTTIMER_H
