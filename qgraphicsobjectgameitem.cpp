#include "qgraphicsobjectgameitem.h"

QGraphicsObjectGameItem::QGraphicsObjectGameItem(Item *item)
{
    this->p_item = item;
}

QRectF QGraphicsObjectGameItem::boundingRect() const
{
    return QRectF(p_item->getX(), p_item->getY() , p_item->getSizeX(), p_item->getSizeY());
}

void QGraphicsObjectGameItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // draw the player
    painter->drawPixmap(p_item->getX(), p_item->getY(), p_item->getItemImage().scaled(p_item->getSizeX(), p_item->getSizeY()));

    // set the pen to draw debug rect
    painter->setPen(QColor(255, 0, 0, 127));

    // for debug purposes, show the bounding rect (clickable area)
    painter->drawRect(boundingRect());
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

Item *QGraphicsObjectGameItem::getP_item()
{
    return p_item;
}

void QGraphicsObjectGameItem::setP_item(Item *item)
{
    p_item = item;
}
