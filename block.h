#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>

#define BLOCK_HEIGHT 50
#define BLOCK_WIDTH 50

class Block : public QObject
{
    Q_OBJECT
public:
    explicit Block(QObject *parent = 0);
    Block()
    {
        box = new QGraphicsRectItem(0,0,BLOCK_WIDTH,BLOCK_HEIGHT);
    }
    
signals:
    
public slots:

private:
    bool movable;
    QGraphicsRectItem *box;
};

#endif // BLOCK_H
