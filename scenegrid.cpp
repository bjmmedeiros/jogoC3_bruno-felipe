#include "scenegrid.h"
#include <QDebug>

SceneGrid::SceneGrid(QObject *parent) :
    QGraphicsScene(parent)
{
}

void SceneGrid::mousePressEvent(QGraphicsSceneMouseEvent *event){

    QPointF posi =  event->scenePos();
    qDebug() << posi.x() << posi.y();
}
