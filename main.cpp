#include "mainscene.h"

#include <QApplication>
#include<QResource>
#include"config.h"
//3425
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainscene w;

    QResource::registerResource(GAME_RES_PATH);

    w.show();
    return a.exec();
}
