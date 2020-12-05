#ifndef PROP_H
#define PROP_H
#include "obj.h"
#include <QPixmap>



class Prop:public Obj
{
public:
    Prop();
    virtual void init(double x,double y,int mod,int width=40,int height=40);
    bool ifGot =0;
    int getKind(){return kind;}
    QPixmap pix;

 protected:
    int kind;  //道具的种类0表加血 1 加hpmax 2attack 3speed
    double degree;//加的程度

    /*

      道具种类说明（范例）
      1代表面值为金币

    */
};

#endif // PROP_H
