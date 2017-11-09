#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
    Q_UNUSED(f);
    setMouseTracking(true);
}

ClickableLabel::~ClickableLabel() {}

double ClickableLabel::getX()
{
    return x;
}

double ClickableLabel::getY()
{
    return y;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    emit clicked();

}

/*
void ClickableLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->x = event->pos().x();
    this->y = event->pos().y();
    emit mousePos();
}
*/
