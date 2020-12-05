#ifndef REMOTEMONSTER_H
#define REMOTEMONSTER_H
#include"monster.h"

//class Obj;
//class Bullet;

class RemoteMonster:public Monster
{
public:
    RemoteMonster();
    virtual void init(double x,double y,int z);
    virtual void move(Obj&p1,int map[12][16]);
    virtual void attackPlayer(Obj&obj);
    virtual void die();
    int width_of_pix;
    int height_of_pix;
    int x_of_pix;
    int y_of_pix;
    QPixmap pix;
    QPixmap rmonster[10][8];
    Bullet boxOfBullet[50];
protected:
    int direction=0;
    int kind;

    int shootTime=0;
    int shootNumber=0;
    int bulletWidth;
    int bulletHeight;
    double directionX;
    double directionY;
    int x_of_gif;
    int y_of_gif;
    int number_of_move;
    bool ifAttack;
};

#endif // REMOTEMONSTER_H
