#include "ccarro.h"

ccarro::ccarro()
{

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
    m_iniciaTiempo = false;
    cout <<"creado carro "<<m_matricula<<endl;
}

ccarro::~ccarro()
{
    cout <<"carro "<<m_matricula<<" destruido"<<endl;
}
