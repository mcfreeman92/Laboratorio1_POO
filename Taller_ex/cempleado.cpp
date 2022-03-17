#include "cempleado.h"

cempleado::~cempleado()
{

}

cempleado::cempleado(cempleado &e) :
    m_dni(e.getDNI())
{
     setNombre(e.getNombre());
}

cempleado::cempleado(const char *nombre, int dni, int id):
    m_dni(dni),
    m_id(id)
{
    setNombre(nombre);
}
