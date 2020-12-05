#include "remotemonster.h"
#include<QDebug>
#include<QTime>
RemoteMonster::RemoteMonster()
{

}

void RemoteMonster::init(double x, double y,int z)
{
    ifprop = 1;
    this->x = x;
    this->y=y;
    ifLive = 1;
    switch(z){
    case 1:

        rmonster[1][1].load(":/remotemonster_1/第一关远程兵左下1");
        rmonster[1][2].load(":/remotemonster_1/第一关远程兵左下2");
        rmonster[1][3].load(":/remotemonster_1/第一关远程兵左下3");
        rmonster[1][4].load(":/remotemonster_1/第一关远程兵左下4");
        rmonster[1][5].load(":/remotemonster_1/第一关远程兵左下5");
        rmonster[1][6].load(":/remotemonster_1/第一关远程兵左下6");
        rmonster[1][7].load(":/remotemonster_1/第一关远程兵左下6");
        rmonster[2][1].load(":/remotemonster_1/第一关远程兵下1");
        rmonster[2][2].load(":/remotemonster_1/第一关远程兵下2");
        rmonster[2][3].load(":/remotemonster_1/第一关远程兵下3");
        rmonster[2][4].load(":/remotemonster_1/第一关远程兵下4");
        rmonster[2][5].load(":/remotemonster_1/第一关远程兵下5");
        rmonster[2][6].load(":/remotemonster_1/第一关远程兵下6");
        rmonster[2][7].load(":/remotemonster_1/第一关远程兵下6");
        rmonster[3][1].load(":/remotemonster_1/第一关远程兵右下1");
        rmonster[3][2].load(":/remotemonster_1/第一关远程兵右下2");
        rmonster[3][3].load(":/remotemonster_1/第一关远程兵右下3");
        rmonster[3][4].load(":/remotemonster_1/第一关远程兵右下4");
        rmonster[3][5].load(":/remotemonster_1/第一关远程兵右下5");
        rmonster[3][6].load(":/remotemonster_1/第一关远程兵右下6");
        rmonster[3][7].load(":/remotemonster_1/第一关远程兵右下6");
        rmonster[4][1].load(":/remotemonster_1/第一关远程兵左1");
        rmonster[4][2].load(":/remotemonster_1/第一关远程兵左2");
        rmonster[4][3].load(":/remotemonster_1/第一关远程兵左3");
        rmonster[4][4].load(":/remotemonster_1/第一关远程兵左4");
        rmonster[4][5].load(":/remotemonster_1/第一关远程兵左5");
        rmonster[4][6].load(":/remotemonster_1/第一关远程兵左6");
        rmonster[4][7].load(":/remotemonster_1/第一关远程兵左6");
        rmonster[6][1].load(":/remotemonster_1/第一关远程兵右1");
        rmonster[6][2].load(":/remotemonster_1/第一关远程兵右2");
        rmonster[6][3].load(":/remotemonster_1/第一关远程兵右3");
        rmonster[6][4].load(":/remotemonster_1/第一关远程兵右4");
        rmonster[6][5].load(":/remotemonster_1/第一关远程兵右5");
        rmonster[6][6].load(":/remotemonster_1/第一关远程兵右6");
        rmonster[6][7].load(":/remotemonster_1/第一关远程兵右6");
        rmonster[7][1].load(":/remotemonster_1/第一关远程兵左上1");
        rmonster[7][2].load(":/remotemonster_1/第一关远程兵左上2");
        rmonster[7][3].load(":/remotemonster_1/第一关远程兵左上3");
        rmonster[7][4].load(":/remotemonster_1/第一关远程兵左上4");
        rmonster[7][5].load(":/remotemonster_1/第一关远程兵左上5");
        rmonster[7][6].load(":/remotemonster_1/第一关远程兵左上6");
        rmonster[7][7].load(":/remotemonster_1/第一关远程兵左上6");
        rmonster[8][1].load(":/remotemonster_1/第一关远程兵上1");
        rmonster[8][2].load(":/remotemonster_1/第一关远程兵上2");
        rmonster[8][3].load(":/remotemonster_1/第一关远程兵上3");
        rmonster[8][4].load(":/remotemonster_1/第一关远程兵上4");
        rmonster[8][5].load(":/remotemonster_1/第一关远程兵上5");
        rmonster[8][6].load(":/remotemonster_1/第一关远程兵上6");
        rmonster[8][7].load(":/remotemonster_1/第一关远程兵上6");
        rmonster[9][1].load(":/remotemonster_1/第一关远程兵右上1");
        rmonster[9][2].load(":/remotemonster_1/第一关远程兵右上2");
        rmonster[9][3].load(":/remotemonster_1/第一关远程兵右上3");
        rmonster[9][4].load(":/remotemonster_1/第一关远程兵右上4");
        rmonster[9][5].load(":/remotemonster_1/第一关远程兵右上5");
        rmonster[9][6].load(":/remotemonster_1/第一关远程兵右上6");
        rmonster[9][7].load(":/remotemonster_1/第一关远程兵右上6");
        attack = 10;
        hp = 40;
        hpMax=40;
        cdOfAttack = 30;
        width  =32;
        height = 32;
        x_of_pix= 0;
        y_of_pix= 0;
        width_of_pix = 40;
        height_of_pix = 34;
        speed = 1;
        pix = rmonster[x_of_gif][y_of_gif];
        break;
    case 2:
        rmonster[1][1].load(":/remotemonster_2/第二关远程兵左下1");
        rmonster[1][2].load(":/remotemonster_2/第二关远程兵左下2");
        rmonster[1][3].load(":/remotemonster_2/第二关远程兵左下2");
        rmonster[1][4].load(":/remotemonster_2/第二关远程兵左下3");
        rmonster[1][5].load(":/remotemonster_2/第二关远程兵左下4");
        rmonster[1][6].load(":/remotemonster_2/第二关远程兵左下5");
        rmonster[1][7].load(":/remotemonster_2/第二关远程兵左下6");
        rmonster[2][1].load(":/remotemonster_2/第二关远程兵下1");
        rmonster[2][2].load(":/remotemonster_2/第二关远程兵下2");
        rmonster[2][3].load(":/remotemonster_2/第二关远程兵下2");
        rmonster[2][4].load(":/remotemonster_2/第二关远程兵下3");
        rmonster[2][5].load(":/remotemonster_2/第二关远程兵下4");
        rmonster[2][6].load(":/remotemonster_2/第二关远程兵下5");
        rmonster[2][7].load(":/remotemonster_2/第二关远程兵下6");
        rmonster[3][1].load(":/remotemonster_2/第二关远程兵右下1");
        rmonster[3][2].load(":/remotemonster_2/第二关远程兵右下2");
        rmonster[3][3].load(":/remotemonster_2/第二关远程兵右下2");
        rmonster[3][4].load(":/remotemonster_2/第二关远程兵右下3");
        rmonster[3][5].load(":/remotemonster_2/第二关远程兵右下4");
        rmonster[3][6].load(":/remotemonster_2/第二关远程兵右下5");
        rmonster[3][7].load(":/remotemonster_2/第二关远程兵右下6");
        rmonster[4][1].load(":/remotemonster_2/第二关远程兵左1");
        rmonster[4][2].load(":/remotemonster_2/第二关远程兵左2");
        rmonster[4][3].load(":/remotemonster_2/第二关远程兵左3");
        rmonster[4][4].load(":/remotemonster_2/第二关远程兵左4");
        rmonster[4][5].load(":/remotemonster_2/第二关远程兵左5");
        rmonster[4][6].load(":/remotemonster_2/第二关远程兵左6");
        rmonster[4][7].load(":/remotemonster_2/第二关远程兵左6");
        rmonster[6][1].load(":/remotemonster_2/第二关远程兵右1");
        rmonster[6][2].load(":/remotemonster_2/第二关远程兵右2");
        rmonster[6][3].load(":/remotemonster_2/第二关远程兵右3");
        rmonster[6][4].load(":/remotemonster_2/第二关远程兵右4");
        rmonster[6][5].load(":/remotemonster_2/第二关远程兵右5");
        rmonster[6][6].load(":/remotemonster_2/第二关远程兵右6");
        rmonster[6][7].load(":/remotemonster_2/第二关远程兵右6");
        rmonster[7][1].load(":/remotemonster_2/第二关远程兵左上1");
        rmonster[7][2].load(":/remotemonster_2/第二关远程兵左上2");
        rmonster[7][3].load(":/remotemonster_2/第二关远程兵左上3");
        rmonster[7][4].load(":/remotemonster_2/第二关远程兵左上4");
        rmonster[7][5].load(":/remotemonster_2/第二关远程兵左上5");
        rmonster[7][6].load(":/remotemonster_2/第二关远程兵左上6");
        rmonster[7][7].load(":/remotemonster_2/第二关远程兵左上6");
        rmonster[8][1].load(":/remotemonster_2/第二关远程兵上1");
        rmonster[8][2].load(":/remotemonster_2/第二关远程兵上2");
        rmonster[8][3].load(":/remotemonster_2/第二关远程兵上3");
        rmonster[8][4].load(":/remotemonster_2/第二关远程兵上4");
        rmonster[8][5].load(":/remotemonster_2/第二关远程兵上5");
        rmonster[8][6].load(":/remotemonster_2/第二关远程兵上6");
        rmonster[8][7].load(":/remotemonster_2/第二关远程兵上6");
        rmonster[9][1].load(":/remotemonster_2/第二关远程兵右上1");
        rmonster[9][2].load(":/remotemonster_2/第二关远程兵右上2");
        rmonster[9][3].load(":/remotemonster_2/第二关远程兵右上3");
        rmonster[9][4].load(":/remotemonster_2/第二关远程兵右上4");
        rmonster[9][5].load(":/remotemonster_2/第二关远程兵右上5");
        rmonster[9][6].load(":/remotemonster_2/第二关远程兵右上6");
        rmonster[9][7].load(":/remotemonster_2/第二关远程兵右上6");
        attack = 15;
        hp = 80;
        hpMax=80;
        cdOfAttack = 30;
        width  =32;
        height = 32;
        x_of_pix= 0;
        y_of_pix= 0;
        width_of_pix = 40;
        height_of_pix = 34;
        speed = 1;
        pix = rmonster[x_of_gif][y_of_gif];
        break;
    case 3:
        rmonster[1][1].load(":/remotemonster_3/第三关远程向左下1");
        rmonster[1][2].load(":/remotemonster_3/第三关远程向左下2");
        rmonster[1][3].load(":/remotemonster_3/第三关远程向左下3");
        rmonster[1][4].load(":/remotemonster_3/第三关远程左下攻击4");
        rmonster[1][5].load(":/remotemonster_3/第三关远程左下攻击5");
        rmonster[1][6].load(":/remotemonster_3/第三关远程左下攻击6");
        rmonster[1][7].load(":/remotemonster_3/第三关远程左下攻击6");
        rmonster[2][1].load(":/remotemonster_3/第三关远程向下1");
        rmonster[2][2].load(":/remotemonster_3/第三关远程向下2");
        rmonster[2][3].load(":/remotemonster_3/第三关远程向3");
        rmonster[2][4].load(":/remotemonster_3/第三关远程下攻击1");
        rmonster[2][5].load(":/remotemonster_3/第三关远程下攻击2");
        rmonster[2][6].load(":/remotemonster_3/第三关远程下攻击3");
        rmonster[2][7].load(":/remotemonster_3/第三关远程下攻击3");
        rmonster[3][1].load(":/remotemonster_3/第三关远程向右下1");
        rmonster[3][2].load(":/remotemonster_3/第三关远程向右下2");
        rmonster[3][3].load(":/remotemonster_3/第三关远程向右下3");
        rmonster[3][4].load(":/remotemonster_3/第三关远程右下攻击1");
        rmonster[3][5].load(":/remotemonster_3/第三关远程右下攻击2");
        rmonster[3][6].load(":/remotemonster_3/第三关远程右下攻击3");
        rmonster[3][7].load(":/remotemonster_3/第三关远程右下攻击3");
        rmonster[4][1].load(":/remotemonster_3/第三关远程向左1");
        rmonster[4][2].load(":/remotemonster_3/第三关远程向左2");
        rmonster[4][3].load(":/remotemonster_3/第三关远程向左3");
        rmonster[4][4].load(":/remotemonster_3/第三关远程左攻击1");
        rmonster[4][5].load(":/remotemonster_3/第三关远程左攻击2");
        rmonster[4][6].load(":/remotemonster_3/第三关远程左攻击3");
        rmonster[4][7].load(":/remotemonster_3/第三关远程左攻击3");
        rmonster[6][1].load(":/remotemonster_3/第三关远程向右1");
        rmonster[6][2].load(":/remotemonster_3/第三关远程向右2");
        rmonster[6][3].load(":/remotemonster_3/第三关远程向右3");
        rmonster[6][4].load(":/remotemonster_3/第三关远程右攻击1");
        rmonster[6][5].load(":/remotemonster_3/第三关远程右攻击2");
        rmonster[6][6].load(":/remotemonster_3/第三关远程右攻击3");
        rmonster[6][7].load(":/remotemonster_3/第三关远程右攻击3");
        rmonster[7][1].load(":/remotemonster_3/第三关远程向左上1");
        rmonster[7][2].load(":/remotemonster_3/第三关远程向左上2");
        rmonster[7][3].load(":/remotemonster_3/第三关远程向左上3");
        rmonster[7][4].load(":/remotemonster_3/第三关远程左上攻击1");
        rmonster[7][5].load(":/remotemonster_3/第三关远程左上攻击2");
        rmonster[7][6].load(":/remotemonster_3/第三关远程左上攻击3");
        rmonster[7][7].load(":/remotemonster_3/第三关远程左上攻击3");
        rmonster[8][1].load(":/remotemonster_3/第三关远程向上1");
        rmonster[8][2].load(":/remotemonster_3/第三关远程向上2");
        rmonster[8][3].load(":/remotemonster_3/第三关远程向上3");
        rmonster[8][4].load(":/remotemonster_3/第三关远程上攻击1");
        rmonster[8][5].load(":/remotemonster_3/第三关远程上攻击2");
        rmonster[8][6].load(":/remotemonster_3/第三关远程上攻击3");
        rmonster[8][7].load(":/remotemonster_3/第三关远程上攻击3");
        rmonster[9][1].load(":/remotemonster_3/第三关远程向右上1");
        rmonster[9][2].load(":/remotemonster_3/第三关远程向右上2");
        rmonster[9][3].load(":/remotemonster_3/第三关远程向右上3");
        rmonster[9][4].load(":/remotemonster_3/第三关远程右上攻击1");
        rmonster[9][5].load(":/remotemonster_3/第三关远程右上攻击2");
        rmonster[9][6].load(":/remotemonster_3/第三关远程右上攻击3");
        rmonster[9][7].load(":/remotemonster_3/第三关远程右上攻击3");
        attack = 20;
        hp = 120;
        hpMax=120;
        cdOfAttack = 30;
        width  =32;
        height = 32;
        x_of_pix= 0;
        y_of_pix= 0;
        width_of_pix = 40;
        height_of_pix = 34;
        speed = 1;
        pix = rmonster[x_of_gif][y_of_gif];
        break;
    case 4:
        rmonster[1][1].load(":/remotemonster_4/第四关远程向左下1");
        rmonster[1][2].load(":/remotemonster_4/第四关远程向左下2");
        rmonster[1][3].load(":/remotemonster_4/第四关远程向左下3");
        rmonster[1][4].load(":/remotemonster_4/第四关远程左下攻击1");
        rmonster[1][5].load(":/remotemonster_4/第四关远程左下攻击2");
        rmonster[1][6].load(":/remotemonster_4/第四关远程左下攻击3");
        rmonster[1][7].load(":/remotemonster_4/第四关远程左下攻击3");
        rmonster[2][1].load(":/remotemonster_4/第四关远程向下1");
        rmonster[2][2].load(":/remotemonster_4/第四关远程向下2");
        rmonster[2][3].load(":/remotemonster_4/第四关远程向下3");
        rmonster[2][4].load(":/remotemonster_4/第四关远程下攻击1");
        rmonster[2][5].load(":/remotemonster_4/第四关远程下攻击2");
        rmonster[2][6].load(":/remotemonster_4/第四关远程下攻击3");
        rmonster[2][7].load(":/remotemonster_4/第四关远程下攻击3");
        rmonster[3][1].load(":/remotemonster_4/第四关远程向右下1");
        rmonster[3][2].load(":/remotemonster_4/第四关远程向右下2");
        rmonster[3][3].load(":/remotemonster_4/第四关远程向右下3");
        rmonster[3][4].load(":/remotemonster_4/第四关远程右下攻击1");
        rmonster[3][5].load(":/remotemonster_4/第四关远程右下攻击2");
        rmonster[3][6].load(":/remotemonster_4/第四关远程右下攻击3");
        rmonster[3][7].load(":/remotemonster_4/第四关远程右下攻击3");
        rmonster[4][1].load(":/remotemonster_4/第四关远程向左1");
        rmonster[4][2].load(":/remotemonster_4/第四关远程向左2");
        rmonster[4][3].load(":/remotemonster_4/第四关远程向左3");
        rmonster[4][4].load(":/remotemonster_4/第四关远程左攻击1");
        rmonster[4][5].load(":/remotemonster_4/第四关远程左攻击2");
        rmonster[4][6].load(":/remotemonster_4/第四关远程左攻击3");
        rmonster[4][7].load(":/remotemonster_4/第四关远程攻击左3");
        rmonster[6][1].load(":/remotemonster_4/第四关远程向右1");
        rmonster[6][2].load(":/remotemonster_4/第四关远程向右2");
        rmonster[6][3].load(":/remotemonster_4/第四关远程向右3");
        rmonster[6][4].load(":/remotemonster_4/第四关远程右攻击1");
        rmonster[6][5].load(":/remotemonster_4/第四关远程右攻击2");
        rmonster[6][6].load(":/remotemonster_4/第四关远程右攻击3");
        rmonster[6][7].load(":/remotemonster_4/第四关远程右攻击3");
        rmonster[7][1].load(":/remotemonster_4/第四关远程向左上1");
        rmonster[7][2].load(":/remotemonster_4/第四关远程向左上2");
        rmonster[7][3].load(":/remotemonster_4/第四关远程向左上3");
        rmonster[7][4].load(":/remotemonster_4/第四关远程左上攻击1");
        rmonster[7][5].load(":/remotemonster_4/第四关远程左上攻击2");
        rmonster[7][6].load(":/remotemonster_4/第四关远程左上攻击3");
        rmonster[7][7].load(":/remotemonster_4/第四关远程左上攻击3");
        rmonster[8][1].load(":/remotemonster_4/第四关远程向上1");
        rmonster[8][2].load(":/remotemonster_4/第四关远程向上2");
        rmonster[8][3].load(":/remotemonster_4/第四关远程向上3");
        rmonster[8][4].load(":/remotemonster_4/第四关远程上攻击1");
        rmonster[8][5].load(":/remotemonster_4/第四关远程上攻击2");
        rmonster[8][6].load(":/remotemonster_4/第四关远程上攻击3");
        rmonster[8][7].load(":/remotemonster_4/第四关远程上攻击3");
        rmonster[9][1].load(":/remotemonster_4/第四关远程向右上1");
        rmonster[9][2].load(":/remotemonster_4/第四关远程向右上2");
        rmonster[9][3].load(":/remotemonster_4/第四关远程向右上3");
        rmonster[9][4].load(":/remotemonster_4/第四关远程右上攻击1");
        rmonster[9][5].load(":/remotemonster_4/第四关远程右上攻击2");
        rmonster[9][6].load(":/remotemonster_4/第四关远程右上攻击3");
        rmonster[9][7].load(":/remotemonster_4/第四关远程右上攻击3");
        attack = 30;
        hp = 200;
        hpMax=200;
        cdOfAttack = 30;
        width  =32;
        height = 32;
        x_of_pix= 0;
        y_of_pix= 0;
        width_of_pix = 40;
        height_of_pix = 34;
        speed = 1;
        pix = rmonster[x_of_gif][y_of_gif];
        break;
    }
}

