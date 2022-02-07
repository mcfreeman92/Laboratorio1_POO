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
    lEmpleados[0] = {nullptr};
    lEmpleados[1] = {nullptr};
    lEmpleados[2] = {nullptr};
    lEmpleados[3] = {nullptr};
    lEmpleados[4] = {nullptr};
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
    empleado->setCarro(carro);
    //empl
}
