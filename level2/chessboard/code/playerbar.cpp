#include "playerbar.h"
#include <QLabel>
#include <QDebug>
PlayerBar::PlayerBar(QWidget *parent,QString *name,QRect *place) : QWidget(parent)
{
    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAutoFillBackground(true);
    //this->setGeometry(place->x(),place->y(),place->width(),place->height());
    this->setFixedSize(place->width(),place->height());
    QLabel * label=new QLabel(this);
    label->setAutoFillBackground(true);
    label->setText(*name);
    label->setFont(QFont("SimSun-ExtB",15,75));
    label->setAlignment(Qt::AlignHCenter);
    label->setGeometry(0,10,200,100);

    opb = new QPushButton(this);
    opb->setGeometry(50,250,100,25);
    opb->setText("打开AI程序");
    connect(opb,SIGNAL(clicked(bool)),this,SLOT(openfile()));

    chbt = new QPushButton(this);
    chbt->setGeometry(25,200,150,25);
    chbt->setText("AI模式(点击切换)");

    surebt = new QPushButton(this);
    surebt->setGeometry(75,250,50,25);
    surebt->setText("确认");

    showfile = new QLabel(this);
    showfile->setGeometry(0,300,200,25);
    showfile->setText("AI程序路径为空");
    showfile->setAlignment(Qt::AlignCenter);
    showfile->setFrameShape(QFrame::Box);

    mythread = new MyThread(this);
    mythread->isAI=1;
    connect(this,SIGNAL(filenamechanged()),this,SLOT(setfilename()));

    timeedit= new QTimeEdit(this);
    timeedit->setGeometry(0,50,200,50);
    timeedit->setDisplayFormat("mm分ss秒");
    timeedit->show();
    timeedit->setAlignment(Qt::AlignCenter);

    tiptime=new QLabel(this);
    tiptime->setGeometry(0,100,200,50);
    tiptime->setText("请设定单手限制时间");
    tiptime->setAlignment(Qt::AlignCenter);
    init();
}

void PlayerBar::init()
{
    timeedit->setTime(QTime(0,0,10,0));
    timeedit->show();
    tiptime->show();
    chbt->show();
    chbt->setText("AI模式(点击切换)");
    chbt->setCheckable(1);
    chbt->setChecked(0);
    connect(chbt,SIGNAL(clicked(bool)),this,SLOT(changemode(bool)));
    surebt->show();
    surebt->setCheckable(1);
    connect(surebt,SIGNAL(clicked(bool)),this,SLOT(makesure(bool)));
    opb->hide();
    opb->setText("打开AI程序");
    showfile->hide();
    showfile->setText("AI程序路径为空");
    isloaded=0;
    mythread->isAI=1;
    mythread->init();
}

void PlayerBar::openfile()
{
    filedialog = new QFileDialog(this);
    filedialog->setWindowTitle("打开AI程序");
    filedialog->setNameFilter("File(*.exe)");
    filedialog->setFileMode(QFileDialog::ExistingFile);
    filedialog->setViewMode(QFileDialog::Detail);
    filedialog->setDirectory("C:");
    if (filedialog->exec()){
        filename=(filedialog->selectedFiles())[0];
        showfile->setText(QString("文件路径:")+filename);
        isloaded=1;
        emit filenamechanged();
    }
}


void PlayerBar::setfilename()
{
    this->mythread->setfilename(&filename);
}

void PlayerBar::changemode(bool checked)
{
    if (checked)mythread->isAI=0,chbt->setText("人工模式(点击切换)");
    else
        mythread->isAI=1,chbt->setText("AI模式(点击切换)");
}

void PlayerBar::makesure(bool checked)
{
    disconnect(chbt,SIGNAL(clicked(bool)),this,SLOT(changemode(bool)));
    surebt->hide();
    if (mythread->isAI){
        chbt->setText("AI模式");
        opb->show();
        showfile->show();
    }else{
        chbt->setText("人工模式");
        emit choosehumanmode();
    }
}



