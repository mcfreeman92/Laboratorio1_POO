#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>
#include "persona.h"

class cEstudiante : public Persona
{
    Q_OBJECT
private:
    float m_notaFinal;

public:
    cEstudiante(const char * nombre, int edad, int ID, int idBD, float notaFinal );
    float getNotaFinal(){return m_notaFinal;};
    void  setNotaFinal(float notaFinal){notaFinal = m_notaFinal;};
    void mostrar();

};

#endif // ESTUDIANTE_H
