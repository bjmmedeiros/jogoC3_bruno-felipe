#include "box.h"

Box::Box(QString material): Block(Block::box)
{
    this->material = material;
    this->onSpot = false;
}
