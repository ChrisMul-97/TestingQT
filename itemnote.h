#ifndef ITEMNOTE_H
#define ITEMNOTE_H

#include<item.h>


class ItemNote : public Item
{
public:
    ItemNote(std::string description);
protected:
    bool checkInteraction(const GameObject *item) override;
};

#endif // ITEMNOTE_H
