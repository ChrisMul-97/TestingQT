#include "player.h"

Player::Player()
{

}

void Player::selectedItem(Item *item)
{

}

void Player::addItem(Item *item)
{
    inventory.push_back(item);
}

std::vector<Item *> Player::getItems()
{
    return inventory;
}

std::string Player::getItemNames()
{
    std::string itemNames;
    if (inventory.size() > 0)
        itemNames = inventory[0]->getShortDescription();
    for (int i = 1; i < inventory.size(); i++)
    {
        itemNames = " " + inventory[i]->getShortDescription();
    }
    return itemNames;
}

void Player::currentItem(Item *currentItem)
{
    this->item = currentItem;
}


