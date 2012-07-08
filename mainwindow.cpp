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
    playerbrush.setColor(Qt::green); playerbrush.setStyle(Qt::SolidPattern);

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
    m =new Map("maps/test.map");
    m->scanMap();
    this->drawMap();
    if ( (player = getPlayer()) == NULL )
    {
        qDebug() << "Map has no player.";
        exit(EXIT_FAILURE);
    }
    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{/*
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
    }*/
}

void MainWindow::on_actionTest_triggered()
{
    m =new Map("maps/test.map");
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
            if(m->mapBuffer[j][i]->type == Block::brick)
            {
                qDebug() << j << i << m->mapBuffer[j][i]->type;
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,brickbrush);
            }

            else if(m->mapBuffer[j][i]->type == Block::box)
            {
                qDebug() << j << i << m->mapBuffer[j][i]->type;
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,boxbrush);
            }

            else if(m->mapBuffer[j][i]->type == Block::spot)
            {
                qDebug() << j << i << m->mapBuffer[j][i]->type;
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,spotbrush);
            }

            else if(m->mapBuffer[j][i]->type == Block::floor)
            {
                qDebug() << j << i << m->mapBuffer[j][i]->type;
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,floorbrush);
            }
            else if(m->mapBuffer[j][i]->type == Block::player)
            {
                qDebug() << j << i << m->mapBuffer[j][i]->type;
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,playerbrush);
            }
            m->mapBuffer[j][i]->square->setPos(j*50,i*50);
        }
    }
}

bool MainWindow::canWalk(int direction, Block *block)
{
    Block *next;

    switch(direction)
    {
    case key_left:
        next = m->mapBuffer[block->coord.x()-1][block->coord.y()];
        break;
    case key_right:
        next = m->mapBuffer[block->coord.x()+1][block->coord.y()];
        break;
    case key_up:
        next = m->mapBuffer[block->coord.x()][block->coord.y()-1];
        break;
    case key_down:
        next = m->mapBuffer[block->coord.x()][block->coord.y()+1];
        break;
    default:
        break;
    }

    switch(next->type)
    {
    case Block::floor:
        /*
        qDebug() << "Pode andar.";
        QPoint temp = block->coord;
        block->coord = next->coord;
        next->coord = temp;
        return true;
        */
        break;
    case Block::spot:
        qDebug() << "Pode andar.";
        return true;
        break;
    case Block::brick:
        qDebug() << next->type << "nao pode andar.";
        return false;
        break;
    case Block::box:
        return boxMove(direction, next);
        break;
    default:
        return false;
        break;
    }
}

bool MainWindow::boxMove(int direction, Block *box)
{
    Block* next;
    switch(direction)
    {
    case key_left:
        next = m->mapBuffer[(box->square->x()-50)/50][(box->square->y())/50];
        break;
    case key_right:
        next = m->mapBuffer[(box->square->x()+50)/50][(box->square->y())/50];
        break;
    case key_up:
        next = m->mapBuffer[(box->square->x())/50][(box->square->y()-50)/50];
        break;
    case key_down:
        next = m->mapBuffer[(box->square->x())/50][(box->square->y()+50)/50];
        break;
    default:
        break;
    }

    if (next->type == Block::floor || next->type == Block::spot)
    {
        return true;
    }
    else return false;
}

Block *MainWindow::getPlayer()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(m->mapBuffer[i][j]->type == Block::player)
            {
                return m->mapBuffer[i][j];
            }
        }
    }
    return NULL;
}
