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

protected:
    bool eventFilter(QObject *, QEvent *); //Looks for keypresses
    void rotate(int degrees); //Rotates cannon
    void fire(); //Creates Ball object at tip of cannon

private:
    //Velocity values
    MainWindow *mw;
    QGraphicsScene *scene;

    int rot = 0; //Stores angle of cannon

    QGraphicsRectItem *r = new QGraphicsRectItem; //Bounding rectangle
};

#endif // CANNON_H
