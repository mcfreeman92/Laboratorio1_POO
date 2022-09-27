#ifndef UNIVERSITARIO_H
#define UNIVERSITARIO_H

#include <QObject>
#include "estudiante.h"
class Universitario : public cEstudiante
{
    Q_OBJECT
private:
    char m_carrera[30];
public: 
    Universitario(const char *nombre, int edad, int ID, float notaFinal, const char * carrera);
    void mostrar();
    char * getCarrera(){return m_carrera;};

};

#endif // UNIVERSITARIO_H
