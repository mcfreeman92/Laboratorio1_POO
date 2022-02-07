#include "ccarro.h"

cCarro::cCarro()
{
    m_matricula[6] = {0};
    m_anno = 0;
}

cCarro::cCarro(int anno, char *matricula)
{
    memcpy(m_matricula,matricula,6) ;
    m_anno = anno;
}
