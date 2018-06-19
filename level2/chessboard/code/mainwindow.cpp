#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRect>
#include <QMainWindow>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(QRect(300,300,1000,600));
    this->setFixedSize(1040,625);
    chessboard = new ChessBoard(this);
    QString * name1=new QString("玩家1");
    QString * name2=new QString("玩家2");
    QRect * place1=new QRect(100,300,200,600);
    QRect * place2=new QRect(900,300,200,600);
    playerbarl = new PlayerBar(nullptr,name1,place1);
    playerbarr = new PlayerBar(nullptr,name2,place2);

    stb=new QPushButton(this);
    stb->setGeometry(470,300,100,25);
    stb->setText("开始对战");
    stb->hide();
    connect(playerbarl,SIGNAL(filenamechanged()),this,SLOT(showstb()));
    connect(playerbarr,SIGNAL(filenamechanged()),this,SLOT(showstb()));
    connect(playerbarl,SIGNAL(choosehumanmode()),this,SLOT(showstb()));
    connect(playerbarr,SIGNAL(choosehumanmode()),this,SLOT(showstb()));
    connect(playerbarl->mythread,SIGNAL(stepfinished()),this,SLOT(playerrstart()));
    connect(playerbarr->mythread,SIGNAL(stepfinished()),this,SLOT(playerlstart()));
    connect(stb,SIGNAL(clicked(bool)),this,SLOT(playing()));
    connect(this,SIGNAL(stoptimel()),playerbarl->mythread->counttimer,SLOT(countTimerRemainupdate()));
    connect(this,SIGNAL(stoptimer()),playerbarr->mythread->counttimer,SLOT(countTimerRemainupdate()));
    connect(playerbarl->mythread->counttimer,SIGNAL(counttimeout()),this,SLOT(timeoverl()));
    connect(playerbarr->mythread->counttimer,SIGNAL(counttimeout()),this,SLOT(timeoverr()));
    connect(chessboard,SIGNAL(getstep(QPoint)),this,SLOT(divide(QPoint)));
    openwinbar();
    winbar->hide();

    mainWindowInit();
    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(playerbarl);
    layout->addWidget(chessboard);
    layout->addWidget(playerbarr);
    this->centralWidget()->setLayout(layout);
    this->setWindowTitle("五子棋对战平台");
    this->setWindowIcon(QIcon(":/myImage/images/myico.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainWindowInit()
{
    all=0;
    winbar->hide();
    QRect s=this->geometry();
    winbar->setGeometry(QRect(s.x()+200,s.y()+200,0,0));
    winbar->setFixedSize(200,200);
    winbartext->setFont(QFont("SimSun-ExtB",20,20));
    playerbarl->init();
    playerbarr->init();
    chessboard->init();
    setchessboard();
}

void MainWindow::playing()
{
    stb->hide();
    playerbarl->opb->hide();
    playerbarr->opb->hide();
    playerbarr->mythread->counttimer->lcdnumber->show();
    playerbarl->mythread->counttimer->lcdnumber->show();
    playerbarr->mythread->counttimer->standardtime=QTime::fromString(playerbarr->timeedit->text(),"mm分ss秒");
    playerbarl->mythread->counttimer->standardtime=QTime::fromString(playerbarl->timeedit->text(),"mm分ss秒");
    playerbarr->mythread->counttimer->countTimeInit();
    playerbarl->mythread->counttimer->countTimeInit();
    playerbarl->timeedit->hide();
    playerbarr->timeedit->hide();
    playerbarl->tiptime->hide();
    playerbarr->tiptime->hide();
    playerbarl->mythread->startrun(1);
}
bool check(int x){
    return 0<=x&&x<=14;
}
void MainWindow::playerlstart()
{
    if (!playerbarr->mythread->counttimer->countTimerRemainupdate()){
        timeoverr();
        return;
    }
    if (!check(playerbarr->mythread->x[0])||!check(playerbarr->mythread->x[1])){
        ui->statusBar->showMessage("玩家2不知道下到哪去了!");
        playerbarr->mythread->startrun(0);
        return;
    }
    if (chessboard->key[playerbarr->mythread->x[0]][playerbarr->mythread->x[1]]){
        ui->statusBar->showMessage("玩家2下子位已有子!");
        playerbarr->mythread->startrun(0);
        return;
    }
    all++;
    ui->statusBar->showMessage("玩家2成功落子");
    playerbarr->mythread->iswaiting=0;
    chessboard->key[playerbarr->mythread->x[0]][playerbarr->mythread->x[1]]=2;
    setchessboard();
    chessboard->update();
    if (chessboard->check()){
        winbartext->setText("玩家2赢了!");
        winbar->show();
        winbar->setGeometry(this->x()+400,this->y()+200,0,0);
    }else{
        playerbarl->mythread->startrun(1);
    }
}

void MainWindow::playerrstart()
{
    if (!playerbarl->mythread->counttimer->countTimerRemainupdate()){
        timeoverl();
        return;
    }
    if (!check(playerbarl->mythread->x[0])||!check(playerbarl->mythread->x[1])){
        ui->statusBar->showMessage("玩家1不知道下到哪去了!");
        playerbarl->mythread->startrun(0);
        return;
    }
    if (chessboard->key[playerbarl->mythread->x[0]][playerbarl->mythread->x[1]]){
        ui->statusBar->showMessage("玩家1下子位已有子!");
        playerbarl->mythread->startrun(0);
        return;
    }
    all++;
    ui->statusBar->showMessage("玩家1成功落子");
    playerbarl->mythread->iswaiting=0;
    chessboard->key[playerbarl->mythread->x[0]][playerbarl->mythread->x[1]]=1;
    setchessboard();
    chessboard->update();
    if (all==225){
        winbartext->setText("平局");
        winbar->show();
        winbar->setGeometry(this->x()+400,this->y()+200,0,0);
        return;
    }
    if (chessboard->check()){
        winbartext->setText("玩家1赢了!");
        winbar->show();
        winbar->setGeometry(this->x()+400,this->y()+200,0,0);
    }else{
        playerbarr->mythread->startrun(1);
    }
}

void MainWindow::restart()
{
    mainWindowInit();
}

void MainWindow::timeoverl()
{
    winbartext->setText("玩家1超时,玩家2获胜!");
    winbartext->setFont(QFont("SimSun-ExtB",10,10));
    winbar->show();
    winbar->setGeometry(this->x()+400,this->y()+200,0,0);
}

void MainWindow::timeoverr()
{
    winbartext->setText("玩家2超时,玩家1获胜!");
    winbartext->setFont(QFont("SimSun-ExtB",10,10));
    winbar->show();
    winbar->setGeometry(this->x()+400,this->y()+200,0,0);
}

void MainWindow::setchessboard()
{
    playerbarl->mythread->setchessboard(chessboard);
    playerbarr->mythread->setchessboard(chessboard);
}

void MainWindow::openwinbar()
{
    winbar=new WinBar(this);
    //winbar->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);//去除窗口上栏
    winbar->setFixedSize(200,200); //固定winbar大小
    winbar->setGeometry(QRect(500,500,200,200));
    winbartext=new QLabel(winbar);
    winbartext->setGeometry(0,0,200,100);
    winbartext->setFont(QFont("SimSun-ExtB",20,20));
    winbartext->setAlignment(Qt::AlignCenter);
    winbartext->setText("玩家1胜利!");
    winbarrestart = new QPushButton(winbar);
    winbarrestart->setGeometry(0,100,100,50);
    winbarrestart->setText("重新开始");
    winbarclose = new QPushButton(winbar);
    winbarclose->setGeometry(100,100,100,50);
    winbarclose->setText("退出对战");
    connect(winbarclose,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(winbarrestart,SIGNAL(clicked(bool)),this,SLOT(restart()));
    //winbar->setAttribute(Qt::);
}

void MainWindow::divide(QPoint step)
{
    if (playerbarl->mythread->iswaiting)
        playerbarl->mythread->gethumanstep(step);
    else
    if (playerbarr->mythread->iswaiting)
        playerbarr->mythread->gethumanstep(step);
}


void MainWindow::showstb()
{
    if (playerbarr->surebt->isHidden()&&playerbarl->surebt->isHidden()&&(playerbarl->isloaded||playerbarl->mythread->isAI==0) && (playerbarr->isloaded||playerbarr->mythread->isAI==0)){

        stb->show();
    }
}
