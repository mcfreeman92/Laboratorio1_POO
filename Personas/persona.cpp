#include "persona.h"

Persona::Persona()
{

}

Persona::Persona(Persona &p) : m_edad(p.getEdad()), m_ID(p.getId())
{
    setNombre(p.getNombre());
}

Persona::Persona(const char *nombre, int edad, int ID, int idBD):
  m_edad(edad),
  m_ID(ID),
  m_idBD(idBD)
{
    setNombre(nombre);
}

void Persona::mostrar()
{
    cout << "Nombre: " << m_nombre << endl;
    cout << "Edad: " << m_edad << endl;
    cout << "ID: " << m_ID << endl;
}
