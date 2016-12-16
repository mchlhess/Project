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
    //scene->addItem(b);

    scene->setSceneRect(0,0,690,490);
    Cannon *cannon = new Cannon(this, scene);
    scene->addItem(cannon);

    ui->graphicsView->setFixedSize(700,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(cannon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
