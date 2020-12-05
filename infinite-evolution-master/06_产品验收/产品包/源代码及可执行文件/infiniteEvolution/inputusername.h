#ifndef INPUTUSERNAME_H
#define INPUTUSERNAME_H

#include <QMainWindow>
#include "gamewidget.h"


class Inputusername : public QMainWindow
{
    Q_OBJECT
public:
    explicit Inputusername(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    GameWidget *game=NULL;
    QString playername;

signals:
    void inputuserback();
    void sendname(QString);

public slots:

};

#endif // INPUTUSERNAME_H
