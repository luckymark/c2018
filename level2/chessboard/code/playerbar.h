#ifndef PLAYERBAR_H
#define PLAYERBAR_H

#include <QMainWindow>
#include <QWidget>
#include "mythread.h"
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QTimeEdit>
#include "mainwindow.h"
class CountTimer;
class MyThread;
class MainWindow;
class PlayerBar : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerBar(QWidget *parent = nullptr,QString *name = nullptr,QRect * place = nullptr);
    QPushButton * opb;
    QPushButton * chbt;
    QPushButton * surebt;
    QTimeEdit * timeedit;
    QLabel * tiptime;
    QFileDialog * filedialog;
    MyThread * mythread;
    bool isloaded;
    void init();
signals:
    void filenamechanged();
    void choosehumanmode();
public slots:
    void openfile();
    void setfilename();
    void changemode(bool checked);
    void makesure(bool checked);
private:
    QString filename;
    QLabel * showfile;
private slots:
};

#endif // PLAYERBAR_H
