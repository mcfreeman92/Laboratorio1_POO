#include "ctaller.h"

CTaller::CTaller(char * nombre_comercial, char *direccion, QObject *parent) :
    QObject(parent),
    m_nombre_comercial(nombre_comercial),
    m_direccion(direccion)
{
    for (int i = 0; i < MAX_EMPLEADOS; lEmpleados[i] = {nullptr}, ++i);
}

bool CTaller::insertar_empleado(cEmpleado *empleado)
{
    bool aux = false;
    if(!exixteEmpleado(empleado))
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

bool CTaller::exixteEmpleado(cEmpleado *empleado)
{
    bool aux = false;

    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(!(lEmpleados[i] == 0))
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
    if(!empleado->getOcupado()&&empleado->getCarro()==nullptr)
        delete empleado;

    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if((lEmpleados[i]->getId() != empleado->getId())&&(lEmpleados[i] == 0))
        {
            break;
        }
    }
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
    bool aux = false;
    for (int i = 0; i < MAX_EMPLEADOS; ++i) {
        if(lEmpleados[i] == 0) break;
        if((lEmpleados[i]->getCarro() == carro)&&(lEmpleados[i]->getOcupado()))
        {
            aux = true;
            break;
        }
    }

    if(!aux)
    {
        qDebug()<<carro->getMatricula();
        carros_terminados(carro);
    }
    //pregunto si no le falta algun otro trabajo
    //recorro la lista y pregunto si alguien tiene este carro asignado
}
