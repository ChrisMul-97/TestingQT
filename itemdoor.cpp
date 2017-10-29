#include "itemdoor.h"

ItemDoor::ItemDoor(std::string description, Item *key)
 : Item(description)
{
    this->key = *key;
}


void ItemDoor::checkInteraction(Item *item)
{

}
