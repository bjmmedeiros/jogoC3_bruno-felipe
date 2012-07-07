#include "map.h"
#include "block.h"

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
    for( int i=0; i<10; i++ )
    {
        while( QString::compare( (data = stream.read(1)), "\n" ) )
        {
            if( QString::compare(data, QString("")) == 0 )
            {
                qDebug() << "Reached EOF earlier. Map grid should be 10x10.";
                exit(EXIT_FAILURE);
            }
            if( QString::compare(data, QString("1")) == 0 )
            {
                row.push_back(new Block(Block::brick));
            }
            else if( QString::compare(data, QString("0")) == 0 )
            {
                row.push_back(new Block(Block::floor));
            }
        }
        mapBuffer.push_back(row);
        row.clear();
    }
    */
}

void Map::testScan()
{
    QVector< QVector<char> > vec;
    QVector<char> row;
    QTextStream stream(file);
    stream.seek(0);
    QString data;
    for(int j=0; j<10; j++)
    {
        vec.push_back(row);
    }
    for (int i=0; i<10; i++)
    {
        //stream.seek(i*11);
        data = stream.readLine();
        for(int j=0; j<10; j++)
        {
            vec[j].push_back(data.at(j).toAscii());
        }
    }

    for (int i=0; i<10; i++)
    {
        qDebug() << vec[i][0] << vec[i][1] << vec[i][2] << vec[i][3] << vec[i][4] << vec[i][5] << vec[i][6] << vec[i][7] << vec[i][8] << vec[i][9];
    }
}
