#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <sstream>
#include <QGraphicsView>
#include <vector>
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
    QGraphicsObjectGameItem *item;
    void setUpGUI();
    void connectSignalsToSlots();
    void printRoomInfo();
    void printRoomImage();
    void removeItemsFromScene();
    bool firstRoomEntered = false;
    //CommandWords *commands;

private slots:
    void clickedRight();
    void clickedLeft();
    void clickedUp();
    void clickedDown();
    //void mouseCurrentPos();
    void on_pushButton_clicked();
    void on_pushButtonTeleport_clicked();
    void itemClicked();
};

#endif // MAINWINDOW_H
