#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>

#include "map.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scenario->hide();
    scene = new QGraphicsScene(this);
    ui->scenario->setScene(scene);

    QPen blackpen(Qt::black);
    blackpen.setWidth(1);
    QBrush redbrush(Qt::red);

    rectangle = scene->addRect(20,20,50,50,blackpen,redbrush);

    border.top = scene->addLine(0,0,500,0,blackpen);
    border.bottom = scene->addLine(0,500,500,500,blackpen);
    border.left = scene->addLine(0,0,0,500,blackpen);
    border.right = scene->addLine(500,0,500,500,blackpen);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->nativeVirtualKey()) {
        case key_left:
            rectangle->setX(rectangle->x()-10);

            if(collided(rectangle,border.left))
            {
                qDebug() << "colidiu";
                rectangle->setX(rectangle->x()+10);
            }
            break;
        case key_right:
            rectangle->setX(rectangle->x()+10);

            if(collided(rectangle,border.right))
            {
                qDebug() << "colidiu";
                rectangle->setX(rectangle->x()-10);
            }
            break;
        case key_up:
            rectangle->setY(rectangle->y()-10);

            if(collided(rectangle,border.top))
            {
                qDebug() << "colidiu";
                rectangle->setY(rectangle->y()+10);
            }
            break;
        case key_down:
            rectangle->setY(rectangle->y()+10);

            if(collided(rectangle,border.bottom))
            {
                qDebug() << "colidiu";
                rectangle->setY(rectangle->y()-10);
            }
            break;
        case key_esc:
            this->close();
        default:
            break;
    }
}
