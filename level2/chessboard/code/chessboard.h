#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QBitmap>
class ChessBoard : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = nullptr);
    QPixmap cb=QPixmap(":/myImage/images/chessboard.png");
    QPainter * painter;
    int len=40;
    int key[15][15];
    bool check();
    void init();
protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void getstep(QPoint step);
public slots:
};

#endif // CHESSBOARD_H
