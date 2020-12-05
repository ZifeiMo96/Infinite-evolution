#include "map.h"

#include <QTime>
#include <QDebug>

#include <algorithm>

Map::Map(){
    QTime time;


        time = QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        //生成第一层地图
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++){
                        floor_1[i][j] = (qrand()%20)+1;
                    }
                }
                //boss
                int randboss1=qrand()%36;
                bossx1=randboss1/6;
                bossy1=randboss1-6*randboss1/6;
                floor_1[bossx1][bossy1]=21;

                //shop
                int randshop1=randboss1-15>=0?randboss1-15:21+randboss1;
                shopx1=randshop1/6;
                shopy1=randshop1-6*randshop1/6;
                floor_1[shopx1][shopy1]=22;
                //prop
                int randprop1=randboss1-5>=0?randboss1-5:31+randboss1;
                propRoomx1=randprop1/6;
                propRoomy1=randprop1-6*randprop1/6;
                floor_1[propRoomx1][propRoomy1]=23;
                //第二层
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++){
                        floor_2[i][j] = (qrand()%20)+1;
                    }
                }
                //boss
                int randboss2=qrand()%36;
                bossx2=randboss2/6;
                bossy2=randboss2-6*randboss2/6;
                floor_2[bossx2][bossy2]=21;
                //shop
                int randshop2=randboss2-15>=0?randboss2-15:21+randboss2;
                shopx2=randshop2/6;
                shopy2=randshop2-6*randshop2/6;
                floor_2[shopx2][shopy2]=22;
                //prop
                int randprop2=randboss2-5>=0?randboss2-5:31+randboss2;
                propRoomx2=randprop2/6;
                propRoomy2=randprop2-6*randprop2/6;
                floor_2[propRoomx2][propRoomy2]=23;
                //第三层
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++){
                        floor_3[i][j] = (qrand()%20)+1;
                    }
                }
                //boss
                int randboss3=qrand()%36;
                bossx3=randboss3/6;
                bossy3=randboss3-6*randboss3/6;
                floor_3[bossx3][bossy3]=21;
                //shop
                int randshop3=randboss3-15>=0?randboss3-15:21+randboss3;
                shopx3=randshop3/6;
                shopy3=randshop3-6*randshop3/6;
                floor_3[shopx3][shopy3]=22;
                //prop
                int randprop3=randboss3-5>=0?randboss3-5:31+randboss3;
                propRoomx3=randprop3/6;
                propRoomy3=randprop3-6*randprop3/6;
                floor_3[propRoomx3][propRoomy3]=23;
                //第四层
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++){
                        floor_4[i][j] = (qrand()%20)+1;
                    }
                }
                //boss
                int randboss4=qrand()%36;
                bossx4=randboss4/6;
                bossy4=randboss4-6*randboss4/6;
                floor_4[bossx4][bossy4]=21;
                //shop
                int randshop4=randboss4-15>=0?randboss4-15:21+randboss4;
                shopx4=randshop4/6;
                shopy4=randshop4-6*randshop4/6;
                floor_4[shopx4][shopy4]=22;
                //prop
                int randprop4=randboss4-5>=0?randboss4-5:31+randboss4;
                propRoomx4=randprop4/6;
                propRoomy4=randprop4-6*randprop4/6;
                floor_4[propRoomx4][propRoomy4]=23;


        bossx1 = 1,bossy1 = 2;
        shopx1 = 2,shopy1 = 1;
        propRoomx1 = 3;propRoomy1 =2;

        floor_1[bossx1][bossy1]=21;
        floor_1[shopx1][shopy1]=22;
        floor_1[propRoomx1][propRoomy1] = 23;


        box_of_prop[0][propRoomx1][propRoomy1][1].init(280,240,2);
        box_of_prop[1][propRoomx2][propRoomy2][1].init(280,240,2);
        box_of_prop[2][propRoomx3][propRoomy3][1].init(280,240,2);
        box_of_prop[3][propRoomx4][propRoomy4][1].init(280,240,2);


    z_of_map = 1;
    x_of_map = 2;
    y_of_map = 2;
    getRoom(this_room);
    setMonster();


}

void Map::changeFloor(int x, int y,Player &p1)
{
    switch(z_of_map){
    case 1:
        if(x_of_map==bossx1&&y_of_map == bossy1){
            if(280<x&&x<320&&y>240&&y<280){
                for(int i = 0;i<6;i++){
                    for(int j= 0;j<6;j++){
                        ifFinish[i][j] = 0;
                        record_of_floor[i][j]= 0;
                    }
                }
                finishfloor = 0;
                z_of_map = 2;
                x_of_map = 2;
                y_of_map = 2;
                p1.setHp(p1.getHpMax());

            }
        }
        break;
    case 2:
        if(x_of_map==bossx2&&y_of_map == bossy2){
            if(280<x&&x<320&&y>240&&y<280){
                for(int i = 0;i<6;i++){
                    for(int j= 0;j<6;j++){
                        ifFinish[i][j] = 0;
                        record_of_floor[i][j] = 0;
                    }
                }
                finishfloor = 0;
                z_of_map = 3;
                x_of_map = 2;
                y_of_map = 2;
                p1.setHp(p1.getHpMax());


            }
        }
        break;
    case 3:
        if(x_of_map==bossx3&&y_of_map == bossy3){
            if(280<x&&x<320&&y>240&&y<280){
                for(int i = 0;i<6;i++){
                    for(int j= 0;j<6;j++){
                        ifFinish[i][j] = 0;
                        record_of_floor[i][j]= 0;
                    }
                }
                finishfloor = 0;
                z_of_map = 4;
                x_of_map = 2;
                y_of_map = 2;
                p1.setHp(p1.getHpMax());


            }
        }
        break;
    case 4:
        if(x_of_map==bossx4&&y_of_map == bossy4){
            if(280<x&&x<320&&y>240&&y<280){
                for(int i = 0;i<6;i++){
                    for(int j= 0;j<6;j++){
                        ifFinish[i][j] = 0;
                        record_of_floor[i][j]= 0;
                    }
                }
                finishfloor = 0;
                z_of_map = 1;
                x_of_map = 2;
                y_of_map = 2;
                p1.setHp(p1.getHpMax());


            }
        }
        break;
    }


}

void Map::checkFinishFloor()
{
    bool i =1;
    for(int i = 0;i<6;i++){
        for(int j= 0;j<6;j++){
            if(ifFinish[i][j] = 0){
                i = 0;
            }
        }
    }
    finishfloor = i;
}

