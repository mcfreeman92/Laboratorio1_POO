#include "ccarro.h"

ccarro::ccarro()
{
   //ccarro("",0,eArea::ninguna);
}

ccarro::ccarro(ccarro & carro)
{
     ccarro(carro.getMatricula(),carro.getAnno(),carro.getArea());
}

ccarro::ccarro(const char *matricula, int anno, const std::vector<eArea> areas):
    m_area(areas)
{
    memcpy(m_matricula,matricula,TAM_MATRICULA) ;
    m_anno = anno;
    allTime = 0;
    m_timeStart = false;
}

ccarro::~ccarro()
{

}
