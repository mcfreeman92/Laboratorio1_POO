#include "ccarro.h"

ccarro::ccarro()
{

}

ccarro::ccarro(ccarro & carro)
{
    ccarro(carro.getMatricula(),carro.getAnno(),carro.getArea());
    m_id = carro.getId();
}

ccarro::ccarro(const char *matricula, int anno, const std::vector<eArea> &areas, int id):
    m_area(0),
    m_anno(anno),
    m_id(id),
    m_iniciaTiempo(false),
    m_allTime(0)

{
    if(!areas.empty())
    for (auto area: areas)
    {
       m_area |= (unsigned short)area;
    }

    cout <<"AREA BIN "<<m_area<<endl;

    setMatricula(matricula);
    cout <<"creado carro "<<m_matricula<<endl;
}

ccarro::~ccarro()
{
    cout <<"carro "<<m_matricula<<" destruido"<<endl;
}

std::vector<eArea> ccarro::getArea()
{
    std::vector<eArea> area;
    if(m_area & eArea::mecanica) area.push_back(eArea::mecanica);
    if(m_area & eArea::pintura) area.push_back(eArea::pintura);
    if(m_area & eArea::electrica) area.push_back(eArea::electrica);
    return area;
}

void ccarro::iniciaTiempo()
{
    if(!m_iniciaTiempo)
    {
        m_iniciaTiempo = true;
        m_tinicio = std::chrono::system_clock::now();
    }
    m_tiniArea = std::chrono::system_clock::now();
}

