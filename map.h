#ifndef MAP_H
#define MAP_H

#include <QFile>
#include <vector>

#include "block.h"
#include "box.h"

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
    std::vector< Box*> boxBuffer;
    std::vector< Block*> spotBuffer;
    Block* gamer;

public:
    void scanMap();
    void testScan();

};

#endif // MAP_H
