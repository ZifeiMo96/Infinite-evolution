#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <windows.h>
#include <QMouseEvent>
#include "map.h"
#include "bullet.h"
#include "player.h"
#include "closemonster.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();


public slots:
    void data_operation();
    void getname(QString);

private:
    int page;
    bool ifFinish;
    Ui::GameWidget *ui;
    QTimer *timer;
    QPixmap door;
    QPixmap bullet_of_monster;
    QPixmap gameoverpic;

    QString name;
    QPixmap shop;
    QPixmap floor_1;
    QPixmap wall_1_2;
    QPixmap wall_1_11;
    QPixmap wall_1_1;
    QPixmap wall_1_12;
    QPixmap wall_1_3;
    QPixmap wall_1_4;
    QPixmap wall_1_5;
    QPixmap wall_1_13;
    QPixmap wall_1_14;

    QPixmap floor_2;
    QPixmap wall_2_2;
    QPixmap wall_2_11;
    QPixmap wall_2_1;
    QPixmap wall_2_12;
    QPixmap wall_2_3;
    QPixmap wall_2_4;
    QPixmap wall_2_5;
    QPixmap wall_2_13;
    QPixmap wall_2_14;

    QPixmap floor_3;
    QPixmap wall_3_2;
    QPixmap wall_3_11;
    QPixmap wall_3_1;
    QPixmap wall_3_12;
    QPixmap wall_3_3;
    QPixmap wall_3_4;
    QPixmap wall_3_5;
    QPixmap wall_3_13;
    QPixmap wall_3_14;


    QPixmap floor_4;
    QPixmap wall_4;

    QPixmap prop4;
    QPixmap prop5;
    QPixmap prop6;
    QPixmap prop7;
    QPixmap prop8;
    QPixmap prop9;
    QPixmap prop10;
    QPixmap prop11;
    QPixmap prop12;
    QPixmap prop13;
    QPixmap prop14;
    QPixmap prop15;
    QPixmap prop16;
    QPixmap prop17;
    QPixmap prop18;
    QPixmap prop19;
    QPixmap prop20;
    QPixmap prop21;
    QPixmap prop22;
    QPixmap prop23;


    QPixmap box_of_player;
    QPixmap pix_map;
    QPixmap pix_box;
    QPixmap image_hp;
    QPixmap image_mp;
    QPixmap pix_hp;
    QPixmap pix_mp;
    QPixmap pix_block_of_map;
    Map *tmap;
    Player player;
    QPixmap pix_block_of_this;

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void changeRoom();
    void changeHp();
    void changeMp();
    void changePage(bool b);
    bool ifStop;
    void shopping(int x,int y);
};

#endif // GAMEWIDGET_H
