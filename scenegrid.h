#ifndef SCENEGRID_H
#define SCENEGRID_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class SceneGrid : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SceneGrid(QObject *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *);
    
signals:
    
public slots:
    
};

#endif // SCENEGRID_H
