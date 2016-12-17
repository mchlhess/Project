#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void genBlock();
    void updateBar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int score = 0;
};

#endif // MAINWINDOW_H
