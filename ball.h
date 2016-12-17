#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "mainwindow.h"

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Ball(MainWindow *w, QGraphicsScene *sc);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setV(int v, int ang); //Sets vertical and horizontal velocity proprotionally according to proper values
    //of a cannonball fired at angle ang
    void setVx(double v) { vx = v; }
    void setVy(double v) { vy = v; }
    enum { Type = UserType + 15 }; //Sets type for the Ball object
    int type() const { return Type; }

public slots:
    void frame(); //Updates position of Ball as called by a timer in constructor

signals:
    void save();

private:
    //Velocity values
    const MainWindow *mw;
    QGraphicsScene *scene;

    QRectF rect = QRectF(0,0,20,20); //Bounding rectangle of Ball
    double vy;
    double vx;
};

#endif // BALL_H
