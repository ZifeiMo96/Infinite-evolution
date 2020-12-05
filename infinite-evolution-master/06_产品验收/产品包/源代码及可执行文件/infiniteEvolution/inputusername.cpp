#include "inputusername.h"
#include <QMenuBar>
#include <QPainter>
#include "myPushButton.h"
#include <QTimer>
#include <QLineEdit>


Inputusername::Inputusername(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("无限进化");

    this->setFixedSize(640,480);

    this->setWindowIcon(QIcon("://res/IE.png"));

    /**game=new GameWidget;**/

    //菜单栏
    QMenuBar *bar=menuBar();

    setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("开始");

    QAction *quitAction = startMenu->addAction("退出");

    QAction *contactAction = startMenu->addAction("联系我们");

    connect(quitAction,&QAction::triggered,[=](){
        this->close();});

   //返回按钮
    MyPushButton *backbtn=new MyPushButton("://res/btn_rank.png");

    backbtn->setParent(this);

    backbtn->move(0,this->height()-backbtn->height());
    //继续按钮
    MyPushButton *contibtn=new MyPushButton("://res/btn_continuepng.png");

    contibtn->setParent(this);

    contibtn->move(this->width()-contibtn->width(),this->height()-contibtn->height());

    QLineEdit *username = new QLineEdit;

    username->setParent(this);

    username->move(245,215);

    username->setFixedSize(150,50);

    QPalette palette;

    palette.setColor(QPalette::Text, QColor(255, 255, 255));

    username->setPalette(palette);

    username->setAlignment(Qt :: AlignCenter);

    username->setPlaceholderText("请输入您的用户名");

    username->setMaxLength(8);

    username->setStyleSheet("background-color:rgba(0,0,0,0)");

    connect(contibtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=]{});
        contibtn->zoom1();
        contibtn->zoom2();
        game=new GameWidget;
        connect(this,SIGNAL(sendname(QString)),game,SLOT(getname(QString)));
        QString namestring=username->text();
        emit sendname(namestring);
        this->close();
        game->show();
     });
    //返回按钮实现
    connect(backbtn,&MyPushButton::clicked,[=](){
       QTimer::singleShot(500,this,[=]{});
       emit this->inputuserback();
       backbtn->zoom1();
       backbtn->zoom2();
    });
}


void Inputusername::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load("://res/bg_main.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
