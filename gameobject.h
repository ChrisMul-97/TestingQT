#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<QPixmap>

class GameObject
{
private:
    int x,y,sizeX,sizeY;
    QPixmap pixmap;
public:
    GameObject();
    ~GameObject();
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getSizeX() const;
    void setSizeX(int value);
    int getSizeY() const;
    void setSizeY(int value);
    QPixmap getItemImage() const;
    void setItemImage(const QPixmap value);
    bool virtual checkInherited() = 0;
};

#endif // GAMEOBJECT_H
