#include "closeMonster.h"
#include<QtMath>
#include<QDebug>
#include"prop.h"
CloseMonster::CloseMonster()
{

}

void CloseMonster::init(double x, double y, int z)
{
    ifprop = 1;
    if(!ifInit){
        ifInit = 1;
        this->x = x;
        this->y=y;
        ifLive = 1;
        x_of_gif = 1;
        y_of_gif = 1;
        switch(z){
        case 1:
                cmonster[1][1].load(":/closemonst_1/第一关近程兵左下1");
                cmonster[1][2].load(":/closemonst_1/第一关近程兵左下2");
                cmonster[1][3].load(":/closemonst_1/第一关近程兵左下2");
                cmonster[1][4].load(":/closemonst_1/第一关近程兵左下3");
                cmonster[1][5].load(":/closemonst_1/第一关近程兵左下4");
                cmonster[1][6].load(":/closemonst_1/第一关近程兵左下5");
                cmonster[1][7].load(":/closemonst_1/第一关近程兵左下6");
                cmonster[2][1].load(":/closemonst_1/第一关近程兵下1");
                cmonster[2][2].load(":/closemonst_1/第一关近程兵下2");
                cmonster[2][3].load(":/closemonst_1/第一关近程兵下2");
                cmonster[2][4].load(":/closemonst_1/第一关近程兵下3");
                cmonster[2][5].load(":/closemonst_1/第一关近程兵下4");
                cmonster[2][6].load(":/closemonst_1/第一关近程兵下5");
                cmonster[2][7].load(":/closemonst_1/第一关近程兵下6");
                cmonster[3][1].load(":/closemonst_1/第一关近程兵右下1");
                cmonster[3][2].load(":/closemonst_1/第一关近程兵右下2");
                cmonster[3][3].load(":/closemonst_1/第一关近程兵右下2");
                cmonster[3][4].load(":/closemonst_1/第一关近程兵右下3");
                cmonster[3][5].load(":/closemonst_1/第一关近程兵右下4");
                cmonster[3][6].load(":/closemonst_1/第一关近程兵右下5");
                cmonster[3][7].load(":/closemonst_1/第一关近程兵右下6");
                cmonster[4][1].load(":/closemonst_1/第一关近程兵左1");
                cmonster[4][2].load(":/closemonst_1/第一关近程兵左2");
                cmonster[4][3].load(":/closemonst_1/第一关近程兵左2");
                cmonster[4][4].load(":/closemonst_1/第一关近程兵左3");
                cmonster[4][5].load(":/closemonst_1/第一关近程兵左4");
                cmonster[4][6].load(":/closemonst_1/第一关近程兵左5");
                cmonster[4][7].load(":/closemonst_1/第一关近程兵左6");
                cmonster[6][1].load(":/closemonst_1/第一关近程兵右1");
                cmonster[6][2].load(":/closemonst_1/第一关近程兵右2");
                cmonster[6][3].load(":/closemonst_1/第一关近程兵右2");
                cmonster[6][4].load(":/closemonst_1/第一关近程兵右3");
                cmonster[6][5].load(":/closemonst_1/第一关近程兵右4");
                cmonster[6][6].load(":/closemonst_1/第一关近程兵右5");
                cmonster[6][7].load(":/closemonst_1/第一关近程兵右6");
                cmonster[7][1].load(":/closemonst_1/第一关近程兵左上1");
                cmonster[7][2].load(":/closemonst_1/第一关近程兵左上2");
                cmonster[7][3].load(":/closemonst_1/第一关近程兵左上2");
                cmonster[7][4].load(":/closemonst_1/第一关近程兵左上3");
                cmonster[7][5].load(":/closemonst_1/第一关近程兵左上4");
                cmonster[7][6].load(":/closemonst_1/第一关近程兵左上5");
                cmonster[7][7].load(":/closemonst_1/第一关近程兵左上6");
                cmonster[8][1].load(":/closemonst_1/第一关近程兵上1");
                cmonster[8][2].load(":/closemonst_1/第一关近程兵上2");
                cmonster[8][3].load(":/closemonst_1/第一关近程兵上2");
                cmonster[8][4].load(":/closemonst_1/第一关近程兵上3");
                cmonster[8][5].load(":/closemonst_1/第一关近程兵上4");
                cmonster[8][6].load(":/closemonst_1/第一关近程兵上5");
                cmonster[8][7].load(":/closemonst_1/第一关近程兵上6");
                cmonster[9][1].load(":/closemonst_1/第一关近程兵右上1");
                cmonster[9][2].load(":/closemonst_1/第一关近程兵右上2");
                cmonster[9][3].load(":/closemonst_1/第一关近程兵右上2");
                cmonster[9][4].load(":/closemonst_1/第一关近程兵右上3");
                cmonster[9][5].load(":/closemonst_1/第一关近程兵右上4");
                cmonster[9][6].load(":/closemonst_1/第一关近程兵右上5");
                cmonster[9][7].load(":/closemonst_1/第一关近程兵右上6");
                attack = 10;
                hp = 40;
                hpMax=40;
                cdOfAttack = 45;
                width  =25;
                height = 25;
                x_of_pix= 9;
                y_of_pix= 6;
                width_of_pix = 40;
                height_of_pix = 34;
                speed = 3;
                attackRange = 30;
                pix = cmonster[x_of_gif][y_of_gif];
                break;
            case 2:
                cmonster[1][1].load(":/closemonster_2/向左下1");
                cmonster[1][2].load(":/closemonster_2/向左下2");
                cmonster[1][3].load(":/closemonster_2/向左下3");
                cmonster[1][4].load(":/closemonster_2/向左下3");
                cmonster[1][5].load(":/closemonster_2/向左下3");
                cmonster[1][6].load(":/closemonster_2/向左下3");
                cmonster[1][7].load(":/closemonster_2/向左下3");
                cmonster[2][1].load(":/closemonster_2/向下1");
                cmonster[2][2].load(":/closemonster_2/向下2");
                cmonster[2][3].load(":/closemonster_2/向下3");
                cmonster[2][4].load(":/closemonster_2/向下3");
                cmonster[2][5].load(":/closemonster_2/向下3");
                cmonster[2][6].load(":/closemonster_2/向下3");
                cmonster[2][7].load(":/closemonster_2/向下3");
                cmonster[3][1].load(":/closemonster_2/向右下1");
                cmonster[3][2].load(":/closemonster_2/向右下2");
                cmonster[3][3].load(":/closemonster_2/向右下3");
                cmonster[3][4].load(":/closemonster_2/向右下3");
                cmonster[3][5].load(":/closemonster_2/向右下3");
                cmonster[3][6].load(":/closemonster_2/向右下3");
                cmonster[3][7].load(":/closemonster_2/向右下3");
                cmonster[4][1].load(":/closemonster_2/向左1");
                cmonster[4][2].load(":/closemonster_2/向左2");
                cmonster[4][3].load(":/closemonster_2/向左3");
                cmonster[4][4].load(":/closemonster_2/向左3");
                cmonster[4][5].load(":/closemonster_2/向左3");
                cmonster[4][6].load(":/closemonster_2/向左3");
                cmonster[4][7].load(":/closemonster_2/向左3");
                cmonster[6][1].load(":/closemonster_2/向右1");
                cmonster[6][2].load(":/closemonster_2/向右2");
                cmonster[6][3].load(":/closemonster_2/向右3");
                cmonster[6][4].load(":/closemonster_2/向右3");
                cmonster[6][5].load(":/closemonster_2/向右3");
                cmonster[6][6].load(":/closemonster_2/向右3");
                cmonster[6][7].load(":/closemonster_2/向右3");
                cmonster[7][1].load(":/closemonster_2/向左上1");
                cmonster[7][2].load(":/closemonster_2/向左上2");
                cmonster[7][3].load(":/closemonster_2/向左上3");
                cmonster[7][4].load(":/closemonster_2/向左上3");
                cmonster[7][5].load(":/closemonster_2/向左上3");
                cmonster[7][6].load(":/closemonster_2/向左上3");
                cmonster[7][7].load(":/closemonster_2/向左上3");
                cmonster[8][1].load(":/closemonster_2/向上1");
                cmonster[8][2].load(":/closemonster_2/向上2");
                cmonster[8][3].load(":/closemonster_2/向上3");
                cmonster[8][4].load(":/closemonster_2/向上3");
                cmonster[8][5].load(":/closemonster_2/向上3");
                cmonster[8][6].load(":/closemonster_2/向上3");
                cmonster[8][7].load(":/closemonster_2/向上3");
                cmonster[9][1].load(":/closemonster_2/向右上1");
                cmonster[9][2].load(":/closemonster_2/向右上2");
                cmonster[9][3].load(":/closemonster_2/向右上3");
                cmonster[9][4].load(":/closemonster_2/向右上3");
                cmonster[9][5].load(":/closemonster_2/向右上3");
                cmonster[9][6].load(":/closemonster_2/向右上3");
                cmonster[9][7].load(":/closemonster_2/向右上3");
                attack = 15;
                hp = 80;
                hpMax=80;
                attackRange = 30;
                cdOfAttack = 45;
                width_of_pix = 26;
                height_of_pix = 26;
                width  =26;
                height = 26;
                speed = 4;
                pix = cmonster[x_of_gif][y_of_gif];
                break;
            case 3:
                cmonster[1][1].load(":/closemonster_3/第三关近程向左下1");
                cmonster[1][2].load(":/closemonster_3/第三关近程向左下2");
                cmonster[1][3].load(":/closemonster_3/第三关近程向左下3");
                cmonster[1][4].load(":/closemonster_3/第三关近程左下攻击1");
                cmonster[1][5].load(":/closemonster_3/第三关近程左下攻击1");
                cmonster[1][6].load(":/closemonster_3/第三关近程左下攻击2");
                cmonster[1][7].load(":/closemonster_3/第三关近程左下攻击2");
                cmonster[2][1].load(":/closemonster_3/第三关近程向下1");
                cmonster[2][2].load(":/closemonster_3/第三关近程向下2");
                cmonster[2][3].load(":/closemonster_3/第三关近程向下3");
                cmonster[2][4].load(":/closemonster_3/第三关近程下攻击1");
                cmonster[2][5].load(":/closemonster_3/第三关近程下攻击1");
                cmonster[2][6].load(":/closemonster_3/第三关近程下攻击2");
                cmonster[2][7].load(":/closemonster_3/第三关近程下攻击2");
                cmonster[3][1].load(":/closemonster_3/第三关近程向右下1");
                cmonster[3][2].load(":/closemonster_3/第三关近程向右下2");
                cmonster[3][3].load(":/closemonster_3/第三关近程向右下3");
                cmonster[3][4].load(":/closemonster_3/第三关近程右下攻击1");
                cmonster[3][5].load(":/closemonster_3/第三关近程右下攻击1");
                cmonster[3][6].load(":/closemonster_3/第三关近程右下攻击2");
                cmonster[3][7].load(":/closemonster_3/第三关近程右下攻击2");
                cmonster[4][1].load(":/closemonster_3/第三关近程向左1");
                cmonster[4][2].load(":/closemonster_3/第三关近程向左2");
                cmonster[4][3].load(":/closemonster_3/第三关近程向左3");
                cmonster[4][4].load(":/closemonster_3/第三关近程左攻击1");
                cmonster[4][5].load(":/closemonster_3/第三关近程左攻击1");
                cmonster[4][6].load(":/closemonster_3/第三关近程左攻击2");
                cmonster[4][7].load(":/closemonster_3/第三关近程左攻击2");
                cmonster[6][1].load(":/closemonster_3/第三关近程向右1");
                cmonster[6][2].load(":/closemonster_3/第三关近程向右2");
                cmonster[6][3].load(":/closemonster_3/第三关近程向右3");
                cmonster[6][4].load(":/closemonster_3/第三关近程右攻击1");
                cmonster[6][5].load(":/closemonster_3/第三关近程右攻击1");
                cmonster[6][6].load(":/closemonster_3/第三关近程右攻击2");
                cmonster[6][7].load(":/closemonster_3/第三关近程右攻击2");
                cmonster[7][1].load(":/closemonster_3/第三关近程向左上1");
                cmonster[7][2].load(":/closemonster_3/第三关近程向左上2");
                cmonster[7][3].load(":/closemonster_3/第三关近程向左上3");
                cmonster[7][4].load(":/closemonster_3/第三关近程左上攻击1");
                cmonster[7][5].load(":/closemonster_3/第三关近程左上攻击1");
                cmonster[7][6].load(":/closemonster_3/第三关近程左上攻击2");
                cmonster[7][7].load(":/closemonster_3/第三关近程左上攻击2");
                cmonster[8][1].load(":/closemonster_3/第三关近程向上1");
                cmonster[8][2].load(":/closemonster_3/第三关近程向上2");
                cmonster[8][3].load(":/closemonster_3/第三关近程向上3");
                cmonster[8][4].load(":/closemonster_3/第三关近程上攻击1");
                cmonster[8][5].load(":/closemonster_3/第三关近程上攻击1");
                cmonster[8][6].load(":/closemonster_3/第三关近程上攻击2");
                cmonster[8][7].load(":/closemonster_3/第三关近程上攻击2");
                cmonster[9][1].load(":/closemonster_3/第三关近程向右上1");
                cmonster[9][2].load(":/closemonster_3/第三关近程向右上2");
                cmonster[9][3].load(":/closemonster_3/第三关近程向右上3");
                cmonster[9][4].load(":/closemonster_3/第三关近程右上攻击1");
                cmonster[9][5].load(":/closemonster_3/第三关近程右上攻击1");
                cmonster[9][6].load(":/closemonster_3/第三关近程右上攻击2");
                cmonster[9][7].load(":/closemonster_3/第三关近程右上攻击2");
                attack = 20;
                hp = 120;
                hpMax=120;
                cdOfAttack = 45;
                width  =22;
                height = 32;
                x_of_pix= 12;
                y_of_pix= 6;
                attackRange =35;
                width_of_pix = 48;
                height_of_pix = 48;
                speed = 2.5;
                pix = cmonster[x_of_gif][y_of_gif];
                break;
            case 4:
                cmonster[1][1].load(":/closemonster_4/第四关近程_06");
                cmonster[1][2].load(":/closemonster_4/第四关近程_14");
                cmonster[1][3].load(":/closemonster_4/第四关近程_22");
                cmonster[1][4].load(":/closemonster_4/第四关近程_30");
                cmonster[1][5].load(":/closemonster_4/第四关近程_38");
                cmonster[1][6].load(":/closemonster_4/第四关近程_38");
                cmonster[1][7].load(":/closemonster_4/第四关近程_46");
                cmonster[2][1].load(":/closemonster_4/第四关近程_07");
                cmonster[2][2].load(":/closemonster_4/第四关近程_15");
                cmonster[2][3].load(":/closemonster_4/第四关近程_23");
                cmonster[2][4].load(":/closemonster_4/第四关近程_31");
                cmonster[2][5].load(":/closemonster_4/第四关近程_39");
                cmonster[2][6].load(":/closemonster_4/第四关近程_39");
                cmonster[2][7].load(":/closemonster_4/第四关近程_47");
                cmonster[3][1].load(":/closemonster_4/第四关近程_08");
                cmonster[3][2].load(":/closemonster_4/第四关近程_16");
                cmonster[3][3].load(":/closemonster_4/第四关近程_24");
                cmonster[3][4].load(":/closemonster_4/第四关近程_32");
                cmonster[3][5].load(":/closemonster_4/第四关近程_40");
                cmonster[3][6].load(":/closemonster_4/第四关近程_40");
                cmonster[3][7].load(":/closemonster_4/第四关近程_48");
                cmonster[4][1].load(":/closemonster_4/第四关近程_05");
                cmonster[4][2].load(":/closemonster_4/第四关近程_13");
                cmonster[4][3].load(":/closemonster_4/第四关近程_21");
                cmonster[4][4].load(":/closemonster_4/第四关近程_29");
                cmonster[4][5].load(":/closemonster_4/第四关近程_37");
                cmonster[4][6].load(":/closemonster_4/第四关近程_37");
                cmonster[4][7].load(":/closemonster_4/第四关近程_45");
                cmonster[6][1].load(":/closemonster_4/第四关近程_01");
                cmonster[6][2].load(":/closemonster_4/第四关近程_09");
                cmonster[6][3].load(":/closemonster_4/第四关近程_17");
                cmonster[6][4].load(":/closemonster_4/第四关近程_25");
                cmonster[6][5].load(":/closemonster_4/第四关近程_33");
                cmonster[6][6].load(":/closemonster_4/第四关近程_33");
                cmonster[6][7].load(":/closemonster_4/第四关近程_41");
                cmonster[7][1].load(":/closemonster_4/第四关近程_04");
                cmonster[7][2].load(":/closemonster_4/第四关近程_12");
                cmonster[7][3].load(":/closemonster_4/第四关近程_20");
                cmonster[7][4].load(":/closemonster_4/第四关近程_28");
                cmonster[7][5].load(":/closemonster_4/第四关近程_36");
                cmonster[7][6].load(":/closemonster_4/第四关近程_36");
                cmonster[7][7].load(":/closemonster_4/第四关近程_44");
                cmonster[8][1].load(":/closemonster_4/第四关近程_03");
                cmonster[8][2].load(":/closemonster_4/第四关近程_11");
                cmonster[8][3].load(":/closemonster_4/第四关近程_19");
                cmonster[8][4].load(":/closemonster_4/第四关近程_27");
                cmonster[8][5].load(":/closemonster_4/第四关近程_35");
                cmonster[8][6].load(":/closemonster_4/第四关近程_35");
                cmonster[8][7].load(":/closemonster_4/第四关近程_43");
                cmonster[9][1].load(":/closemonster_4/第四关近程_02");
                cmonster[9][2].load(":/closemonster_4/第四关近程_10");
                cmonster[9][3].load(":/closemonster_4/第四关近程_18");
                cmonster[9][4].load(":/closemonster_4/第四关近程_26");
                cmonster[9][5].load(":/closemonster_4/第四关近程_34");
                cmonster[9][7].load(":/closemonster_4/第四关近程_34");
                cmonster[9][7].load(":/closemonster_4/第四关近程_42");
                attack = 30;
                hp = 200;
                hpMax=200;
                cdOfAttack = 45;
                width  =20;
                height = 25;
                x_of_pix= 9;
                y_of_pix= 6;
                width_of_pix = 40;
                height_of_pix = 40;
                attackRange = 30;
                speed = 3;
                pix = cmonster[x_of_gif][y_of_gif];
                break;
        }

    }

}

