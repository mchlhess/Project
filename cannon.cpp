#include "cannon.h"

Cannon::Cannon(MainWindow *w, QGraphicsScene *sc)
{
    mw = w;
    scene = sc;
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawEllipse(10,scene->height(), 30, 30);
}

QRectF Cannon::boundingRect() const {
    return rect;
}
