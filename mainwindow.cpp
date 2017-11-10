#include "mainwindow.h"
#include "zorkgame.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->append(zorkgame.getWelcomeText());
    //setUpFunctions
    for (int i = 0; i < 5;i++)
    {
        item[i] = nullptr;
    }
    gameOverScreen.load("../MoreTestingAgain/Images/GAMEOVER.png");
    setUpGUI();
    connectSignalsToSlots();
    printRoomInfo();
    printRoomImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpGUI()
{
    QImage image("../MoreTestingAgain/Images/arrow.png");
    QPoint center = image.rect().center();

    QPixmap pixmap = QPixmap::fromImage(image);

    int height = pixmap.height();
    int width = pixmap.width();
    ui->labelRight->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));

    ui->labelRight->setScaledContents( true );

    ui->labelRight->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    QMatrix matrix;
    matrix.translate(center.x(), center.y());
    matrix.rotate(270);
    QImage newImage = image.transformed(matrix);
    pixmap = QPixmap::fromImage(newImage);
    ui->labelUp->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));

    ui->labelUp->setScaledContents( true );

    ui->labelUp->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    matrix.rotate(-90);
    newImage = image.transformed(matrix);
    pixmap = QPixmap::fromImage(newImage);
    ui->labelLeft->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));

    ui->labelLeft->setScaledContents( true );

    ui->labelLeft->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    matrix.rotate(-90);
    newImage = image.transformed(matrix);
    pixmap = QPixmap::fromImage(newImage);
    ui->labelDown->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));

    ui->labelDown->setScaledContents( true );

    ui->labelDown->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    view = ui->graphicsView;
    scene = new QGraphicsScene();
    view->setScene(scene);

    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    this->listViewItems = ui->listWidgetItems;
}

void MainWindow::connectSignalsToSlots()
{
    connect(ui->labelRight, SIGNAL(clicked()), this, SLOT(clickedRight()));
    connect(ui->labelUp, SIGNAL(clicked()), this, SLOT(clickedUp()));
    connect(ui->labelLeft, SIGNAL(clicked()), this, SLOT(clickedLeft()));
    connect(ui->labelDown, SIGNAL(clicked()), this, SLOT(clickedDown()));
}

