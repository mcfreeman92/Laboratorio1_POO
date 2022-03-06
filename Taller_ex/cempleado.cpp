#include "cempleado.h"

cempleado::cempleado()
{

}

cempleado::cempleado(cempleado &e) :
    m_id(e.getId())
{
    memcpy(m_nombre,e.getNombre(),TAM_NOMBRE);
}

cempleado::cempleado(const char *nombre, int id)
{
    memcpy(m_nombre,nombre,TAM_NOMBRE);
    m_id = id;
//    connect(&m_reloj,SIGNAL(timeout()),this,SIGNAL(on_run()));
//    connect(&m_reloj,SIGNAL(timeout()),this,SIGNAL(s_trabajo_terminado()));
}
