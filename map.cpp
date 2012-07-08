#include "map.h"
#include "block.h"
#include "box.h"

#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <ostream>

Map::Map(){

}

Map::Map(QString path)
{
    file = new QFile(path);
    if ( !file->open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Error opening map for reading.";
        return;
    }
}


Map::~Map()
{

}


void Map::scanMap()
{
    std::vector<Block*> row;
    QTextStream stream(file);
    stream.seek(0);
    QString data, mat;
    QPoint p;
    Box * b;
    Block * bl;
    int number;

    for(int j=0; j<10; j++)
    {
        mapBuffer.push_back(row);
    }
    //READING MAP
    for (int i=0; i<10; i++)
    {
        data = stream.readLine();
        for(int j=0; j<10; j++)
        {
            if ( data.at(j) == QChar('0') ) //FLOOR
            {
                mapBuffer[j].push_back(new Block(Block::floor));
            }
            else if ( data.at(j) == QChar('1') ) //BRICK
            {
                mapBuffer[j].push_back(new Block(Block::brick));
            }
            mapBuffer[j][i]->setCoord(j, i);
        }
    }
    data = stream.readLine();
    if ( QString::compare(data, QString("")) != 0 )
    {
        qDebug() << "Error reading map boxes.";
        exit(EXIT_FAILURE);
    }

    //READING BOXES
    data = stream.readLine(); //NUMBER OF BOXES
    number = data.toInt();
    for (int i=0; i<number; i++)
    {
        data = stream.readLine(); //BOX MATERIAL
        mat = data;
        data = stream.readLine(); //BOX COORDINATES
        p = QPoint( data.at(0).digitValue(), data.at(1).digitValue() );
        b = new Box(mat);
        b->setCoord(p);
        boxBuffer.push_back(b);
    }

    data = stream.readLine();
    if ( QString::compare(data, QString("")) != 0 )
    {
        qDebug() << "Error reading map spots.";
        exit(EXIT_FAILURE);
    }
    //READING SPOTS
    data = stream.readLine(); //NUMBER OF SPOTS
    number = data.toInt();
    for (int i=0; i<number; i++)
    {
        data = stream.readLine(); //SPOTS COORDINATES
        p = QPoint( data.at(0).digitValue(), data.at(1).digitValue() );
        bl = new Block(Block::spot);
        bl->setCoord(p);
        spotBuffer.push_back(bl);
    }

    data = stream.readLine();
    if ( QString::compare(data, QString("")) != 0 )
    {
        qDebug() << "Error reading map player.";
        exit(EXIT_FAILURE);
    }

    //READING PLAYER
    data = stream.readLine(); //PLAYER COORDINATES
    p = QPoint( data.at(0).digitValue(), data.at(1).digitValue() );
    bl = new Block(Block::player);
    bl->setCoord(p);
    gamer = bl;
}

void Map::testScan()
{
    QTextStream stream(file);
    stream.seek(0);
    QString data;
    std::vector<Block*> row;

    for(int j=0; j<10; j++)
    {
        mapBuffer.push_back(row);
    }
    for (int i=0; i<10; i++)
    {
        data = stream.readLine();
        for(int j=0; j<10; j++)
        {
            if ( data.at(j) == QChar('0') ) //FLOOR
            {
                mapBuffer[j].push_back(new Block(Block::floor));
            }
            else if ( data.at(j) == QChar('1') ) //BRICK
            {
                mapBuffer[j].push_back(new Block(Block::brick));
            }
            else if ( data.at(j) == QChar('2') ) //BOX
            {
                mapBuffer[j].push_back(new Block(Block::box));
            }
            else if ( data.at(j) == QChar('3') ) //SPOT
            {
                mapBuffer[j].push_back(new Block(Block::spot));
            }
            else if ( data.at(j) == QChar('4') ) //PLAYER
            {
                mapBuffer[j].push_back(new Block(Block::player));
            }
            else
            {
                qDebug() << "Error reading map.";
                exit(EXIT_FAILURE);
            }
            mapBuffer[j][i]->coord = QPoint(j,i);
        }
    }

    /*
    std::vector<Block*> row;
    QTextStream stream(file);
    stream.seek(0);
    QString data, mat;
    QPoint p;
    Box * b;
    Block * bl;
    int number;

    for(int j=0; j<10; j++)
    {
        mapBuffer.push_back(row);
    }
    //READING MAP
    for (int i=0; i<10; i++)
    {
        data = stream.readLine();
        for(int j=0; j<10; j++)
        {
            if ( data.at(j) == QChar('0') ) //FLOOR
            {
                mapBuffer[j].push_back(new Block(Block::floor));
            }
            else if ( data.at(j) == QChar('1') ) //BRICK
            {
                mapBuffer[j].push_back(new Block(Block::brick));
            }
        }
    }
    data = stream.readLine();
    if ( QString::compare(data, QString("")) != 0 )
    {
        qDebug() << "Error reading map boxes.";
        exit(EXIT_FAILURE);
    }

    //READING BOXES
    data = stream.readLine(); //NUMBER OF BOXES
    number = data.toInt();
    for (int i=0; i<number; i++)
    {
        data = stream.readLine(); //BOX MATERIAL
        mat = data;
        data = stream.readLine(); //BOX COORDINATES
        p = QPoint( data.at(0).digitValue(), data.at(1).digitValue() );
        b = new Box(mat);
        b->setCoord(p);
        boxBuffer.push_back(b);
    }

    data = stream.readLine();
    if ( QString::compare(data, QString("")) != 0 )
    {
        qDebug() << "Error reading map spots.";
        exit(EXIT_FAILURE);
    }
    //READING SPOTS
    data = stream.readLine(); //NUMBER OF SPOTS
    number = data.toInt();
    for (int i=0; i<number; i++)
    {
        data = stream.readLine(); //SPOTS COORDINATES
        p = QPoint( data.at(0).digitValue(), data.at(1).digitValue() );
        bl = new Block(Block::spot);
        bl->setCoord(p);
        spotBuffer.push_back(bl);
    }

    data = stream.readLine();
    if ( QString::compare(data, QString("")) != 0 )
    {
        qDebug() << "Error reading map player.";
        exit(EXIT_FAILURE);
    }

    //READING PLAYER
    data = stream.readLine(); //PLAYER COORDINATES
    p = QPoint( data.at(0).digitValue(), data.at(1).digitValue() );
    bl = new Block(Block::player);
    bl->setCoord(p);
    gamer = bl;

    for (int i=0; i<10; i++)
    {
        qDebug() << mapBuffer[i][0]->type << mapBuffer[i][1]->type << mapBuffer[i][2]->type << mapBuffer[i][3]->type << mapBuffer[i][4]->type << mapBuffer[i][5]->type << mapBuffer[i][6]->type << mapBuffer[i][7]->type << mapBuffer[i][8]->type << mapBuffer[i][9]->type;
    }

    for (int i=0; i<2; i++)
    {
        qDebug() << boxBuffer[i]->coord.x() << boxBuffer[i]->coord.y();
    }
    qDebug() << spotBuffer[0]->coord.x() << spotBuffer[0]->coord.y();
    qDebug() << gamer->coord.x() << gamer->coord.y();
    */
}
