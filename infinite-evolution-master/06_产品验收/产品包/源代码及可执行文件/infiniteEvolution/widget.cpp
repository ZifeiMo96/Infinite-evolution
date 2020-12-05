#include "widget.h"
#include "ui_widget.h"
#include "myPushButton.h"
#include "rankmainwindow.h"
#include "inputusername.h"
#include <QTimer>
#include <QMenuBar>

    Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("InFinite EvoluTion");

    this->setFixedSize(640,480);

    this->setWindowIcon(QIcon("://res/IE.png"));
     //创建新页面
     rank=new Rankmainwindow;

     user=new Inputusername;

     QMenuBar *bar=menuBar();
     //设置本页面
     setMenuBar(bar);

     QMenu * startMenu = bar->addMenu("开始");

     QAction *quitAction = startMenu->addAction("退出");

     QAction *contactAction = startMenu->addAction("联系我们");

     connect(quitAction,&QAction::triggered,[=](){
         this->close();});

    //监听返回
    connect(rank,&Rankmainwindow::Rankmainwindowback,this,[=](){
        QTimer::singleShot(500,this,[=](){
        rank->close();
        this->show();});
    });
    connect(user,&Inputusername::inputuserback,this,[=](){
        QTimer::singleShot(500,this,[=](){
        user->close();
        this->show();});
    });

    //开始按钮
    MyPushButton *startbtn =new MyPushButton("://res/btn_start.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.3);
    //弹起特效
    connect(startbtn,&MyPushButton::clicked,[=](){
        startbtn->zoom1();
        startbtn->zoom2();
    //延时进入下一个页面
        QTimer::singleShot(500,this,[=](){
        user->show();
        this->close();
        });

    });

    //rank按钮
    MyPushButton *rankbtn =new MyPushButton("://res/btn_rank.png");
    rankbtn->setParent(this);
    rankbtn->move(this->width()*0.5-rankbtn->width()*0.5,this->height()*0.5);
    //弹起特效
    connect(rankbtn,&MyPushButton::clicked,[=](){
        rankbtn->zoom1();
        rankbtn->zoom2();
    //延时进入rank场景
        QTimer::singleShot(500,this,[=](){
        this->close();
        rank->show();

        });

    });

    //退出按钮
    MyPushButton *endbtn =new MyPushButton("://res/btn_end.png");
    endbtn->setParent(this);
    endbtn->move(this->width()*0.5-endbtn->width()*0.5,this->height()*0.7);
    //弹起特效
    connect(endbtn,&MyPushButton::clicked,[=](){
        endbtn->zoom1();
        endbtn->zoom2();
        this->close();
    });
    QSound *bgsound= new QSound("://res/bgmusic.wav");
    bgsound->setLoops(-1);
    bgsound->play();
}

   Widget::~Widget()
   {
       delete ui;
   }

   void Widget::paintEvent(QPaintEvent *)
   {
       QPainter painter(this);
       QPixmap pix;
       pix.load("://res/bg_main.png");
       painter.drawPixmap(0,0,this->width(),this->height(),pix);
   }
