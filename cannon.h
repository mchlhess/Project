#ifndef CANNON_H
#define CANNON_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "mainwindow.h"

class Cannon : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cannon(MainWindow *w, QGraphicsScene *sc);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

//public slots:
    //void frame();

private:
    //Velocity values
    const MainWindow *mw;
    const QGraphicsScene *scene;

    QRectF rect = QRectF(0,0,80,20);
};

#endif // CANNON_H
