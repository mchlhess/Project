#include "cannon.h"
#include <QDebug>
#include <cmath>

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
}

void Cannon::fire() {
    Ball *b = new Ball(mw, scene);
    auto shp = r->shape().controlPointRect();
    QPointF point = QPointF(shp.right(), shp.top());

    float s = sin((-rot+180) * 3.14159265 / 180.0);
    float c = cos((-rot+180) * 3.14159265 / 180.0);

    // translate point back to origin:
    point.setX(-shp.right() + 15);
    point.setY(-std::abs(shp.top() - (scene->height() - 30)));

    // rotate point
    float x = point.x() * c + point.y() * s;
    float y = point.x() * s - point.y() * c;

    // translate point back:
    point.setX(x + 15);
    point.setY(-y + scene->height() - 30);
    b->setX(point.x());
    b->setY(std::abs(-point.y()));

    b->setV(1, -rot);

    scene->addItem(b);
}

//Listens for keypresses and handles them accordingly
bool Cannon::eventFilter(QObject *target, QEvent *e)
{
    Q_UNUSED(target);
    bool handled = false;

    if ( e->type() == QEvent::KeyPress ) {
        QKeyEvent *keyEvent = (QKeyEvent *)e;
        //Rotate cannon up
        if (keyEvent->key() == Qt::Key_Up) {
            rotate(-3); //Angles are inverse because Y axis points down
            qDebug() << "Key up";
        }

        //Rotate cannon down
        else if (keyEvent->key() == Qt::Key_Down) {
            rotate(3);
            qDebug() << "Key down";
        }

        //Fire cannonball
        else if (keyEvent->key() == Qt::Key_Space) {
            this->fire();
        }
    }
    return handled;
}
