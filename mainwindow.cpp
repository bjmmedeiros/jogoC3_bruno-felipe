#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>

//#include "map.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scenario->hide();
    ui->console->hide();

    scene = new QGraphicsScene(this);
    ui->scenario->setScene(scene);

    blackpen.setColor(Qt::black);
    redbrush.setColor(Qt::red);
    redbrush.setStyle(Qt::SolidPattern);

    //player = scene->addRect(20,20,50,50,blackpen,redbrush);

    border.top = scene->addLine(0,0,500,0,blackpen);
    border.bottom = scene->addLine(0,500,500,500,blackpen);
    border.left = scene->addLine(0,0,0,500,blackpen);
    border.right = scene->addLine(500,0,500,500,blackpen);

    m =new Map("maps/test.map");
    m->scanMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    this->drawMap(m->mapBuffer);
    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->nativeVirtualKey()) {
        case key_left:
            player->setX(player->x()-10);

            if(collided(player,border.left))
            {
                qDebug() << "colidiu";
                player->setX(player->x()+10);
            }
            break;
        case key_right:
            player->setX(player->x()+10);

            if(collided(player,border.right))
            {
                qDebug() << "colidiu";
                player->setX(player->x()-10);
            }
            break;
        case key_up:
            player->setY(player->y()-10);

            if(collided(player,border.top))
            {
                qDebug() << "colidiu";
                player->setY(player->y()+10);
            }
            break;
        case key_down:
            player->setY(player->y()+10);

            if(collided(player,border.bottom))
            {
                qDebug() << "colidiu";
                player->setY(player->y()-10);
            }
            break;
        case key_esc:
            this->close();
        default:
            break;
    }
}

void MainWindow::on_actionTest_triggered()
{
    ui->gameName->hide();
    ui->scenario->hide();

    ui->console->clear();

    Map *mapa = new Map(QString("maps/test.map"));

    mapa->scanMap();

    ui->console->show();
}

void MainWindow::drawMap(std::vector< std::vector<Block*> > &v)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            Block *b = v[i][j];
            if(b->type == Block::brick)
            {
                scene->addRect(i*50, j*50, 50, 50, blackpen, redbrush);
            }
        }
    }
}
