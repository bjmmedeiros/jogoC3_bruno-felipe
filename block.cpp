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
        movable = false;
        break;
    case brick:
        type = brick;
        movable = false;
        break;
    case box:
        type = box;
        movable =true;
        break;
    case spot:
        type = spot;
        movable =false;
        break;
    case player:
        type = player;
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
