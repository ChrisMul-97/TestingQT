#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <sstream>
#include <QGraphicsView>
#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include "zorkgame.h"
#include "commandwords.h"
#include "qgraphicsobjectgameitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ZorkGame p_zorkgame;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *background;
    QGraphicsObjectGameItem *item[5];
    QListWidget *listViewItems;
    void setUpGUI();
    void connectSignalsToSlots();
    void printRoomInfo();
    void printRoomImage();
    void removeItemsFromScene();
    bool firstRoomEntered = false;
    void showPlayerInventory();

private slots:
    void clickedRight();
    void clickedLeft();
    void clickedUp();
    void clickedDown();
    void on_pushButton_clicked();
    void on_pushButtonTeleport_clicked();
    void itemClicked();
    void onInventoryItemClicked(QListWidgetItem*);
};

#endif // MAINWINDOW_H
