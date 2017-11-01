#include "itemdoor.h"

ItemDoor::ItemDoor(std::string description, Room *newRoom)
 : Item(description)
{
    this->room = newRoom;
}


void ItemDoor::checkInteraction(Item *item)
{

}
