#include "qgraphicsobjectgameitem.h"

QGraphicsObjectGameItem::QGraphicsObjectGameItem(Item *item)
{
    this->p_item = item;
}

QRectF QGraphicsObjectGameItem::boundingRect() const
{
    return QRectF(0, 15, 50, 50);
}

void QGraphicsObjectGameItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // draw the player
    painter->drawPixmap(0, 0, p_item->getItemImage().scaled(50, 50));

    // set the pen to draw debug rect
    painter->setPen(QColor(255, 0, 0, 127));

    // for debug purposes, show the bounding rect (clickable area)
    painter->drawRect(boundingRect());
}

void QGraphicsObjectGameItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //hurah
    emit clicked();
}
