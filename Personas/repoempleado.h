#ifndef REPOEMPLEADO_H
#define REPOEMPLEADO_H

#include <QObject>
#include <typeinfo>

#include <fstream> // flujo de archivo
#include <memory>
#include <sys/stat.h>
#include "universitario.h"
#include "estudiante.h"
#include "profesor.h"

class RepoEmpleado : public QObject
{
    Q_OBJECT
private:
    std::vector<shared_ptr<cProfesor>> empleados;
    const char *m_filename;
    int generaId();
    int tam_fichero();


public:
    RepoEmpleado();

    void insertar_empleado(shared_ptr<cProfesor> &empleado);
    bool guardarEmpleados(shared_ptr<cProfesor> &empleado);
    list<shared_ptr<cProfesor> > leerEmpleados();

    bool eliminar(int id);
    bool modificar(shared_ptr<cProfesor> &empleado);
signals:

};

#endif // REPOEMPLEADO_H
