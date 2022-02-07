#ifndef CTALLER_H
#define CTALLER_H

#include <QObject>
#include "cempleado.h"

class CTaller : public QObject
{
    Q_OBJECT
public:
    explicit CTaller(QObject *parent = nullptr);

    bool insertar_nuevo_empleado(cEmpleado* empleado);
    bool insertar_nuevo_carro(cCarro* carro, eTrabajo trabajo1 = eTrabajo::ninguno,
                                             eTrabajo trabajo2 = eTrabajo::ninguno,
                                             eTrabajo trabajo3 = eTrabajo::ninguno);

private:
    cEmpleado* lEmpleados[MAX_EMPLEADOS];
    void inicializa_empleados();
    bool disponibilidadEmpleado(eTrabajo trabajo);
    bool asignarCarro_Empleado(cCarro* carro,cEmpleado* empleado);
signals:

};

#endif // CTALLER_H
