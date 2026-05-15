#ifndef EDIE_H
#define EDIE_H
#include"config.h"
#include<QPixmap>
#include<QVector>

class edie
{
public:
    edie();

    void updateInfo();

public:

    QPixmap m_edie;

    int m_X;
    int m_Y;

    bool m_Free;

    int m_recoder;


};

#endif // EDIE_H
