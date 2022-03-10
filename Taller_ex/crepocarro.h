#ifndef CREPOCARRO_H
#define CREPOCARRO_H

#include <QObject>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <sys/stat.h>

class ccarro;

using namespace std;

class crepocarro : public QObject
{
    Q_OBJECT
public:
     crepocarro();
     void insertar(std::shared_ptr<ccarro> carro);
     void eliminar();
     void modificar();
     shared_ptr<ccarro> buscar(int id = 1);

private:
    int generaID();
    const char * m_filename;
};

#endif // CREPOCARRO_H
