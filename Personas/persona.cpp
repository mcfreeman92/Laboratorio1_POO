#include "persona.h"

Persona::Persona()
{

}

Persona::Persona(Persona &p) : m_edad(p.getEdad()), m_ID(p.getId())
{
    setNombre(p.getNombre());
}

Persona::Persona(const char *nombre, int edad, int ID)
{
    m_ID = ID;
    setNombre(nombre);
    m_edad = edad;
}

void Persona::mostrar()
{
    cout << "Nombre: " << m_nombre << endl;
    cout << "Edad: " << m_edad << endl;
    cout << "ID: " << m_ID << endl;
}
