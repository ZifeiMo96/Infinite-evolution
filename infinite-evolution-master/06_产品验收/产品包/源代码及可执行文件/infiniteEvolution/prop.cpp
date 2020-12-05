#include "prop.h"
#include <Qtime>



Prop::Prop()
{

}

void Prop::init(double x, double y,int mod, int width, int height)
{
    ifGot = 1;
    this->x = x;
    this->y = y;
    this->width =width;
    this->height =height;
    ifLive = 1;
    QTime time;

    //qsrand(time.msec()+time.second()*1000);
    int tmp=qrand()%100;
    switch(mod){
    case 1:
        if(tmp<60){
            kind = 1;
        }else if(tmp<85){
            kind = 2;
        }else if(tmp<95){
            kind = 3;
        }else{
            int tmp2=qrand()%15;
            switch(tmp2){
            case 0:
                kind = 4;
                break;
            case 1:
                kind =5;
                break;
            case 2:
                kind =6;
                break;
            case 3:
                kind =7;
                break;
            case 4:
                kind =10;
                break;
            case 5:
                kind =11;
                break;
            case 6:
                kind =12;
                break;
            case 7:
                kind =13;
                break;
            case 8:
                kind =14;
                break;
            case 9:
                kind =15;
                break;
            case 10:
                kind =16;
                break;
            case 11:
                kind =17;
                break;
            case 12:
                kind =19;
                break;
            case 13:
                kind =21;
                break;
            case 14:
                kind =23;
                break;
            }
        }
        break;
    case 2:
        if(tmp<90){
            int tmp2=qrand()%15;
            switch(tmp2){
            case 0:
                kind = 4;
                break;
            case 1:
                kind =5;
                break;
            case 2:
                kind =6;
                break;
            case 3:
                kind =7;
                break;
            case 4:
                kind =10;
                break;
            case 5:
                kind =11;
                break;
            case 6:
                kind =12;
                break;
            case 7:
                kind =13;
                break;
            case 8:
                kind =14;
                break;
            case 9:
                kind =15;
                break;
            case 10:
                kind =16;
                break;
            case 11:
                kind =17;
                break;
            case 12:
                kind =19;
                break;
            case 13:
                kind =21;
                break;
            case 14:
                kind =23;
                break;
            }
        }else if(tmp<98){
            int tmp3=qrand()%4;
            switch(tmp3){
            case 0:
                kind =8;
                break;
            case 1:
                kind =9;
                break;
            case 2:
                kind =18;
                break;
            case 3:
                kind =20;
                break;
            }
        }else{
            kind = 22;
        }
        break;
    }
    switch(kind){
    case 1:
        pix.load(":/res/prop1");
        break;
    case 2:
        pix.load(":/res/prop2");
        break;
    case 3:
        pix.load(":/res/prop3");
        break;
    case 4:
        pix.load(":/res/prop4");
        break;
    case 5:
        pix.load(":/res/prop5");
        break;
    case 6:
        pix.load(":/res/prop6");
        break;
    case 7:
        pix.load(":/res/prop7");
        break;
    case 8:
        pix.load(":/res/prop8");
        break;
    case 9:
        pix.load(":/res/prop9");
        break;
    case 10:
        pix.load(":/res/prop10");
        break;
    case 11:
        pix.load(":/res/prop11");
        break;
    case 12:
        pix.load(":/res/prop12");
        break;
    case 13:
        pix.load(":/res/prop13");
        break;
    case 14:
        pix.load(":/res/prop14");
        break;
    case 15:
        pix.load(":/res/prop15");
        break;
    case 16:
        pix.load(":/res/prop16");
        break;
    case 17:
        pix.load(":/res/prop17");
        break;
    case 18:
        pix.load(":/res/prop18");
        break;
    case 19:
        pix.load(":/res/prop19");
        break;
    case 20:
        pix.load(":/res/prop20");
        break;
    case 21:
        pix.load(":/res/prop21");
        break;
    case 22:
        pix.load(":/res/prop22");
        break;
    case 23:
        pix.load(":/res/prop23");
        break;
    }

}






