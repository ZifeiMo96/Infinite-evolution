#include "knight.h"

#include<QtMath>
#include<QTime>
Knight::Knight()
{

}
void Knight::init(double x, double y, int attack, int hp, int hpMax, int cdOfAttack, int width, int height, double speed, double attackRange, int skillOfDamage)
{
    this->x=x;
    this->y=y;
    this->attack=attack;
    this->hp=hp;
    this->hpMax=hpMax;
    this->cdOfAttack=cdOfAttack;
    this->width=width;
    this->height=height;
    this->speed=speed;
    this->attackRange=attackRange;
    this->skillOfDamage=skillOfDamage;
    ifMove = 1;
}


void Knight::charge(Obj&obj)
{
    double chargeSpeed=3*speed;
    int direction = 0;
    double s2 = (x-obj.getX())*(x-obj.getX())+(y-obj.getY())*(y-obj.getY());
    double s = pow(s2,0.5);
        if(bool ifStuporous=0)
        {

            if(obj.getX()<=x&&obj.getY()<=y){direction=1;}          //玩家在怪物的左上方
            if(obj.getX()<=x&&obj.getY()>y){direction=2;}           //左下方
            if(obj.getX()>x&&obj.getY()>y){direction=3;}            //右下方
            if(obj.getX()>x&&obj.getY()<=y){direction=4;}           //右上方
            switch (direction)
            {
            case 1:
                x+=chargeSpeed*((x-obj.getX())/s);
                y+=chargeSpeed*((y-obj.getY())/s);
                                                      //遗留撞墙检测
                break;
            case 2:
                x+=chargeSpeed*((x-obj.getX())/s);
                y-=chargeSpeed*((obj.getY()-y)/s);

                break;
            case 3:
                x-=chargeSpeed*((obj.getX()-x)/s);
                y-=chargeSpeed*((obj.getY()-y)/s);

                break;
            case 4:
                x-=chargeSpeed*((obj.getX())-x/s);
                y+=chargeSpeed*((y-obj.getY())/s);

                break;
            default:
                break;
            }
        }
}
void Knight::skill(Obj&obj)
{
    if((hp<=(0.5*hpMax))&&!ifStuporous&&!ifHit)
    {
        charge(obj);
        ifHit=1;
        if(checkHit(obj))                              //图片碰撞检测
        {
            skillDamage(obj);
        }
    }
}

void Knight::skillDamage(Obj&obj)
{
    obj.setHp(obj.getHp()-skillOfDamage);
}

void Knight::die()
{
    if(hp<=0){
        //hide the remoteMonster
        ifLive=0;
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int skillKind=qrand()%2;
        skillOfFirst.init(x,y,skillKind);
        init(0,0,0,0,0,0,0,0,0,0,0);
        //跳转到下一关地图
        }

}

bool Knight::checkHit(Obj&obj)
{
    if(x<=obj.getX()){
        if(y<=obj.getY()){
            if((int)(obj.getX()-x)<=width&&(int)(obj.getY()-y)<=height) return true;
            else  return false;
        }
        if(y>obj.getY()){
            if((int)(obj.getX()-x)<=width&&(int)(y-obj.getY())<=obj.getHeight()) return true;
            else  return false;
        }
    }
    else{
        if(y<=obj.getY()){
            if((int)(x-obj.getX())<=obj.getWidth()&&(int)(obj.getY()-y)<=height) return true;
            else  return false;
        }
        if(y>obj.getY()){
            if((int)(x-obj.getX())<=obj.getWidth()&&(int)(y-obj.getY())<=obj.getHeight()) return true;
            else  return false;
        }
    }
}
