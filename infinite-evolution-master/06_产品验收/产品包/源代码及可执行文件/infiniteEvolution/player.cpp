#include "player.h"
#include <QDebug>

Player::Player()
{
    img_player.load(":/res/img_player");
    x = 280;
    y = 240;
    speed = 4;
    height =25;
    width =15;
    hp = 100;
    hpMax = 100;
    cdOfAttack=5;
    attack = 10;
    money = 100;
    number_of_prop = 0;
    pix_player = img_player.copy(0,0,20,17);
    ifLive = 1;

}

void Player::getProp(Prop &obj)
{
    if(checkCrashWith(this->x,this->y,obj)){
        switch(obj.getKind()){
        case 1:
            money+=1;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 2:
            money+=5;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 3:
            money+=10;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 4:
            attack+=5;
            box_of_prop[number_of_prop] = 4;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 5:
            hp+=15;
            hpMax+=15;
            box_of_prop[number_of_prop] = 5;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 6:
            attack+=10;
            hp-=5;
            hpMax-=5;
            box_of_prop[number_of_prop] = 6;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 7:
            speed+=0.2;
            hp+=5;
            hpMax+=5;
            box_of_prop[number_of_prop] = 7;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 8:
            hp+=30;
            hpMax+=30;
            attack +=10;
            box_of_prop[number_of_prop] = 8;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 9:
            attack+=15;
            speed+=0.5;
            box_of_prop[number_of_prop] = 9;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 10:
            attack+=5;
            speed+=0.2;
            box_of_prop[number_of_prop] = 10;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 11:
            hp+=5;
            hpMax+=5;
            speed+=0.3;
            box_of_prop[number_of_prop] = 11;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 12:
            hp+=30;
            hpMax+=30;
            speed-=0.5;
            box_of_prop[number_of_prop] = 12;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 13:
            attack+=5;
            hp+=10;
            hpMax+=10;
            box_of_prop[number_of_prop] = 13;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 14:
            attack+=3;
            hp+=10;
            hpMax+=10;
            speed+=0.1;
            box_of_prop[number_of_prop] = 14;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 15:
            attack+=3;
            hp+=5;
            hpMax+=5;
            speed+=0.2;
            box_of_prop[number_of_prop] = 15;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 16:
            attack+=10;
            speed+=0.2;
            hp-=10;
            hpMax-=10;
            box_of_prop[number_of_prop] = 16;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 17:
            hp+=25;
            hpMax+=25;
            box_of_prop[number_of_prop] = 17;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 18:
            hp+=50;
            hpMax+=50;
            box_of_prop[number_of_prop] = 18;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 19:
            mp+=20;
            mpMax+=20;
            speed+=0.2;
            box_of_prop[number_of_prop] = 19;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 20:
            mp+=30;
            mpMax+=30;
            hp+=30;
            hpMax+=30;
            box_of_prop[number_of_prop] = 20;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 21:
            mp+=20;
            mpMax+=20;
            hp+=20;
            hpMax+=20;
            speed-=0.2;
            box_of_prop[number_of_prop] = 21;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 22:
            attack+=20;
            hp+=30;
            hpMax+=30;
            mp+=40;
            mpMax+=40;
            speed+=0.5;
            box_of_prop[number_of_prop] = 22;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;
        case 23:
            speed+=0.4;
            box_of_prop[number_of_prop] = 23;
            number_of_prop++;
            obj.setX(0);
            obj.setY(0);
            obj.ifGot =0;
            obj.ifLive=0;
            break;

        }
    }
}



void Player::move(int map[12][16],Obj obj1[10],Obj obj2[10])
{

    if(ifLive){
        if(ifUp) {
            int tx=0,ty=0;
            tx=int(x);
            ty=int(y-speed);

            bool if_move_y = 1;
            for(int i =0;i<10;i++){
                if(this->checkCrashWith(x,ty,obj1[i])){
                     if_move_y = 0;
                }
                if(this->checkCrashWith(x,ty,obj2[i])){
                     if_move_y = 0;
                }
            }

            if(checkCrash(tx,ty,map)&&if_move_y){
               y-=speed;
            }
        }
        if(ifDown){
            int tx=0,ty=0;
            tx=int(x);
            ty=int(y+speed);

            bool if_move_y = 1;

            for(int i =0;i<10;i++){
                if(this->checkCrashWith(x,ty,obj1[i])){
                     if_move_y = 0;
                }
                if(this->checkCrashWith(x,ty,obj1[i])){
                     if_move_y = 0;
                }
            }

            if(checkCrash(tx,ty,map)&&if_move_y){
               y+=speed;
            }
        }
        if(ifLeft) {
            int tx=0,ty=0;
            tx=int(x-speed);
            ty=int(y);
            bool if_move_x = 1;
            for(int i = 0;i<10;i++){
                if(this->checkCrashWith(tx,y,obj1[i])){
                    if_move_x = 0;
                }
                if(this->checkCrashWith(tx,y,obj2[i])){
                    if_move_x = 0;
                }
            }
            if(checkCrash(tx,ty,map)&&if_move_x){
               x-=speed;
            }
        }
        if(ifRight) {
            int tx=0,ty=0;
            tx=int(x+speed);
            ty=int(y);
            bool if_move_x = 1;
            for(int i = 0;i<10;i++){
                if(this->checkCrashWith(tx,y,obj1[i])){
                    if_move_x = 0;
                }
                if(this->checkCrashWith(tx,y,obj2[i])){
                    if_move_x = 0;
                }
            }
            if(checkCrash(tx,ty,map)){
               x+=speed;
            }
        }


    }

}

