#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <sstream>
#include "zorkgame.h"

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
    void setUpGUI();
    void connectSignalsToSlots();
    void printRoomInfo();
    void printRoomImage();

private slots:
    void clickedRight();
    void clickedLeft();
    void clickedUp();
    void clickedDown();
    //void mouseCurrentPos();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
