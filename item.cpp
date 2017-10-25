#include "item.h"

Item::Item(std::string inDescription) {
    p_description = inDescription;
}

QPixmap Item::getItemImage()
{
    return this->p_itemImage;
}

std::string Item::getShortDescription()
{
    return p_description;
}

std::string Item::getLongDescription()
{
    return " item(s), " + p_description + ".\n";
}

void Item::setItemImage(QPixmap pixmap)
{
    this->p_itemImage = pixmap;
}

