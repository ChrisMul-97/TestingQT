#ifndef ZORKGAME_H
#define ZORKGAME_H

#include "room.h"
#include <QString>


class ZorkGame
{
public:
    ZorkGame();
    QString getHelpText();
    QString getWelcomeText();
    QString getCurrentRoomDescription();
    Room *getCurrentRoom();
    std::string go(std::string direction);
private:
    Room *currentRoom;
    void createRooms();
};

#endif // ZORKGAME_H
