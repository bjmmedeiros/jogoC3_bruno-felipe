#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>

#define BLOCK_HEIGHT 50
#define BLOCK_WIDTH 50

class Block
{
public:
    Block();
    Block(int t);
    
    void setMovable(bool set);

signals:
    
public slots:

private:

public:
    bool movable;
    QGraphicsRectItem *square;
    int type;
    enum types
    {
        floor=0,
        brick=1,
        box=2,
        spot=3
    };
};

#endif // BLOCK_H