void CloseMonster::move(Player &p1,int map[12][16],Obj obj1[10],Obj obj2[10])
{
    if(!ifStuporous){
        double distance = (x-p1.getX())*(x-p1.getX())+(y-p1.getY())*(y-p1.getY());
        double r;
        r = pow(distance,0.5);

                if((r<=attackRange&&attackTime>=cdOfAttack)||ifAttack)
                {

                    attackTime=0;
                    ifAttack = 1;
                    if(ifAttack){
                        if(number_of_attack>3)
                            switch (y_of_gif){
                            case 4:
                                y_of_gif = 5;
                                pix = cmonster[x_of_gif][y_of_gif];
                                number_of_attack = 0;
                                break;
                            case 5:
                                y_of_gif = 6;
                                pix = cmonster[x_of_gif][y_of_gif];
                                number_of_attack = 0;
                                break;
                            case 6:
                                y_of_gif = 7;
                                pix = cmonster[x_of_gif][y_of_gif];
                                number_of_attack = 0;
                                break;
                            case 7:
                                y_of_gif = 1;
                                pix = cmonster[x_of_gif][y_of_gif];
                                number_of_attack = 0;
                                ifAttack = 0;
                                break;
                            default:
                                y_of_gif = 4;
                                pix = cmonster[x_of_gif][y_of_gif];
                                number_of_attack = 0;
                                attackPlayer(p1);
                                break;

                            }
                        else{
                            number_of_attack++;

                        }
                    }

                }
                else
                {
                    attackTime++;
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
                        }
                        else if(ty/tx<=2.4142&&ty/tx>0.4142){

                            x_of_gif=3;

                        }
                        else if(ty/tx<=0.4142&&ty/tx>-0.4142){

                            x_of_gif=6;

                        }
                        else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

                           x_of_gif=9;

                        }
                        else if(ty/tx<-2.4142){

                            x_of_gif=8;

                        }

                    }
                    else if(tx==0){
                        if(ty<0){

                            x_of_gif=8;
                        }else{

                            x_of_gif=2;
                        }

                    }
                    else if(tx<0){
                        if(ty/tx>2.4142){

                            x_of_gif=8;
                        }
                        else if(ty/tx<=2.4142&&ty/tx>0.4142){

                            x_of_gif=7;

                        }
                        else if(ty/tx<=0.4142&&ty/tx>-0.4142){

                          x_of_gif=4;
                        }
                        else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

                           x_of_gif=1;

                        }
                        else if(ty/tx<-2.4142){

                            x_of_gif=2;

                        }
                    }



                    if(number_of_move>10&!ifAttack){
                        switch(y_of_gif){
                        case 1:
                            y_of_gif = 2;
                            pix = cmonster[x_of_gif][y_of_gif];
                            number_of_move = 0;
                            break;
                        case 2:
                            y_of_gif = 3;
                            pix = cmonster[x_of_gif][y_of_gif];
                            number_of_move = 0;
                            break;
                        case 3:
                            y_of_gif = 1;
                            pix = cmonster[x_of_gif][y_of_gif];
                            number_of_move = 0;
                            break;
                        default:
                            y_of_gif = 1;
                            pix = cmonster[x_of_gif][y_of_gif];
                            number_of_move = 0;
                            break;
                        }

                    }
                    bool if_move_x = 1;
                    bool if_move_y = 1;
                    for(int i = 0;i<10;i++){
                        if(this->checkCrashWith(x+speed*directionX,y,obj1[i])){
                            if_move_x = 0;
                        }
                        if(this->checkCrashWith(x+speed*directionX,y,obj2[i])){
                            if_move_x = 0;
                        }
                    }
                    for(int i =0;i<10;i++){
                        if(this->checkCrashWith(x,y+speed*directionY,obj1[i])){
                             if_move_y = 0;
                        }
                        if(this->checkCrashWith(x,y+speed*directionY,obj2[i])){
                             if_move_y = 0;
                        }
                    }


                    if(checkCrash(dx,y,map)&&if_move_x){

                        x+=speed*directionX;

                    }
                    if(checkCrash(x,dy,map)&&if_move_y){
                        y+=speed*directionY;


               }
            }
        }
    }


void CloseMonster::attackPlayer(Obj &p2)
{
    p2.setHp(p2.getHp()-attack);
}

void CloseMonster::die()
{
    if(hp<=0){
    ifLive=0;
    propLost();
    init(320,280,0);
    }
}
