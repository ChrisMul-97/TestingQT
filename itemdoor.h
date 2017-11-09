#ifndef ITEMDOOR_H
#define ITEMDOOR_H

#include <iostream>
#include "item.h"
#include "room.h"

class ItemDoor : public Item
{
public:
    ItemDoor(std::string description, Room *room);
    void roomDetails(Room *room, std::string direction);
    Room *getAdjacentRoom() const;
    void setAdjacentRoom(Room *value);
    std::string getDirection() const;
    void setDirection(const std::string &value);
    Room *getRoom() const;
    void setRoom(Room *value);

private:
    Room *room;
    Room *adjacentRoom;
    std::string direction;
protected:
    bool checkInteraction(Item *item);
};

#endif // ITEMDOOR_H
