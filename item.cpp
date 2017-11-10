#include "item.h"


Item::Item(std::string description)
    :GameObject()
{
    this->description = description;
}

std::string Item::getDescription() const
{
    return description;
}

void Item::setDescription(const std::string &value)
{
    description = value;
}

std::string Item::getLongDescription() const
{
    return longDescription;
}

void Item::setLongDescription(const std::string &value)
{
    longDescription = value;
}

void Item::setIsGameOverItem(bool value)
{
    this->isGameOverItem = value;
}

bool Item::getIsGameOverItem() const
{
    return isGameOverItem;
}

bool Item::operator==(Item &item)
{
    if (this->getDescription().compare(item.getDescription()) == 0)
        return true;
    return false;
}

bool Item::checkInherited()
{
    return true;
}



