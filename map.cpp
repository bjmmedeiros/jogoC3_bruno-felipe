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
    QString data;
    std::vector<Block*> row;
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
}
