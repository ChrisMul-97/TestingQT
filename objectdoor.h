#ifndef OBJECTDOOR_H
#define OBJECTDOOR_H

#include "gameobject.h"
#include "room.h"

class ObjectDoor : public GameObject
{
public:
    ObjectDoor(Room *newRoom);
    void roomDetails(Room *room, std::string direction);
    Room *getAdjacentRoom() const;
    void setAdjacentRoom(Room *value);
    std::string getDirection() const;
    void setDirection(const std::string &value);
    Room *getRoom() const;
    void setRoom(Room *value);

private:
    Room *room;
    Room *adjacentRoom;
    std::string direction;

protected:
    bool checkInherited() override;
};

#endif // OBJECTDOOR_H
