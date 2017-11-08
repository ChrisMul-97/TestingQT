#ifndef ITEMKEY_H
#define ITEMKEY_H

#include <string>
#include "item.h"

class ItemKey : public Item
{
public:
    ItemKey(std::string description, GameObject *door);
private:
    GameObject *door;
protected:
    bool checkInteraction(const GameObject *item) override;

};

#endif // ITEMKEY_H
