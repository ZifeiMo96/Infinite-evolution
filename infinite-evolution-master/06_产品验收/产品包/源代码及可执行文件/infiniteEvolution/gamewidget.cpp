#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QString>
#include <QDebug>

extern bool ifFinish;
extern bool ifbossFinish;

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    tmap = new Map();
    timer = new QTimer();
    page = 0;

    floor_1.load(":/res/grass");
    wall_1_2.load(":/res/wall_1");
    wall_1_11.load(":/res/wall_2");
    wall_1_1.load(":/res/wall_3");
    wall_1_12.load(":/res/wall_4");
    wall_1_3.load(":/res/wall_5");
    wall_1_4.load(":/res/wall_6");
    wall_1_5.load(":/res/wall_7");
    wall_1_13.load(":/res/wall_8");
    wall_1_14.load(":/res/wall_9");

    floor_2.load(":/res/pix_of_floor4");
    wall_2_2.load(":/res/pix_wall_4");
    wall_2_11.load(":/res/pix_of_4-7");
    wall_2_1.load(":/res/pix_of_4-8");
    wall_2_12.load(":/res/pix_of_4-9");
    wall_2_3.load(":/res/pix_of_4-4");
    wall_2_4.load(":/res/pix_of_4-6");
    wall_2_5.load(":/res/pix_of_4-2");
    wall_2_13.load(":/res/pix_of_4-1");
    wall_2_14.load(":/res/pix_of_4-3");

    floor_3.load(":/res/pix_floor_of-3");
    wall_3_2.load(":/res/pix_wall_3");
    wall_3_11.load(":/res/pix_of_3-7");
    wall_3_1.load(":/res/pix_of_3-8");
    wall_3_12.load(":/res/pix_of_3-9");
    wall_3_3.load(":/res/pix_of_3-4-");
    wall_3_4.load(":/res/pix_of_3-6");
    wall_3_5.load(":/res/pix_of_3-2");
    wall_3_13.load(":/res/pix_of_3-1");
    wall_3_14.load(":/res/pix_of_3-3");
    bullet_of_monster.load(":/res/bullet_of_monster");

    prop4.load(":/res/prop4");
    prop5.load(":/res/prop5");
    prop6.load(":/res/prop6");
    prop7.load(":/res/prop7");
    prop8.load(":/res/prop8");
    prop9.load(":/res/prop9");
    prop10.load(":/res/prop10");
    prop11.load(":/res/prop11");
    prop12.load(":/res/prop12");
    prop13.load(":/res/prop13");
    prop14.load(":/res/prop14");
    prop15.load(":/res/prop15");
    prop16.load(":/res/prop16");
    prop17.load(":/res/prop17");
    prop18.load(":/res/prop18");
    prop19.load(":/res/prop19");
    prop20.load(":/res/prop20");
    prop21.load(":/res/prop21");
    prop22.load(":/res/prop22");
    prop23.load(":/res/prop23");
    gameoverpic.load(":/res/gameoverpic");



    wall_4.load(":/res/pix_wall");
    floor_4.load(":/res/pix_of_floor4");

    pix_box.load(":/res/box_of_hp");
    pix_block_of_this.load(":/res/block_of_this");
    image_hp.load(":/res/hp");
    image_mp.load(":/res/mp");
    pix_hp = image_hp.copy();
    pix_mp = image_mp.copy();
    pix_map.load(":/res/pix_map");
    box_of_player.load(":/res/box_of_player");
    pix_block_of_map.load(":/res/block_of_map");
    door.load(":/res/door");
    shop.load(":/res/shop");




    tmap->setRecordOfFloor(2,2,1);
    //设置固定大小
    setFixedSize(640,480);

    //设置图标
    setWindowIcon(QIcon(":/res/IE.png"));
    //设置标题
    setWindowTitle("无限进化");

    ifStop = 0;

    connect(timer,SIGNAL(timeout()),this,SLOT(data_operation()));
    timer->start(30);

}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(ifStop){
        painter.drawPixmap(0,0,box_of_player);
        painter.drawPixmap(5,38,pix_map);
        for(int i =0;i<6;i++){
            for(int j =0;j<6;j++){
                if(tmap->getRecordOfFloor(i,j)==1){
                    painter.drawPixmap(39*i+6,24*j+39,pix_block_of_map);
                }
            }
        }
        painter.drawPixmap(39*tmap->get_x_of_map()+5,24*tmap->get_y_of_map()+38,pix_block_of_this);
        //属性面板
        //姓名
        QFont font2("OCR A Std",12,true);
        painter.setFont(font2);
        painter.setPen(Qt::white);
        QString str2 =name;
        painter.drawText(150,250,str2);
        QFont font8("OCR A Std",12,true);
        painter.setFont(font8);
        painter.setPen(Qt::white);
        QString str8 =QString::number(player.number_of_prop);
        painter.drawText(360,465,str8);
        //生命
        QFont font3("OCR A Std",12,true);
        painter.setFont(font3);
        painter.setPen(Qt::red);
        QString str3 =QString::number(player.getHpMax());
        painter.drawText(150,287,str3);
        //魔法
        QFont font4("OCR A Std",12,true);
        painter.setFont(font4);
        painter.setPen(Qt::blue);
        QString str4 =QString::number(player.mpMax);
        painter.drawText(150,328,str4);
        //攻击力
        QFont font5("OCR A Std",12,true);
        painter.setFont(font5);
        painter.setPen(Qt::white);
        QString str5 =QString::number(player.getAttack());
        painter.drawText(150,373,str5);
        //速度
        QFont font6("OCR A Std",12,true);
        painter.setFont(font6);
        painter.setPen(QColor(180,0,255));
        QString str6 =QString::number(player.getSpeed());
        painter.drawText(150,417,str6);

        QFont font7("OCR A Std",12,true);
        painter.setFont(font7);
        painter.setPen(Qt::yellow);
        QString str7 =QString::number(player.getMoney());
        painter.drawText(150,463,str7);
        QFont font13("黑体",12,true);
        painter.setFont(font7);
        painter.setPen(Qt::white);
        QString number_page =QString::number(page/6+1);
        painter.drawText(562,465,number_page);

        int x1=258;
        int x2 = 40;
        int x3 = 170;
        int y1=65;
        int y2=57;
        int y3=84;
        int twidth=40;
        int theight = 40;
        QFont font9("黑体",12,true);
        QFont font10("黑体",8,true);

        painter.setPen(Qt::white);
        for(int i = page;i<page+6;i++){
            QString name;
            QString tstr;
            switch(player.box_of_prop[i]){
            case 4:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop4);
                name="落魄骑士大剑";
                tstr="攻击力+5";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);

                break;
            case 5:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop5);
                name="落魄骑士大盾";
                tstr="血量+15";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 6:

                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop6);
                name="血意骑士大剑";
                 tstr="攻击力+10，血量-5";
                 painter.setFont(font9);
                 painter.drawText(x1+x2,y1*(i%6)+y3,name);
                 painter.setFont(font10);
                 painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 7:

                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop7);
                name="血意骑士大盾";
                tstr="血量+5，速度+0.2";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 8:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop8);
                name="天国的祝福";
                tstr="血量+30，攻击力+10";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 9:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop9);
                name="天国之箭";
                tstr="攻击力+15，速度+0.5";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 10:
                tstr="攻击力+5，速度+0.2";
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop10);
                name="精灵之箭";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 11:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop11);
                name="精灵的护佑";
                tstr="血量+5，速度+0.3";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 12:
                tstr="血量+30，速度-0.5";
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop12);
                name="矮人的铁壁";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 13:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop13);
                name="平底锅";
                tstr="攻击力+5，血量+10";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 14:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop14);
                name="勇者项链";
                tstr="攻+3，血+10，速+0.1";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 15:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop15);
                name="猎人项链";
                tstr="攻+3，血+5，速+0.2";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 16:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop16);
                name="血意项链";
                tstr="攻+10，血-10，速+0.2";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 17:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop17);
                name="生命之果";
                tstr="血量+25";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 18:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop18);
                name="黄金果实";
                tstr="血量+50";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 19:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop19);
                name="熏风魔珠";
                tstr="魔法+20，速度+0.2";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 20:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop20);
                name="黄金魔珠";
                tstr="血量+30，魔法+30";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 21:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop21);
                name="大地魔珠";
                tstr="血+20，魔+20，速-0.2";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 22:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop22);
                name="天赐的礼物";
                tstr="攻+20，血+30，蓝+40，速+0.5";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;
            case 23:
                painter.drawPixmap(x1,y1*(i%6)+y2,twidth,theight,prop23);
                name="游历者的迅捷";
                tstr="速度+0.4";
                painter.setFont(font9);
                painter.drawText(x1+x2,y1*(i%6)+y3,name);
                painter.setFont(font10);
                painter.drawText(x1+x3,y1*(i%6)+y3,tstr);
                break;

            }
        }
        
    }else{
        for(int i = 0;i<16;i++){
            for(int j=0;j<12;j++){
                if(tmap->get_z_of_map() == 1){
                    switch(this->tmap->this_room[j][i]){
                    case 0:
                        painter.drawPixmap(40*i,40*j,40,40,floor_1);
                        break;
                    case 2:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_2);
                        break;
                    case 11:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_11);
                        break;
                    case 1:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_1);
                        break;
                    case 12:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_12);
                        break;
                    case 3:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_3);
                        break;
                    case 4:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_4);
                        break;
                    case 5:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_5);
                        break;
                    case 13:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_13);
                        break;
                    case 14:
                        painter.drawPixmap(40*i,40*j,40,40,wall_1_14);
                        break;
                    }
                }
                else if(tmap->get_z_of_map() == 2){
                    switch(this->tmap->this_room[j][i]){
                    case 0:
                        painter.drawPixmap(40*i,40*j,40,40,floor_2);
                        break;
                    case 2:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_2);
                        break;
                    case 11:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_11);
                        break;
                    case 1:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_1);
                        break;
                    case 12:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_12);
                        break;
                    case 3:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_3);
                        break;
                    case 4:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_4);
                        break;
                    case 5:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_5);
                        break;
                    case 13:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_13);
                        break;
                    case 14:
                        painter.drawPixmap(40*i,40*j,40,40,wall_2_14);
                        break;
                    }
                }
                else if(tmap->get_z_of_map() == 3){
                    switch(this->tmap->this_room[j][i]){
                    case 0:
                        painter.drawPixmap(40*i,40*j,40,40,floor_3);
                        break;
                    case 2:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_2);
                        break;
                    case 11:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_11);
                        break;
                    case 1:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_1);
                        break;
                    case 12:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_12);
                        break;
                    case 3:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_3);
                        break;
                    case 4:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_4);
                        break;
                    case 5:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_5);
                        break;
                    case 13:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_13);
                        break;
                    case 14:
                        painter.drawPixmap(40*i,40*j,40,40,wall_3_14);
                        break;
                    }
                }
                else if(tmap->get_z_of_map() == 4){
                    switch(this->tmap->this_room[j][i]){
                    case 0:
                        painter.drawPixmap(40*i,40*j,40,40,floor_4);
                        break;
                    case 2:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 11:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 1:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 12:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 3:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 4:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 5:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 13:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    case 14:
                        painter.drawPixmap(40*i,40*j,40,40,wall_4);
                        break;
                    }
                }

            }
        }
       if(tmap->checkShop()){
            painter.drawPixmap(240,160,160,160,shop);
       }
        if(tmap->checkroom()){

            painter.drawPixmap(280,240,40,40,door);
        }
        ifFinish = 1;
        for(int i = 0;i<10;i++){

            if(tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifLive){
                painter.drawPixmap(tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getX()-
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].x_of_pix,
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getY()
                        -tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].y_of_pix,
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].width_of_pix,
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].height_of_pix,
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].pix);
                        ifFinish = 0;

            }
            RemoteMonster *d = &tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i];
            if((*d).ifLive ==1){
                painter.drawPixmap((*d).getX()-(*d).x_of_pix,(*d).getY()-(*d).y_of_pix,(*d).width_of_pix,(*d).height_of_pix,(*d).pix);
            ifFinish = 0;

            }
        }
        for(int i =0;i<50;i++){
            if(player.boxOfBullet[i].ifLive){
              painter.drawPixmap(int(player.boxOfBullet[i].getX()),int(player.boxOfBullet[i].getY()),player.boxOfBullet[i].getWidth(),player.boxOfBullet[i].getHeight(),player.boxOfBullet[i].pix);
            }
        }
        for(int i = 0;i<10;i++){
            if(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifLive){
                for(int j = 0;j<50;j++){
                    if(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].ifLive){
                        painter.drawPixmap(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].getX(),
                                tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].getY(),10,10,bullet_of_monster);

                    }

                }
            }
        }
        for(int i=0;i<20;i++){
            if(tmap->box_of_prop[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifGot){
                painter.drawPixmap(tmap->box_of_prop[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getX(),
                        tmap->box_of_prop[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getY(),
                        tmap->box_of_prop[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].pix);
            }

        }
        painter.drawPixmap(int(player.getX())-9,int(player.getY())-1,40,34,player.pix_player);
        painter.drawPixmap(0,0,270,120,pix_box);
        double i = double(player.getHp())/player.getHpMax();
        painter.drawPixmap(3,3,int(180*i),24,pix_hp);
        double j = double(player.mp)/player.mpMax;
        painter.drawPixmap(3,40,int(180*j),24,pix_mp);
        QFont font1("OCR A Std",12,true);
        painter.setFont(font1);
        painter.setPen(Qt::red);
        QString str =QString::number(player.getHp());
        painter.drawText(140,23,str);
        painter.setPen(Qt::blue);
        QString str2 =QString::number(player.mp);
        painter.drawText(140,60,str2);
        if(!player.ifLive){
            painter.drawPixmap(0,0,640,480,gameoverpic);
            QTimer::singleShot(2000,this,[=](){this->close();});

        }
    }
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
   if(GetAsyncKeyState(87)) {
        player.setUp(1);

   }
   if(GetAsyncKeyState(83)){
        player.setDown(1);

   }
   if(GetAsyncKeyState(65)){
       player.setLeft(1);

   }
   if(GetAsyncKeyState(68)){
       player.setRight(1);

   }
   if(GetAsyncKeyState(9)){
        if(ifStop == 0){
            ifStop =1;
        }else{
            ifStop =0;
        }
   }
   if(GetAsyncKeyState(81)){

       changePage(0);
   }
   if(GetAsyncKeyState(69)){
       changePage(1);
   }

}

void GameWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(!GetAsyncKeyState(87)) {
         player.setUp(0);

    }
    if(!GetAsyncKeyState(83)){
         player.setDown(0);

    }
    if(!GetAsyncKeyState(65)){
        player.setLeft(0);

    }
    if(!GetAsyncKeyState(68)){
        player.setRight(0);

    }


}

