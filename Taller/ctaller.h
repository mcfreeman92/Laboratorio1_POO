#ifndef CTALLER_H
#define CTALLER_H

#include <QObject>
#include <QDebug>
#include "cempleado.h"

using namespace std;

class CTaller : public QObject
{
    Q_OBJECT
public:
    explicit CTaller(char* nombre_comercial, char* direccion, QObject *parent = nullptr);

    void setNombreComercial(char* nombre_comercial){m_nombre_comercial = nombre_comercial;}
    void setDireccion(char* direccion){m_direccion = direccion;}

    bool insertar_empleado(cEmpleado* empleado);
    bool eliminar_empleado(cEmpleado* empleado);

    bool insertar_nuevo_carro(shared_ptr<cCarro> carro, eTrabajo trabajo1 = eTrabajo::ninguno,
                                             eTrabajo trabajo2 = eTrabajo::ninguno,
                                             eTrabajo trabajo3 = eTrabajo::ninguno);

private:
    void ordena(tuple<int, cCarro, eTrabajo, eTrabajo, eTrabajo> &arr);
    cEmpleado* lEmpleados[MAX_EMPLEADOS];
    shared_ptr<cCarro> lCarrosEspera[MAX_CARROS_ESPERA];
    tuple<int,shared_ptr<cCarro>,eTrabajo,eTrabajo,eTrabajo> m_ListaEspera[MAX_CARROS_ESPERA];
    bool exixteEmpleado(cEmpleado* empleado);
    bool trabajoDisponible(eTrabajo trabajo);
    void insertaEspera(tuple<int, shared_ptr<cCarro>, eTrabajo,eTrabajo,eTrabajo> carro_espera);
    bool asignarEmpleado(shared_ptr<cCarro> carro, eTrabajo trabajo);
    char *m_nombre_comercial;
    char *m_direccion;
    int m_orden;
private slots:

    void trabajoTerminado();

};

#endif // CTALLER_H
