#ifndef KEYITEM_H
#define KEYITEM_H

#include <string>
#include "itemdoor.h"

class KeyItem : public Item
{
public:
    KeyItem(std::string description, ItemDoor door);
    bool checkDoor(ItemDoor door);
private:
    ItemDoor door;

};

#endif // KEYITEM_H
