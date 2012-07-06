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
    boxbrush.setColor(Qt::blue); boxbrush.setStyle(Qt::SolidPattern);
    brickbrush.setColor(Qt::gray); brickbrush.setStyle(Qt::SolidPattern);
    spotbrush.setColor(Qt::red); spotbrush.setStyle(Qt::SolidPattern);
    floorbrush.setColor(Qt::black); floorbrush.setStyle(Qt::SolidPattern);

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
    this->drawMap();
    player = scene->addRect(100,100,50,50,blackpen,Qt::green);
    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->nativeVirtualKey()) {
    case key_left:
        walk(key_left);
        player->setX(player->x()-Block::BLOCK_WIDTH);

        if(collided(player,border.left))
        {
            qDebug() << "colidiu";
            player->setX(player->x()+Block::BLOCK_WIDTH);
        }
        break;
    case key_right:
        player->setX(player->x()+Block::BLOCK_WIDTH);

        if(collided(player,border.right))
        {
            qDebug() << "colidiu";
            player->setX(player->x()-Block::BLOCK_WIDTH);
        }
        break;
    case key_up:
        player->setY(player->y()-Block::BLOCK_HEIGHT);

        if(collided(player,border.top))
        {
            qDebug() << "colidiu";
            player->setY(player->y()+Block::BLOCK_HEIGHT);
        }
        break;
    case key_down:
        player->setY(player->y()+Block::BLOCK_HEIGHT);

        if(collided(player,border.bottom))
        {
            qDebug() << "colidiu";
            player->setY(player->y()-Block::BLOCK_HEIGHT);
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

void MainWindow::drawMap()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(m->mapBuffer[i][j]->type == Block::brick)
            {
                m->mapBuffer[i][j]->square = scene->addRect(i*50,j*50,50,50,blackpen,brickbrush);
            }

            if(m->mapBuffer[i][j]->type == Block::box)
            {
                m->mapBuffer[i][j]->square = scene->addRect(i*50,j*50,50,50,blackpen,boxbrush);
            }

            if(m->mapBuffer[i][j]->type == Block::spot)
            {
                m->mapBuffer[i][j]->square = scene->addRect(i*50,j*50,50,50,blackpen,spotbrush);
            }

            if(m->mapBuffer[i][j]->type == Block::floor)
            {
                m->mapBuffer[i][j]->square = scene->addRect(i*50,j*50,50,50,blackpen,floorbrush);
            }
        }
    }
}

bool MainWindow::walk(int direction, QGraphicsRectItem* block)
{
    switch(direction)
    {
    case key_left:
        if( scene->itemAt(block->x()-50,block->y()) == 0 )
        {
            qDebug() << "pode andar.";
        }
        else
        {
            QGraphicsRectItem next = scene->itemAt(block->x()-50,block->y());
        }
        break;
    case key_right:
        break;
    case key_up:
        break;
    case key_down:
        break;
    default:
        break;
    }
}
