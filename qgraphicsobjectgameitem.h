#ifndef QGRAPHICSOBJECTGAMEITEM_H
#define QGRAPHICSOBJECTGAMEITEM_H

#include <QGraphicsObject>
#include <QPainter>
#include "gameobject.h"

class QGraphicsObjectGameItem : public QGraphicsObject
{
    Q_OBJECT
public:
    QGraphicsObjectGameItem(GameObject *gameObject);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool getClickedCheck();
    void setClickedCheck(bool check);
    GameObject *getGameObject();
    void setGameObject(GameObject *gameObject);

private:
    GameObject *object = NULL;
    bool clickedCheck = false;
    int x, y;
signals:
    void clicked();
};

#endif // QGRAPHICSOBJECTGAMEITEM_H
