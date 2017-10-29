#ifndef ITEMKEY_H
#define ITEMKEY_H

#include <string>
#include "item.h"

class ItemKey : public Item
{
public:
    ItemKey(std::string description, Item *door);
private:
    Item door;
protected:
    void checkInteraction(Item *item);

};

#endif // ITEMKEY_H
