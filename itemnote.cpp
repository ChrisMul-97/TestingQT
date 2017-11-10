#include "itemnote.h"

ItemNote::ItemNote(std::string description)
    :Item(description)
{
    this->setDescription(description);
}

bool ItemNote::checkInteraction(const GameObject *item)
{
    Q_UNUSED(item);
    return false;
}
