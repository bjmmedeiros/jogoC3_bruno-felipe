#ifndef MAP_H
#define MAP_H

#include <QFile>
#include <vector>

#include "block.h"
#include "box.h"

class Map: public QObject
{
    Q_OBJECT
public:
    Map();
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
    void openMap(QString path);
    void createMap(QString path);

signals:
};

#endif // MAP_H
