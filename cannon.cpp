#include "cannon.h"
#include <QDebug>
#include <cmath>

Cannon::Cannon(MainWindow *w, QGraphicsScene *sc)
{
    mw = w;
    scene = sc;
    r->setRect(0,scene->height()-30,80,20); //Creates bounding rectangle
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawEllipse(15,scene->height()-30, 30, 30); //Cannon wheel
    painter->drawRect(r->boundingRect()); //Cannon barrel
}

QRectF Cannon::boundingRect() const {
    return r->boundingRect();
}

void Cannon::rotate(int degrees) {
    //Add 3 degrees to total rotation
    rot += degrees;
    //Sets transform point to center of cannon
    this->setTransformOriginPoint(15,scene->height()-30);
    //Update cannon rotation
    this->setRotation(rot);
}

void Cannon::fire() {
    Ball *b = new Ball(mw, scene);
    //Creates QPointF at the center of the shape()
    auto shp = r->shape().controlPointRect();

    QPointF point = QPointF(shp.right(), shp.top());

    float s = sin((-rot+180) * 3.14159265 / 180.0); //Convert degrees to radians
    float c = cos((-rot+180) * 3.14159265 / 180.0);

    //Subtract rotation point from the actual point
    point.setX(-shp.right() + 15);
    point.setY(-std::abs(shp.top() - (scene->height() - 30)));

    //Caclulate new rotated position
    float x = point.x() * c + point.y() * s;
    float y = point.x() * s - point.y() * c;

    //Add back in subtracted control point
    point.setX(x + 15);
    point.setY(-y + scene->height() - 30);

    //Update ball location
    b->setX(point.x());
    b->setY(std::abs(-point.y()));

    //Set cannonball moving
    b->setV(10, -rot);

    scene->addItem(b);

    connect(b, SIGNAL(save()), mw, SLOT(updateBar()));
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
            this->rotate(-3); //Angles are inverse because Y axis points down
            qDebug() << "Key up";
        }

        //Rotate cannon down
        else if (keyEvent->key() == Qt::Key_Down) {
            this->rotate(3);
            qDebug() << "Key down";
        }

        //Fire cannonball
        else if (keyEvent->key() == Qt::Key_Space) {
            this->fire();
        }
    }
    return handled;
}