bool Map::checkroom()
{
    switch(z_of_map){
    case 1:
        if(x_of_map==bossx1&&y_of_map==bossy1){
            return 1;
        }else{
            return 0;
        }
        break;
    case 2:
        if(x_of_map==bossx2&&y_of_map==bossy2){
            return 1;
        }else{
            return 0;
        }
        break;
    case 3:
        if(x_of_map==bossx3&&y_of_map==bossy3){
            return 1;
        }else{
            return 0;
        }
        break;
    case 4:
        if(x_of_map==bossx4&&y_of_map==bossy4){
            return 1;
        }else{
            return 0;
        }
        break;
    }
}

void Map::checkFinish(bool b){


    ifFinish[x_of_map][y_of_map] = b;

}




void Map::getRoom(int this_room[12][16])
{
    int n = z_of_map;
    int x = x_of_map;
    int y = y_of_map;
    if(n == 1){
        switch(floor_1[x][y]){
        case 1:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room1[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room2[i][j];
                }
            }
            break;
        case 3:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room3[i][j];
                }
            }
            break;
        case 4:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room4[i][j];
                }
            }
            break;
        case 5:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room5[i][j];
                }
            }
            break;

        case 6:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room6[i][j];
                }
            }
            break;
        case 7:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room7[i][j];
                }
            }
            break;
        case 8:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room8[i][j];
                }
            }
            break;
        case 9:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room9[i][j];
                }
            }
            break;
        case 10:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room10[i][j];
                }
            }
            break;
        case 11:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room11[i][j];
                }
            }
            break;
        case 12:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room12[i][j];
                }
            }
            break;
        case 13:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room13[i][j];
                }
            }
            break;
        case 14:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room14[i][j];
                }
            }
            break;
        case 15:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room15[i][j];
                }
            }
            break;
        case 16:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room16[i][j];
                }
            }
            break;
        case 17:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room17[i][j];
                }
            }
            break;
        case 18:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room18[i][j];
                }
            }
            break;
        case 19:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room19[i][j];
                }
            }
            break;
        case 20:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room20[i][j];
                }
            }
            break;
        case 21:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room21[i][j];
                }
            }
            break;
        case 22:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room22[i][j];
                }
            }
            break;
        case 23:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room23[i][j];
                }
            }
            break;
        }
    }
    else if(n == 2){
        switch(floor_2[x][y]){
        case 1:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room1[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room2[i][j];
                }
            }
            break;
        case 3:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room3[i][j];
                }
            }
            break;
        case 4:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room4[i][j];
                }
            }
            break;
        case 5:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room5[i][j];
                }
            }
            break;

        case 6:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room6[i][j];
                }
            }
            break;
        case 7:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room7[i][j];
                }
            }
            break;
        case 8:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room8[i][j];
                }
            }
            break;
        case 9:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room9[i][j];
                }
            }
            break;
        case 10:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room10[i][j];
                }
            }
            break;
        case 11:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room11[i][j];
                }
            }
            break;
        case 12:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room12[i][j];
                }
            }
            break;
        case 13:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room13[i][j];
                }
            }
            break;
        case 14:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room14[i][j];
                }
            }
            break;
        case 15:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room15[i][j];
                }
            }
            break;
        case 16:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room16[i][j];
                }
            }
            break;
        case 17:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room17[i][j];
                }
            }
            break;
        case 18:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room18[i][j];
                }
            }
            break;
        case 19:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room19[i][j];
                }
            }
            break;
        case 20:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room20[i][j];
                }
            }
            break;
        case 21:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room21[i][j];
                }
            }
            break;
        case 22:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room22[i][j];
                }
            }
            break;
        case 23:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room23[i][j];
                }
            }
            break;
        }

    }
    else if(n == 3 ){
        switch(floor_3[x][y]){
        case 1:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room1[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room2[i][j];
                }
            }
            break;
        case 3:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room3[i][j];
                }
            }
            break;
        case 4:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room4[i][j];
                }
            }
            break;
        case 5:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room5[i][j];
                }
            }
            break;

        case 6:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room6[i][j];
                }
            }
            break;
        case 7:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room7[i][j];
                }
            }
            break;
        case 8:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room8[i][j];
                }
            }
            break;
        case 9:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room9[i][j];
                }
            }
            break;
        case 10:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room10[i][j];
                }
            }
            break;
        case 11:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room11[i][j];
                }
            }
            break;
        case 12:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room12[i][j];
                }
            }
            break;
        case 13:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room13[i][j];
                }
            }
            break;
        case 14:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room14[i][j];
                }
            }
            break;
        case 15:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room15[i][j];
                }
            }
            break;
        case 16:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room16[i][j];
                }
            }
            break;
        case 17:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room17[i][j];
                }
            }
            break;
        case 18:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room18[i][j];
                }
            }
            break;
        case 19:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room19[i][j];
                }
            }
            break;
        case 20:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room20[i][j];
                }
            }
            break;
        case 21:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room21[i][j];
                }
            }
            break;
        case 22:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room22[i][j];
                }
            }
            break;
        case 23:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room23[i][j];
                }
            }
            break;
        }

    }
    else if(n == 4){
        switch(floor_4[x][y]){
        case 1:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room1[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room2[i][j];
                }
            }
            break;
        case 3:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room3[i][j];
                }
            }
            break;
        case 4:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room4[i][j];
                }
            }
            break;
        case 5:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room5[i][j];
                }
            }
            break;

        case 6:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room6[i][j];
                }
            }
            break;
        case 7:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room7[i][j];
                }
            }
            break;
        case 8:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room8[i][j];
                }
            }
            break;
        case 9:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room9[i][j];
                }
            }
            break;
        case 10:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room10[i][j];
                }
            }
            break;
        case 11:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room11[i][j];
                }
            }
            break;
        case 12:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room12[i][j];
                }
            }
            break;
        case 13:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room13[i][j];
                }
            }
            break;
        case 14:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room14[i][j];
                }
            }
            break;
        case 15:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room15[i][j];
                }
            }
            break;
        case 16:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room16[i][j];
                }
            }
            break;
        case 17:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room17[i][j];
                }
            }
            break;
        case 18:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room18[i][j];
                }
            }
            break;
        case 19:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room19[i][j];
                }
            }
            break;
        case 20:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room20[i][j];
                }
            }
            break;
        case 21:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room21[i][j];
                }
            }
            break;
        case 22:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room22[i][j];
                }
            }
            break;
        case 23:
            for(int i = 0;i<12;i++){
                for(int j= 0;j<16;j++){
                    this_room[i][j]=room23[i][j];
                }
            }
            break;
        }

    }

}

int Map::get_z_of_map()
{
    return z_of_map;
}

int Map::get_x_of_map()
{
    return x_of_map;
}

int Map::get_y_of_map()
{
    return y_of_map;
}

void Map::set_z_of_map(int i)
{
    z_of_map=i;
}

void Map::set_x_of_map(int i)
{
    x_of_map = i;
}

void Map::set_y_of_map(int i)
{
    y_of_map = i;
}

