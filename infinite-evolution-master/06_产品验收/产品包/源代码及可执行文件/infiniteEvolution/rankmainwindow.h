#ifndef RANKMAINWINDOW_H
#define RANKMAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>


class Rankmainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Rankmainwindow(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *);

signals:
     //自定义信号，用于返回按钮
    void Rankmainwindowback();
public slots:
};

#endif // RANKMAINWINDOW_H
