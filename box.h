#ifndef BOX_H
#define BOX_H

#include "block.h"

class Box: public Block
{
public:
    Box(QString material);
public:
    QString material;
private:
private:
};

#endif // BOX_H