void Map::cleanRecord()
{
    for(int i =0;i<6;i++){
        for(int j =0;j<6;j++){
            record_of_floor[i][j]=0;
        }
    }
}

void Map::setRecordOfFloor(int i, int j, bool b)
{
    record_of_floor[i][j]=b;
}

bool Map::getRecordOfFloor(int i, int j)
{
    return record_of_floor[i][j];
}

void Map::setMonster()
{
    for(int z =0;z<4;z++){
        for(int x = 0;x<6;x++){
            for(int y = 0;y<6;y++){
                switch(z){
                case 0:
                    switch(floor_1[x][y]){
                    case 1:
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,1);
                        box_of_cmonster[z][x][y][1].init(10*40,3*40,1);
                        box_of_cmonster[z][x][y][2].init(3*40,7*40,1);
                        box_of_cmonster[z][x][y][3].init(12*40,7*40,1);
                        box_of_cmonster[z][x][y][4].init(5*40,9*40,1);
                        box_of_cmonster[z][x][y][5].init(10*40,9*40,1);
                        continue;
                    case 2:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(14*40,2*40,1);
                        box_of_rmonster[z][x][y][2].init(1*40,10*40,1);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,1);
                        continue;
                    case 3:
                        box_of_cmonster[z][x][y][0].init(9*40,2*40,1);
                        box_of_cmonster[z][x][y][1].init(11*40,4*40,1);
                        box_of_cmonster[z][x][y][2].init(11*40,8*40,1);
                        box_of_cmonster[z][x][y][3].init(13*40,8*40,1);
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,1);
                        continue;
                    case 4:
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_cmonster[z][x][y][1].init(12*40,2*40,1);
                        box_of_cmonster[z][x][y][2].init(7*40,4*40,1);
                        box_of_cmonster[z][x][y][3].init(14*40,6*40,1);
                        box_of_cmonster[z][x][y][4].init(9*40,8*40,1);
                        box_of_cmonster[z][x][y][5].init(3*40,10*40,1);
                        continue;
                    case 5:
                        box_of_cmonster[z][x][y][0].init(14*40,2*40,1);
                        box_of_cmonster[z][x][y][1].init(12*40,5*40,1);
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,1);
                        box_of_rmonster[z][x][y][2].init(11*40,7*40,1);
                        continue;
                    case 6:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(14*40,4*40,1);
                        box_of_rmonster[z][x][y][2].init(14*40,10*40,1);
                        box_of_cmonster[z][x][y][0].init(4*40,8*40,1);
                        box_of_cmonster[z][x][y][1].init(14*40,8*40,1);
                        continue;
                    case 7:
                        box_of_cmonster[z][x][y][0].init(12*40,5*40,1);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(5*40,4*40,1);
                        box_of_rmonster[z][x][y][2].init(9*40,8*40,1);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,1);
                        continue;
                    case 8:
                        box_of_cmonster[z][x][y][0].init(1*40,10*40,1);
                        box_of_cmonster[z][x][y][1].init(4*40,3*40,1);
                        box_of_cmonster[z][x][y][2].init(12*40,3*40,1);
                        box_of_cmonster[z][x][y][3].init(11*40,5*40,1);
                        box_of_cmonster[z][x][y][4].init(10*40,10*40,1);
                        box_of_cmonster[z][x][y][5].init(13*40,9*40,1);
                        continue;
                    case 9:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,1);
                        box_of_cmonster[z][x][y][1].init(5*40,9*40,1);
                        box_of_cmonster[z][x][y][2].init(13*40,9*40,1);
                        box_of_rmonster[z][x][y][0].init(3*40,3*40,1);
                        box_of_rmonster[z][x][y][1].init(13*40,3*40,1);
                        box_of_rmonster[z][x][y][2].init(2*40,10*40,1);
                        continue;
                    case 10:
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(4*40,7*40,1);
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,1);
                        box_of_cmonster[z][x][y][1].init(8*40,4*40,1);
                        box_of_cmonster[z][x][y][2].init(5*40,9*40,1);
                        box_of_cmonster[z][x][y][3].init(8*40,9*40,1);
                        continue;
                    case 11:
                        box_of_rmonster[z][x][y][0].init(2*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,1);
                        box_of_rmonster[z][x][y][2].init(4*40,2*40,1);
                        box_of_rmonster[z][x][y][3].init(14*40,2*40,1);
                        box_of_rmonster[z][x][y][4].init(10*40,10*40,1);
                        box_of_rmonster[z][x][y][5].init(14*40,10*40,1);
                        continue;
                    case 12:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,1);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,1);
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_cmonster[z][x][y][1].init(4*40,10*40,1);
                        box_of_cmonster[z][x][y][2].init(10*40,2*40,1);
                        box_of_cmonster[z][x][y][3].init(10*40,8*40,1);
                        continue;
                    case 13:
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,1);
                        box_of_cmonster[z][x][y][1].init(10*40,4*40,1);
                        box_of_cmonster[z][x][y][2].init(4*40,10*40,1);
                        box_of_cmonster[z][x][y][3].init(12*40,4*40,1);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,1);
                        continue;
                    case 14:
                        box_of_rmonster[z][x][y][0].init(4*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(13*40,4*40,1);
                        box_of_rmonster[z][x][y][2].init(9*40,7*40,1);
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,1);
                        box_of_cmonster[z][x][y][1].init(14*40,9*40,1);
                        continue;
                    case 15:
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,1);
                        box_of_rmonster[z][x][y][1].init(12*40,8*40,1);
                        box_of_cmonster[z][x][y][0].init(13*40,2*40,1);
                        box_of_cmonster[z][x][y][1].init(2*40,6*40,1);
                        box_of_cmonster[z][x][y][2].init(11*40,10*40,1);
                        continue;
                    case 16:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,1);
                        box_of_cmonster[z][x][y][1].init(10*40,8*40,1);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,1);
                        box_of_rmonster[z][x][y][1].init(13*40,2*40,1);
                        box_of_rmonster[z][x][y][2].init(1*40,8*40,1);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,1);
                        continue;
                    case 17:
                        box_of_rmonster[z][x][y][0].init(1*40,3*40,1);
                        box_of_rmonster[z][x][y][1].init(3*40,9*40,1);
                        box_of_rmonster[z][x][y][2].init(5*40,3*40,1);
                        box_of_rmonster[z][x][y][3].init(10*40,9*40,1);
                        box_of_rmonster[z][x][y][4].init(12*40,3*40,1);
                        box_of_rmonster[z][x][y][5].init(14*40,9*40,1);
                        continue;
                    case 18:
                        box_of_rmonster[z][x][y][0].init(2*40,4*40,1);
                        box_of_rmonster[z][x][y][1].init(2*40,8*40,1);
                        box_of_cmonster[z][x][y][0].init(13*40,4*40,1);
                        box_of_cmonster[z][x][y][1].init(13*40,8*40,1);
                        continue;
                    case 19:
                        box_of_cmonster[z][x][y][0].init(2*40,2*40,1);
                        box_of_cmonster[z][x][y][1].init(13*40,4*40,1);
                        box_of_cmonster[z][x][y][2].init(2*40,8*40,1);
                        box_of_cmonster[z][x][y][3].init(13*40,10*40,1);
                        box_of_rmonster[z][x][y][0].init(2*40,10*40,1);
                        box_of_rmonster[z][x][y][1].init(13*40,8*40,1);
                        continue;
                    case 20:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,1);
                        box_of_rmonster[z][x][y][1].init(12*40,2*40,1);
                        box_of_rmonster[z][x][y][2].init(3*40,10*40,1);
                        box_of_rmonster[z][x][y][3].init(14*40,8*40,1);
                        box_of_cmonster[z][x][y][0].init(3*40,4*40,1);
                        box_of_cmonster[z][x][y][1].init(12*40,7*40,1);
                        continue;
                    case 21:
                        continue;
                    case 22:
                        continue;
                    case 23:
                        continue;
                    }
                case 1:
                    switch(floor_2[x][y]){
                    case 1:
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,2);
                        box_of_cmonster[z][x][y][1].init(10*40,3*40,2);
                        box_of_cmonster[z][x][y][2].init(3*40,7*40,2);
                        box_of_cmonster[z][x][y][3].init(12*40,7*40,2);
                        box_of_cmonster[z][x][y][4].init(5*40,9*40,2);
                        box_of_cmonster[z][x][y][5].init(10*40,9*40,2);
                        continue;
                    case 2:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(14*40,2*40,2);
                        box_of_rmonster[z][x][y][2].init(1*40,10*40,2);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,2);
                        continue;
                    case 3:
                        box_of_cmonster[z][x][y][0].init(9*40,2*40,2);
                        box_of_cmonster[z][x][y][1].init(11*40,4*40,2);
                        box_of_cmonster[z][x][y][2].init(11*40,8*40,2);
                        box_of_cmonster[z][x][y][3].init(13*40,8*40,2);
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,2);
                        continue;
                    case 4:
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_cmonster[z][x][y][1].init(12*40,2*40,2);
                        box_of_cmonster[z][x][y][2].init(7*40,4*40,2);
                        box_of_cmonster[z][x][y][3].init(14*40,6*40,2);
                        box_of_cmonster[z][x][y][4].init(9*40,8*40,2);
                        box_of_cmonster[z][x][y][5].init(3*40,10*40,2);
                        continue;
                    case 5:
                        box_of_cmonster[z][x][y][0].init(14*40,2*40,2);
                        box_of_cmonster[z][x][y][1].init(12*40,5*40,2);
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,2);
                        box_of_rmonster[z][x][y][2].init(11*40,7*40,2);
                        continue;
                    case 6:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(14*40,4*40,2);
                        box_of_rmonster[z][x][y][2].init(14*40,10*40,2);
                        box_of_cmonster[z][x][y][0].init(4*40,8*40,2);
                        box_of_cmonster[z][x][y][1].init(14*40,8*40,2);
                        continue;
                    case 7:
                        box_of_cmonster[z][x][y][0].init(12*40,5*40,2);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(5*40,4*40,2);
                        box_of_rmonster[z][x][y][2].init(9*40,8*40,2);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,2);
                        continue;
                    case 8:
                        box_of_cmonster[z][x][y][0].init(1*40,10*40,2);
                        box_of_cmonster[z][x][y][1].init(4*40,3*40,2);
                        box_of_cmonster[z][x][y][2].init(12*40,3*40,2);
                        box_of_cmonster[z][x][y][3].init(11*40,5*40,2);
                        box_of_cmonster[z][x][y][4].init(10*40,10*40,2);
                        box_of_cmonster[z][x][y][5].init(13*40,9*40,2);
                        continue;
                    case 9:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,2);
                        box_of_cmonster[z][x][y][1].init(5*40,9*40,2);
                        box_of_cmonster[z][x][y][2].init(13*40,9*40,2);
                        box_of_rmonster[z][x][y][0].init(3*40,3*40,2);
                        box_of_rmonster[z][x][y][1].init(13*40,3*40,2);
                        box_of_rmonster[z][x][y][2].init(2*40,10*40,2);
                        continue;
                    case 10:
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(4*40,7*40,2);
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,2);
                        box_of_cmonster[z][x][y][1].init(8*40,4*40,2);
                        box_of_cmonster[z][x][y][2].init(5*40,9*40,2);
                        box_of_cmonster[z][x][y][3].init(8*40,9*40,2);
                        continue;
                    case 11:
                        box_of_rmonster[z][x][y][0].init(2*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,2);
                        box_of_rmonster[z][x][y][2].init(5*40,2*40,2);
                        box_of_rmonster[z][x][y][3].init(14*40,2*40,2);
                        box_of_rmonster[z][x][y][4].init(10*40,10*40,2);
                        box_of_rmonster[z][x][y][5].init(14*40,10*40,2);
                        continue;
                    case 12:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,2);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,2);
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_cmonster[z][x][y][1].init(4*40,10*40,2);
                        box_of_cmonster[z][x][y][2].init(10*40,2*40,2);
                        box_of_cmonster[z][x][y][3].init(10*40,8*40,2);
                        continue;
                    case 13:
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,2);
                        box_of_cmonster[z][x][y][1].init(10*40,4*40,2);
                        box_of_cmonster[z][x][y][2].init(4*40,10*40,2);
                        box_of_cmonster[z][x][y][3].init(12*40,4*40,2);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,2);
                        continue;
                    case 14:
                        box_of_rmonster[z][x][y][0].init(4*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(13*40,4*40,2);
                        box_of_rmonster[z][x][y][2].init(9*40,7*40,2);
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,2);
                        box_of_cmonster[z][x][y][1].init(14*40,9*40,2);
                        continue;
                    case 15:
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,2);
                        box_of_rmonster[z][x][y][1].init(12*40,8*40,2);
                        box_of_cmonster[z][x][y][0].init(13*40,2*40,2);
                        box_of_cmonster[z][x][y][1].init(2*40,6*40,2);
                        box_of_cmonster[z][x][y][2].init(11*40,10*40,2);
                        continue;
                    case 16:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,2);
                        box_of_cmonster[z][x][y][1].init(10*40,8*40,2);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,2);
                        box_of_rmonster[z][x][y][1].init(13*40,2*40,2);
                        box_of_rmonster[z][x][y][2].init(1*40,8*40,2);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,2);
                        continue;
                    case 17:
                        box_of_rmonster[z][x][y][0].init(1*40,3*40,2);
                        box_of_rmonster[z][x][y][1].init(3*40,9*40,2);
                        box_of_rmonster[z][x][y][2].init(5*40,3*40,2);
                        box_of_rmonster[z][x][y][3].init(10*40,9*40,2);
                        box_of_rmonster[z][x][y][4].init(12*40,3*40,2);
                        box_of_rmonster[z][x][y][5].init(14*40,9*40,2);
                        continue;
                    case 18:
                        box_of_rmonster[z][x][y][0].init(2*40,4*40,2);
                        box_of_rmonster[z][x][y][1].init(2*40,8*40,2);
                        box_of_cmonster[z][x][y][0].init(13*40,4*40,2);
                        box_of_cmonster[z][x][y][1].init(13*40,8*40,2);
                        continue;
                    case 19:
                        box_of_cmonster[z][x][y][0].init(2*40,2*40,2);
                        box_of_cmonster[z][x][y][1].init(13*40,4*40,2);
                        box_of_cmonster[z][x][y][2].init(2*40,8*40,2);
                        box_of_cmonster[z][x][y][3].init(13*40,10*40,2);
                        box_of_rmonster[z][x][y][0].init(2*40,10*40,2);
                        box_of_rmonster[z][x][y][1].init(13*40,8*40,2);
                        continue;
                    case 20:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,2);
                        box_of_rmonster[z][x][y][1].init(12*40,2*40,2);
                        box_of_rmonster[z][x][y][2].init(3*40,10*40,2);
                        box_of_rmonster[z][x][y][3].init(14*40,8*40,2);
                        box_of_cmonster[z][x][y][0].init(3*40,4*40,2);
                        box_of_cmonster[z][x][y][1].init(12*40,7*40,2);
                        continue;
                    case 21:
                        continue;
                    case 22:
                        continue;
                    case 23:
                        continue;
                    }
                case 2:
                    switch(floor_3[x][y]){
                    case 1:
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,3);
                        box_of_cmonster[z][x][y][1].init(10*40,3*40,3);
                        box_of_cmonster[z][x][y][2].init(3*40,7*40,3);
                        box_of_cmonster[z][x][y][3].init(12*40,7*40,3);
                        box_of_cmonster[z][x][y][4].init(5*40,9*40,3);
                        box_of_cmonster[z][x][y][5].init(10*40,9*40,3);
                        continue;
                    case 2:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(14*40,2*40,3);
                        box_of_rmonster[z][x][y][2].init(1*40,10*40,3);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,3);
                        continue;
                    case 3:
                        box_of_cmonster[z][x][y][0].init(9*40,2*40,3);
                        box_of_cmonster[z][x][y][1].init(11*40,4*40,3);
                        box_of_cmonster[z][x][y][2].init(11*40,8*40,3);
                        box_of_cmonster[z][x][y][3].init(13*40,8*40,3);
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,3);
                        continue;
                    case 4:
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_cmonster[z][x][y][1].init(12*40,2*40,3);
                        box_of_cmonster[z][x][y][2].init(7*40,4*40,3);
                        box_of_cmonster[z][x][y][3].init(14*40,6*40,3);
                        box_of_cmonster[z][x][y][4].init(9*40,8*40,3);
                        box_of_cmonster[z][x][y][5].init(3*40,10*40,3);
                        continue;
                    case 5:
                        box_of_cmonster[z][x][y][0].init(14*40,2*40,3);
                        box_of_cmonster[z][x][y][1].init(12*40,5*40,3);
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,3);
                        box_of_rmonster[z][x][y][2].init(11*40,7*40,3);
                        continue;
                    case 6:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(14*40,4*40,3);
                        box_of_rmonster[z][x][y][2].init(14*40,10*40,3);
                        box_of_cmonster[z][x][y][0].init(4*40,8*40,3);
                        box_of_cmonster[z][x][y][1].init(14*40,8*40,3);
                        continue;
                    case 7:
                        box_of_cmonster[z][x][y][0].init(12*40,5*40,3);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(5*40,4*40,3);
                        box_of_rmonster[z][x][y][2].init(9*40,8*40,3);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,3);
                        continue;
                    case 8:
                        box_of_cmonster[z][x][y][0].init(1*40,10*40,3);
                        box_of_cmonster[z][x][y][1].init(4*40,3*40,3);
                        box_of_cmonster[z][x][y][2].init(12*40,3*40,3);
                        box_of_cmonster[z][x][y][3].init(11*40,5*40,3);
                        box_of_cmonster[z][x][y][4].init(10*40,10*40,3);
                        box_of_cmonster[z][x][y][5].init(13*40,9*40,3);
                        continue;
                    case 9:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,3);
                        box_of_cmonster[z][x][y][1].init(5*40,9*40,3);
                        box_of_cmonster[z][x][y][2].init(13*40,9*40,3);
                        box_of_rmonster[z][x][y][0].init(3*40,3*40,3);
                        box_of_rmonster[z][x][y][1].init(13*40,3*40,3);
                        box_of_rmonster[z][x][y][2].init(2*40,10*40,3);
                        continue;
                    case 10:
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(4*40,7*40,3);
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,3);
                        box_of_cmonster[z][x][y][1].init(8*40,4*40,3);
                        box_of_cmonster[z][x][y][2].init(5*40,9*40,3);
                        box_of_cmonster[z][x][y][3].init(8*40,9*40,3);
                        continue;
                    case 11:
                        box_of_rmonster[z][x][y][0].init(2*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,3);
                        box_of_rmonster[z][x][y][2].init(4*40,2*40,3);
                        box_of_rmonster[z][x][y][3].init(14*40,2*40,3);
                        box_of_rmonster[z][x][y][4].init(10*40,10*40,3);
                        box_of_rmonster[z][x][y][5].init(14*40,10*40,3);
                        continue;
                    case 12:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,3);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,3);
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_cmonster[z][x][y][1].init(4*40,10*40,3);
                        box_of_cmonster[z][x][y][2].init(10*40,2*40,3);
                        box_of_cmonster[z][x][y][3].init(10*40,8*40,3);
                        continue;
                    case 13:
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,3);
                        box_of_cmonster[z][x][y][1].init(10*40,4*40,3);
                        box_of_cmonster[z][x][y][2].init(4*40,10*40,3);
                        box_of_cmonster[z][x][y][3].init(12*40,4*40,3);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,3);
                        continue;
                    case 14:
                        box_of_rmonster[z][x][y][0].init(4*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(13*40,4*40,3);
                        box_of_rmonster[z][x][y][2].init(9*40,7*40,3);
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,3);
                        box_of_cmonster[z][x][y][1].init(14*40,9*40,3);
                        continue;
                    case 15:
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,3);
                        box_of_rmonster[z][x][y][1].init(12*40,8*40,3);
                        box_of_cmonster[z][x][y][0].init(13*40,2*40,3);
                        box_of_cmonster[z][x][y][1].init(2*40,6*40,3);
                        box_of_cmonster[z][x][y][2].init(11*40,10*40,3);
                        continue;
                    case 16:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,3);
                        box_of_cmonster[z][x][y][1].init(10*40,8*40,3);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,3);
                        box_of_rmonster[z][x][y][1].init(13*40,2*40,3);
                        box_of_rmonster[z][x][y][2].init(1*40,8*40,3);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,3);
                        continue;
                    case 17:
                        box_of_rmonster[z][x][y][0].init(1*40,3*40,3);
                        box_of_rmonster[z][x][y][1].init(3*40,9*40,3);
                        box_of_rmonster[z][x][y][2].init(5*40,3*40,3);
                        box_of_rmonster[z][x][y][3].init(10*40,9*40,3);
                        box_of_rmonster[z][x][y][4].init(12*40,3*40,3);
                        box_of_rmonster[z][x][y][5].init(14*40,9*40,3);
                        continue;
                    case 18:
                        box_of_rmonster[z][x][y][0].init(2*40,4*40,3);
                        box_of_rmonster[z][x][y][1].init(2*40,8*40,3);
                        box_of_cmonster[z][x][y][0].init(13*40,4*40,3);
                        box_of_cmonster[z][x][y][1].init(13*40,8*40,3);
                        continue;
                    case 19:
                        box_of_cmonster[z][x][y][0].init(2*40,2*40,3);
                        box_of_cmonster[z][x][y][1].init(13*40,4*40,3);
                        box_of_cmonster[z][x][y][2].init(2*40,8*40,3);
                        box_of_cmonster[z][x][y][3].init(13*40,10*40,3);
                        box_of_rmonster[z][x][y][0].init(2*40,10*40,3);
                        box_of_rmonster[z][x][y][1].init(13*40,8*40,3);
                        continue;
                    case 20:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,3);
                        box_of_rmonster[z][x][y][1].init(12*40,2*40,3);
                        box_of_rmonster[z][x][y][2].init(3*40,10*40,3);
                        box_of_rmonster[z][x][y][3].init(14*40,8*40,3);
                        box_of_cmonster[z][x][y][0].init(3*40,4*40,3);
                        box_of_cmonster[z][x][y][1].init(12*40,7*40,3);
                        continue;
                    case 21:
                        continue;
                    case 22:
                        continue;
                    case 23:
                        continue;
                    }
                case 3:
                    switch(floor_4[x][y]){
                    case 1:
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,4);
                        box_of_cmonster[z][x][y][1].init(10*40,3*40,4);
                        box_of_cmonster[z][x][y][2].init(3*40,7*40,4);
                        box_of_cmonster[z][x][y][3].init(12*40,7*40,4);
                        box_of_cmonster[z][x][y][4].init(5*40,9*40,4);
                        box_of_cmonster[z][x][y][5].init(10*40,9*40,4);
                        continue;
                    case 2:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(14*40,2*40,4);
                        box_of_rmonster[z][x][y][2].init(1*40,10*40,4);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,4);
                        continue;
                    case 3:
                        box_of_cmonster[z][x][y][0].init(9*40,2*40,4);
                        box_of_cmonster[z][x][y][1].init(11*40,4*40,4);
                        box_of_cmonster[z][x][y][2].init(11*40,8*40,4);
                        box_of_cmonster[z][x][y][3].init(13*40,8*40,4);
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,4);
                        continue;
                    case 4:
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_cmonster[z][x][y][1].init(12*40,2*40,4);
                        box_of_cmonster[z][x][y][2].init(7*40,4*40,4);
                        box_of_cmonster[z][x][y][3].init(14*40,6*40,4);
                        box_of_cmonster[z][x][y][4].init(9*40,8*40,4);
                        box_of_cmonster[z][x][y][5].init(3*40,10*40,4);
                        continue;
                    case 5:
                        box_of_cmonster[z][x][y][0].init(14*40,2*40,4);
                        box_of_cmonster[z][x][y][1].init(12*40,5*40,4);
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,4);
                        box_of_rmonster[z][x][y][2].init(11*40,7*40,4);
                        continue;
                    case 6:
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(14*40,4*40,4);
                        box_of_rmonster[z][x][y][2].init(14*40,10*40,4);
                        box_of_cmonster[z][x][y][0].init(4*40,8*40,4);
                        box_of_cmonster[z][x][y][1].init(14*40,8*40,4);
                        continue;
                    case 7:
                        box_of_cmonster[z][x][y][0].init(12*40,5*40,4);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(5*40,4*40,4);
                        box_of_rmonster[z][x][y][2].init(9*40,8*40,4);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,4);
                        continue;
                    case 8:
                        box_of_cmonster[z][x][y][0].init(1*40,10*40,4);
                        box_of_cmonster[z][x][y][1].init(4*40,3*40,4);
                        box_of_cmonster[z][x][y][2].init(12*40,3*40,4);
                        box_of_cmonster[z][x][y][3].init(11*40,5*40,4);
                        box_of_cmonster[z][x][y][4].init(10*40,10*40,4);
                        box_of_cmonster[z][x][y][5].init(13*40,9*40,4);
                        continue;
                    case 9:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,4);
                        box_of_cmonster[z][x][y][1].init(5*40,9*40,4);
                        box_of_cmonster[z][x][y][2].init(13*40,9*40,4);
                        box_of_rmonster[z][x][y][0].init(3*40,3*40,4);
                        box_of_rmonster[z][x][y][1].init(13*40,3*40,4);
                        box_of_rmonster[z][x][y][2].init(2*40,10*40,4);
                        continue;
                    case 10:
                        box_of_rmonster[z][x][y][0].init(3*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(4*40,7*40,4);
                        box_of_cmonster[z][x][y][0].init(5*40,3*40,4);
                        box_of_cmonster[z][x][y][1].init(8*40,4*40,4);
                        box_of_cmonster[z][x][y][2].init(5*40,9*40,4);
                        box_of_cmonster[z][x][y][3].init(8*40,9*40,4);
                        continue;
                    case 11:
                        box_of_rmonster[z][x][y][0].init(2*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(1*40,10*40,4);
                        box_of_rmonster[z][x][y][2].init(6*40,2*40,4);
                        box_of_rmonster[z][x][y][3].init(14*40,2*40,4);
                        box_of_rmonster[z][x][y][4].init(10*40,10*40,4);
                        box_of_rmonster[z][x][y][5].init(14*40,10*40,4);
                        continue;
                    case 12:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,4);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,4);
                        box_of_cmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_cmonster[z][x][y][1].init(4*40,10*40,4);
                        box_of_cmonster[z][x][y][2].init(10*40,2*40,4);
                        box_of_cmonster[z][x][y][3].init(10*40,8*40,4);
                        continue;
                    case 13:
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,4);
                        box_of_cmonster[z][x][y][1].init(10*40,4*40,4);
                        box_of_cmonster[z][x][y][2].init(4*40,10*40,4);
                        box_of_cmonster[z][x][y][3].init(12*40,4*40,4);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(14*40,10*40,4);
                        continue;
                    case 14:
                        box_of_rmonster[z][x][y][0].init(4*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(13*40,4*40,4);
                        box_of_rmonster[z][x][y][2].init(9*40,7*40,4);
                        box_of_cmonster[z][x][y][0].init(3*40,8*40,4);
                        box_of_cmonster[z][x][y][1].init(14*40,9*40,4);
                        continue;
                    case 15:
                        box_of_rmonster[z][x][y][0].init(1*40,10*40,4);
                        box_of_rmonster[z][x][y][1].init(12*40,8*40,4);
                        box_of_cmonster[z][x][y][0].init(13*40,2*40,4);
                        box_of_cmonster[z][x][y][1].init(2*40,6*40,4);
                        box_of_cmonster[z][x][y][2].init(11*40,10*40,4);
                        continue;
                    case 16:
                        box_of_cmonster[z][x][y][0].init(5*40,4*40,4);
                        box_of_cmonster[z][x][y][1].init(10*40,8*40,4);
                        box_of_rmonster[z][x][y][0].init(1*40,2*40,4);
                        box_of_rmonster[z][x][y][1].init(13*40,2*40,4);
                        box_of_rmonster[z][x][y][2].init(1*40,8*40,4);
                        box_of_rmonster[z][x][y][3].init(14*40,10*40,4);
                        continue;
                    case 17:
                        box_of_rmonster[z][x][y][0].init(1*40,3*40,4);
                        box_of_rmonster[z][x][y][1].init(3*40,9*40,4);
                        box_of_rmonster[z][x][y][2].init(5*40,3*40,4);
                        box_of_rmonster[z][x][y][3].init(10*40,9*40,4);
                        box_of_rmonster[z][x][y][4].init(12*40,3*40,4);
                        box_of_rmonster[z][x][y][5].init(14*40,9*40,4);
                        continue;
                    case 18:
                        box_of_rmonster[z][x][y][0].init(2*40,4*40,4);
                        box_of_rmonster[z][x][y][1].init(2*40,8*40,4);
                        box_of_cmonster[z][x][y][0].init(13*40,4*40,4);
                        box_of_cmonster[z][x][y][1].init(13*40,8*40,4);
                        continue;
                    case 19:
                        box_of_cmonster[z][x][y][0].init(2*40,2*40,4);
                        box_of_cmonster[z][x][y][1].init(13*40,4*40,4);
                        box_of_cmonster[z][x][y][2].init(2*40,8*40,4);
                        box_of_cmonster[z][x][y][3].init(13*40,10*40,4);
                        box_of_rmonster[z][x][y][0].init(2*40,10*40,4);
                        box_of_rmonster[z][x][y][1].init(13*40,8*40,4);
                        continue;
                    case 20:
                        box_of_rmonster[z][x][y][0].init(1*40,4*40,4);
                        box_of_rmonster[z][x][y][1].init(12*40,2*40,4);
                        box_of_rmonster[z][x][y][2].init(3*40,10*40,4);
                        box_of_rmonster[z][x][y][3].init(14*40,8*40,4);
                        box_of_cmonster[z][x][y][0].init(3*40,4*40,4);
                        box_of_cmonster[z][x][y][1].init(12*40,7*40,4);
                        continue;
                    case 21:
                        continue;
                    case 22:
                        continue;
                    case 23:
                        continue;
                    }
                }
            }
        }
    }
}
/*
void Map::check_die_of_monster()
{
    for(int i =0;i<10;i++){
        box_of_cmonster[z_of_map][x_of_map][y_of_map][i].checkDie();

        box_of_rmonster[z_of_map][x_of_map][y_of_map][i].checkDie();
    }
}
*/
void Map::addProp(int x, int y, int kind)
{
    int number;
    for(int i = 0;i<20;i++){
        if(!box_of_prop[z_of_map-1][x_of_map][y_of_map][i].ifGot){
            number = i;
            break;
        }
    }
    x=(x/40)*40;
    y = (y/40)*40;
    box_of_prop[z_of_map-1][x_of_map][y_of_map][number].init(x,y,kind);
}

