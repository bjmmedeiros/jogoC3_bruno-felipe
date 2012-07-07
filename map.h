#ifndef MAP_H
#define MAP_H

#include <QFile>
#include <vector>

#include "block.h"

class Map
{
public:
    Map();
    Map(QString path);
    ~Map();

private:


public:
    QFile *file;
    std::vector< std::vector<Block*> > mapBuffer;

public:
    void scanMap();
    void testScan();

};

#endif // MAP_H
