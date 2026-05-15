#include "edie.h"

edie::edie() {

    m_edie.load(DIE_PATH);

    m_X = 0;
    m_Y = 0;
    m_Free = true;
    m_recoder=0;
}

void edie::updateInfo()
{
    if(m_Free){
        return;
    }
    if(m_recoder ==DIE_INTERVAL){
        m_Free = true;
        m_recoder=0;
        return;
    }
    m_recoder++;


}
