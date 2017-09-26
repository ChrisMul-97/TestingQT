#include "mainwindow.h"
#include "zorkgame.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->append(p_zorkgame.getWelcomeText());
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
    QImage image("C:/Users/Chris Mulcahy/Documents/build-MoreTestingAgain-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug/arrow.png");
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
}

void MainWindow::connectSignalsToSlots()
{
    connect(ui->labelRight, SIGNAL(clicked()), this, SLOT(clickedRight()));
    connect(ui->labelUp, SIGNAL(clicked()), this, SLOT(clickedUp()));
    connect(ui->labelLeft, SIGNAL(clicked()), this, SLOT(clickedLeft()));
    connect(ui->labelDown, SIGNAL(clicked()), this, SLOT(clickedDown()));
    //connect(ui->labelRoomImage, SIGNAL(mousePos()), this, SLOT(mouseCurrentPos()));
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
        QPixmap pixmap = p_zorkgame.getCurrentRoom()->getRoomImage();
        ui->labelRoomImage->setPixmap(pixmap);
        //ui->labelRoomImage->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));

        ui->labelRoomImage->setScaledContents( true );

        ui->labelRoomImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
    else
        ui->textBrowser->append("You can't see anything in here!");
}

void MainWindow::on_pushButton_clicked()
{
    std::string input = ui->textEdit->toPlainText().toLocal8Bit().constData();
    std::string inputArray[2];
    std::stringstream stream(input);
    int i = 0;
    while (stream.good() && i < 2){
        stream >> inputArray[i];
        i++;
    }
    if (inputArray[0].compare("go") == 0)
    {
        QString newString = QString::fromStdString(p_zorkgame.go(inputArray[1]));
        ui->textBrowser->append(newString);
        printRoomImage();
    }
}
