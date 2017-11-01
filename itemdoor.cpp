#include "itemdoor.h"

ItemDoor::ItemDoor(std::string description, Room *newRoom)
 : Item(description)
{
    this->room = newRoom;
    this->setIsClickable(false);
}


void ItemDoor::checkInteraction(Item *item)
{

}
