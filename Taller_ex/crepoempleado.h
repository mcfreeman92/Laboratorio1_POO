#ifndef CREPOEMPLEADO_H
#define CREPOEMPLEADO_H
#include <iostream>
#include <fstream>
#include <memory.h>


class ccarro;

class crepoempleado
{
public:
    crepoempleado();
    void insertar(ccarro);
    void eliminar();
    void modificar();
    ccarro buscar(int id);
};

#endif // CREPOEMPLEADO_H
