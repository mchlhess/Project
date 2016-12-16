#include "ball.h"
#include <QDebug>
#include <cmath>

Ball::Ball(MainWindow *w, QGraphicsScene *sc) {
    mw = w;
    scene = sc;
    vy = 0.0;
    vx = 0.0;
    qDebug() << x() << " " << y();

    QTimer *timer = new QTimer;
    timer->setInterval(1);
    timer->start();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
}

void Ball::frame() {
    const double g_acc = 0.02;

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
    setX(x());
    setY(y() + vy);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawEllipse(rect);
}

QRectF Ball::boundingRect() const {
    return rect;
}
