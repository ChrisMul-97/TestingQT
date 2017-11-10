#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include <iostream>

class Player
{
public:
    Player();
    ~Player();
    void currentItem(std::string currentItem);
    void addItem(Item *item);
    Item *getCurrentItem();
    std::vector<Item*> getItems();
    std::string getItemNames();
    void removeItem(Item *item);
private:
    std::vector<Item*> inventory;
    Item *item = NULL;
};

#endif // PLAYER_H
