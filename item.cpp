#include "item.h"

bool Item::getIsTakeable() const
{
    return isTakeable;
}

void Item::setIsTakeable(bool value)
{
    isTakeable = value;
}

std::string Item::getP_description() const
{
    return p_description;
}

void Item::setP_description(const std::string &value)
{
    p_description = value;
}

Item::Item()
{
    this->x = 0;
    this->y = 0;
    this->sizeX = 50;
    this->sizeY = 50;
}

Item::Item(std::string inDescription) {
    p_description = inDescription;
    this->x = 0;
    this->y = 0;
    this->sizeX = 50;
    this->sizeY = 50;
}

QPixmap Item::getItemImage()
{
    return this->p_itemImage;
}

bool Item::checkInteraction(Item *item)
{
    Q_UNUSED(item);
    //just virtual
    return false;
}

std::string Item::getShortDescription()
{
    return p_description;
}

std::string Item::getLongDescription()
{
    return p_longDescription;
}

void Item::setLongDescription(std::string longDesc)
{
    this->p_longDescription = longDesc;
}

void Item::setItemImage(QPixmap pixmap)
{
    this->p_itemImage = pixmap;
}

int Item::getX() const
{
    return x;
}

void Item::setX(int value)
{
    x = value;
}

int Item::getY() const
{
    return y;
}

void Item::setY(int value)
{
    y = value;
}

int Item::getSizeX() const
{
    return sizeX;
}

void Item::setSizeX(int value)
{
    sizeX = value;
}

int Item::getSizeY() const
{
    return sizeY;
}

void Item::setSizeY(int value)
{
    sizeY = value;
}

void Item::setIsGameOverItem(bool value)
{
    isGameOverItem = value;
}

bool Item::getIsGameOverItem() const
{
    return isGameOverItem;
}
