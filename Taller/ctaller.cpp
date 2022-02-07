#include "ctaller.h"

CTaller::CTaller(QObject *parent) : QObject(parent)
{
    inicializa_empleados();
}

bool CTaller::insertar_nuevo_empleado(cEmpleado *empleado)
{
    bool aux = false;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == 0)
        {
            lEmpleados[i] = empleado;
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
    if(disponibilidadEmpleado(trabajo1)&&
            disponibilidadEmpleado(trabajo2)&&
            disponibilidadEmpleado(trabajo3))
    {
        aux = true;
    }
    return aux;
}

void CTaller::inicializa_empleados()
{
    for (int i = 0; i < MAX_EMPLEADOS; lEmpleados[i] = {nullptr}, ++i);
}

bool CTaller::disponibilidadEmpleado(eTrabajo trabajo)
{
    bool aux = false;
    if(!trabajo) return true;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if((lEmpleados[i]->getTipoEmpleo() == trabajo)&&(!lEmpleados[i]->getOcupado()))
        {
            aux = true;
            break;
        }
    }
    return aux;
}

bool CTaller::asignarCarro_Empleado(cCarro *carro, cEmpleado *empleado)
{
    bool aux = false;
    if((!empleado->getOcupado()))
    {
        empleado->setCarro(carro);
        aux = true;
    }
    return aux;

}
