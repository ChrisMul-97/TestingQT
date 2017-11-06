#include "itemkey.h"

ItemKey::ItemKey(std::string description, Item *item)
    : Item(description)
{
    door = item;
}

bool ItemKey::checkInteraction(Item *item)
{
    if (item == door)
        return true;
    return false;
}
