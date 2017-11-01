#include "room.h"

Room::Room(std::string description)
{
    p_description = description;
}

void Room::setDescription(std::string description)
{
    p_description = description;
}

std::string Room::getDescription()
{
    return p_description;
}


void Room::setExits(Room *west, Room *north, Room *east, Room *south)
{
    if (west != NULL)
    {
        p_exits["west"] = west;
    }
    if (north != NULL)
    {
        p_exits["north"] = north;
    }
    if (east != NULL)
    {
        p_exits["east"] = east;
    }
    if (south != NULL)
    {
        p_exits["south"] = south;
    }
}

void Room::addItem(Item *item)
{
    p_items.push_back(item);
}

void Room::deleteItem(Item *item)
{
    for (int i = 0; i < p_items.size(); i++)
    {
        if (p_items[i] == item)
        {
            p_items.erase(p_items.begin() + i);
        }
    }
}

Room* Room::nextRoom(std::string direction) {
    std::map<std::string, Room*>::iterator next = p_exits.find(direction); //returns an iterator for the "pair"
    if (next == p_exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::setRoomImage(QPixmap image)
{
    roomImage = image;
}

QPixmap Room::getRoomImage()
{
    return roomImage;
}

std::vector<Item*> Room::getItems()
{
    return p_items;
}
