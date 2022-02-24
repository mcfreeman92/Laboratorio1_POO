#include "ccarro.h"
#include <QDebug>
#include "string.h"

cCarro::cCarro()
{

}

cCarro::cCarro(int anno, const char *matricula): m_timeStart(false), allTime(0)
{
    memcpy(m_matricula,matricula,TAM_MATRICULA) ;
    m_anno = anno;
    LOG("carro "<<m_matricula<<" a sido creado");
}

cCarro::~cCarro()
{
    LOG("carro "<<m_matricula<<" a sido destruido");
}
