#include "room.h"

Room::Room(std::string description)
{
    description = description;
}

void Room::setDescription(std::string description)
{
    description = description;
}

std::string Room::getDescription()
{
    return description;
}


void Room::setExits(Room *west, Room *north, Room *east, Room *south)
{
    if (west != NULL)
    {
        exits["west"] = west;
    }
    if (north != NULL)
    {
        exits["north"] = north;
    }
    if (east != NULL)
    {
        exits["east"] = east;
    }
    if (south != NULL)
    {
        exits["south"] = south;
    }
}

void Room::setExit(Room *room, std::string direction)
{
    exits[direction] = room;
}

void Room::addGameObjct(GameObject *gameObject)
{
    gameObjects.push_back(gameObject);
}

void Room::deleteGameObject(GameObject *gameObject)
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (gameObjects[i] == gameObject)
        {
            gameObjects.erase(gameObjects.begin() + i);
        }
    }
}



Room *Room::nextRoom(std::string direction) {
    std::map<std::string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
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

std::vector<GameObject *> Room::getGameObjects()
{
    return gameObjects;
}


