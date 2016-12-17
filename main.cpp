#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMainWindow mw;
    mw.show();
    mw.close();
    w.setWindowTitle("Cannon assault");
    w.show();

    return a.exec();
}
