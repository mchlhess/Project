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
    void setV(int v, int ang);
    void setVx(double v) { vx = v; }
    void setVy(double v) { vy = v; }

public slots:
    void frame();

private:
    //Velocity values
    const MainWindow *mw;
    const QGraphicsScene *scene;

    QRectF rect = QRectF(0,0,20,20);
    double vy;
    double vx;
};

#endif // BALL_H
