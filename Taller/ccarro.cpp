#include "ccarro.h"

cCarro::cCarro()
{

}

cCarro::cCarro(int anno, char *matricula)
{
    memcpy(m_matricula,matricula,6) ;
    m_anno = anno;
}
