#include "alumno.h"


Alumno::Alumno(const char *nombre, int edad, int ID, char * codigoAlumno, float notaFinal) : Persona(nombre,edad,ID)
{
    m_codigoAlumno = codigoAlumno;
    m_notaFinal = notaFinal;
}

void Alumno::mostrar()
{
    Persona::mostrar();
    cout << "CodigoAlumno: " << m_codigoAlumno << endl;
    cout << "Nota Final: " << m_notaFinal << endl;
}
