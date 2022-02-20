#include "ctaller.h"

CTaller::CTaller(char * nombre_comercial, char *direccion, QObject *parent) :
    QObject(parent),
    m_nombre_comercial(nombre_comercial),
    m_direccion(direccion),
    m_orden(0)
{
    for (int i = 0; i < MAX_EMPLEADOS; lEmpleados[i] = {nullptr}, ++i);
    //    for (int i = 0; i < MAX_CARROS_ESPERA; lCarrosEspera[i] = {nullptr}, ++i);
    for(auto e: m_ListaEspera){
        e = make_tuple(0,nullptr,eTrabajo::ninguno,eTrabajo::ninguno,eTrabajo::ninguno);
    }
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

//bool CTaller::carros_terminados(cCarro *carro)
//{
//    bool aux = false;
//    for (int i = 0; i < MAX_CARROS_LISTOS; ++i) {
////        if(lCarrosListos[i] == nullptr)
//        {
////            lCarrosListos[i] = carro;
////            qDebug()<<lCarrosListos[i]->getMatricula();
//            aux = true;
//            break;
//        }
//    }
//    return aux;
//}

bool CTaller::insertar_nuevo_carro(shared_ptr<cCarro> carro, eTrabajo trabajo1, eTrabajo trabajo2, eTrabajo trabajo3)
{
    bool aux = false;

    if(trabajoDisponible(trabajo1)&&trabajoDisponible(trabajo2)&&trabajoDisponible(trabajo3))
    {
        aux = true;
        asignarEmpleado(carro,trabajo1);
        asignarEmpleado(carro,trabajo2);
        asignarEmpleado(carro,trabajo3);
    }
    else
    {
        m_orden++;
        insertaEspera(make_tuple(m_orden,carro,trabajo1,trabajo2,trabajo3));
    }

    return aux;
}

void CTaller::ordena(tuple<int, cCarro, eTrabajo, eTrabajo, eTrabajo> &arr)
{
//    if (n == 1)return;

//    for (int i = 0; i < n - 1; i++) {
//        if (arr[i] > arr[i + 1]) {
//            swap(arr[i], arr[i + 1]);
//        }
//    }

//    ordena(arr, n - 1);
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
    for(auto e: m_ListaEspera)
        if(get<0>(e) != 0)
            if(get<1>(e) == get<1>(carro_espera)) return;

    //busco una pos vacia para insertarlo
    for(auto e: m_ListaEspera)
    {
        if(get<0>(e) == 0)
        {
            e = carro_espera;
            aux = true;
            break;
        }
    }
}

void CTaller::trabajoTerminado()
{
    for(auto e: m_ListaEspera)
        if(get<0>(e) != 0)
            if(insertar_nuevo_carro(get<1>(e),get<2>(e),get<3>(e),get<4>(e)))
            {
                e = make_tuple(0,nullptr,eTrabajo::ninguno,eTrabajo::ninguno,eTrabajo::ninguno);

                return;
            }

//    ordena(m_ListaEspera);
}
