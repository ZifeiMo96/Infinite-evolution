#include "rankmainwindow.h"
#include <QMenuBar>
#include <QPainter>
#include <myPushButton.h>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QTextBrowser>
#include <QlineEdit>
#include <QDebug>

Rankmainwindow::Rankmainwindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("InFinite EvoluTion");

    this->setFixedSize(640,480);

    this->setWindowIcon(QIcon("://res/IE.png"));
    //菜单栏
    QMenuBar *bar=menuBar();

    setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("开始");

    QAction *quitAction = startMenu->addAction("退出");

    QAction *contactAction = startMenu->addAction("联系我们");

    connect(quitAction,&QAction::triggered,[=](){
        this->close();});
    //创建back按钮
    MyPushButton *backbtn=new MyPushButton("://res/btn_rank.png");

    backbtn->setParent(this);

    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
    //创建排名榜
    QLineEdit *playerrank1 = new QLineEdit;

    playerrank1->setParent(this);

    playerrank1->move(245,125);

    playerrank1->setFixedSize(150,50);

    QPalette palette1;

    palette1.setColor(QPalette::Text, QColor(255, 196, 196));

    playerrank1->setPalette(palette1);

    playerrank1->setAlignment(Qt :: AlignCenter);

    playerrank1->setReadOnly(1);

    playerrank1->setStyleSheet("background-color:rgba(0,200,40,40)");

    QLineEdit *playerrank2 = new QLineEdit;

    playerrank2->setParent(this);

    playerrank2->move(245,175);

    playerrank2->setFixedSize(150,50);

    QPalette palette2;

    palette2.setColor(QPalette::Text, QColor(255, 196, 196));

    playerrank2->setPalette(palette2);

    playerrank2->setAlignment(Qt :: AlignCenter);

    playerrank2->setReadOnly(1);

    playerrank2->setStyleSheet("background-color:rgba(0,200,40,40)");

    QLineEdit *playerrank3 = new QLineEdit;

    playerrank3->setParent(this);

    playerrank3->move(245,225);

    playerrank3->setFixedSize(150,50);

    QPalette palette3;

    palette3.setColor(QPalette::Text, QColor(255, 196, 196));

    playerrank3->setPalette(palette1);

    playerrank3->setAlignment(Qt :: AlignCenter);

    playerrank3->setReadOnly(1);

    playerrank3->setStyleSheet("background-color:rgba(0,200,40,40)");
    //获取排名文件
    QFile file("://res/playerrank.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        QString line[3] = in.readLine();

            playerrank1->setText(line[0]);
            playerrank2->setText(line[1]);
            playerrank3->setText(line[2]);
     file.close();

    //back按钮的实现
    connect(backbtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=]{});
        emit this->Rankmainwindowback();
        backbtn->zoom1();
        backbtn->zoom2();
    });

}

void Rankmainwindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load("://res/bg_main.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
