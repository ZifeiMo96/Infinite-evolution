#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include "monster.h"
#include "prop.h"
#include "bullet.h"
#include "obj.h"




class Player:public Obj
{
public:

    Player();
    void getProp(Prop &obj);


    void attackMonster();
    void buyProp(Prop &obj);

    //__________________________
    void die();
    QPixmap img_player;
    QPixmap pix_player;
    void change_status_of_player(int i);
    int get_status_of_player();
    void change_page_of_player(int i);
    int get_page_of_player();
    void setUp(bool b);
    void setDown(bool b);
    void setLeft(bool b);
    void setRight(bool b);
    void checkMove();
    void move(int map[12][16],Obj obj1[10],Obj obj2[10]);  //移动函数
    bool ifAttack=0;
    void setBullet(int i,int x, int y);
    void shoot(int x,int y);
    Bullet boxOfBullet[50];
    void changeIfShoot(bool b);
    int x_of_attack;
    int y_of_attack;
    void cleanBullet();
    void checkBulletHit(Obj &obj,bool &b);
    int box_of_prop[180];
    int getAttack(){
        return attack;
    }
    int getMoney();
    int number_of_prop;
    int mp=100;
    int mpMax = 100;

    int dieNumber = 0;

    void checkDie();
    bool ifDie;
    int setMoney(int i);


    int status_of_player =0;
    int page_of_player =0;


public slots:
    void gif();


private:

    int money;
    int attack;
    int shootNumber=0;
    int cdOfAttack=20;
    int shootTime=0;
    int kindOfBullet=0;
    bool ifUp=0;
    bool ifDown=0;
    bool ifRight=0;
    bool ifLeft=0;
    bool ifMove=0;
    bool ifShoot =0;




};

#endif // PLAYER_H
