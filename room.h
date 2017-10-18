#ifndef ROOM_H
#define ROOM_H

#include "room.h"
#include "item.h"
#include <string>
#include <map>
#include <vector>
#include <QPixmap>


class Room
{

private:
    std::string p_description;
    std::map<std::string, Room*> p_exits;
    std::vector<Item*> p_items;
    QPixmap roomImage;
public:
    Room(std::string description);
    ~Room();
    void setDescription(std::string description);
    std::string getDescription();
    void setExits(Room *west, Room *north, Room *east, Room *south);
    void addItem(Item *item);
    Room* nextRoom(std::string direction);
    void setRoomImage(QPixmap image);
    QPixmap getRoomImage();
    std::vector<Item*> getItems();
};

#endif // ROOM_H