bool Map::checkShop()
{
    switch(z_of_map){
    case 1:
        if(x_of_map==shopx1&&y_of_map==shopy1){
            return 1;
        }else{
            return 0;
        }
        break;
    case 2:
        if(x_of_map==shopx2&&y_of_map==shopy2){
            return 1;
        }else{
            return 0;
        }
        break;
    case 3:
        if(x_of_map==shopx3&&y_of_map==shopy3){
            return 1;
        }else{
            return 0;
        }
        break;
    case 4:
        if(x_of_map==shopx4&&y_of_map==shopy4){
            return 1;
        }else{
            return 0;
        }
        break;
    }
}




int Map::room1[12][16]={
    //1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6
/*1*/   11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
/*2*/   3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
/*3*/   3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
/*4*/   3,0,0,11,12,0,0,0,0,0,0,11,12,0,0,4,
/*5*/   3,0,0,13,14,0,0,0,0,0,0,13,14,0,0,4,
/*6*/   3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
/*7*/   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*8*/   3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
/*9*/   3,0,0,11,12,0,0,0,0,0,0,11,12,0,0,4,
/*0*/   3,0,0,13,14,0,0,0,0,0,0,13,14,0,0,4,
/*1*/   3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
/*2*/   13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14
};

int Map::room2[12][16]={
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14
};

