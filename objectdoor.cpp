#include "objectdoor.h"

ObjectDoor::ObjectDoor(Room *newRoom)
    :GameObject()
{
    this->room = newRoom;
}

void ObjectDoor::roomDetails(Room *room, std::string exitDirection)
{
    this->adjacentRoom = room;
    this->direction = exitDirection;
}

Room *ObjectDoor::getAdjacentRoom() const
{
    return adjacentRoom;
}

void ObjectDoor::setAdjacentRoom(Room *value)
{
    adjacentRoom = value;
}

std::string ObjectDoor::getDirection() const
{
    return direction;
}

void ObjectDoor::setDirection(const std::string &value)
{
    direction = value;
}

Room *ObjectDoor::getRoom() const
{
    return room;
}

void ObjectDoor::setRoom(Room *value)
{
    room = value;
}

bool ObjectDoor::checkInherited()
{
    return true;
}

void GameObject::setItemImage(const QPixmap value)
{
    this->pixmap = value;
}


