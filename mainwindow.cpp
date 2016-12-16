#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "cannon.h"
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QDesktopWidget>
#include <QDebug>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Establish scene
    scene = new QGraphicsScene(this);
    //scene->setSceneRect(this->rect());
    scene->setSceneRect(0,0,690,490);
    Cannon *cannon = new Cannon(this, scene);
    scene->addItem(cannon);

    ui->graphicsView->setFixedSize(700,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(cannon);

    //Set a timer to generate blocks from the right side of the screen every 1000ms
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, &QTimer::timeout, this, &MainWindow::genBlock);
}

void MainWindow::genBlock() {
    //Generate 50x50 block
    QGraphicsRectItem *block = new QGraphicsRectItem(710, (rand() % 300) + 200, 50, 50);
    scene->addItem(block);

    qDebug() << "Block generated!";

    //Update position of block every 12ms using lambda function inside connect statement
    QTimer *timer = new QTimer(this);
    timer->setInterval(12);
    timer->start();

    connect(timer, &QTimer::timeout, [=]() {
      block->setX(block->x() - 5);
      if(block->x() < -700) { scene->removeItem(block);
      }
      qDebug() << block->x();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