int Map::room3[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,11,1,1,1,12,0,0,0,0,0,4,
    3,5,5,5,5,14,0,0,0,4,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,
    3,0,0,0,0,3,0,0,0,4,0,0,0,0,0,4,
    3,0,0,0,0,13,5,5,5,14,0,0,4,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,4,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,

    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14
};

int Map::room4[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,1,1,1,1,1,1,1,1,1,1,1,12,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,
    3,5,5,5,5,5,5,5,5,5,5,5,5,14,0,4,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,11,1,1,1,1,1,1,1,1,1,1,1,1,4,
    3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,13,5,5,5,5,5,5,5,5,5,5,5,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};

int Map::room5[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,1,1,1,1,12,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,4,0,0,0,0,0,0,0,0,4,
    0,0,0,3,0,0,4,0,1,1,1,1,12,0,0,0,
    3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
    3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
    3,0,0,13,5,5,5,0,0,0,0,0,4,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14
};

int Map::room6[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,11,1,1,1,1,1,0,0,1,1,1,1,12,
    3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
    0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0, 3,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,13,5,5,5,5,5,0,0,5,5,5,5,14,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14
};

int Map::room7[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,11,1,1,0,1,1,12,0,0,0,0,4,
    3,0,0,0,3,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,3,0,0,0,0,0,4,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,0,0,3,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,3,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,13,5,5,0,5,5,14,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};

