#ifndef ZORKGAME_H
#define ZORKGAME_H

#include "room.h"
#include "player.h"
#include "itemkey.h"
#include "itemnote.h"
#include "objectdoor.h"
#include <list>
#include <QString>


class ZorkGame
{
public:
    ZorkGame();
    ~ZorkGame();
    QString getHelpText();
    QString getWelcomeText();
    QString getCurrentRoomDescription();
    Room *getCurrentRoom();
    std::string go(std::string direction);
    void teleport();
    Player *getPlayer();
    void addPlayerItem(Item *item);
    Item *getGameOverItem();
    void addNewRoom(Room *newRoom, Room *oldRoom, std::string direction);
private:
    Room *currentRoom;
    std::vector<Room*> rooms;
    Item *gameOverItem;
    Player *player;
    //ArrayList<Room> rooms = new ArrayList<Room>();
    void createRooms();
};

#endif // ZORKGAME_H
