#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QTimer>
#include"map.h"
#include"hero.h"
#include"bullet.h"
#include"enemy.h"
#include"edie.h"
#include<QApplication>

class Mainscene : public QWidget
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);
    ~Mainscene();
    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新所有游戏中元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);

    //地图对象
    map m_map;

    //人物对象
    Hero m_hero;

    //定时器
    QTimer m_Timer;

    //敌人出场
    void enemyToScene();

    //敌人数组
    Enemy m_enemys[ENEMY_NUM];

    //敌人出场间隔
    int m_recorder;

    //死亡数组
    edie m_edies[DIE_NUM];


    //碰撞检测
    void collisionDetection();

    //游戏状态
    bool game_play=true;

    //结束游戏
    void gameover();

};
#endif // MAINSCENE_H
