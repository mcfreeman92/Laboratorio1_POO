#ifndef CTALLER_H
#define CTALLER_H

#include <QObject>
#include <QDebug>
#include "cempleado.h"

class CTaller : public QObject
{
    Q_OBJECT
public:
    explicit CTaller(char* nombre_comercial, char* direccion, QObject *parent = nullptr);

    void setNombreComercial(char* nombre_comercial){m_nombre_comercial = nombre_comercial;}
    void setDireccion(char* direccion){m_direccion = direccion;}

    bool insertar_empleado(cEmpleado* empleado);
    bool eliminar_empleado(cEmpleado* empleado);

    bool insertar_nuevo_carro(cCarro* carro, eTrabajo trabajo1 = eTrabajo::ninguno,
                                             eTrabajo trabajo2 = eTrabajo::ninguno,
                                             eTrabajo trabajo3 = eTrabajo::ninguno);

private:
    cEmpleado* lEmpleados[MAX_EMPLEADOS];
    cCarro* lCarrosListos[MAX_CARROS_LISTOS];
    bool exixteEmpleado(cEmpleado* empleado);
    bool trabajoDisponible(eTrabajo trabajo);
    bool carros_terminados(cCarro* carro);
    bool asignarEmpleado(cCarro* carro, eTrabajo trabajo);
    char *m_nombre_comercial;
    char *m_direccion;

private slots:
    void trabajoTerminado(cCarro* carro);

};

#endif // CTALLER_H
