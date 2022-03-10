#include "cempleado.h"

cempleado::cempleado()
{

}

cempleado::cempleado(cempleado &e) :
    m_id(e.getId())
{
     setNombre(e.getNombre());
}

cempleado::cempleado(const char *nombre, int id):
    m_id(id)
{
    setNombre(nombre);
}
