#include "box.h"

Box::Box(QChar nFace, QChar sFace, QChar eFace, QChar wFace): Block(Block::box)
{
    this->_nFace = nFace;
    this->_sFace = sFace;
    this->_eFace = eFace;
    this->_wFace = wFace;

    this->onSpot = false;
}

QChar Box::nFace()
{
    return _nFace;
}

QChar Box::sFace()
{
    return _sFace;
}

QChar Box::eFace()
{
    return _eFace;
}

QChar Box::wFace()
{
    return _wFace;
}
