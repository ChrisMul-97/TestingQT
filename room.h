#ifndef ROOM_H
#define ROOM_H

#include "room.h"
#include "item.h"
#include "gameobject.h"
#include <string>
#include <map>
#include <vector>
#include <QPixmap>


class Room
{

private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<GameObject*> gameObjects;
    QPixmap roomImage;
public:
    Room(std::string description);
    ~Room();
    void setDescription(std::string description);
    std::string getDescription();
    void setExits(Room *west, Room *north, Room *east, Room *south);
    void setExit(Room *room, std::string direction);
    void addGameObjct(GameObject *gameObject);
    void deleteGameObject(GameObject *gameObject);
    Room *nextRoom(std::string direction);
    void setRoomImage(QPixmap image);
    QPixmap getRoomImage();
    std::vector<GameObject *> getGameObjects();
};

#endif // ROOM_H
