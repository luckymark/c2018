#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QProcess>
class Program : public QObject
{
    Q_OBJECT
public:
    Program();
    QProcess * process;
signals:
    void stepfinished(QStringList temp);
public slots:
    void run(QString input,QString filename);
    //void stop();
};

#endif // PROGRAM_H
