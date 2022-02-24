#include "ccarro.h"
#include <QDebug>

cCarro::cCarro()
{

}

cCarro::cCarro(int anno, const char matricula[])
{
    memcpy(m_matricula,matricula,TAM_MATRICULA) ;
    m_anno = anno;
    LOG("carro "<<m_matricula<<" a sido creado");
}

cCarro::~cCarro()
{
    LOG("carro "<<m_matricula<<" a sido destruido");
}
