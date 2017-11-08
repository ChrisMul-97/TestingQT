#include "gameobject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

int GameObject::getX() const
{
    return x;
}

void GameObject::setX(int value)
{
    x = value;
}

int GameObject::getY() const
{
    return y;
}

void GameObject::setY(int value)
{
    y = value;
}

int GameObject::getSizeX() const
{
    return sizeX;
}

void GameObject::setSizeX(int value)
{
    sizeX = value;
}

int GameObject::getSizeY() const
{
    return sizeY;
}

void GameObject::setSizeY(int value)
{
    sizeY = value;
}

QPixmap GameObject::getItemImage() const
{
    return pixmap;
}
