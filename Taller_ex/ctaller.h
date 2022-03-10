#ifndef CTALLER_H
#define CTALLER_H

#include <QObject>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include "ceareaproductiva.h"
#include "ceareaservicio.h"

using namespace std;

class ctaller : public QObject
{
    Q_OBJECT
public:
    ctaller(const char* nombre, const char* direccion);
    void insertar_empleado(shared_ptr<ceareaproductiva> &empleado);
    void insertar_empleado(shared_ptr<ceareaservicio> &empleado);
    bool insertar_carro(shared_ptr<ccarro> &carro);
    bool eliminar_empleado(int id);
    shared_ptr<ccarro> muestra_trabajos_carro_espera(const char *matricula);
    void muestra_tiempo_carro_taller(const char *matricula);
    bool eliminar_carro_espera(const char *matricula);

private:
    char m_nombre[20];
    char m_direccion[40];
    std::vector<shared_ptr<cempleado>> empleados;
    std::list<shared_ptr<ccarro>> areaEspera, carros;
    std::string m_tiempo_ini, m_tiempo_fin;

    void muestra_empleados();
    void muestra_carros_espera();
    void muestra_tiempo_area_mas_demorada();
    void muestra_areas(shared_ptr<ccarro> &carro);
    bool disponibilidad_trabajos(shared_ptr<ccarro> &carro);
    void inicia_trabajos(shared_ptr<ccarro> &carro);

    void generar_reporte();
    bool termine_trabajos();

    const char *areaToStr(eArea a);    
    std::string tiempo_hora_actual();
};

#endif // CTALLER_H
