#include "player.h"

Player::Player()
{

}

Player::~Player()
{
    //delete this->item;
}

void Player::addItem(Item *item)
{
    inventory.push_back(item);
}

Item *Player::getCurrentItem()
{
    if (this->item != NULL)
        return this->item;
    else
        return NULL;
}

std::vector<Item*> Player::getItems()
{
    return inventory;
}

std::string Player::getItemNames()
{
    std::string itemNames;
    if (inventory.size() > 0)
        itemNames = inventory[0]->getDescription();
    for (int i = 1; i < inventory.size(); i++)
    {
        itemNames = " " + inventory[i]->getDescription();
    }
    return itemNames;
}

void Player::currentItem(std::string currentItem)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory.at(i)->getDescription() == currentItem)
        {
            this->item = inventory.at(i);
        }
    }
}


