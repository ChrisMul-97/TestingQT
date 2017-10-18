#include "item.h"

Item::Item (std::string inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/) {
    p_description = inDescription;
    setWeight(inWeightGrams);
    p_value = inValue;
    /**weaponCheck(isWeapon);*/
}

Item::Item(std::string inDescription) {
    p_description = inDescription;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       std::cout << "weight invalid, must be 0<weight<9999" ;
    else
       p_weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       std::cout << "value invalid, must be 0<value<9999" ;
    else
        p_value = inValue;
}

void Item::setItemImage(QPixmap pixmap)
{
    this->p_itemImage = pixmap;
}

QPixmap Item::getItemImage()
{
    return this->p_itemImage;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

std::string Item::getShortDescription()
{
    return p_description;
}

std::string Item::getLongDescription()
{
    return " item(s), " + p_description + ".\n";
}

