#include "ctaller.h"

ctaller::ctaller(const char *nombre, const char *direccion)
{
    memcpy(m_nombre,nombre,20) ;
    memcpy(m_direccion,direccion,40) ;
    m_tiempo_ini = tiempo_hora_actual();
    cout << "Taller: "<< m_nombre <<"   Direccion: "<< m_direccion <<endl;
}

const char* ctaller::areaToStr(eArea a)
{
    const char * str = nullptr;
    switch (a) {
    case 1:
        str = "mecanica";
        break;
    case 2:
        str = "pintura";
        break;
    case 4:
        str = "electronica";
        break;
    }
    return str;
}

string ctaller::tiempo_hora_actual()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

void ctaller::insertar_empleado(shared_ptr<ceareaproductiva> &empleado)
{
    //creo conexion para indicar que el empleado terminó su trabajo
    connect(empleado.get(),&ceareaproductiva::s_trabajo_terminado,[&]()
    {
        if(areaEspera.size()!=0) //pregunto si es el ultimo carro en espera
        {
            auto carro = areaEspera.begin();
            if(insertar_carro(*carro)) //si entra al trabajo
            {
                areaEspera.erase(carro); //borro el carro de la lista
                //                muestra_carros_espera();
            }
        }
        else
        {

            if(termine_trabajos())
            {
                cout<<"generando reporte ..."<<endl;
                muestra_tiempo_carro_taller("P44322");
                muestra_tiempo_area_mas_demorada();
                m_tiempo_fin = tiempo_hora_actual();
                generar_reporte();
                exit(1);




            }

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

    // inserto un carro si no existe en la lista
    auto it = find(carros.cbegin(),carros.cend(),carro);
    if(it == carros.end())
    {
        carros.push_back(carro);
    }
    //-----------------------------------


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
        return false;
    }
    else
    {
        inicia_trabajos(carro);
        return true;
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
        if((*it->getMatricula() == *matricula))
            cout<<"carro "<<it->getMatricula()<<" tiempo en taller "<<it->getAllTime()<< " "<<it.use_count()<<endl;
}

void ctaller::muestra_tiempo_area_mas_demorada()
{
    auto eAux = ((ceareaproductiva*)empleados.begin()->get());
    for (auto e: empleados )
    {

        if(typeid(*e) == typeid(ceareaproductiva))
        {
            ceareaproductiva *eap = (ceareaproductiva*)e.get();
            cout<<"area demorada "<< eap->getTiempoDemora()<<" area "<<eap->getArea()<<endl;
            if((eap->getTiempoDemora() > eAux->getTiempoDemora()))
                eAux = eap;
        }
    }
    cout<<" esta es el  area mas demorada "<< eAux->getTiempoDemora()<<" area "<<eAux->getArea()<<endl;
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
                    if(eap->getCarro() != nullptr)
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

void ctaller::generar_reporte()
{
    ofstream f;
    string nombreF = "reporte_taller.txt";
    f.open (nombreF, ios::out /*| ios::app*/ );
    f << " <<<< Reporte del Taller: "<<m_nombre<<" >>>>"<<endl;
    f <<endl;
    f << " Inicio de trabajos: "<<m_tiempo_ini<<endl;
    f <<endl;
    f << "|------- Empleados -------|"<<endl;
    f << "Total de empleados: "<<empleados.size() <<endl;
    for(auto e: empleados)
    {
        f <<e->getId() <<" -> "<< e->getNombre()<<endl;
        if(typeid(*e) == typeid(ceareaproductiva))
        {
            ceareaproductiva *eap = (ceareaproductiva*)e.get();
            f<<"Area "<< areaToStr(eap->getArea())<<" tiempo mas malo "<< eap->getTiempoDemora()<<endl;
        }
    }
    f <<endl;f <<endl;
    f << "|------- Carros -------|"<<endl;
    f << "Total de Carros: "<<carros.size() <<endl;
    for(auto c: carros)
    {
        f <<c->getMatricula() <<" -> "<< c->getAnno()<<" (";
        for(auto t: c.get()->getArea())
            f <<" "<< areaToStr(t);
        f <<" ) "<<endl;
        f <<"Tiempo total en taller: "<<c->getAllTime()<<endl;
    }
    f <<endl;
    f << " Fin de trabajos: "<<m_tiempo_fin<<endl;
    f.close();
}

bool ctaller::termine_trabajos()
{
    for(auto e: empleados)
    {
        if(typeid(*e.get()) == typeid(ceareaproductiva))
        {
            ceareaproductiva *eap = (ceareaproductiva*)e.get();
            if(eap->getCarro() != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}
