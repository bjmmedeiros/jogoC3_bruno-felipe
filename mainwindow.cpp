#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QObject::connect(this, SIGNAL(gamerUpdated()), this, SLOT(updateGamer()));

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
    gamerbrush.setColor(Qt::green); gamerbrush.setStyle(Qt::SolidPattern);

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
    this->drawSpots();
    this->drawBoxes();
    this->drawGamer();

    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->nativeVirtualKey()) {
    case key_left:
        if ( canWalk(key_left, m->gamer) )
        {
            m->gamer->coord.setX(m->gamer->coord.x()-1);
            emit this->gamerUpdated();
        }
        break;
    case key_right:
        if ( canWalk(key_right, m->gamer) )
        {
            m->gamer->coord.setX(m->gamer->coord.x()+1);
            emit this->gamerUpdated();
        }
        break;
    case key_up:
        if ( canWalk(key_up, m->gamer) )
        {
            m->gamer->coord.setY(m->gamer->coord.y()-1);
            emit this->gamerUpdated();
        }
        break;
    case key_down:
        if ( canWalk(key_down, m->gamer) )
        {
            m->gamer->coord.setY(m->gamer->coord.y()+1);
            emit this->gamerUpdated();
        }
        break;
    case key_esc:
        this->close();
        break;
    case key_enter:
        qDebug() << m->gamer->coord.x() << m->gamer->coord.y();
        break;
    default:
        break;
    }
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

void MainWindow::updateGamer()
{
    m->gamer->square->setPos(m->gamer->coord.x()*50, m->gamer->coord.y()*50);
}

void MainWindow::drawMap()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(m->mapBuffer[j][i]->type == Block::brick)
            {
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,brickbrush);
            }

            else if(m->mapBuffer[j][i]->type == Block::floor)
            {
                m->mapBuffer[j][i]->square = scene->addRect(0,0,50,50,blackpen,floorbrush);
            }

            m->mapBuffer[j][i]->square->setPos(j*50,i*50);
        }
    }
}

void MainWindow::drawSpots()
{
    for (int i=0; i < (int)m->spotBuffer.size(); i++)
    {
        m->spotBuffer.at(i)->square = scene->addRect(0,0,50,50,blackpen,spotbrush);
        m->spotBuffer.at(i)->square->setPos( m->spotBuffer.at(i)->coord.x()*50, m->spotBuffer.at(i)->coord.y()*50 );
    }
}

void MainWindow::drawBoxes()
{
    for (int i=0; i < (int)m->boxBuffer.size(); i++)
    {
        m->boxBuffer.at(i)->square = scene->addRect(0,0,50,50,blackpen,boxbrush);
        m->boxBuffer.at(i)->square->setPos( m->boxBuffer.at(i)->coord.x()*50, m->boxBuffer.at(i)->coord.y()*50 );
    }
}

void MainWindow::drawGamer()
{
    m->gamer->square = scene->addRect(0,0,50,50,blackpen,gamerbrush);
    m->gamer->square->setPos(m->gamer->coord.x()*50, m->gamer->coord.y()*50);
}

bool MainWindow::canWalk(int direction, Block *current)
{
    Block *next;

    switch(direction)
    {
    case key_left:
        next = m->mapBuffer[current->coord.x()-1][current->coord.y()];
        break;
    case key_right:
        next = m->mapBuffer[current->coord.x()+1][current->coord.y()];
        break;
    case key_up:
        next = m->mapBuffer[current->coord.x()][current->coord.y()-1];
        break;
    case key_down:
        next = m->mapBuffer[current->coord.x()][current->coord.y()+1];
        break;
    default:
        break;
    }

    if ( next->type == Block::brick )
    {
        return false;
    }
    //else, it means is floor. So we need to check the other buffers first...

    Box *box;
    foreach (box, m->boxBuffer)
    {
        if( box->coord == next->coord )
        {
            return false;
        }
    }

    Block *spot;
    foreach (spot, m->spotBuffer)
    {
        if( spot->coord == next->coord )
        {
            return true;
        }
    }

    return true; //its only floor.
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
