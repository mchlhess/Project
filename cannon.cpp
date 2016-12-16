#include "cannon.h"
#include <QDebug>

Cannon::Cannon(MainWindow *w, QGraphicsScene *sc)
{
    mw = w;
    scene = sc;
    r->setRect(0,scene->height()-30,80,20);
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawEllipse(15,scene->height()-30, 30, 30);
    painter->drawRect(r->boundingRect());
}

QRectF Cannon::boundingRect() const {
    return r->boundingRect();
}

void Cannon::rotate(int degrees) {
    rot += degrees;
    this->setTransformOriginPoint(15,scene->height()-30);
    this->setRotation(rot);
    //this->update();
    //qDebug("%f %f %f %f", r->boundingRect().left(), r->boundingRect().top(), r->boundingRect().right(), r->boundingRect().bottom());
}

bool Cannon::eventFilter(QObject *target, QEvent *e)
{
    Q_UNUSED(target);

    bool handled = false;
    if ( e->type() == QEvent::KeyPress ) {
        QKeyEvent *keyEvent = (QKeyEvent *)e;
        if (keyEvent->key() == Qt::Key_Up) {
            this->rotate(-3); //Angles are inverse because Y axis points down
            qDebug() << "Key up";
        }
        else if (keyEvent->key() == Qt::Key_Down) {
            this->rotate(3);
            qDebug() << "Key down";
        }
        else if (keyEvent->key() == Qt::Key_Space) {
            //this->fire();
        }
    }
    return handled;
}