void MainWindow::clickedRight()
{
    QString newString = QString::fromStdString(zorkgame.go("east"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::clickedUp()
{
    QString newString = QString::fromStdString(zorkgame.go("north"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::clickedLeft()
{
    QString newString = QString::fromStdString(zorkgame.go("west"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::clickedDown()
{
    QString newString = QString::fromStdString(zorkgame.go("south"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::printRoomInfo()
{
    ui->textBrowser->append(zorkgame.getCurrentRoomDescription());
}

void MainWindow::printRoomImage()
{
    if (!(zorkgame.getCurrentRoom()->getRoomImage().isNull()))
    {
        if (firstRoomEntered)
            removeItemsFromScene();

        int width = ui->graphicsView->width();
        int height = ui->graphicsView->height();

        QPixmap pixmap = zorkgame.getCurrentRoom()->getRoomImage();
        background = new QGraphicsPixmapItem(pixmap.scaled(width, height, Qt::KeepAspectRatio));
        scene->addItem(background);
        firstRoomEntered = true;
        std::vector<GameObject*> itemsToDisplay = zorkgame.getCurrentRoom()->getGameObjects();
        for (int i = 0; i < itemsToDisplay.size(); i++)
        {

            this->item[i] = new QGraphicsObjectGameItem(itemsToDisplay[i]);
            scene->addItem(item[i]);
            connect(item[i], SIGNAL(clicked()), this, SLOT(itemClicked()));
        }

        questionMark = new ObjectQuestionMark();
        questionMark->setX(0);
        questionMark->setY(0);
        questionMark->setSizeY(50);
        questionMark->setSizeX(50);
        pixmap.load("../MoreTestingAgain/Images/Question_Mark.png");
        questionMark->setItemImage(pixmap);
        questionMarkSymbol = new QGraphicsObjectGameItem(questionMark);
        scene->addItem(questionMarkSymbol);
        connect(questionMarkSymbol, SIGNAL(clicked()), this, SLOT(onQuestionMarkClicked()));
    }
    else
        ui->textBrowser->append("You can't see anything in here!");
}

void MainWindow::removeItemsFromScene()
{
    if (scene != NULL)
    {
        if (background != nullptr)
            scene->removeItem(background);
        background = nullptr;
        for (int i = 0; i < 5; i++)
        {
            if (item[i] != nullptr)
                scene->removeItem(item[i]);
            item[i] = nullptr;
        }
        if (questionMarkSymbol != nullptr)
            scene->removeItem(questionMarkSymbol);
    }
}

void MainWindow::showPlayerInventory()
{
    Player *player = zorkgame.getPlayer();
    std::vector<Item*> itemsFromPlayer = player->getItems();
    std::vector<std::string> itemsForDisplay;
    std::vector<QString> qStringArrayItems;
    this->listViewItems->clear();
    for (int i = 0; i < itemsFromPlayer.size(); i++)
    {
        itemsForDisplay.push_back(itemsFromPlayer[i]->getDescription());
        qStringArrayItems.push_back(QString::fromStdString(itemsForDisplay[i]));
        this->listViewItems->addItem(qStringArrayItems[i]);
    }
    connect(this->listViewItems, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onInventoryItemClicked(QListWidgetItem*)));
}

void MainWindow::itemClicked()
{
    for (int i = 0; i < 5; i++)
    {
        if (item[i] != nullptr)
        {
            if (item[i]->getGameObject() != NULL)
            {
                if (item[i]->getClickedCheck())
                {
                    if (Item *clickedItem = dynamic_cast<Item*> (item[i]->getGameObject()))
                    {
                        zorkgame.addPlayerItem(clickedItem);
                        item[i]->setClickedCheck(false);
                        scene->removeItem(item[i]);
                        zorkgame.getCurrentRoom()->deleteGameObject(clickedItem);
                        item[i] = nullptr;
                        showPlayerInventory();
                    }
                    else if (zorkgame.getPlayer()->getCurrentItem()->checkInteraction(item[i]->getGameObject()))
                    {
                        if (ObjectDoor* door = dynamic_cast<ObjectDoor*>(item[i]->getGameObject()))
                        {
                            Room *newRoom = door->getRoom();
                            std::string newDirection = door->getDirection();
                            zorkgame.addNewRoom(newRoom, door->getAdjacentRoom() ,newDirection);
                            ui->textBrowser->append(QString::fromStdString("New room unlocked: " + newRoom->getDescription() + " to the " + newDirection + " of " + door->getAdjacentRoom()->getDescription()));
                            zorkgame.getPlayer()->removeItem(zorkgame.getPlayer()->getCurrentItem());
                            showPlayerInventory();
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::onInventoryItemClicked(QListWidgetItem *item)
{
    zorkgame.getPlayer()->currentItem(item->text().toLocal8Bit().constData());
}

void MainWindow::onQuestionMarkClicked()
{
    if (zorkgame.getPlayer()->getCurrentItem() != NULL) {
        ui->textBrowser->append(QString::fromStdString(zorkgame.getPlayer()->getCurrentItem()->getLongDescription()));
        if(zorkgame.getPlayer()->getCurrentItem()->getIsGameOverItem() == true)
            gameOver();
    }
    else
        ui->textBrowser->append("You have no current item selected!");

}


void MainWindow::gameOver()
{
    removeItemsFromScene();
    int width = ui->graphicsView->width();
    int height = ui->graphicsView->height();
    background = new QGraphicsPixmapItem(gameOverScreen.scaled(width, height, Qt::KeepAspectRatio));
    scene->addItem(background);
}
