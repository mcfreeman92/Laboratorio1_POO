#include "ceareaproductiva.h"

ceareaproductiva::ceareaproductiva()
{

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
}

void ceareaproductiva::setCarro(shared_ptr<ccarro> carro)
{
   m_carro = carro;
}
