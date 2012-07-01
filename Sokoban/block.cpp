#include "block.h"

Block::Block(QObject *parent) :
    QObject(parent)
{
    QImage *image = new QImage();

    if (movable) {
        image->load("images/wall.png");
    } else {
        image->load("images/box.png");
    }
}