int Map::room8[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
       3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,3,0,0,0,1,1,1,1,1,12,0,0,4,
       3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
       0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,
       3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
       3,0,0,13,5,5,5,5,5,0,0,0,4,0,0,4,
       3,0,0,0,0,0,0,0,0,0,0,0,4,0,0,4,
       3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
       13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};

int Map::room9[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,
    3,5,5,5,5,0,5,5,5,5,14,5,5,0,0,4,
    3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};

int Map::room10[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
       3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
      3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
       3,0,0,13,5,5,5,0,0,5,5,5,14,0,0,4,
       0,0,0,11,1,1,1,0,0,1,1,1,12,0,0,0,
       3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
       3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
       3,0,0,3,0,0,0,0,0,0,0,0,4,0,0,4,
       3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
       13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14
};

int Map::room11[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
      3,0,0,0,3,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,3,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,3,0,0,0,0,0,0,4,0,0,0,4,
      0,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,
      3,0,0,0,3,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,3,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,3,0,0,0,0,0,0,4,0,0,0,4,
     13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};

int Map::room12[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,4,
    3,1,1,1,12,0,0,0,0,0,0,3,0,0,0,4,
      0,0,0,0,4,0,0,0,0,0,0,3,0,0,0,0,
      3,0,0,0,4,0,0,0,0,0,0,13,5,5,5,4,
      3,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,0,4,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
     13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};
