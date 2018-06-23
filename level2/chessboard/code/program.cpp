#include "program.h"
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QString>
Program::Program()
{
}

void Program::run(QString input,QString filename)
{
    process=new QProcess();
    process->start(filename);
    process->waitForStarted(-1);
    process->write(input.toUtf8());//转成QByteArray进行传输
    //process->write(input.toLatin1());
    process->waitForFinished(-1);
    QString output=process->readAllStandardOutput();
    process->kill();
    process->deleteLater();
    output=output.replace("\r\n","");
    QStringList temp=output.split(" ");
    emit stepfinished(temp);
    disconnect(this,0,0,0);
}

/*void Program::stop()
{
    disconnect(this,0,0,0);
}*/

