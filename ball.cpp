#include "ball.h"
#include <QDebug>
#include <cmath>

Ball::Ball(MainWindow *w, QGraphicsScene *sc) {
    mw = w;
    scene = sc;
    vy = 0.0;
    vx = 0.0;

    QTimer *timer = new QTimer;
    timer->setInterval(30);
    timer->start();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(frame())); //Call frame every millisecond
}

void Ball::setV(int v, int ang) {
    vy = -sin(ang * 3.14159265 / 180.0)*v;
    vx = cos(ang * 3.14159265 / 180.0)*v;
}

void Ball::frame() {
    const double g_acc = 0.03;

    //Coefficient of restitution
    const double c_res = 0.8;
    //qDebug() << x() << " " << y();

    //If the ball hits the bottom of the frame, make it bounce (reverse direction)
    //Multiply by c_res to account for energy loss
    if (this->y() > scene->height()) vy = -std::abs(vy + g_acc)*(c_res);
    //qDebug() << this->y() << " " << g_acc << " " << mw->height();
    //qDebug() << vy;

    //Gravity does work
    vy += g_acc;

    //Update position
    setX(x() + vx);
    setY(y() + vy);

    //Collision monitoring
    //Loop through every item in scene
    foreach(QGraphicsItem *g, scene->items()) {
        //If the item is the cannon, ignore
        if (g->type() != 65536) {
            //Loop through every item again to match for a collision
            foreach(QGraphicsItem *del, scene->items()) {
                //Check if there is a collision
                if (g->collidesWithItem(del)) {

                    //Make sure it's a cannonball hitting a block or a block hitting a cannonball
                    if ((g->type() == 3 && del->type() == 65551) || (g->type() == 65551 && del->type() == 3)) {
                        qDebug() << "deleted";
                        scene->removeItem(del);
                        emit save();
                    }
                }
            }
        }
    }
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawEllipse(rect);
}

QRectF Ball::boundingRect() const {
    return rect;
}
