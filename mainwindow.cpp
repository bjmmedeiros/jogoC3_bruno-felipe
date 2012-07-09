#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QObject::connect( this, SIGNAL(gamerUpdated()), this, SLOT(updateGamer()) );
    QObject::connect( this, SIGNAL(boxUpdated()), this, SLOT(updateBoxes()) );
    QObject::connect( this, SIGNAL(nextLevel()), this, SLOT(on_actionNew_Game_triggered()) );

    ui->setupUi(this);

    ui->scenario->hide();

    scene = new QGraphicsScene(this);
    ui->scenario->setScene(scene);

    blackpen.setColor(Qt::black);

    floorbrush.setColor(Qt::black); floorbrush.setStyle(Qt::SolidPattern);
    brickbrush.setColor(Qt::gray); brickbrush.setStyle(Qt::SolidPattern);
    boxbrush.setColor(Qt::blue); boxbrush.setStyle(Qt::SolidPattern);
    spotbrush.setColor(Qt::red); spotbrush.setStyle(Qt::SolidPattern);
    boxspotbrush.setColor(Qt::yellow); boxspotbrush.setStyle(Qt::SolidPattern);
    gamerbrush.setColor(Qt::green); gamerbrush.setStyle(Qt::SolidPattern);

    border.top = scene->addLine(0,0,500,0,blackpen);
    border.bottom = scene->addLine(0,500,500,500,blackpen);
    border.left = scene->addLine(0,0,0,500,blackpen);
    border.right = scene->addLine(500,0,500,500,blackpen);

    folder = new QDir("maps");
    mapList = folder->entryList();

    currentLevel = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    m =new Map(folder->filePath(mapList.at(currentLevel+1)));
    m->scanMap();
    this->drawMap();
    this->drawSpots();
    this->drawBoxes();
    this->drawGamer();

    ui->scenario->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch(k->nativeVirtualKey())
    {
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

    if ( allBoxesOnSpot() )
    {
        if (currentLevel != 3)
        {
            currentLevel++;
            emit this->nextLevel();
        }
        else
        {
            this->close();
        }
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

void MainWindow::updateBoxes()
{
    Box * box;
    foreach(box, m->boxBuffer)
    {
        box->square->setPos(box->coord.x()*50, box->coord.y()*50);
        if ( box->onSpot )
        {
            box->square->setBrush(boxspotbrush);
        }
        else
        {
            box->square->setBrush(boxbrush);
        }
    }
}

void MainWindow::boxOnSpot(QPoint pos)
{
    Box *box;
    foreach(box, m->boxBuffer)
    {
        if ( box->coord == pos )
        {
            box->square->setBrush(boxspotbrush);
        }
    }
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
            if ( canMoveBox(direction, box) )
            {
                return true;
            }
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

    return true; //its just floor.
}

bool MainWindow::canMoveBox(int direction, Box *current)
{
    Block* next;
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
            current->setCoord(next->coord.x(), next->coord.y());
            current->onSpot = true;
            emit this->boxUpdated();
            return true;
        }
    }
    current->onSpot = false;
    current->setCoord(next->coord.x(), next->coord.y());
    emit this->boxUpdated();
    return true; //its just floor.
}

bool MainWindow::allBoxesOnSpot()
{
    Box *box;
    foreach(box, m->boxBuffer)
    {
        if( !(box->onSpot) )
        {
            return false;
        }
    }
    return true;
}
