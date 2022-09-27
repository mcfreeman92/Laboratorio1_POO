#include "universitario.h"

Universitario::Universitario(const char * nombre, int edad, int ID, float notaFinal, const char * carrera) : Estudiante(nombre,edad,ID,notaFinal)
{
   memcpy(m_carrera,carrera,30);
}

void Universitario::mostrar()
{
    Persona::mostrar();
    cout << "Carrera: " << m_carrera << endl;
}
