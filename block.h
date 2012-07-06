#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>

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
    enum dimension {
        BLOCK_HEIGHT=50,
        BLOCK_WIDTH=50
    };

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
