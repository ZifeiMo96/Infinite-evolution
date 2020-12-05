#include "obj.h"
#include <QDebug>

Obj::Obj()
{

}

bool Obj::checkCrash(int x, int y, int map[12][16])
{
    if(y<=0||y+height>=480||x<=0||x+width>=640){
        return 0;
    }else if
       (map[y/40][x/40]==0&&
       map[(y+this->height)/40][x/40]==0&&
       map[y/40][(x+this->width)/40]==0&&
       map[(y+this->height)/40][(x+this->width)/40]==0){
        return 1;
    }else{

        return 0;

    }

}
//我是想把中毒和昏睡的时间留给player的技能函数来写
//注意中毒和昏睡函数每次都要调 不然容易出问题 而且在调的时候不用加判定 这里已经写了 计算量是一样的
void Obj::beToxic(int damage)
{
    if(beToxicTimed<beToxicTime&&ifToxic){//注意这里不能用while while会一次性作用完 起不到时间作用
        hp-= (int)(0.2*damage);//注意damage要适当大一点
        beToxicTimed++;
    }
}
void Obj::beStuporous(){}

bool Obj::checkCrashWith(int x,int y,Obj &obj)
{
    if(obj.ifLive){
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
    else  return false;
}

void Obj::checkDie(bool &b)
{
    if(hp<=0){
        ifLive = 0;
        b = 1;
    }
}

//空函数即可
