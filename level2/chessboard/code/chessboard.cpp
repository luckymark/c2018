#include "chessboard.h"
#include <QIcon>
#include <QPalette>
#include <QDebug>
ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent)
{
    //this->setGeometry(QRect(0,0,600,600));
    this->setFixedSize(600,600);
    init();
   /* this->setAutoFillBackground(true);
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,QBrush(cb.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(bgPalette);*/

    /*boardlayout = new QGridLayout(this);
    boardlayout->setMargin(0);
    boardlayout->setContentsMargins(1,1,0,0);
    boardlayout->setSpacing(0);
    boardlayout->setVerticalSpacing(0);
    boardlayout->setHorizontalSpacing(0);

    wk=new QBitmap(len,len);
    bk=new QBitmap(len,len);
    painter = new*QPainter(wk);
    painter.setPen(QColor(0,0,0));
    painter->drawEllipse(QPoint(len/2,len/2),len/2,len/2);
    for (int i=0;i<1;i++)
        for (int j=0;j<1;j++){
            key[i][j]=new QLabel(this);
            key[i][j]->setFixedSize(len,len);
            boardlayout->addWidget(key[i][j],i,j);
            key[i][j]->setAutoFillBackground(true);
            QPalette bgPalette = key[i][j]->palette();
            bgPalette.setBrush(QPalette::Background,QBrush(wk.scaled(QSize(100,100),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
            key[i][j]->setPalette(bgPalette);
            key[i][j]->setMask(wk);
        }
    setLayout(boardlayout);*/
    painter=new QPainter(this);
}
bool issame(int x,int y,int z,int xx,int yy){
    return x==y&&x==z&&x==xx&&x==yy;
}
bool ChessBoard::check()
{
    for (int i=0;i<11;i++)
        for (int j=0;j<15;j++)
            if ((key[i][j]&&issame(key[i][j],key[i+1][j],key[i+2][j],key[i+3][j],key[i+4][j]))||(key[j][i]&&issame(key[j][i],key[j][i+1],key[j][i+2],key[j][i+3],key[j][i+4])))
                return 1;
    for (int i=0;i<11;i++)
        for (int j=0;j<11;j++)
            if (key[i][j]&&issame(key[i][j],key[i+1][j+1],key[i+2][j+2],key[i+3][j+3],key[i+4][j+4]))return 1;
    for (int i=0;i<11;i++)
        for (int j=4;j<15;j++)
            if (key[i][j]&&issame(key[i][j],key[i+1][j-1],key[i+2][j-2],key[i+3][j-3],key[i+4][j-4]))return 1;
    return 0;
}

void ChessBoard::init()
{
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
            key[i][j]=0;
    this->update();
}

void ChessBoard::paintEvent(QPaintEvent *event)
{
    painter->begin(this);
    painter->drawPixmap(0,0,this->width(),this->height(),cb);
    painter->setPen(QColor(0,0,0,200));
    painter->setBrush(QColor(0,0,0,200));
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
            if (key[i][j]==1)
            painter->drawEllipse(QPoint(len/2+len*i,len/2+len*j),len/2-4,len/2-4);
    painter->setPen(QColor(255,255,255,200));
    painter->setBrush(QColor(255,255,255,200));
    for (int i=0;i<15;i++)
        for (int j=0;j<15;j++)
            if (key[i][j]==2)
            painter->drawEllipse(QPoint(len/2+len*i,len/2+len*j),len/2-4,len/2-4);
    painter->end();
}

void ChessBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton){
        emit getstep(event->pos());
    }
}


