#include "itemkey.h"

ItemKey::ItemKey(std::string description, GameObject *item)
    : Item(description)
{
    door = item;
}

bool ItemKey::checkInteraction(const GameObject *item)
{
    if (item == door)
        return true;
    return false;
}
