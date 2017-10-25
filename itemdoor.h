#ifndef ITEMDOOR_H
#define ITEMDOOR_H

#include <iostream>
#include "keyitem.h"

class ItemDoor : public Item
{
public:
    ItemDoor(std::string description, ItemKey key);
private:
    ItemKey key;
};

#endif // ITEMDOOR_H
