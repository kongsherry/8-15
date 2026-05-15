#include "enemy.h"
#include"config.h"

Enemy::Enemy() {
    //敌人资源加载
    m_enemy.load(ENEMY_PATH);

    //敌人坐标
    m_X=0;
    m_Y=0;

    //敌人状态
    m_Free = true;

    //敌人速度
    m_Speed = ENEMY_SPEED;

    //敌人边框
    m_rect.setWidth(m_enemy.width());
    m_rect.setHeight(m_enemy.height());
    m_rect.moveTo(m_X,m_Y);
}

void Enemy::updatePosition()
{
    //空闲状态下敌人，无坐标
    if(m_Free){
        return;
    }

    //敌人向下移动
    m_Y += m_Speed;
    m_rect.moveTo(m_X,m_Y);

    //敌人超出屏幕，改变状态
    if(m_Y >= GAME_HEIGHT + m_rect.height()){
        m_Free = true;
    }
}
