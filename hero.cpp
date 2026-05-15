#include "hero.h"
#include "config.h"

Hero::Hero() {
    //初始化加载人物图片资源
    m_Hero.load(HERO_PATH);

    //初始化人物坐标
    m_X = (GAME_WIDTH-m_Hero.width())*0.5;
    m_Y = GAME_HEIGHT - m_Hero.height();

    //初始化矩形边框
    m_rect.setWidth(m_Hero.width());
    m_rect.setHeight(m_Hero.height());
    m_rect.moveTo(m_X,m_Y);
}

void Hero::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //数字未到
    if(m_recorder<BULLET_INTERVAL){
        return;
    }

    //达到发射时间
    m_recorder = 0;

    //发射子弹
    for(int i=0;i<BULLET_NUM;i++){
        if(m_bullets[i].m_Free){
            //改状态
            m_bullets[i].m_Free = false;
            //设置子弹坐标
            m_bullets[i].m_X = m_X +20;
            m_bullets[i].m_Y = m_Y-50;
            break;
        }
    }
}

void Hero::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_rect.moveTo(m_X,m_Y);
}
