#include "zorkgame.h"

ZorkGame::ZorkGame()
{
    createRooms();
    player;
}

void ZorkGame::createRooms()
{
    Room *testRoomA, *testRoomB, *testRoomC;
    testRoomA = new Room("testRoomA");
    testRoomB = new Room("testRoomB");
    testRoomC = new Room("testRoomC");
    testRoomA->setExits(testRoomB, NULL, testRoomC, NULL);
    testRoomB->setExits(NULL, NULL, testRoomA, NULL);
    testRoomC->setExits(testRoomA, NULL, NULL, NULL);
    rooms[0] = testRoomA;
    rooms[1] = testRoomB;
    rooms[2] = testRoomC;
    QPixmap pixmap;
    pixmap.load("C:/Users/Chris Mulcahy/Pictures/ProofOfConcept.png");
    testRoomA->setRoomImage(pixmap);
    pixmap.load("C:/Users/Chris Mulcahy/Pictures/number2.png");
    testRoomB->setRoomImage(pixmap);
    pixmap.load("C:/Users/Chris Mulcahy/Pictures/number3.png");
    testRoomC->setRoomImage(pixmap);
    Item *item = new Item("Note");
    item->setX(95);
    item->setY(95);
    pixmap.load("C:/Users/Chris Mulcahy/Pictures/paper.png");
    item->setItemImage(pixmap);
    testRoomA->addItem(item);

    currentRoom = testRoomA;
}

QString ZorkGame::getHelpText()
{
    QString helpText = "Help text to be filled in!";
    return helpText;
}

QString ZorkGame::getWelcomeText()
{
    QString welcomeText = "Welcome to my testing session";
    return welcomeText;
}

std::string ZorkGame::go(std::string direction)
{
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->getDescription();
    }
}

void ZorkGame::teleport()
{
    int random = std::rand() % 3;
    currentRoom = rooms[random];
}

QString ZorkGame::getCurrentRoomDescription()
{
    if (currentRoom == NULL)
    {
        return "You are nowhere. The vast emptiness mirrors your own. You sit on nothing and wait.";
    }
    else
    {
        QString returnString = QString::fromStdString(currentRoom->getDescription());
        return returnString;
    }
}

Room *ZorkGame::getCurrentRoom()
{
    return currentRoom;
}

Player ZorkGame::getPlayer()
{
    return player;
}

void ZorkGame::addPlayerItem(Item *item)
{
    player.addItem(item);
}




