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

void Player::currentItem(Item *currentItem)
{
    this->item = currentItem;
}


