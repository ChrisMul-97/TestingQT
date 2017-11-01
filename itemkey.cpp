#include "itemkey.h"


ItemKey::ItemKey(std::string description, Item *item)
    : Item(description)
{
    door = *item;
}

void ItemKey::checkInteraction(Item *item)
{
    QString newString = NULL;

    if(&door == item)
    {
        //call method in itemdoor
        //door.openDoor();

        newString = "The door opens";
    }
    else
    {
        newString = "This isn't the right key";
    }

    //print
}