void GameWidget::mouseMoveEvent(QMouseEvent *event)
{
    setMouseTracking(true);
    player.x_of_attack = event->x();
    player.y_of_attack = event->y();
    double tx = double(event->x())-player.getX();
    double ty = double(event->y())-player.getY();
    if(tx>0){
        if(ty/tx>2.4142){

            player.change_status_of_player(6);

        }
        else if(ty/tx<=2.4142&&ty/tx>0.4142){

            player.change_status_of_player(7);

        }
        else if(ty/tx<=0.4142&&ty/tx>-0.4142){

            player.change_status_of_player(0);

        }
        else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

            player.change_status_of_player(1);

        }
        else if(ty/tx<-2.4142){

            player.change_status_of_player(2);

        }

    }
    else if(tx==0){
        if(ty<0){

            player.change_status_of_player(2);

        }else{

            player.change_status_of_player(6);

        }

    }
    else if(tx<0){
        if(ty/tx>2.4142){

            player.change_status_of_player(2);

        }
        else if(ty/tx<=2.4142&&ty/tx>0.4142){

            player.change_status_of_player(3);

        }
        else if(ty/tx<=0.4142&&ty/tx>-0.4142){

            player.change_status_of_player(4);

        }
        else if(ty/tx<=-0.4142&&ty/tx>-2.4142){

            player.change_status_of_player(5);

        }
        else if(ty/tx<-2.4142){

            player.change_status_of_player(6);

        }
    }
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        player.ifAttack = 1;
        player.changeIfShoot(1);
        shopping(event->x(),event->y());
    }
}

void GameWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        player.ifAttack = 0;
        player.changeIfShoot(0);
    }

}

void GameWidget::changeRoom()
{
    if(tmap->ifFinish[tmap->get_x_of_map()][tmap->get_y_of_map()]){
        if(player.getX()<10){
            if(tmap->get_x_of_map()==0){
                tmap->set_x_of_map(5);
            }else{
                tmap->set_x_of_map(tmap->get_x_of_map()-1);
            }
           tmap->setRecordOfFloor(tmap->get_x_of_map(),tmap->get_y_of_map(),1);
           tmap->getRoom(tmap->this_room);
           player.setX(640-60);
           player.cleanBullet();
        }
        if(player.getX()>640-10-player.getWidth()){
            if(tmap->get_x_of_map()==5){
                tmap->set_x_of_map(0);
            }else{
                tmap->set_x_of_map(tmap->get_x_of_map()+1);
            }
           tmap->setRecordOfFloor(tmap->get_x_of_map(),tmap->get_y_of_map(),1);
           tmap->getRoom(tmap->this_room);
           player.setX(40);
           player.cleanBullet();
           player.cleanBullet();
        }
        if(player.getY()>480-10-player.getHeight()){
            if(tmap->get_y_of_map()==5){
                tmap->set_y_of_map(0);
            }else{
                tmap->set_y_of_map(tmap->get_y_of_map()+1);
            }
           tmap->setRecordOfFloor(tmap->get_x_of_map(),tmap->get_y_of_map(),1);
           tmap->getRoom(tmap->this_room);
           player.setY(40);
           player.cleanBullet();
        }
        if(player.getY()<10){
            if(tmap->get_y_of_map()==0){
                tmap->set_y_of_map(5);
            }else{
                tmap->set_y_of_map(tmap->get_y_of_map()-1);
            }
            tmap->setRecordOfFloor(tmap->get_x_of_map(),tmap->get_y_of_map(),1);
           tmap->getRoom(tmap->this_room);
           player.setY(480-60);
           player.cleanBullet();
        }
        }
        else {}
    }



