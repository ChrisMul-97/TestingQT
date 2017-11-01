#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include <iostream>

class Player
{
public:
    Player();
    void currentItem(Item *currentItem);
    void selectedItem(Item *item);
    void addItem(Item *item);
    std::vector<Item *> getItems();
    std::string getItemNames();
private:
    std::vector<Item*> inventory;
    Item *item;
};

#endif // PLAYER_H