void RemoteMonster::move(Obj&p1,int map[12][16])
{

    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int tmp1=qrand()%100;
    if(tmp1<=49){
    int tmp = qrand() % 100;
    if(tmp<19)direction=0;
    else if(tmp<39) direction=1;
    else if(tmp<59) direction=2;
    else if(tmp<79) direction=3;
    else  direction=4;
    int dy,dx;
    switch(direction){
    case 0: break;
    case 1:
        dy=y-speed;
        if(this->checkCrash(x,dy,map)){
            y-=speed;
        }
        break;
    case 2:
        dy=y+speed;
        if(this->checkCrash(x,dy,map)){
            y+=speed;
        }
        break;
    case 3:
        dx=x-speed;
        if(this->checkCrash(dx,y,map)){
            x-=speed;
        }
        break;
    case 4:
        dx=x+speed;
        if(this->checkCrash(dx,y,map)){
            x+=speed;
        }
        break;
    }
  }
    else {
        number_of_move++;
        double s=pow(p1.getX()-this->getX(),2)+pow(p1.getY()-this->getY(),2);
        directionX=(p1.getX()-this->getX())/pow(s,0.5);
        directionY=(p1.getY()-this->getY())/pow(s,0.5);
        int dx = int (x+speed*directionX);
        int dy = int(y+speed*directionY);
        double tx =directionX;
        double ty = directionY;

        if(tx>0){
            if(ty/tx>2.4142){
                x_of_gif=2;
                pix = rmonster[x_of_gif][y_of_gif];
            }
            else if(ty/tx<=2.4142&&ty/tx>0.4142){

                x_of_gif=3;
                pix = rmonster[x_of_gif][y_of_gif];

            }
            else if(ty/tx<=0.4142&&ty/tx>-0.4142){

                x_of_gif=6;
                pix = rmonster[x_of_gif][y_of_gif];

            }
            else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

               x_of_gif=9;
               pix = rmonster[x_of_gif][y_of_gif];

            }
            else if(ty/tx<-2.4142){

                x_of_gif=8;
                pix = rmonster[x_of_gif][y_of_gif];

            }

        }
        else if(tx==0){
            if(ty<0){

                x_of_gif=8;
                pix = rmonster[x_of_gif][y_of_gif];
            }else{

                x_of_gif=2;
                pix = rmonster[x_of_gif][y_of_gif];
            }

        }
        else if(tx<0){
            if(ty/tx>2.4142){

                x_of_gif=8;
                pix = rmonster[x_of_gif][y_of_gif];
            }
            else if(ty/tx<=2.4142&&ty/tx>0.4142){

                x_of_gif=7;
                pix = rmonster[x_of_gif][y_of_gif];

            }
            else if(ty/tx<=0.4142&&ty/tx>-0.4142){

              x_of_gif=4;
              pix = rmonster[x_of_gif][y_of_gif];
            }
            else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

               x_of_gif=1;
               pix = rmonster[x_of_gif][y_of_gif];

            }
            else if(ty/tx<-2.4142){

                x_of_gif=2;
                pix = rmonster[x_of_gif][y_of_gif];

            }
        }



        if(number_of_move>10&!ifAttack){
            switch(y_of_gif){
            case 1:
                y_of_gif = 2;
                pix = rmonster[x_of_gif][y_of_gif];
                number_of_move = 0;
                break;
            case 2:
                y_of_gif = 3;
                pix = rmonster[x_of_gif][y_of_gif];
                number_of_move = 0;
                break;
            case 3:
                y_of_gif = 1;
                pix = rmonster[x_of_gif][y_of_gif];
                number_of_move = 0;
                break;
            default:
                y_of_gif = 1;
                pix = rmonster[x_of_gif][y_of_gif];
                number_of_move = 0;
                break;
            }

        }

        if(checkCrash(dx,y,map)){
            x+=speed*directionX;

        }
        if(checkCrash(x,dy,map)){
            y+=speed*directionY;


   }
    }

}

void RemoteMonster::attackPlayer(Obj &obj)
{
    if(!ifStuporous){
    if(shootTime>=cdOfAttack){
       boxOfBullet[shootNumber].calDirection(x,y,obj.getX(),obj.getY());
       boxOfBullet[shootNumber].Init(x,y,0,attack,bulletWidth,bulletHeight);

       shootNumber++;
       shootTime=0;
    }
    else if(shootTime<cdOfAttack){
        shootTime++;
    }
    if(shootNumber>40){
        shootNumber=0;
    }
   }
}

void RemoteMonster::die()
{
    if(hp<=0){
    //hide the remoteMonster
    ifLive=0;
    propLost();
    init(0,0,1);
    }
}