void GameWidget::changeHp()
{
    double i = double(player.getHp())/player.getHpMax();
    pix_hp  = image_hp.copy(0,0,int(image_hp.width()*i),image_hp.height());

}

void GameWidget::changeMp()
{
    double i = double(player.mp)/player.mpMax;
    pix_hp  = image_hp.copy(0,0,int(image_mp.width()*i),image_mp.height());
}

void GameWidget::changePage(bool b)
{
    if(ifStop){
        if(b){
            if(page<168&&page>=0){
                page+=6;
            }else{
                page=174;
            }
        }else{
            if(page>0&&page<=180){
                page-=6;
            }else{
                page = 0;
            }
        }
    }
}

void GameWidget::shopping(int x, int y)
{
    if(tmap->checkShop()){
        if(x>240&x<400&&y>200&y<360){
            if(player.getMoney()>=50){
                player.setMoney(player.getMoney()-50);
                tmap->addProp(280,240,2);
            }
        }
    }
}




void GameWidget::data_operation()
{

    if(!ifStop){
        Obj obj1[10];
        Obj obj2[10];
        for(int i= 0;i<10;i++){
            obj1[i] = tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i];
            obj2[i] = tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i];
        }
        static int time_of_playergif = 0;
        player.move(tmap->this_room,obj1,obj2);
        if(time_of_playergif<2){
            time_of_playergif++;
        }else{
            player.gif();
            time_of_playergif = 0;
        }
        player.shoot(player.x_of_attack,player.y_of_attack);
        for(int i =0;i<10;i++){
            bool b;
            player.checkBulletHit(tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i],b);


            if(tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifdie()){
                tmap->addProp(tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getX(),
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getY(),1);
            }


            player.checkBulletHit(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i],b);
           if(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifdie()){
                tmap->addProp(tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getX(),
                        tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].getY(),1);
               }

        }

        tmap->checkFinish(ifFinish);



        for(int i = 0;i<10;i++){

            if((tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i]).ifLive){

                obj1[i].setX(player.getX());
                obj1[i].setY(player.getY());
                obj1[i].setSize(15,25);
                tmap->box_of_cmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].move(player,tmap->this_room,obj1,obj2);

            }

            if(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifLive ==1){
                tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].move(player,tmap->this_room);
                tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].attackPlayer(player);
            }
        }
        for(int i =0;i<50;i++){


            if(player.boxOfBullet[i].checkCrash(int(player.boxOfBullet[i].getX()),int(player.boxOfBullet[i].getY()),tmap->this_room)){
                player.boxOfBullet[i].move();

            }else{
                player.boxOfBullet[i].hide();
            }
        }
        for(int i =0;i<20;i++){
            player.getProp(tmap->box_of_prop[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i]);
        }
        for(int i = 0;i<10;i++){
            if(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].ifLive){
                for(int j = 0;j<50;j++){
                    if( tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].ifLive){
                        tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].move();
                        if(!tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].checkCrash(
                                    tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].getX(),
                                tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].getY(),tmap->this_room)){
                                tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].hide();

                        };
                        if(tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].checkHit(player)){

                            tmap->box_of_rmonster[tmap->get_z_of_map()-1][tmap->get_x_of_map()][tmap->get_y_of_map()][i].boxOfBullet[j].loseHp(player);
                    }

                   }
                }
            }
        }
        if(!player.ifLive){
            if(player.dieNumber>5&&!player.ifDie){
                if(player.status_of_player == 8&&player.page_of_player == 0){
                    player.status_of_player = 9,player.page_of_player = 0;
                }else if(player.status_of_player == 9&&player.page_of_player == 0){
                    player.status_of_player = 8,player.page_of_player = 1;
                }
                else if(player.status_of_player == 8&&player.page_of_player == 1){

                    player.status_of_player = 9,player.page_of_player = 1;
                }
                else if(player.status_of_player == 9&&player.page_of_player == 1){
                    player.status_of_player = 8,player.page_of_player = 2;

                }
                else if(player.status_of_player == 8&&player.page_of_player == 2){

                    player.status_of_player = 9,player.page_of_player = 2;
                }
                else if(player.status_of_player == 9&&player.page_of_player == 2){

                    player.status_of_player = 8,player.page_of_player = 3;
                }
                else if(player.status_of_player == 8&&player.page_of_player == 3){
                    player.status_of_player = 9,player.page_of_player = 3;

                }
                else if(player.status_of_player == 9&&player.page_of_player == 3){
                        player.ifDie  = 1;

                }else{
                    player.status_of_player = 8,player.page_of_player = 0;
                }
            }else{
                if(!player.ifDie){
                    player.dieNumber++;
                }

            }
            player.pix_player = player.img_player.copy(player.status_of_player*20,player.page_of_player*17,20,17);
        }

        tmap->changeFloor(player.getX(),player.getY(),player);
        changeHp();
        changeMp();
        changeRoom();
        player.checkDie();


    }
    this->update();

}

void GameWidget::getname(QString str)
{
      name=str;
}

