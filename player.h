#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include <iostream>

class Player
{
public:
    Player();
    void selectedItem(Item *item);
    void addItem(Item *item);
    std::vector<Item *> getItems();
    std::string getItemNames();
private:
    std::vector<Item*> inventory;
    void currentItem(Item *currentItem);
    Item *item;
};

#endif // PLAYER_H
