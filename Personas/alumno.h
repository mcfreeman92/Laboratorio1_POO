#ifndef ALUMNO_H
#define ALUMNO_H

#include <QObject>
#include "persona.h"

class Alumno : public Persona
{
    Q_OBJECT
private:
    string m_codigoAlumno;
    float m_notaFinal;

public:
    Alumno(const char * nombre, int edad, int ID, char *codigoAlumno, float notaFinal );
    void mostrar();
};

#endif // ALUMNO_H
