#include "map.h"
#include"config.h"

map::map() {
    //初始化加载地图对象
    m_map1.load(":/res/glass");
    m_map2.load(":/res/glass");

    //初始化Y轴坐标
    m_map1_posY=-GAME_HEIGHT;
    m_map2_posY=0;

    //地图滚动速度
    m_scroll_speed= 2;
}

void map::mapPosition()
{
    //处理第一张图片位置
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY>=0){
        m_map1_posY=-GAME_HEIGHT;
    }
    //第二张
    m_map2_posY += m_scroll_speed;
    if(m_map2_posY>=GAME_HEIGHT){
        m_map2_posY=0;
    }
}
