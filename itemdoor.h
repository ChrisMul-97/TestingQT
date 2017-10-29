#ifndef ITEMDOOR_H
#define ITEMDOOR_H

#include <iostream>
#include "item.h"

class ItemDoor : public Item
{
public:
    ItemDoor(std::string description, Item *key);
private:
    Item key;
protected:
    void checkInteraction(Item *item);
};

#endif // ITEMDOOR_H
