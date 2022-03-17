#include "ceareaproductiva.h"

ceareaproductiva::~ceareaproductiva()
{
    cout <<"empleado "<<getNombre()<<" destruido"<<endl;
}

//ceareaproductiva::ceareaproductiva(ceareaproductiva &e)
//{
//    ceareaproductiva(e.getNombre(),e.getDNI(),e.getId(),e.getArea());
//}

ceareaproductiva::ceareaproductiva(const char *nombre, int dni, int id, eArea area):
   cempleado(nombre,dni,id),
    m_carro(nullptr),
    m_area(area),
    m_tdemora(0)
{
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
