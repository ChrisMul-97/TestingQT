#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include <iostream>

class Player
{
public:
    Player();
    void currentItem(std::string currentItem);
    void selectedItem(Item *item);
    void addItem(Item *item);
    Item *getCurrentItem();
    std::vector<Item*> getItems();
    std::string getItemNames();
private:
    std::vector<Item*> inventory;
    Item *item = NULL;
};

#endif // PLAYER_H
