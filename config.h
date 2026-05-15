#ifndef CONFIG_H
#define CONFIG_H

/*游戏配置数据*/
#define GAME_WIDTH 500 //宽
#define GAME_HEIGHT 833 //高
#define GAME_TITLE "风神大战丘丘人" //标题
#define GAME_RES_PATH "./windy.rcc" //rcc文件路径
#define GAME_RATH 10 //定时器 单位毫秒

/*人物*/
#define HERO_PATH ":/res/windy1"

//子弹
#define BULLET_PATH ":/res/arrow"
#define BULLET_SPEED 5
#define BULLET_NUM 30  //子弹总数
#define BULLET_INTERVAL 30 //发射间隔

//敌人
#define ENEMY_PATH ":/res/qiuqiu1"
#define ENEMY_SPEED 5
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 30

//die
#define DIE_PATH ":/res/qiuqiudie"
#define DIE_NUM 20
#define DIE_MAX 7
#define DIE_INTERVAL 20

#endif // CONFIG_H
