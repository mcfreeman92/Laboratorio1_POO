#include "ceareaproductiva.h"

ceareaproductiva::ceareaproductiva()
{

}

ceareaproductiva::~ceareaproductiva()
{
    cout <<"empleado "<<getNombre()<<" destruido"<<endl;
}

ceareaproductiva::ceareaproductiva(cempleado &e, eArea area)
{
    ceareaproductiva(e.getNombre(),e.getId(),m_area);
}

ceareaproductiva::ceareaproductiva(const char *nombre, int id, eArea area):
    m_carro(nullptr),
    m_area(area)
{
    setId(id);
    setNombre(nombre);
    cout <<"creado empleado "<<getNombre()<< " area productiva"<<endl;
    setReloj();
    connect(getReloj(),SIGNAL(timeout()),this,SLOT(on_run()));
}

void ceareaproductiva::setCarro(shared_ptr<ccarro> carro)
{
   m_carro = carro;
   m_carro.reset();
   relojStart(5000);
}

void ceareaproductiva::on_run()
{
    relojStop();
    m_carro.reset();
    emit(s_trabajo_terminado());
}
