#include "cempleado.h"

cempleado::cempleado():    
    m_nombre("")
{
    m_id = 0;
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
}