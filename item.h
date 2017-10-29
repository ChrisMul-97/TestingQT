#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <QPixmap>

class Item
{
private:
    std::string p_description;
    std::string p_longDescription;
    QPixmap p_itemImage;
public:
    Item();
    Item(std::string description);
    std::string getShortDescription();
    std::string getLongDescription();
    void setItemImage(QPixmap pixmap);
    QPixmap getItemImage();
    virtual void checkInteraction(Item *item);
};

#endif // ITEM_H