int Map::room13[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
      3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,
      0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,
      3,5,5,5,5,5,5,5,5,5,5,14,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
     13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};
int Map::room14[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
      3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
      0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,
      3,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
      3,5,5,5,5,5,5,5,5,5,5,5,5,5,0,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
     13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};
int Map::room15[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
      3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
      3,0,0,1,1,12,0,0,0,0,0,0,0,4,0,4,
      3,0,0,0,0,4,0,0,0,0,0,0,0,4,0,4,
    3,0,0,0,0,4,0,0,0,0,0,0,0,4,0,4,
      0,0,0,0,0,4,0,0,0,0,0,0,0,4,0,0,
      3,0,0,0,0,4,0,0,0,0,0,0,0,4,0,4,
      3,0,0,0,0,4,0,0,0,0,0,0,0,4,0,4,
      3,0,0,0,0,13,5,5,5,5,5,5,5,14,0,4,
      3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
     13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};
int Map::room16[12][16]{
    11,1,1,1,1,1, 1,0,0, 1,1,1,1,1,1,12,
    3, 2,2,2,2,2, 2,0,0, 2,2,2,2,2,2,4,
    3, 0,0,0,0,0, 4,0,0, 3,0,0,0,0,0,4,
    3, 0,0,0,0,0, 4,0,0, 3,0,0,0,0,0,4,
    3, 0,0,0,0,0, 4,0,0, 3,0,0,0,0,0,4,
    3, 0,0,5,5,5,14,0,0,13,5,5,5,0,0,4,
    0, 0,0,0,0,0, 0,0,0, 0,0,0,0,0,0,0,
    3, 0,0,1,1,1,12,0,0,11,1,1,1,0,0,4,
    3, 0,0,0,0,0, 4,0,0, 3,0,0,0,0,0,4,
    3, 0,0,0,0,0, 4,0,0, 3,0,0,0,0,0,4,
    3, 0,0,0,0,0, 4,0,0, 3,0,0,0,0,0,4,
    13,5,5,5,5,5, 5,0,0, 5,5,5,5,5,5,14


};
int Map::room17[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3, 2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    3, 0,4,0,3,0,4,0,0,3,0,4,0,3,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14


};
int Map::room18[12][16]{
    11,1,1,1, 1,1,1,0,0,1,1, 1,1,1,1,12,
    3, 2,2,2, 2,2,2,0,0,2,2, 2,2,2,2,4,
    3, 0,0,0, 4,0,3,0,0,4,0, 4,0,0,0,4,
    3, 0,5,5,14,0,3,0,0,4,0,13,5,5,0,4,
    3, 0,0,0, 0,0,3,0,0,4,0, 0,0,0,0,4,
    3, 0,0,0, 0,0,3,0,0,4,0, 0,0,0,0,4,
    0, 0,0,0, 0,0,0,0,0,0,0, 0,0,0,0,0,
    3, 0,0,0, 0,0,3,0,0,4,0, 0,0,0,0,4,
    3, 0,0,0, 0,0,3,0,0,4,0, 0,0,0,0,4,
    3, 0,1,1,12,0,3,0,0,4,0,11,1,1,0,4,
    3, 0,0,0, 4,0,3,0,0,4,0, 3,0,0,0,4,
    13,5,5,5, 5,5,5,0,0,5,5, 5,5,5,5,14


};

