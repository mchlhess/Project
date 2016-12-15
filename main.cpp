#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget desk;

    w.setFixedSize((desk.width() * 0.5), (desk.height() * 0.5));
    w.show();

    return a.exec();
}
