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
    int x, y, sizeX, sizeY;
    bool isClickable = true;
public:
    Item();
    Item(std::string description);
    std::string getShortDescription();
    std::string getLongDescription();
    void setItemImage(QPixmap pixmap);
    QPixmap getItemImage();
    virtual void checkInteraction(Item *item);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getSizeX() const;
    void setSizeX(int value);
    int getSizeY() const;
    void setSizeY(int value);
    bool getIsClickable() const;
    void setIsClickable(bool value);
    std::string getP_description() const;
    void setP_description(const std::string &value);
};

#endif // ITEM_H
