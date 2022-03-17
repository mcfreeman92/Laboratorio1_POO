#ifndef REPOUNIVERSITARIO_H
#define REPOUNIVERSITARIO_H

#include <typeinfo>

#include <fstream> // flujo de archivo
#include <memory>
#include <sys/stat.h>
#include "universitario.h"

class RepoUniversitario
{
public:
    RepoUniversitario();

    void insertar_universitario(shared_ptr<Universitario> &universitario);
    bool guardar_universitarios(shared_ptr<Universitario> &universitario);
    list<shared_ptr<Universitario> > leerUniversitarios();

    bool eliminar(int id);
private:
    std::vector<shared_ptr<Universitario>> universitarios;
    const char *m_filename;
    int generaId();
    int tam_fichero();

};

#endif // REPOUNIVERSITARIO_H
