#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Block : public QObject
{
    Q_OBJECT

public:
    Block();
    Block(int t);
    
    void setMovable(bool set);
    void setCoord(QPoint p);
    void setCoord(int x, int y);

signals:
    
public slots:

private:

public:
    QPoint coord;
    bool movable;
    QGraphicsRectItem *square;
    QGraphicsPixmapItem * _square;
    int type;

    enum dimension {
        BLOCK_HEIGHT=50,
        BLOCK_WIDTH=50
    };
    enum types
    {
        floor=0,
        brick=1,
        box=2,
        spot=3,
        player=4
    };
};

#endif // BLOCK_H
