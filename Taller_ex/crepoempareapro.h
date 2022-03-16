#ifndef CREPOEMPAREAPRO_H
#define CREPOEMPAREAPRO_H
#include <QObject>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <sys/stat.h>

class cempleado;
class ceareaproductiva;

using namespace std;

class crepoempareapro: public QObject
{
    Q_OBJECT

public:
    crepoempareapro();
    bool insertar(shared_ptr<ceareaproductiva> &empl);
    bool eliminar(int id);
    bool modificar(shared_ptr<ceareaproductiva> &empl);
    std::vector<shared_ptr<cempleado>> leerTodo();
private:
    int generaID();
    int tam_fichero();
    const char * m_filename;
};

#endif // CREPOEMPAREAPRO_H
