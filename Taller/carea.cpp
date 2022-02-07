#include "carea.h"

cArea::cArea()
{
     m_plaza = false;
}

void cArea::setNuevoEmpleado(int id, char *nombre)
{
    m_empleado = new cEmpleado(id, nombre);
    m_plaza = true;
}

bool cArea::eliminaEmpleado()
{
    delete m_empleado;
    m_plaza = false;
    return true;
}

