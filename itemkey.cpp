#include "itemkey.h"

ItemKey::ItemKey(std::string description, Item *item)
    : Item(description)
{
    door = *item;
}

void ItemKey::checkInteraction(Item *item)
{

}
