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
     bool insertar(shared_ptr<ccarro> &carro);
     bool eliminar(int id);
     bool modificar(shared_ptr<ccarro> &carro);
     std::list<shared_ptr<ccarro>> leerTodo();
     bool checkExiste(int id);

private:
    int generaID(bool b = false);
    int tam_fichero();
    int m_sum;
    const char * m_filename;
};

#endif // CREPOCARRO_H
