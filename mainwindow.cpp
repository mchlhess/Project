#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "cannon.h"
#include <QGraphicsItem>
#include <QMessageBox>
#include <QGraphicsEllipseItem>
#include <QDesktopWidget>
#include <QDebug>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox diff;
    diff.setWindowTitle("Game Start");
    diff.setText("Select difficulty:");
    QPushButton* easy = diff.addButton(tr("Difficult"), QMessageBox::YesRole);
    QPushButton* med = diff.addButton(tr("Medium"), QMessageBox::YesRole);
    QPushButton* hard = diff.addButton(tr("Easy"), QMessageBox::YesRole);
    diff.exec();

    scene = new QGraphicsScene(this);

    scene->setSceneRect(this->rect());

    //Create cannon
    scene->setSceneRect(0,0,690,490);
    Cannon *cannon = new Cannon(this, scene);
    scene->addItem(cannon);

    //Estabish graphicsView things...
    ui->graphicsView->setFixedSize(700,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->installEventFilter(cannon);

    //Create a new block every 1000ms
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, &QTimer::timeout, this, &MainWindow::genBlock);
}

void MainWindow::updateBar() {
    score += 1;
    ui->progressBar->setValue(score);
}

void MainWindow::genBlock() {
    QGraphicsRectItem *block = new QGraphicsRectItem(710, (rand() % 300) + 200, 50, 50); //Creates a block at a random height
    scene->addItem(block);

    qDebug() << "Block generated!";

    QTimer *timer = new QTimer(this);
    timer->setInterval(12);
    timer->start();

    //Move block to the left using **lambda function** in QObject::connect call
    connect(timer, &QTimer::timeout, [=]() {
      block->setX(block->x() - 5);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
