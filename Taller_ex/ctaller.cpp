#include "ctaller.h"

ctaller::ctaller(const char *nombre, const char *direccion)
{
    memcpy(m_nombre,nombre,20) ;
    memcpy(m_direccion,direccion,40) ;

    cout << "Taller: "<< m_nombre <<"   Direccion: "<< m_direccion <<endl;
}

void ctaller::insertar_empleado(shared_ptr<ceareaproductiva> &empleado)
{
    connect(empleado.get(),&ceareaproductiva::s_trabajo_terminado,[&](){
        if(areaEspera.size()!=0)
        {
            auto carro = areaEspera.begin();
            if(insertar_carro(*carro))
            {

                areaEspera.erase(carro);
                muestra_carros_espera();
            }
        }
        else
        {
            muestra_tiempo_carro_taller("B12345");
            muestra_tiempo_area_mas_demorada();
            cout<<endl;

        }

    });
    empleados.push_back(empleado);
}

void ctaller::insertar_empleado(shared_ptr<ceareaservicio> &empleado)
{
    empleados.push_back(empleado);
}

bool ctaller::insertar_carro(shared_ptr<ccarro> &carro)
{

    auto it = find(carros.cbegin(),carros.cend(),carro);
    if(it == carros.end())
    {
        carros.push_back(carro);
    }

    if(!disponibilidad_trabajos(carro))
    {
        auto it = find(areaEspera.cbegin(),areaEspera.cend(),carro);
        if(it == areaEspera.end())
        {
            areaEspera.push_back(carro);
            cout <<"carro "<<carro->getMatricula()<<" en espera..."<<endl;
        }
        else
            cout <<"carro "<<carro->getMatricula()<<" sigue espera..."<<endl;
        return true;
    }
    else
    {
        inicia_trabajos(carro);
        return false;
    }

}

bool ctaller::eliminar_empleado(int id)
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
                    cout<<"empleado id:"<<id<<" eliminado OK"<<endl;
                    muestra_empleados();
                    return true;
                }
            }
        }
    }
    cout<<"empleado id:"<<id<<" eliminado BAD"<<endl;
    return false;
}

shared_ptr<ccarro> ctaller::muestra_trabajos_carro_espera(const char *matricula)
{

    for (auto it = areaEspera.begin(); it != areaEspera.end(); it++) {
        shared_ptr<ccarro> carro = *it;
        if(*carro->getMatricula() == *matricula)
        {
            cout<<"carro "<<matricula<<" trabajos: ";
            muestra_areas(carro);
            return carro;
        }

    }
}

void ctaller::muestra_tiempo_carro_taller(const char *matricula)
{
    for(auto it: carros)
        if(*it->getMatricula() == *matricula)
            cout<<"carro "<<it->getMatricula()<<" tiempo en taller "<<it->getAllTime()<<endl;
}

void ctaller::muestra_tiempo_area_mas_demorada()
{
    for (auto it : empleados)
    {
        ceareaproductiva *e = (ceareaproductiva*)it.get();
         cout<<"area demorada "<< e->getTiempoDemora()<<" area "<<e->getArea()<<endl;
}
}

bool ctaller::eliminar_carro_espera(const char *matricula)
{
    for (auto it = areaEspera.begin(); it != areaEspera.end(); it++) {
        shared_ptr<ccarro> carro = *it;
        if(*carro->getMatricula() == *matricula)
        {
            carro.reset();
            areaEspera.erase(it);
            cout <<"carro "<<matricula<< " eliminado OK"<<endl;
            muestra_carros_espera();
            return true;
        }
    }
    cout <<"carro "<<matricula<< " eliminado BAD"<<endl;
    return false;
}

void ctaller::muestra_empleados()
{
    for (auto it : empleados) {
        cout << it->getNombre()<<endl;
    }
    cout <<"total empleados "<< empleados.size()<<endl;
}

void ctaller::muestra_carros_espera()
{
    cout <<"--- carros en espera --- "<<endl;
    for (auto it = areaEspera.begin(); it != areaEspera.end(); it++) {
        shared_ptr<ccarro> c = *it;
        cout << c->getMatricula()<<endl;
    }
    cout <<"--- total en espera "<< areaEspera.size()<<" --- "<<endl;
}

void ctaller::muestra_areas(shared_ptr<ccarro> &carro)
{
    for(auto a: carro->getArea())
        cout <<a <<" ";
    cout << endl;
}

bool ctaller::disponibilidad_trabajos(shared_ptr<ccarro> &carro)
{
    for(auto a: carro->getArea())
    {
        for (auto e: empleados )
        {
            if(typeid(*e) == typeid(ceareaproductiva))
            {
                ceareaproductiva *eap = (ceareaproductiva*)e.get();
                if((eap->getArea() == a))
                    if(!(eap->getCarro() == nullptr))
                    {
                        return false;
                    }
            }

        }
    }
    return true;
}

void ctaller::inicia_trabajos(shared_ptr<ccarro> &carro)
{
    for(auto a: carro->getArea())
    {
        for (auto e: empleados )
        {
            if(typeid(*e) == typeid(ceareaproductiva))
            {
                ceareaproductiva *eap = (ceareaproductiva*)e.get();
                if((eap->getArea() == a))
                {
                    cout <<e->getNombre()<< " inicia trabajo en carro "<<carro->getMatricula()<<endl;
                    eap->setCarro(carro);
                }
            }

        }
    }
}

