#include "itemdoor.h"

ItemDoor::ItemDoor(std::string description, Room *newRoom)
 : Item(description)
{
    this->room = newRoom;
    this->setIsTakeable(false);
}

void ItemDoor::roomDetails(Room *room, std::string exitDirection)
{
    this->adjacentRoom = room;
    this->direction = exitDirection;
}

Room *ItemDoor::getAdjacentRoom() const
{
    return adjacentRoom;
}

void ItemDoor::setAdjacentRoom(Room *value)
{
    adjacentRoom = value;
}

std::string ItemDoor::getDirection() const
{
    return direction;
}

void ItemDoor::setDirection(const std::string &value)
{
    direction = value;
}

Room *ItemDoor::getRoom() const
{
    return room;
}

void ItemDoor::setRoom(Room *value)
{
    room = value;
}


bool ItemDoor::checkInteraction(Item *item)
{
    return false;
}
