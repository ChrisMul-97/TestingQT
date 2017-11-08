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

bool Item::checkInherited()
{
    return true;
}



