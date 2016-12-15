#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QDesktopWidget>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    Ball *b = new Ball(scene);

    scene->addItem(b);

     /*QGraphicsRectItem *p = new QGraphicsRectItem(0, 0, 20, 50);
     QGraphicsEllipseItem *b = new QGraphicsEllipseItem(0, 0, 20, 20);
     b->setPos(100,100);*/
    b->setPos(static_cast<double>(width()) * 0.5, static_cast<double>(height()) * 0.5);

    QTimer *timer = new QTimer;
    timer->setInterval(12);
    timer->start();
    QObject::connect(timer, SIGNAL(timeout()), b, SLOT(frame()));


    ui->graphicsView->setMinimumSize(this->width(),this->height());


}

MainWindow::~MainWindow()
{
    delete ui;
}
