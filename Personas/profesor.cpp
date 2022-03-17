#include "profesor.h"
cProfesor::~cProfesor()
{

}

cProfesor::cProfesor(Persona & e, float creditos)
{
    cProfesor(e.getNombre(),e.getEdad(),e.getId(),e.getIdBD(),creditos);
}

cProfesor::cProfesor(const char * nombre, int edad, int ID, int idBD, float creditos) :
    Persona(nombre,edad,ID,idBD),
    m_credito(creditos)
{

}

void cProfesor::mostrar()
{
    Persona::mostrar();
    cout<< "Creditos: " << m_credito << endl;
}
