#ifndef BOX_H
#define BOX_H

#include "block.h"

class Box: public Block
{
public:
    Box(QChar nFace, QChar sFace, QChar eFace, QChar wFace);
public:
    bool onSpot;
private:

    QChar _nFace,_sFace,_eFace,_wFace;

public:
    QChar nFace();
    QChar sFace();
    QChar eFace();
    QChar wFace();
};

#endif // BOX_H
