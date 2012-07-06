#include "block.h"

Block::Block()
{

}

Block::Block(int t)
{
    switch (t)
    {
    case floor:
        type = floor;
        square = NULL;
        movable = false;
        break;
    case brick:
        type = brick;
        square = new QGraphicsRectItem(0,0,BLOCK_WIDTH,BLOCK_HEIGHT);
        movable = false;
        break;
    case box:
        type = box;
        square = new QGraphicsRectItem(0,0,BLOCK_WIDTH,BLOCK_HEIGHT);
        movable =true;
        break;
    case spot:
        type = spot;
        square = new QGraphicsRectItem(0,0,BLOCK_WIDTH,BLOCK_HEIGHT);
        movable =false;
        break;
    default:
        break;
    }
}

void Block::setMovable(bool set)
{
    movable = set;
}
