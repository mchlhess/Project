#ifndef CANNON_H
#define CANNON_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "mainwindow.h"
#include "ball.h"

class Cannon : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cannon(MainWindow *w, QGraphicsScene *sc);
    ~Cannon() { delete r; }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public signals:
    void stoprotate();

protected:
    bool eventFilter(QObject *, QEvent *);
    //void rotate(int degrees);
    void fire();

private:
    //Velocity values
    MainWindow *mw;
    QGraphicsScene *scene;

    int rot = 0;

    QGraphicsRectItem *r = new QGraphicsRectItem;
};

#endif // CANNON_H
