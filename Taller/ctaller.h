#ifndef CTALLER_H
#define CTALLER_H

#include <QObject>
#include <QDebug>
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
    cCarro* lCarrosListos[MAX_CARROS_LISTOS];
    bool trabajoDisponible(eTrabajo trabajo);
    bool carros_terminados(cCarro* carro);
    bool asignarEmpleado(cCarro* carro, eTrabajo trabajo);

private slots:
    void trabajoTerminado(cCarro* carro);

};

#endif // CTALLER_H
