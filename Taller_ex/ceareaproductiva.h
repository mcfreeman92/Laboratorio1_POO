#ifndef CEAREAPRODUCTIVA_H
#define CEAREAPRODUCTIVA_H

#include "cempleado.h"
#include "ccarro.h"
#include <memory>

using namespace std;

class ceareaproductiva : public cempleado
{

public:
    ceareaproductiva();
    ~ceareaproductiva();
    ceareaproductiva(cempleado &e, eArea area);
    ceareaproductiva(const char *nombre, int id, eArea area);

    void setCarro(shared_ptr<ccarro> carro);

    shared_ptr<ccarro> getCarro(){return m_carro;}
    eArea getArea(){return m_area;}

public slots:
    void on_run();

private:
    shared_ptr<ccarro> m_carro;
    eArea m_area;

};

#endif // CEAREAPRODUCTIVA_H
