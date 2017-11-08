#include "qgraphicsobjectgameitem.h"

QGraphicsObjectGameItem::QGraphicsObjectGameItem(GameObject *gameObject)
{
    this->object = gameObject;
}

QRectF QGraphicsObjectGameItem::boundingRect() const
{
    return QRectF(object->getX(), object->getY() , object->getSizeX(), object->getSizeY());
}

void QGraphicsObjectGameItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // draw the player
    painter->drawPixmap(object->getX(), object->getY(), object->getItemImage().scaled(object->getSizeX(), object->getSizeY()));

    // set the pen to draw debug rect
    //painter->setPen(QColor(255, 0, 0, 127));

    // for debug purposes, show the bounding rect (clickable area)
    //painter->drawRect(boundingRect());
}

void QGraphicsObjectGameItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    clickedCheck = true;
    emit clicked();
}

bool QGraphicsObjectGameItem::getClickedCheck()
{
    return clickedCheck;
}

void QGraphicsObjectGameItem::setClickedCheck(bool clickedCheck)
{
    this->clickedCheck = clickedCheck;
}

GameObject *QGraphicsObjectGameItem::getGameObject()
{
    return object;
}

void QGraphicsObjectGameItem::setGameObject(GameObject *gameObject)
{
    this->object = gameObject;
}


