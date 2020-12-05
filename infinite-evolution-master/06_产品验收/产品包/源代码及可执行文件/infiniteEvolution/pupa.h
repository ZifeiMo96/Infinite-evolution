#ifndef PUPA_H
#define PUPA_H

#include"remoteMonster.h"
#include"skill.h"
class Pupa:RemoteMonster
{
public:
    Pupa();
    void attackPlayer(Obj&obj);
    void die();//可能要调下一关地图的出现 特以区分
private:
    int cdOfBomb;
    int attackDistance;
    bool ifFirst=1;
    int pupaWidth;
    int pupaHeight;
    Skill skillOfSec;
    bool ifInited=0;
};


#endif // PUPA_H
