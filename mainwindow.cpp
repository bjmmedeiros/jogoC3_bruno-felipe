#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>
#include <iostream>

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
    player = scene->addRect(0,0,50,50,blackpen,Qt::green);
    player->setPos(100,100);
    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->nativeVirtualKey()) {
    case key_left:
        if( canWalk(key_left, player) == true )
        {
            player->setX(player->x()-Block::BLOCK_WIDTH);
        }
        break;
    case key_right:
        if( canWalk(key_right, player) == true )
        {
            player->setX(player->x()+Block::BLOCK_WIDTH);
        }
        break;
    case key_up:
        if( canWalk(key_up, player) == true )
        {
            player->setY(player->y()-Block::BLOCK_HEIGHT);
        }
        break;
    case key_down:
        if( canWalk(key_down, player) == true )
        {
            player->setY(player->y()+Block::BLOCK_HEIGHT);
        }
        break;
    case key_esc:
        this->close();
        break;
    case key_enter:
        qDebug() << player->x() << player->y();
        break;
    default:
        break;
    }
}

void MainWindow::on_actionTest_triggered()
{
    m->testScan();
    /*
    for ( int i=0; i<10; i++ )
    {
        qDebug() << m->mapBuffer[i][0]->type << m->mapBuffer[i][1]->type << m->mapBuffer[i][2]->type << m->mapBuffer[i][3]->type << m->mapBuffer[i][4]->type << m->mapBuffer[i][5]->type << m->mapBuffer[i][6]->type << m->mapBuffer[i][7]->type << m->mapBuffer[i][8]->type << m->mapBuffer[i][9]->type;
    }
    */
}

void MainWindow::drawMap()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(m->mapBuffer[i][j]->type == Block::brick)
            {
                m->mapBuffer[i][j]->square = scene->addRect(0,0,50,50,blackpen,brickbrush);
            }

            if(m->mapBuffer[i][j]->type == Block::box)
            {
                m->mapBuffer[i][j]->square = scene->addRect(0,0,50,50,blackpen,boxbrush);
            }

            if(m->mapBuffer[i][j]->type == Block::spot)
            {
                m->mapBuffer[i][j]->square = scene->addRect(0,0,50,50,blackpen,spotbrush);
            }

            if(m->mapBuffer[i][j]->type == Block::floor)
            {
                m->mapBuffer[i][j]->square = scene->addRect(0,0,50,50,blackpen,floorbrush);
            }
            m->mapBuffer[i][j]->square->setPos(i*50,j*50);
        }
    }
}

bool MainWindow::canWalk(int direction, QGraphicsRectItem* block)
{
    Block *next;

    switch(direction)
    {
    case key_left:
        next = m->mapBuffer[(block->x()-50)/50][(block->y())/50];
        break;
    case key_right:
        next = m->mapBuffer[(block->x()+50)/50][(block->y())/50];
        break;
    case key_up:
        next = m->mapBuffer[(block->x())/50][(block->y()-50)/50];
        break;
    case key_down:
        next = m->mapBuffer[(block->x())/50][(block->y()+50)/50];
        break;
    default:
        break;
    }

    if( next->type == Block::floor )
    {
        qDebug() << "pode andar.";
        return true;
    }
    else
    {
        qDebug() << next->type;
        qDebug() << "nao pode andar.";
        return false;
    }
}
