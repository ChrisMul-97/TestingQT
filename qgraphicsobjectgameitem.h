#ifndef QGRAPHICSOBJECTGAMEITEM_H
#define QGRAPHICSOBJECTGAMEITEM_H

#include <QGraphicsObject>
#include <QPainter>
#include "item.h"

class QGraphicsObjectGameItem : public QGraphicsObject
{
    Q_OBJECT
public:
    QGraphicsObjectGameItem(Item *item);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool getClickedCheck();
    void setClickedCheck(bool check);
    Item *getP_item();
    void setP_item(Item *item);

private:
    Item *p_item = NULL;
    bool clickedCheck = false;
    int x, y;
signals:
    void clicked();
};

#endif // QGRAPHICSOBJECTGAMEITEM_H
