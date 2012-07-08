#ifndef BOX_H
#define BOX_H

#include "block.h"

class Box: public Block
{
public:
    Box(QString material);
public:
    QString material;
    bool onSpot;
private:
};

#endif // BOX_H
