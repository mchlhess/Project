#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Ball(QGraphicsScene *scene);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void frame();

private:
    //Velocity values
    const QGraphicsScene *scene;

    QRectF rect;
    double vy;
    double vx;

};

#endif // BALL_H
