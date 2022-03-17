#ifndef REPOEMPLEADO_H
#define REPOEMPLEADO_H

#include <QObject>
#include <typeinfo>

#include <fstream> // flujo de archivo
#include <memory>
#include <sys/stat.h>
#include "profesor.h"

class RepoProfesor : public QObject
{
    Q_OBJECT
private:
    std::vector<shared_ptr<cProfesor>> empleados;
    const char *m_filename;
    int generaId();
    int tam_fichero();


    int generaID();
public:
    RepoProfesor();

    bool insertar(shared_ptr<cProfesor> &profe);
    bool eliminar(int id);
    bool existe();
    bool modificar(shared_ptr<cProfesor> &profe);
    std::list<shared_ptr<cProfesor>> leerTodo();

};

#endif // REPOEMPLEADO_H
