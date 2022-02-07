#include "cempleado.h"

cEmpleado::cEmpleado()
{

}

cEmpleado::cEmpleado(char *nombre, int id, int tipo_empleo):
    m_ocupado(false),
    m_tiempo_trabajo(5000)
{
    connect(&m_reloj,SIGNAL(timeout()),this,SLOT(terminaTrabajo()));
    memcpy(m_nombre,nombre,20);
    m_id = id;
    m_tipo_empleo = tipo_empleo;
}

void cEmpleado::terminaTrabajo()
{

}
