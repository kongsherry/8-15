#include "bullet.h"
//修改
bullet::bullet() {
    //加载资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标
    m_X=GAME_WIDTH*0.5-m_Bullet.width()*0.5;
    m_Y=GAME_HEIGHT;

    //子弹状态
    m_Free = true;

    //子弹速度
    m_Speed = BULLET_SPEED;

    //子弹边框
    m_rect.setWidth(m_Bullet.width()+10);
    m_rect.setHeight(m_Bullet.height());
    m_rect.moveTo(m_X+35,m_Y+10);

}

void bullet::updatePosition()
{
    //空闲状态下子弹，无坐标
    if(m_Free){
        return;
    }

    //子弹向上移动
    m_Y -= m_Speed;
    m_rect.moveTo(m_X,m_Y);

    //子弹超出屏幕，改变状态
    if(m_Y <= -m_rect.height()){
        m_Free = true;
    }
}
