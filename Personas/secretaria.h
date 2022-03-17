#ifndef RECEPCION_H
#define RECEPCION_H

#include <QObject>
#include <QDebug>
#include <typeinfo>

#include <fstream> // flujo de archivo
#include <memory>
#include <sys/stat.h>
#include "estudiante.h"
#include "profesor.h"
#include "repoprofesor.h"
#include "repouniversitario.h"

class cSecretaria : public QObject
{
    Q_OBJECT
private:
    std::list<shared_ptr<Persona>> personas;
    const char *m_filename;
    RepoProfesor m_repProfe;
public:
    cSecretaria();

    void insertar_persona(shared_ptr<cProfesor> &profesor);
    void insertar_persona(shared_ptr<cEstudiante> &estudiante);
    void eliminar_persona(int id);
    void modifica_persona(int id);

    bool asignarEstudianteTutor();
    bool eliminaTutoria(int id);
    void asignarNotafinalEstudiante(int id);
    void asignar_a_Estudiante(int id);
    float solicita_Creditos(int id);
    float solicita_NotaFinal(int id);

    void muestra_todos_profesores();
    void muestra_todos_estudiantes();
    void muestra_todos();

signals:

};

#endif // RECEPCION_H
