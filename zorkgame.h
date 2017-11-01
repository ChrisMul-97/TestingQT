#ifndef ZORKGAME_H
#define ZORKGAME_H

#include "room.h"
#include "player.h"
#include <list>
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
    void teleport();
    Player getPlayer();
    void addPlayerItem(Item item);
private:
    Room *currentRoom;
    Room *rooms[3];
    Player player;
    //ArrayList<Room> rooms = new ArrayList<Room>();
    void createRooms();
};

#endif // ZORKGAME_H
