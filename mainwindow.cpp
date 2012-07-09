#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>
#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QObject::connect( this, SIGNAL(gamerUpdated(int)), this, SLOT(updateGamer(int)) );
    QObject::connect( this, SIGNAL(boxUpdated()), this, SLOT(updateBoxes()) );
    QObject::connect( this, SIGNAL(nextLevel()), this, SLOT(on_actionNew_Game_triggered()) );
    QObject::connect( this, SIGNAL(hudUpdated()), this, SLOT(updateHUD()) );

    ui->setupUi(this);

    ui->scenario->hide();
    ui->gameHUD->hide();
    ui->scenarioEditor->hide();
    ui->editorPanel->hide();
    ui->QtSoko->hide();
    ui->loadSavePanel->hide();

    scene = new QGraphicsScene(this);


    blackpen.setColor(Qt::black);

    floorbrush.setColor(Qt::black); floorbrush.setStyle(Qt::SolidPattern);
    brickbrush.setColor(Qt::gray); brickbrush.setStyle(Qt::SolidPattern);
    boxbrush.setColor(Qt::blue); boxbrush.setStyle(Qt::SolidPattern);
    spotbrush.setColor(Qt::red); spotbrush.setStyle(Qt::SolidPattern);
    boxspotbrush.setColor(Qt::yellow); boxspotbrush.setStyle(Qt::SolidPattern);
    gamerbrush.setColor(Qt::green); gamerbrush.setStyle(Qt::SolidPattern);

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
    ui->scenario->setScene(scene);

    border.top = scene->addLine(0,0,500,0,blackpen);
    border.bottom = scene->addLine(0,500,500,500,blackpen);
    border.left = scene->addLine(0,0,0,500,blackpen);
    border.right = scene->addLine(500,0,500,500,blackpen);

    moves = 0;
    pushes = 0;

    ui->moves->setText(QString::number(moves));
    ui->pushes->setText(QString::number(pushes));
    ui->label_currentLevel->setText(QString::number(currentLevel));
    ui->label_maxLevel->setText(QString::number(mapList.size()-2));

    m =new Map();
    m->openMap(folder->filePath(mapList.at(currentLevel+1)));

    m->scanMap();
    this->drawMap();
    this->drawSpots();
    this->drawBoxes();
    this->drawGamer();

    ui->actionMap_Editor->setDisabled(true);

    ui->QtSoko->show();
    ui->scenario->show();
    ui->gameHUD->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if ( ui->actionNew_Game->isEnabled() )
    {
        switch(k->nativeVirtualKey())
        {
        case key_left:
            if ( canWalk(key_left, m->gamer) )
            {
                m->gamer->coord.setX(m->gamer->coord.x()-1);
                emit this->gamerUpdated(key_left);
            }
            break;
        case key_right:
            if ( canWalk(key_right, m->gamer) )
            {
                m->gamer->coord.setX(m->gamer->coord.x()+1);
                emit this->gamerUpdated(key_right);
            }
            break;
        case key_up:
            if ( canWalk(key_up, m->gamer) )
            {
                m->gamer->coord.setY(m->gamer->coord.y()-1);
                emit this->gamerUpdated(key_up);
            }
            break;
        case key_down:
            if ( canWalk(key_down, m->gamer) )
            {
                m->gamer->coord.setY(m->gamer->coord.y()+1);
                emit this->gamerUpdated(key_down);
            }
            break;
        case key_esc:
            this->close();
            break;
        case key_enter:
        case key_backspace:
            this->on_actionNew_Game_triggered();
            break;
        default:
            break;
        }

        emit this->hudUpdated();

        if ( allBoxesOnSpot() )
        {
            if (currentLevel != mapList.size()-2)
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
}

void MainWindow::on_actionTest_triggered()
{
}

void MainWindow::updateGamer(int direction)
{
    switch(direction)
    {
    case key_left:
        m->gamer->_square->setPixmap(QPixmap("images/gamerLEFT.png"));
        break;
    case key_right:
        m->gamer->_square->setPixmap(QPixmap("images/gamerRIGHT.png"));
        break;
    case key_up:
        m->gamer->_square->setPixmap(QPixmap("images/gamerUP.png"));
        break;
    case key_down:
        m->gamer->_square->setPixmap(QPixmap("images/gamerDOWN.png"));
        break;
    default:
        break;
    }
    m->gamer->_square->setPos(m->gamer->coord.x()*50, m->gamer->coord.y()*50);
    this->moves++;
}

void MainWindow::updateBoxes()
{
    Box * box;
    foreach(box, m->boxBuffer)
    {
        box->_square->setPos(box->coord.x()*50, box->coord.y()*50);
        if ( box->onSpot )
        {
            box->_square->setPixmap(QPixmap("images/boxspot.png"));
        }
        else
        {
            box->_square->setPixmap(QPixmap("images/box.png"));
        }
    }
    this->pushes++;
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

void MainWindow::updateHUD()
{
    ui->moves->setText(QString::number(this->moves));
    ui->pushes->setText(QString::number(this->pushes));
}

void MainWindow::drawMap()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(m->mapBuffer[j][i]->type == Block::brick)
            {
                m->mapBuffer[j][i]->_square = scene->addPixmap(QPixmap("images/brick.png"));
            }

            else if(m->mapBuffer[j][i]->type == Block::floor)
            {
                m->mapBuffer[j][i]->_square = scene->addPixmap(QPixmap("images/floor.png"));
            }

            m->mapBuffer[j][i]->_square->setPos(j*50,i*50);
        }
    }
}

