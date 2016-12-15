#include "ball.h"

Ball::Ball(QGraphicsScene *sc) {
    scene = sc;
    rect.adjust(0,0,20,20);
    vy = 0.0;
    vx = 0.0;
}

void Ball::frame() {
    const double g_acc = 0.2;

    //If the ball hits the bottom of the frame, make it bounce (reverse direction)
    //Additionally, subtract 1.5 to account for elastic losses
    if (this->y() + g_acc > scene->height()) vy = -(vy + g_acc - 1.5);

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