void Player::shoot(int x,int y)
{
    if(ifLive){
        static int number_of_attack;
        static int number_of_bullet;
        number_of_attack++;
        if(ifShoot){
            if(number_of_attack>cdOfAttack){
                for(int i = 0;i<50;i++){
                    if(boxOfBullet[i].ifLive == 0){
                        number_of_bullet = i;
                        break;
                    }
                }
                boxOfBullet[number_of_bullet].Init(int(this->x+this->width*0.5-5),int(this->y+this->height*0.5-5),0,this->attack,0,0);
                setBullet(number_of_bullet,x,y);
                boxOfBullet[number_of_bullet].calDirection(this->x,this->y,x,y);
                number_of_attack = 0;
            }
        }

    }

}

void Player::changeIfShoot(bool b)
{
    ifShoot =b;
}

void Player::cleanBullet()
{
    for(int i= 0;i<50;i++){
        boxOfBullet[i].hide();
    }
}

void Player::checkBulletHit(Obj &obj1,bool &b)
{
    for(int i=0;i<50;i++){
        if(boxOfBullet[i].ifLive){

                if(boxOfBullet[i].checkHit(obj1)){

                    boxOfBullet[i].loseHp(obj1,b);
                    boxOfBullet[i].hide();


            }


        }
    }

}

int Player::getMoney()
{
    return money;
}

void Player::checkDie()
{
    if(hp<=0){
        ifLive = 0;
    }
}

int Player::setMoney(int i)
{
    money = i;
}

void Player::setBullet(int i, int x, int y)
{
    boxOfBullet[i].setDamage(attack);

    double tx = double(x)-this->x;
    double ty = double(y)-this->y;
    if(tx>0){
        if(ty/tx>2.4142){

            this->boxOfBullet[i].direction = 6;//向下
            this->boxOfBullet[i].setSize(6,12);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_8");

        }
        else if(ty/tx<=2.4142&&ty/tx>0.4142){

            this->boxOfBullet[i].direction = 7;//右下
            this->boxOfBullet[i].setSize(10,10);
           this->boxOfBullet[i].pix.load(":/res/bullet_of_player_9");


        }
        else if(ty/tx<=0.4142&&ty/tx>-0.4142){

            this->boxOfBullet[i].direction = 0;
            this->boxOfBullet[i].setSize(12,6);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_6");

        }
        else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

            this->boxOfBullet[i].direction = 1;
            this->boxOfBullet[i].setSize(10,10);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_3");


        }
        else if(ty/tx<-2.4142){

            this->boxOfBullet[i].direction = 2;
            this->boxOfBullet[i].setSize(6,12);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_2");

        }

    }
    else if(tx==0){
        if(ty<0){

            this->boxOfBullet[i].direction = 2;
            this->boxOfBullet[i].setSize(6,12);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_2");
        }else{

            this->boxOfBullet[i].direction = 6;
            this->boxOfBullet[i].setSize(6,12);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_8");
        }

    }
    else if(tx<0){
        if(ty/tx>2.4142){

            this->boxOfBullet[i].direction = 2;
            this->boxOfBullet[i].setSize(6,12);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_2");
        }
        else if(ty/tx<=2.4142&&ty/tx>0.4142){

            this->boxOfBullet[i].direction = 3;
            this->boxOfBullet[i].setSize(10,10);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_1");

        }
        else if(ty/tx<=0.4142&&ty/tx>-0.4142){

           this->boxOfBullet[i].direction = 4;
           this->boxOfBullet[i].setSize(12,6);
           this->boxOfBullet[i].pix.load(":/res/bullet_of_player_4");
        }
        else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

           this->boxOfBullet[i].direction = 5;
           this->boxOfBullet[i].setSize(10,10);
           this->boxOfBullet[i].pix.load(":/res/bullet_of_player_7");

        }
        else if(ty/tx<-2.4142){

            this->boxOfBullet[i].direction = 6;
            this->boxOfBullet[i].setSize(6,12);
            this->boxOfBullet[i].pix.load(":/res/bullet_of_player_8");

        }
    }

}




void Player::change_status_of_player(int i)
{
    this->status_of_player = i;
}

int Player::get_status_of_player()
{
    return this->status_of_player;
}

void Player::change_page_of_player(int i)
{
    this->page_of_player = i;
}

int Player::get_page_of_player()
{
    return this->page_of_player;
}

void Player::setUp(bool b)
{
    ifUp = b;
}

void Player::setDown(bool b)
{
    ifDown = b;
}

void Player::setLeft(bool b)
{
    ifLeft = b;
}

void Player::setRight(bool b)
{
    ifRight = b;
}

void Player::checkMove()
{
    if(!ifUp&&!ifDown&&!ifLeft&&!ifRight){
        ifMove=0;
    }else{
        ifMove=1;
    }
}



void Player::gif()
{
    checkMove();
    if(status_of_player!=8&&status_of_player!=9&&ifAttack){
        switch(page_of_player){
        case 3:
            page_of_player = 4;
            pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
            break;
        case 4:
            page_of_player = 5;
            pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
            break;
        case 5:
            page_of_player = 3;
            pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
            break;
        default:
            page_of_player = 3;
            pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
            break;
        }
    }
    else if(status_of_player!=8&&status_of_player!=9&&!ifAttack){
        if(status_of_player!=8&&status_of_player!=9&&ifMove){
            switch(page_of_player){
            case 0:
                page_of_player = 1;
                pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
                break;
            case 1:
                page_of_player = 2;
                pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
                break;
            case 2:
                page_of_player = 0;
                pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
                break;
            default:
                page_of_player = 0;
                pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
                break;
            }
        }else if(status_of_player!=8&&status_of_player!=9&&!ifMove){
            pix_player = img_player.copy(status_of_player*20,page_of_player*17,20,17);
        }
    }




}