void MainWindow::drawSpots()
{
    for (int i=0; i < (int)m->spotBuffer.size(); i++)
    {
        m->spotBuffer.at(i)->_square = scene->addPixmap(QPixmap("images/spot.png"));
        m->spotBuffer.at(i)->_square->setPos( m->spotBuffer.at(i)->coord.x()*50, m->spotBuffer.at(i)->coord.y()*50 );
    }
}

void MainWindow::drawBoxes()
{
    for (int i=0; i < (int)m->boxBuffer.size(); i++)
    {
        m->boxBuffer.at(i)->_square = scene->addPixmap(QPixmap("images/box.png"));
        m->boxBuffer.at(i)->_square->setPos( m->boxBuffer.at(i)->coord.x()*50, m->boxBuffer.at(i)->coord.y()*50 );
    }
}

void MainWindow::drawGamer()
{
    if ( m->gamer != NULL )
    {
        m->gamer->_square = scene->addPixmap(QPixmap("images/gamerDOWN.png"));
        m->gamer->_square->setPos(m->gamer->coord.x()*50, m->gamer->coord.y()*50);
    }
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

bool MainWindow::isGamer(QPoint point)
{
    if(m->gamer->coord == point)
    {
        return true;
    }
    return false;
}

bool MainWindow::isBox(QPoint point)
{
    Box * box;
    foreach(box, m->boxBuffer)
    {
        if ( box->coord == point )
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::isSpot(QPoint point)
{
    Block * bl;
    foreach(bl, m->spotBuffer)
    {
        if ( bl->coord == point )
        {
            return true;
        }
    }
    return false;
}

void MainWindow::on_actionMap_Editor_triggered()
{
    ui->gameName->hide();
    ui->scenario->hide();
    ui->gameHUD->hide();

    ui->scenarioEditor->show();
    ui->QtSoko->show();
    ui->editorPanel->show();
    ui->loadSavePanel->show();
    ui->loadSavePanel->move(ui->editorPanel->x(), ui->editorPanel->y()+110);
    ui->editorPanel->move(ui->gameHUD->x(), ui->gameHUD->y());

    ui->actionNew_Game->setDisabled(true);

    ui->scenarioEditor->setScene(scene);

    m =new Map();
    m->openMap("templates/square.map");

    bs.isSet = false;

    m->scanMap();
    this->drawMap();
    this->drawSpots();
    this->drawBoxes();
    this->drawGamer();
}


void MainWindow::on_loadButton_clicked()
{
    QString path;
    path = QFileDialog::getOpenFileName(this,"Load Map","maps", tr("Map files (*.map);;All files (*.*)"));

    m = new Map();
    m->openMap(path);

    m->scanMap();
    this->drawMap();
    this->drawSpots();
    this->drawBoxes();
    this->drawGamer();
}

void MainWindow::on_saveButton_clicked()
{
    QString path;
    QString mapName;
    path = QFileDialog::getSaveFileName(this,"Save Map","maps", tr("Map files (*.map);;All files (*.*)"));

    mapName = path.split("/").last();

    m->createMap(path);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QPoint point;

    if ( bs.isSet )
    {
        if ( (e->pos().x() > 60 && e->pos().x() < 560) && (e->pos().y() > 92 && e->pos().y() < 592) )
        {
            point = QPoint( (e->pos().x()-60)/50, (e->pos().y()-92)/50 ); //coordinates of the block
        }

        if ( isGamer(point) )
        {
            //delete m->gamer;
            qDebug() << "Is gamer.";

        }
        else if ( isBox(point) )
        {
            Box *b;
            std::vector<Box*>::iterator it = m->boxBuffer.begin();
            for (; it != m->boxBuffer.end(); it++)
            {
                b = *it;
                if ( b->coord == point )
                {
                    m->boxBuffer.erase(it);
                    break;
                }
            }

            qDebug() << "is box.";
        }
        else if ( isSpot(point) )
        {
            Block *b;
            std::vector<Block*>::iterator it = m->spotBuffer.begin();
            for (; it != m->spotBuffer.end(); it++)
            {
                b = *it;
                if ( b->coord == point )
                {
                    m->spotBuffer.erase(it);
                    break;
                }
            }

            qDebug() << "is spot.";
        }
        else
        {
            qDebug() << "is brick or floor.";
        }

        Box *box;
        Block *block;

        switch(bs.button)
        {
        case setFloor:
            m->mapBuffer[point.x()][point.y()]->type = Block::floor;
            m->mapBuffer[point.x()][point.y()]->_square->setPixmap(QPixmap("images/floor.png"));
            break;

        case setBrick:
            m->mapBuffer[point.x()][point.y()]->type = Block::brick;
            m->mapBuffer[point.x()][point.y()]->_square->setPixmap(QPixmap("images/brick.png"));
            break;

        case setBox:
            m->mapBuffer[point.x()][point.y()]->type = Block::floor;
            m->mapBuffer[point.x()][point.y()]->_square->setPixmap(QPixmap("images/floor.png"));

            box = new Box('w','w','w','w');
            box->setCoord(point);
            m->boxBuffer.push_back(box);
            this->drawBoxes();
            break;

        case setSpot:
            m->mapBuffer[point.x()][point.y()]->type = Block::floor;
            m->mapBuffer[point.x()][point.y()]->_square->setPixmap(QPixmap("images/floor.png"));

            block = new Block(Block::spot);
            block->setCoord(point);
            m->spotBuffer.push_back(block);
            this->drawSpots();
            break;

        case setGamer:
            m->mapBuffer[point.x()][point.y()]->type = Block::floor;
            m->mapBuffer[point.x()][point.y()]->_square->setPixmap(QPixmap("images/floor.png"));

            block = new Block(Block::player);
            block->setCoord(point);
            m->gamer = block;
            break;
        }
        this->drawMap();
        this->drawSpots();
        this->drawBoxes();
        this->drawGamer();
    }
    else
    {
        qDebug() << "bs.isSet is false.";
    }

}

void MainWindow::on_floorButton_clicked()
{
    if(bs.button != setFloor)
    {
        bs.button = setFloor;
        bs.isSet = true;
    }
    else
    {
        bs.isSet = !bs.isSet;
    }

}

void MainWindow::on_brickButton_clicked()
{
    if(bs.button != setBrick)
    {
        bs.button = setBrick;
        bs.isSet = true;
    }
    else
    {
        bs.isSet = !bs.isSet;
    }
}

void MainWindow::on_boxButton_clicked()
{
    if(bs.button != setBox)
    {
        bs.button = setBox;
        bs.isSet = true;
    }
    else
    {
        bs.isSet = !bs.isSet;
    }
}

void MainWindow::on_spotButton_clicked()
{
    if(bs.button != setSpot)
    {
        bs.button = setSpot;
        bs.isSet = true;
    }
    else
    {
        bs.isSet = !bs.isSet;
    }
}

void MainWindow::on_gamerButton_clicked()
{
    if(bs.button != setGamer)
    {
        bs.button = setGamer;
        bs.isSet = true;
    }
    else
    {
        bs.isSet = !bs.isSet;
    }
}
