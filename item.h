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
    int p_weightGrams;
    float p_value;
    bool p_weaponCheck;
    QPixmap p_itemImage;
public:
    Item(std::string description);
    Item (std::string description, int inWeight, float inValue);
    std::string getShortDescription();
    std::string getLongDescription();
    int getWeight();
    void setWeight(int weightGrams);
    float getValue();
    void setValue(float value);
    int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
    void setItemImage(QPixmap pixmap);
    QPixmap getItemImage();

};

#endif // ITEM_H
