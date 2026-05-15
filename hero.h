#ifndef HERO_H
#define HERO_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"

class Hero
{
public:
    Hero();

    //发射箭
    void shoot();
    //设置人物位置
    void setPosition(int x, int y);

public:
    //人物资源 对象
    QPixmap m_Hero;

    //人物坐标
    int m_X;
    int m_Y;

    //飞机的矩形边框
    QRect m_rect;

    //弹匣
    bullet m_bullets[BULLET_NUM];

    //发射间隔记录
    int m_recorder;


};

#endif // HERO_H
