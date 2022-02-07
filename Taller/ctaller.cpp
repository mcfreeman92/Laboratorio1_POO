#include "ctaller.h"

CTaller::CTaller(QObject *parent) : QObject(parent)
{
    for (int i = 0; i < MAX_EMPLEADOS; lEmpleados[i] = {nullptr}, ++i);
}

bool CTaller::insertar_nuevo_empleado(cEmpleado *empleado)
{
    bool aux = false;

    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == 0)
        {
            lEmpleados[i] = empleado;
            connect(lEmpleados[i],SIGNAL(s_trabajoTerminado(cCarro*)),this,SLOT(trabajoTerminado(cCarro*)));
            aux = true;
            break;
        }
    }

    return aux;
}

bool CTaller::carros_terminados(cCarro *carro)
{
    bool aux = false;
    for (int i = 0; i < MAX_CARROS_LISTOS; ++i) {
        if(lCarrosListos[i] == 0)
        {
            lCarrosListos[i] = carro;
            aux = true;
            break;
        }
    }
    return aux;
}

bool CTaller::insertar_nuevo_carro(cCarro *carro, eTrabajo trabajo1, eTrabajo trabajo2, eTrabajo trabajo3)
{
    bool aux = false;

    if(trabajoDisponible(trabajo1)&&trabajoDisponible(trabajo2)&&trabajoDisponible(trabajo3))
    {
        aux = true;
        asignarEmpleado(carro,trabajo1);
        asignarEmpleado(carro,trabajo2);
        asignarEmpleado(carro,trabajo3);
    }

    return aux;
}

bool CTaller::trabajoDisponible(eTrabajo trabajo)
{
    bool aux = false;

    if(!trabajo) return true;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == 0) break;
        if((lEmpleados[i]->getTipoEmpleo() == trabajo)&&(!lEmpleados[i]->getOcupado()))
        {
            aux = true;
            break;
        }
    }

    return aux;
}

bool CTaller::asignarEmpleado(cCarro *carro, eTrabajo trabajo)
{
    bool aux = false;

    if(!trabajo) return true;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == 0) break;
        if((lEmpleados[i]->getTipoEmpleo() == trabajo)&&(!lEmpleados[i]->getOcupado()))
        {
            aux = true;
            lEmpleados[i]->setCarro(carro);
            break;
        }
    }

    return aux;
}

void CTaller::trabajoTerminado(cCarro *carro)
{
    qDebug()<<carro->getMatricula();
    //pregunto si no le falta algun otro trabajo
    //recorro la lista y pregunto si alguien tiene este carro asignado
}
