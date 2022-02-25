#include "ctaller.h"

CTaller::CTaller(char * nombre_comercial, char *direccion, QObject *parent) :
    QObject(parent),
    m_nombre_comercial(nombre_comercial),
    m_direccion(direccion),
    m_orden(0)
{
    for (int i = 0; i < MAX_EMPLEADOS; lEmpleados[i] = {nullptr}, ++i);
    for (int i = 0; i < MAX_CARROS_ESPERA;
         m_ListaEspera[i] = make_tuple(0,nullptr,eTrabajo::ninguno,eTrabajo::ninguno,
                                       eTrabajo::ninguno),++i);
}

bool CTaller::insertar_empleado(cEmpleado *empleado)
{
    bool aux = false;
    if(!exixteEmpleado(empleado))
        for (int i = 0; i < MAX_EMPLEADOS; ++i) {
            if(lEmpleados[i] == nullptr)
            {
                lEmpleados[i] = empleado;
                connect(lEmpleados[i],SIGNAL(s_trabajoTerminado()),this,SLOT(trabajoTerminado()));
                aux = true;
                break;
            }
        }
    return aux;
}

bool CTaller::exixteEmpleado(cEmpleado *empleado)
{
    bool aux = false;

    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(!(lEmpleados[i] == nullptr))
        {
            if(lEmpleados[i]->getId() == empleado->getId())
            {
                aux = true;
                break;
            }
        }
    }

    return aux;
}

bool CTaller::eliminar_empleado(cEmpleado *empleado)
{
    bool aux = false;

    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] != nullptr)
            if(lEmpleados[i] == empleado)
            {
                lEmpleados[i] = nullptr;
                aux=true;
                break;
            }
    }
    return aux;
}

bool CTaller::insertar_nuevo_carro(shared_ptr<cCarro> carro, eTrabajo trabajo1, eTrabajo trabajo2, eTrabajo trabajo3)
{
    bool aux = false;

    if(trabajoDisponible(trabajo1)&&trabajoDisponible(trabajo2)&&trabajoDisponible(trabajo3))
    {
        LOG("carro "<<carro->getMatricula()<<" en trabajos...");
        aux = true;
        asignarEmpleado(carro,trabajo1);
        asignarEmpleado(carro,trabajo2);
        asignarEmpleado(carro,trabajo3);
    }
    else
    {
        LOG("carro "<<carro->getMatricula()<<" en espera...");
        m_orden++;
        insertaEspera(make_tuple(m_orden,carro,trabajo1,trabajo2,trabajo3));
    }

    return aux;
}

char* CTaller::TrabajoToStr(eTrabajo t){
    char * str = nullptr;
    switch (t) {
    case 1:
        str = "pintura";
        break;
    case 2:
        str = "mecanica";
        break;
    case 3:
        str = "electronica";
        break;
    }
    return str;
}

void CTaller::areaMasDemorada()
{
    ordena(lEmpleados);
    LOG("El area mas demorada es " << TrabajoToStr(lEmpleados[0]->getTipoEmpleo()));

}

void CTaller::ajustaLista()
{

};

void CTaller::busca_carro_espera(char *matricula)
{
    for(auto e: m_ListaEspera)
    {
        if(get<0>(e) != 0)
            if(get<1>(e)->getMatricula() == matricula)
            {
                LOG("trabajos del carro " << matricula);
                if(get<2>(e))
                    LOG(TrabajoToStr(get<2>(e)));
                if(get<3>(e))
                    LOG(TrabajoToStr(get<3>(e)));
                if(get<4>(e))
                    LOG(TrabajoToStr(get<4>(e)));
                return;
            }
    }
}

void CTaller::ordena(cEmpleado* arr[], int n)
{
        if (n == 1)return;

        for (int i = 0; i < n - 1; i++) {
            if((arr[i] != nullptr) && (arr[i+1] != nullptr))
            {
            if (arr[i]->getDemora() < arr[i + 1]->getDemora()) {
                swap(arr[i], arr[i + 1]);
            }
            }
            else break;
        }

        ordena(arr, n - 1);
}



bool CTaller::trabajoDisponible(eTrabajo trabajo)
{
    bool aux = false;

    if(!trabajo) return true;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == nullptr) break;
        if((lEmpleados[i]->getTipoEmpleo() == trabajo)&&(!lEmpleados[i]->getOcupado()))
        {
            aux = true;
            break;
        }
    }

    return aux;
}

bool CTaller::asignarEmpleado(shared_ptr<cCarro> carro, eTrabajo trabajo)
{
    bool aux = false;

    if(!trabajo) return true;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == nullptr) break;
        if((lEmpleados[i]->getTipoEmpleo() == trabajo)&&(!lEmpleados[i]->getOcupado()))
        {
            aux = true;
            lEmpleados[i]->setCarro(carro);
            break;
        }
    }

    return aux;
}

void CTaller::insertaEspera(tuple<int,shared_ptr<cCarro>,eTrabajo,eTrabajo,eTrabajo> carro_espera)
{
    bool aux = false;

    //me aseguro que no existe este carro
    for(int i = 0;i<MAX_CARROS_ESPERA;i++)
        if(get<0>(m_ListaEspera[i]) != 0)
            if(get<1>(m_ListaEspera[i]) == get<1>(carro_espera)) return;

    //busco una pos vacia para insertarlo
    for(int i = 0;i<MAX_CARROS_ESPERA;i++)
    {
        if(get<0>(m_ListaEspera[i]) == 0)
        {
            m_ListaEspera[i] = carro_espera;
            aux = true;
            break;
        }
    }
}

void CTaller::trabajoTerminado()
{
    //lista ya est'a vacia
    bool aux = false;
    for(int i = 0;i<MAX_CARROS_ESPERA;i++)
        if(get<0>(m_ListaEspera[i]) != 0){ aux = true; break;}
    if(!aux)  areaMasDemorada();


    for(int i = 0;i<MAX_CARROS_ESPERA;i++)
        if(get<0>(m_ListaEspera[i]) != 0)
            if(insertar_nuevo_carro(get<1>(m_ListaEspera[i]),get<2>(m_ListaEspera[i]),get<3>(m_ListaEspera[i]),get<4>(m_ListaEspera[i])))
            {
                m_ListaEspera[i] = make_tuple(0,nullptr,eTrabajo::ninguno,eTrabajo::ninguno,eTrabajo::ninguno);
                return;
            }

    //        ordena(m_ListaEspera,MAX_CARROS_LISTOS);
}
