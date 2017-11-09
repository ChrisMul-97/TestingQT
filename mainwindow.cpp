#include "mainwindow.h"
#include "zorkgame.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->append(p_zorkgame.getWelcomeText());
    //setUpFunctions
    for (int i = 0; i < 5;i++)
    {
        item[i] = NULL;
    }
    gameOverScreen.load("C:/Users/Mark/Pictures/Saved Pictures/trailer_10516.jpg");
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
    QImage image("C:/Users/Mark/Pictures/Saved Pictures/16738_3d_space_scene_sunrise_in_space.jpg");
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
    QString newString = QString::fromStdString(p_zorkgame.go("east"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::clickedUp()
{
    QString newString = QString::fromStdString(p_zorkgame.go("north"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::clickedLeft()
{
    QString newString = QString::fromStdString(p_zorkgame.go("west"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::clickedDown()
{
    QString newString = QString::fromStdString(p_zorkgame.go("south"));
    ui->textBrowser->append(newString);
    printRoomImage();
}

void MainWindow::printRoomInfo()
{
    ui->textBrowser->append(p_zorkgame.getCurrentRoomDescription());
}

void MainWindow::printRoomImage()
{
    if (!(p_zorkgame.getCurrentRoom()->getRoomImage().isNull()))
    {
        if (firstRoomEntered)
            removeItemsFromScene();

         width = ui->graphicsView->width();
         height = ui->graphicsView->height();

        QPixmap pixmap = p_zorkgame.getCurrentRoom()->getRoomImage();
        background = new QGraphicsPixmapItem(pixmap.scaled(width, height, Qt::KeepAspectRatio));
        scene->addItem(background);
        firstRoomEntered = true;
        std::vector<Item*> itemsToDisplay = p_zorkgame.getCurrentRoom()->getItems();
        for (int i = 0; i < itemsToDisplay.size(); i++)
        {

            this->item[i] = new QGraphicsObjectGameItem(itemsToDisplay[i]);
            scene->addItem(item[i]);
            connect(item[i], SIGNAL(clicked()), this, SLOT(itemClicked()));
        }
        questionMark = new Item("Question Mark");
        pixmap.load("C:/Users/Mark/Pictures/Saved Pictures/questionmark.png");
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
        if (background != NULL)
            scene->removeItem(background);
        background = NULL;
        for (int i = 0; i < 5; i++)
        {
            if (item[i] != NULL)
                scene->removeItem(item[i]);
            item[i] = NULL;
        }
        if (questionMarkSymbol != NULL)
            scene->removeItem(questionMarkSymbol);
    }
}

void MainWindow::showPlayerInventory()
{
    Player *player = p_zorkgame.getPlayer();
    std::vector<Item*> itemsFromPlayer = player->getItems();
    std::vector<std::string> itemsForDisplay;
    std::vector<QString> qStringArrayItems;
    this->listViewItems->clear();
    for (int i = 0; i < itemsFromPlayer.size(); i++)
    {
        itemsForDisplay.push_back(itemsFromPlayer[i]->getP_description());
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
        if (item[i] != NULL)
        {
            //if(p_zorkgame.getPlayer()->getCurrentItem()->getIsGameOverItem() == true)


            if (item[i]->getClickedCheck() == true && item[i]->getP_item()->getIsTakeable())
            {
                p_zorkgame.addPlayerItem(item[i]->getP_item());
                item[i]->setClickedCheck(false);
                scene->removeItem(item[i]);
                p_zorkgame.getCurrentRoom()->deleteItem(item[i]->getP_item());
                item[i] = NULL;
                showPlayerInventory();



               // if(item[i]->getP_item()->getIsGameOverItem() == true)
               //     gameOver();


/*
                //if (item[i]->getP_item() == p_zorkgame.getGameOverItem())
                //if (item[i]->getP_item()->getIsGameOverItem() == true)
                {
                    //removeItemsFromScene();
                    //gameOver();

                }
*/
            }
            else
            {
                if (p_zorkgame.getPlayer()->getCurrentItem() != NULL)
                {
                    if (p_zorkgame.getPlayer()->getCurrentItem()->checkInteraction(item[i]->getP_item()))
                    {
                        if (ItemDoor* door = dynamic_cast<ItemDoor*>(item[i]->getP_item()))
                        {
                            Room *newRoom = door->getRoom();
                            std::string newDirection = door->getDirection();
                            p_zorkgame.addNewRoom(newRoom, door->getAdjacentRoom() ,newDirection);
                            ui->textBrowser->append(QString::fromStdString("New room unlocked: " + newRoom->getDescription() + " to the " + newDirection + " of " + door->getRoom()->getDescription()));
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::onInventoryItemClicked(QListWidgetItem *item)
{
    p_zorkgame.getPlayer()->currentItem(item->text().toLocal8Bit().constData());


}

void MainWindow::onQuestionMarkClicked()
{
    if (p_zorkgame.getPlayer()->getCurrentItem() != NULL) {
        ui->textBrowser->append(QString::fromStdString(p_zorkgame.getPlayer()->getCurrentItem()->getLongDescription()));
        if(p_zorkgame.getPlayer()->getCurrentItem()->getIsGameOverItem() == true)
            gameOver();
    }
    else
        ui->textBrowser->append("You have no current item selected!");

}




//called when the game ends
void MainWindow::gameOver()
{
    removeItemsFromScene();
    background = new QGraphicsPixmapItem(gameOverScreen.scaled(width, height, Qt::KeepAspectRatio));
    scene->addItem(background);



}
