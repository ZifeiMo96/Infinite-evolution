#ifndef MAP_H
#define MAP_H
#include "monster.h"
#include "prop.h"
#include "closemonster.h"
#include "remotemonster.h"
#include "player.h"


class Map
{
public:
    Map();

    void changeFloor(int x,int y,Player &p);
    void checkFinishFloor();
    bool checkroom();
    void getRoom(int this_room[12][16]);//根据房间的层数，位置，返回房间具体的分布（传递指针）
    void drawMyself();//绘制地图的函数
    void checkFinish(bool b);//检验怪物是否被清理完
    void changeBox(int floor,int xx,int yy,int x,int y,int number);//改变某层某个房间某个格子的状态。
    static int room1[12][16];
    static int room2[12][16];
    static int room3[12][16];
    static int room4[12][16];
    static int room5[12][16];
    static int room6[12][16];
    static int room7[12][16];
    static int room8[12][16];
    static int room9[12][16];
    static int room10[12][16];
    static int room11[12][16];
    static int room12[12][16];
    static int room13[12][16];
    static int room14[12][16];
    static int room15[12][16];
    static int room16[12][16];
    static int room17[12][16];
    static int room18[12][16];
    static int room19[12][16];
    static int room20[12][16];
    static int room21[12][16];
    static int room22[12][16];
    static int room23[12][16];
    int bossx1;
    int bossy1;
    int bossx2;
    int bossy2;
    int bossx3;
    int bossy3;
    int bossx4;
    int bossy4;
    int shopx1;
    int shopx2;
    int shopx3;
    int shopx4;
    int shopy1;
    int shopy2;
    int shopy3;
    int shopy4;
    int propRoomx1;
    int propRoomx2;
    int propRoomx3;
    int propRoomx4;
    int propRoomy1;
    int propRoomy2;
    int propRoomy3;
    int propRoomy4;
    bool finishfloor;


    int this_room[12][16];
    int get_z_of_map();
    int get_x_of_map();
    int get_y_of_map();
    void set_z_of_map(int i);
    void set_x_of_map(int i);
    void set_y_of_map(int i);
    void cleanRecord();
    void setRecordOfFloor(int i,int j,bool b);
    bool getRecordOfFloor(int i,int j);
    void setMonster();
    void check_die_of_monster();
    CloseMonster box_of_cmonster[4][6][6][10];
    RemoteMonster box_of_rmonster[4][6][6][10];
    Prop box_of_prop[4][6][6][20];
    void addProp(int x,int y,int kind);
    bool checkShop();

    bool ifFinish[6][6];

private:
    int floor_1[6][6];//储存第一层的地图配置
    int floor_2[6][6];//储存第二层的地图配置
    int floor_3[6][6];//储存第三层的地图配置
    int floor_4[6][6];//储存第四层的地图配置


    bool ifStartd;//房间是否被开启
    int z_of_map;
    int x_of_map;
    int y_of_map;
    bool record_of_floor[6][6];

};

//示例房间
/*
 * 暂定 1表示墙， 0表示路，8表示向上的门，5表示向下的门，4表示向左的门，6表示向右的门。之后可以加多的
 */




#endif // MAP_H
