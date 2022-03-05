#ifndef CEAREAPRODUCTIVA_H
#define CEAREAPRODUCTIVA_H

#include "cempleado.h"
#include "ccarro.h"
#include <memory>

using namespace std;

class ceareaproductiva : public cempleado
{
public:
    enum eArea
    {
       mecanica = 1,
       pintura = 2,
       electrica = 3
    };

    ceareaproductiva();
    ceareaproductiva(cempleado &e, eArea area);
    ceareaproductiva(const char *nombre, int id, eArea area);

    void setCarro(shared_ptr<ccarro> carro){m_carro = carro;}

    shared_ptr<ccarro> getCarro(){return m_carro;}
    eArea getArea(){return m_area;}

private:
    shared_ptr<ccarro> m_carro;
    eArea m_area;
};

#endif // CEAREAPRODUCTIVA_H
