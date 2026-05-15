#include "mainscene.h"
#include"config.h"
#include<QIcon>
#include<QPainter>
#include<QMouseEvent>
#include<ctime>



Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();

    //启动游戏
    playGame();

}

Mainscene::~Mainscene() {}

void Mainscene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);
    //加载图标
    setWindowIcon(QIcon(":/res/windy1"));
    //定时器设置
    m_Timer.setInterval(GAME_RATH);
    //敌人出场时间间隔 初始化
    m_recorder =0;

    //随机数种子
    srand((unsigned int)time(NULL));
}

void Mainscene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer , &QTimer::timeout,[=](){
        //敌人出场
        enemyToScene();
        //更新游戏中元素的坐标
        updatePosition();
        //绘制到屏幕中
        update();
        //碰撞检测
        collisionDetection();
    });
}

void Mainscene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //发射子弹
    m_hero.shoot();

    //计算所有空闲子弹当前坐标
    for(int i=0;i< BULLET_NUM;i++){
        //如果非空闲，计算发射位置
        if(m_hero.m_bullets[i].m_Free==false){
            m_hero.m_bullets[i].updatePosition();
        }
    }
    //敌人出场
    for(int i=0;i< ENEMY_NUM;i++){
        if(m_enemys[i].m_Free==false){
            m_enemys[i].updatePosition();
        }
    }
    //死亡播放
    for(int i=0;i<DIE_NUM;i++){
        if(m_edies[i].m_Free==false){
            m_edies[i].updateInfo();
        }
    }

}

void Mainscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制人物
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Hero);

    //绘制子弹
    for(int i=0;i< BULLET_NUM;i++){
        //如果非空闲
        if(m_hero.m_bullets[i].m_Free==false){
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }
    }
    //绘制敌人
    for(int i=0;i< ENEMY_NUM;i++){
        //如果非空闲
        if(m_enemys[i].m_Free==false){
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }
    //绘制死亡
    for(int i=0;i< DIE_NUM;i++){
        //如果非空闲
        if(m_edies[i].m_Free==false){
            painter.drawPixmap(m_edies[i].m_X,m_edies[i].m_Y,m_edies[i].m_edie);
        }
    }
}

void Mainscene::mouseMoveEvent(QMouseEvent * event)
{
    int x = event->x() - m_hero.m_rect.width()*0.5;
    int y = event->y() - m_hero.m_rect.height()*0.5;

    //边界检测
    if(x <=0){
        x=0;
    }
    if(x>=GAME_WIDTH - m_hero.m_rect.width()){
        x = GAME_WIDTH - m_hero.m_rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_rect.height()){
        y=GAME_HEIGHT - m_hero.m_rect.height();
    }
    m_hero.setPosition(x,y);
}

void Mainscene::enemyToScene()
{
    //累加时间间隔记录变量
    m_recorder++;

    //数字未到
    if(m_recorder<ENEMY_INTERVAL){
        return;
    }

    //达到发射时间
    m_recorder = 0;

    //发射敌人
    for(int i=0;i<ENEMY_NUM;i++){
        if(m_enemys[i].m_Free){
            //改状态
            m_enemys[i].m_Free = false;
            //设置敌人坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH - m_enemys[i].m_rect.width()-1);
            m_enemys[i].m_Y = - m_enemys[i].m_rect.height();
            break;
        }
    }
}

void Mainscene::collisionDetection()
{
    //遍历所有非空闲敌人
    for(int i=0;i<ENEMY_NUM;i++){
        //如果空闲，下一个
        if(m_enemys[i].m_Free){
            continue;
        }
        //遍历所有非空闲子弹
        for(int j=0;j<BULLET_NUM;j++){
            //空闲，下一个
            if(m_hero.m_bullets[j].m_Free){
                continue;
            }

            //如果子弹和敌人相交，改变状态
            if(m_enemys[i].m_rect.intersects(m_hero.m_bullets[j].m_rect)){
                m_enemys[i].m_Free=true;
                m_hero.m_bullets[j].m_Free=true;

                //死亡效果
                for(int k=0;k<DIE_NUM;k++){
                    if(m_edies[k].m_Free){
                        m_edies[k].m_Free=false;
                        m_edies[k].m_X=m_enemys[i].m_X;
                        m_edies[k].m_Y=m_enemys[i].m_Y+20;
                        break;
                    }
                }
            }
            if(m_enemys[i].m_rect.intersects(m_hero.m_rect)){
                gameover();
            }
        }
    }
}

void Mainscene::gameover()
{
    m_Timer.stop();
    //删除子弹
    for(int i=0;i< BULLET_NUM;i++){
        //如果非空闲
        if(m_hero.m_bullets[i].m_Free==false){
            m_hero.m_bullets[i].m_Free=true;
        }
    }
    //删除敌人
    for(int i=0;i< ENEMY_NUM;i++){
        //如果非空闲
        if(m_enemys[i].m_Free==false){
            m_enemys[i].m_Free=true;
        }
    }
    //删除死亡
    for(int i=0;i< DIE_NUM;i++){
        //如果非空闲
        if(m_edies[i].m_Free==false){
            m_edies[i].m_Free=true;
        }
    }
    //人物初始化
    m_hero.setPosition((GAME_WIDTH-55)*0.5,GAME_HEIGHT - 117);
    QApplication::quit();
}