int Map::room19[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3, 2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3, 5,5,5,5,5,5,0,0,5,5,5,5,5,5,4,
    3, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3, 1,1,1,1,1,1,0,0,1,1,1,1,1,1,4,
    0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3, 5,5,5,5,5,5,0,0,5,5,5,5,5,5,4,
    3, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3, 1,1,1,1,1,1,0,0,1,1,1,1,1,1,4,
    3, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14



};
int Map::room20[12][16]{
    11,1,1,1,1, 1, 1, 0, 0, 1, 1,1,1,1,1,12,
    3, 2,2,2,2, 2, 2, 0, 0, 2, 2,2,2,2,2,4,
    3, 0,0,0,0, 0, 0, 0, 0, 0, 0,0,0,0,0,4,
    3, 0,0,0,0, 0, 0,11,12, 0, 0,0,0,0,0,4,
    3, 0,0,0,0, 0,11, 0, 0,12, 0,0,0,0,0,4,
    3, 0,0,0,0,11, 0, 0, 0, 0,12,0,0,0,0,4,
    0, 0,0,0,0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,
    3, 0,0,0,0,13, 0, 0, 0, 0,14,0,0,0,0,4,
    3, 0,0,0,0, 0, 13,0, 0,14, 0,0,0,0,0,4,
    3, 0,0,0,0, 0, 0,13,14, 0, 0,0,0,0,0,4,
    3, 0,0,0,0, 0, 0, 0, 0, 0, 0,0,0,0,0,4,
    13,5,5,5,5, 5, 5, 0, 0, 5, 5,5,5,5,5,14


};
int Map::room21[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14

};
int Map::room22[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14

};
int Map::room23[12][16]{
    11,1,1,1,1,1,1,0,0,1,1,1,1,1,1,12,
    3,2,2,2,2,2,2,0,0,2,2,2,2,2,2,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,
    13,5,5,5,5,5,5,0,0,5,5,5,5,5,5,14

};







