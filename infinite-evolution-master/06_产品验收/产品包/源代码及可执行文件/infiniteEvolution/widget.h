#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QAction>
#include <QSound>
#include "rankmainwindow.h"
#include "inputusername.h"

namespace Ui {
class Widget;
}

class Widget: public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    Rankmainwindow *rank=NULL;
    Inputusername *user=NULL;


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
