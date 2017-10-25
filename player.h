#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player();
    void selectedItem(Item *item);
    void addItem(Item *item);
private:
    ArrayList<Item*> inventory;
    void currentItem(Item *currentItem);
    Item *currentItem;
};

#endif // PLAYER_H
