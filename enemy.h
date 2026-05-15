#ifndef ENEMY_H
#define ENEMY_H
#include<QPixmap>
#include<QRect>

class Enemy
{
public:
    Enemy();

    //更新坐标
    void updatePosition();
public:
    //敌人资源对象
    QPixmap m_enemy;
    //位置
    int m_X;
    int m_Y;

    //矩形边框
    QRect m_rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

};

#endif // ENEMY_H
