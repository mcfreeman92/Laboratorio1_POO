#include "ceareaproductiva.h"

ceareaproductiva::~ceareaproductiva()
{
    cout <<"empleado "<<getNombre()<<" destruido"<<endl;
}

ceareaproductiva::ceareaproductiva(cempleado &e, eArea area)
{
    ceareaproductiva(e.getNombre(),e.getDNI(),m_area);
}

ceareaproductiva::ceareaproductiva(const char *nombre, int id, eArea area):
    m_carro(nullptr),
    m_area(area),
    m_tdemora(0)
{
    setDNI(id);
    setNombre(nombre);
    cout <<"creado empleado "<<getNombre()<< " area productiva"<<endl;
}

void ceareaproductiva::setCarro(shared_ptr<ccarro> carro)
{
    m_carro = carro;
    m_carro->iniciaTiempo();
    QTimer::singleShot(5000, this, SLOT(termina()));
}

void ceareaproductiva::termina()
{
    m_carro->setAllTime();
    double auxTiempo = m_carro->getTiempoArea();
    if(m_tdemora < auxTiempo) m_tdemora = auxTiempo;
    m_tdemora = m_carro->getTiempoArea();
    m_carro.reset();
    emit(s_trabajo_terminado());
}
