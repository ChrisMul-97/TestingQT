#include "player.h"

Player::Player()
{

}

void Player::selectedItem(Item item)
{

}

void Player::addItem(Item item)
{
    inventory.push_back(item);
}

Item Player::getCurrentItem()
{
    return item;
}

std::vector<Item> Player::getItems()
{
    return inventory;
}

std::string Player::getItemNames()
{
    std::string itemNames;
    if (inventory.size() > 0)
        itemNames = inventory[0].getShortDescription();
    for (int i = 1; i < inventory.size(); i++)
    {
        itemNames = " " + inventory[i].getShortDescription();
    }
    return itemNames;
}

void Player::currentItem(std::string currentItem)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory.at(i).getShortDescription() == currentItem)
        {
            this->item.setP_description(currentItem);
        }
    }
}


