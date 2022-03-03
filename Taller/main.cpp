#include <QCoreApplication>

#include "ctaller.h"

using namespace std::chrono;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    cout << "Taller Hola Mundo FORD" << endl;

    CTaller taller("Bartolete","Playa");

    cEmpleado empleado1("PINTOR",1,eTrabajo::pintura);
    cEmpleado empleado2("MECANICO",2,eTrabajo::mecanica);
    cEmpleado empleado3("ELECTRICO",3,eTrabajo::electronica);

    shared_ptr<cCarro> carro1 = make_shared<cCarro>(2019,"B12345");
    shared_ptr<cCarro> carro2 = make_shared<cCarro>(2020,"P22344");
    shared_ptr<cCarro> carro3 = make_shared<cCarro>(1992,"P44322");

    taller.insertar_empleado(&empleado1);
    taller.insertar_empleado(&empleado2);
    taller.insertar_empleado(&empleado3);

    taller.insertar_nuevo_carro(carro1,eTrabajo::mecanica,eTrabajo::pintura);
    taller.insertar_nuevo_carro(carro2,eTrabajo::mecanica);
    taller.insertar_nuevo_carro(carro3,eTrabajo::electronica,eTrabajo::pintura,eTrabajo::mecanica);

    taller.busca_carro_espera(carro2->getMatricula());

    return a.exec();
}
