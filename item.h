#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <QPixmap>
#include "gameobject.h"

class Item : public GameObject
{
private:
    std::string description, longDescription;
     bool isGameOverItem = false;
public:
    Item(std::string description);
    virtual bool checkInteraction(const GameObject *item) = 0;
    std::string getDescription() const;
    void setDescription(const std::string &value);
    std::string getLongDescription() const;
    void setLongDescription(const std::string &value);
    void setIsGameOverItem(bool value);
    bool getIsGameOverItem() const;
    bool operator==(Item &item);
protected:
    bool checkInherited() override;
};

#endif // ITEM_H
