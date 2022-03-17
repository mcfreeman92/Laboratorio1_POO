#include "estudiante.h"


cEstudiante::cEstudiante(const char * nombre, int edad, int ID, int idBD, float notaFinal) :
    Persona(nombre,edad,ID,idBD)
{
    m_notaFinal = notaFinal;
}

void cEstudiante::mostrar()
{
    Persona::mostrar();
    cout << "Nota Final: " << m_notaFinal << endl;
}
