#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "cannon.h"
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



    scene->setSceneRect(this->rect());
    Ball *b = new Ball(this, scene);
    b->setPos(0,0);
    scene->addItem(b);

    Cannon *can = new Cannon(this, scene);
    scene->addItem(can);

    ui->graphicsView->setMinimumSize(700,500);
    scene->setSceneRect(0,0,690,490);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
