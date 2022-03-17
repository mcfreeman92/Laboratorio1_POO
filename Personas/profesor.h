#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QObject>
#include "persona.h"
#include "estudiante.h"
#include <memory>
class cProfesor : public Persona
{
    Q_OBJECT
private:
    float m_credito;
    shared_ptr<cEstudiante> m_estudiante;

public:
    ~cProfesor();
    cProfesor(Persona &, float creditos);
    cProfesor(const char *nombre = "", int edad = 0, int ID = 0, float creditos= 0.0f);

    void  setCredito(float credito){m_credito = credito;};
    void  setEstudiante(shared_ptr<cEstudiante> estudiante){m_estudiante = estudiante;};

    float getCredito(){return m_credito;};
    shared_ptr<cEstudiante>  getEstudiante(){return m_estudiante;};

    void mostrar();
};

#endif // EMPLEADO_H
