#include "ctaller.h"

ctaller::ctaller(const char *nombre, const char *direccion)
{
    memcpy(m_nombre,nombre,20) ;
    memcpy(m_direccion,direccion,40) ;

    cout << "Taller: "<< m_nombre <<"   Direccion: "<< m_direccion <<endl;
}

void ctaller::insertar_empleado(shared_ptr<ceareaproductiva> empleado)
{
    empleados.push_back(empleado);
}

void ctaller::insertar_empleado(shared_ptr<ceareaservicio> empleado)
{
    empleados.push_back(empleado);
}

void ctaller::insertar_carro(shared_ptr<ccarro> carro)
{
    areaEspera.push_back(carro);
}

void ctaller::eliminar_empleado(int id)
{
    for (auto it = empleados.begin(); it != empleados.end(); it++)
    {
        shared_ptr<cempleado>e = *it;
        if(e->getId() == id)
        {
            if(typeid(*e.get()) == typeid(ceareaproductiva))
            {
                ceareaproductiva *eap = (ceareaproductiva*)e.get();
                if(eap->getCarro() == nullptr)
                {
                    empleados.erase(it);
                }
            }
        }
    }
    muestra_empleados();
}

shared_ptr<ccarro> ctaller::muestra_trabajos_carro_espera(const char *matricula)
{
    for (auto it = areaEspera.begin(); it != areaEspera.end(); it++) {
        shared_ptr<ccarro> carro = *it;
        if(*carro->getMatricula() == *matricula)
        {
            return carro;
            for(auto a: carro->getArea())
                cout <<a;
            cout <<endl;
        }

    }
}

void ctaller::muestra_tiempo_carro_taller(const char *matricula)
{

}

void ctaller::muestra_tiempo_area_mas_demorada(const char *matricula)
{

}

void ctaller::eliminar_carro_espera(const char *matricula)
{
    for (auto it = areaEspera.begin(); it != areaEspera.end(); it++) {
        shared_ptr<ccarro> carro = *it;
        if(*carro->getMatricula() == *matricula)
        {
            carro.reset();
            areaEspera.erase(it);
            break;
        }
    }
    muestra_carros_espera();
}

void ctaller::muestra_empleados()
{
    for (auto it = empleados.begin(); it != empleados.end(); it++) {
        cempleado e = **it;
        cout << e.getNombre()<<endl;
    }
    cout <<"Total empleados "<< empleados.size()<<endl;
}

void ctaller::muestra_carros_espera()
{
    for (auto it = areaEspera.begin(); it != areaEspera.end(); it++) {
        shared_ptr<ccarro> c = *it;
        cout << c->getMatricula()<<endl;
    }
    cout <<"Total en espera "<< areaEspera.size()<<endl;
}

void ctaller::muestra_areas(shared_ptr<ccarro> carro)
{
    for(auto a: carro->getArea())
        cout <<a;
    cout <<endl;
}

