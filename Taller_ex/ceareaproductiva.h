#ifndef CEAREAPRODUCTIVA_H
#define CEAREAPRODUCTIVA_H

#include "cempleado.h"
#include "ccarro.h"
#include <memory>
#include <QTimer>

using namespace std;

class ceareaproductiva : public cempleado
{
public:
    ~ceareaproductiva();
//    ceareaproductiva(ceareaproductiva &e);
    ceareaproductiva(const char *nombre = "", int dni = 0, int id = 0, eArea area = (eArea)0);

    void setCarro(shared_ptr<ccarro> carro);

    shared_ptr<ccarro> getCarro(){return m_carro;}
    eArea getArea(){return m_area;}
    double getTiempoDemora(){return m_tdemora;}
public slots:
    void termina();

private:
    shared_ptr<ccarro> m_carro;
    eArea m_area;
    double m_tdemora;

};

#endif // CEAREAPRODUCTIVA_H
