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
    QImage image("C:/Users/Mark/Pictures/Saved Pictures/I-dont-want-to-live-on-this-planet-anymore");
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

/*
void MainWindow::mouseCurrentPos()
{
    ui->textBrowser->append(QString("X= %1, Y = %2").arg(ui->labelRoomImage->x()).arg(ui->labelRoomImage->y()));
}
*/

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

        int width = ui->graphicsView->width();
        int height = ui->graphicsView->height();

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
    }
}

void MainWindow::showPlayerInventory()
{
    Player player = p_zorkgame.getPlayer();
    std::string items[5];
    std::string itemsFromPlayer = player.getItemNames();
    int i = 0;
    stringstream streamIn(itemsFromPlayer);
    while (streamIn.good() && i < 5){
        streamIn >> items[i];
        i++;
    }
    QString qStringArrayItems[5];
    for (int i = 0; i < 5; i++)
    {
        if (!(items[i].empty()))
        {
            qStringArrayItems[i] = QString::fromStdString(items[i]);
            this->listViewItems->addItem(qStringArrayItems[i]);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    std::string input = ui->textEdit->toPlainText().toLocal8Bit().constData();
    std::string inputArray[2];
    std::stringstream stream(input);
    int i = 0;
    while (stream.good() && i < 2)
    {
        stream >> inputArray[i];
        i++;
    }

    ui->textEdit->clear();
    //if (commands->isCommand(inputArray[i]))
    //{
        if (inputArray[0].compare("go") == 0)
        {
            QString newString = QString::fromStdString(p_zorkgame.go(inputArray[1]));
            ui->textBrowser->append(newString);
            printRoomImage();
        }
        if (inputArray[0].compare("info") == 0)
        {
            ui->textBrowser->append("Valid commands are: \n go    info    teleport");
            //ui->textBrowser->append(Command->showAll());
        }
        if (inputArray[0].compare("teleport") == 0)
        {
            p_zorkgame.teleport();
            ui->textBrowser->append(p_zorkgame.getCurrentRoomDescription());
            printRoomImage();
        }
        if (inputArray[0].compare("unlock") == 0)
        {
            p_zorkgame.unlockRoom();
            ui->textBrowser->append(p_zorkgame.getCurrentRoomDescription());
            printRoomImage();
        }

    //}
}

void MainWindow::on_pushButtonTeleport_clicked()
{
    p_zorkgame.teleport();
    ui->textBrowser->append(p_zorkgame.getCurrentRoomDescription());
    printRoomImage();
}

void MainWindow::itemClicked()
{
    for (int i = 0; i < 5; i++)
    {
        if (item[i] != NULL)
        {
            if (item[i]->getClickedCheck() == true)
            {
                p_zorkgame.addPlayerItem(item[i]->getP_item());
                scene->removeItem(item[i]);
                p_zorkgame.getCurrentRoom()->deleteItem(item[i]->getP_item());
                item[i] = NULL;
            }
        }
    }
    showPlayerInventory();
}

void MainWindow::appendText(QString newString)
{

    ui->textBrowser->append(newString);
}
