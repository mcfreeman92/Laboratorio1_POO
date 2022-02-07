#ifndef CAREA_H
#define CAREA_H
#include "cempleado.h"

class cArea
{
private:
    cEmpleado *m_empleado;
    int m_CantEmpleados;
    bool m_plaza;
public:
    cArea();
    int getCantidaEmpleados(){return m_CantEmpleados;}
    void setNuevoEmpleado(int id, char *nombre);
    cEmpleado*  getEmpleado(){return  m_empleado;}

    bool getPlazaOcupada(){return m_plaza;}
    bool eliminaEmpleado();


};

#endif // CAREA_H
