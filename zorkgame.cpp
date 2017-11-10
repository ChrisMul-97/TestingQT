#include "zorkgame.h"

ZorkGame::ZorkGame()
{
    createRooms();
    player = new Player();
}

ZorkGame::~ZorkGame()
{
    delete player;
    delete currentRoom;
    for (int i = 0; i < rooms.size(); i++)
    {
        delete rooms.at(i);
    }
}

void ZorkGame::createRooms()
{
    Room *testRoomA = new Room("Where am I?"), *testRoomB = new Room("How do I get out of here?"), *testRoomC = new Room("Theory Room?");
    testRoomA->setExits(testRoomB, NULL, NULL, NULL);
    testRoomB->setExits(testRoomC, NULL, testRoomA, NULL);
    testRoomC->setExits(NULL, NULL, testRoomB, NULL);
    rooms.push_back(testRoomA);
    rooms.push_back(testRoomB);
    rooms.push_back(testRoomC);
    QPixmap pixmap;
    pixmap.load("../MoreTestingAgain/Images/ProofOfConcept.png");
    testRoomA->setRoomImage(pixmap);
    pixmap.load("../MoreTestingAgain/Images/room2.png");
    testRoomB->setRoomImage(pixmap);
    pixmap.load("../MoreTestingAgain/Images/room3.png");
    testRoomC->setRoomImage(pixmap);
    ItemNote *note = new ItemNote("Note");
    note->setX(150);
    note->setY(145);
    note->setSizeX(35);
    note->setSizeY(35);
    note->setLongDescription("It reads: 'Oh boy, it's the waking hours of the morning and I've yet to find a way out\nThis is what I've gathered from notes scattered around.\nMy name is Winston and I suffer from a chronic case of daily amensia.\nThis is most certainly not a good thing.\nI'm also locked in this house.\nAgain, not good. Not at all. When I fall asleep I'll surely not remember anything of this. Not good at all'");
    pixmap.load("../MoreTestingAgain/Images/paper.png");
    note->setItemImage(pixmap);

    //testing doors and keys
    Room *testRoomD = new Room("The Great Outdoors");
    pixmap.load("../MoreTestingAgain/Images/outside.png");
    testRoomD->setRoomImage(pixmap);
    ObjectDoor *door = new ObjectDoor(testRoomD);
    door->roomDetails(testRoomA, "north");
    pixmap.load("../MoreTestingAgain/Images/door.png");
    door->setItemImage(pixmap);
    door->setX(290);
    door->setY(35);
    door->setSizeX(90);
    door->setSizeY(160);

    Room *finalRoom = new Room("What was always yours");
    pixmap.load("../MoreTestingAgain/Images/space.jpeg");
    finalRoom->setRoomImage(pixmap);
    finalRoom->setExit(testRoomD, "south");
    testRoomD->setExit(finalRoom,"north");

    //room 2 items
    ItemNote *secondNote = new ItemNote("AnotherNote");
    secondNote->setX(150);
    secondNote->setY(200);
    secondNote->setSizeX(35);
    secondNote->setSizeY(35);
    secondNote->setLongDescription("It reads: 'I wouldn't believe a word out of any of these other notes. It's all lies.\nMy name is Larry and I have the world's best memory, I just haven't figured who stole it and why.'");
    pixmap.load("../MoreTestingAgain/Images/paper.png");
    secondNote->setItemImage(pixmap);

    //room 3 items
    ItemKey *key = new ItemKey("Key", door);
    pixmap.load("../MoreTestingAgain/Images/sprite_key.jpg");
    key->setLongDescription("A rusty old key");
    key->setItemImage(pixmap);
    key->setX(150);
    key->setY(230);
    key->setSizeX(25);
    key->setSizeY(25);

    ItemNote *moreNote = new ItemNote("Note #231");
    moreNote->setX(100);
    moreNote->setY(100);
    moreNote->setSizeX(35);
    moreNote->setSizeY(35);
    moreNote->setLongDescription("It reads: 'Okay, what if Big Foot is real, and I'm his brother???'");
    pixmap.load("../MoreTestingAgain/Images/note2.png");
    moreNote->setItemImage(pixmap);

    ItemNote *theoryNote = new ItemNote("Note #78");
    theoryNote->setX(200);
    theoryNote->setY(150);
    theoryNote->setSizeX(35);
    theoryNote->setSizeY(35);
    theoryNote->setLongDescription("It reads: 'Hi, it's me Socrates, the inventor of jokes.\nAnd I'm here to tell you losing your memory is no joke.'");
    theoryNote->setItemImage(pixmap);

    ItemNote *moreTheoryNote = new ItemNote("Note #HELP");
    moreTheoryNote->setX(75);
    moreTheoryNote->setY(112);
    moreTheoryNote->setSizeX(35);
    moreTheoryNote->setSizeY(35);
    moreTheoryNote->setLongDescription("It reads: 'Thinking about getting into humming... hmmm'");
    moreTheoryNote->setItemImage(pixmap);

    ItemNote *finalNote = new ItemNote("Note #32");
    finalNote->setX(180);
    finalNote->setY(140);
    finalNote->setSizeX(35);
    finalNote->setSizeY(35);
    finalNote->setLongDescription("It reads: 'I can see the ever spiralling sea of time and soon I will\nbe one with it and FREE'");
    finalNote->setItemImage(pixmap);

    //outside items
    ItemNote *earthsLastDemand = new ItemNote("Final Letter");
    earthsLastDemand->setX(180);
    earthsLastDemand->setY(220);
    earthsLastDemand->setSizeX(35);
    earthsLastDemand->setSizeY(35);
    earthsLastDemand->setLongDescription("It reads: 'If you're reading this then humanity has failed.\nGo on take your prize, we could never stop you from taking it. Pepsiman, truly you have bested us.\nNow, go to the stars as we weep in fear.\nIt always was yours to take, we were foolish to try and stop you.\nMay God have mercy on our souls.'");
    pixmap.load("../MoreTestingAgain/Images/paper.png");
    earthsLastDemand->setItemImage(pixmap);

    //Final Frontier items
    ItemNote *earthItself = new ItemNote("Earth; What was always yours.");
    earthItself->setX(-20);
    earthItself->setY(200);
    earthItself->setSizeX(200);
    earthItself->setSizeY(200);
    earthItself->setLongDescription("It screams hopelessly in your pocket; forever yours.");
    earthItself->setIsGameOverItem(true);
    pixmap.load("../MoreTestingAgain/Images/earth.png");
    earthItself->setItemImage(pixmap);




    //final setup
    testRoomA->addGameObjct(note);
    testRoomA->addGameObjct(door);
    testRoomB->addGameObjct(secondNote);
    testRoomC->addGameObjct(key);
    testRoomC->addGameObjct(moreNote);
    testRoomC->addGameObjct(theoryNote);
    testRoomC->addGameObjct(moreTheoryNote);
    testRoomC->addGameObjct(finalNote);
    testRoomD->addGameObjct(earthsLastDemand);
    finalRoom->addGameObjct(earthItself);
    gameOverItem = earthItself;
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
    Room *nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("You scratch your head and stroke your beard, yet you can't imagine any way to go in that direction!");
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

Player *ZorkGame::getPlayer()
{
    return player;
}

void ZorkGame::addPlayerItem(Item *item)
{
    player->addItem(item);
}

Item *ZorkGame::getGameOverItem()
{
    return gameOverItem;
}

void ZorkGame::addNewRoom(Room *newRoom, Room *room ,std::string direction)
{
    std::string oppositeDirection = "";
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms.at(i) == room)
        {
            rooms.at(i)->setExit(newRoom, direction);
            if (direction.compare("north") == 0)
                oppositeDirection = "south";
            else if (direction.compare("south") == 0)
                oppositeDirection = "north";
            else if (direction.compare("east") == 0)
                oppositeDirection = "west";
            else if (direction.compare("west") == 0)
                oppositeDirection = "east";
            newRoom->setExit(room, oppositeDirection);
            rooms.push_back(newRoom);
        }
    }
}




