#ifndef ITEMDOOR_H
#define ITEMDOOR_H

#include <iostream>
#include "item.h"
#include "room.h"

class ItemDoor : public Item
{
public:
    ItemDoor(std::string description, Room *room);
private:
    Room *room;
protected:
    void checkInteraction(Item *item);
};

#endif // ITEMDOOR_H
