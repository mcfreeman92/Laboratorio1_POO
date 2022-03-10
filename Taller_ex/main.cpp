#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "ctaller.h"
#include "crepoempleado.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ctaller taller("bartolete","playa");

    shared_ptr<ceareaproductiva> e1= make_shared<ceareaproductiva>("pintor",1,eArea::pintura);
    shared_ptr<ceareaproductiva> e2= make_shared<ceareaproductiva>("electrico",2,eArea::electrica);
    shared_ptr<ceareaproductiva> e3= make_shared<ceareaproductiva>("pintor1",3,eArea::pintura);
    shared_ptr<ceareaproductiva> e4= make_shared<ceareaproductiva>("mecanico",4,eArea::mecanica);

    std::vector<eArea> trabajos1 = {eArea::mecanica, eArea::pintura, eArea::electrica};
    std::vector<eArea> trabajos2 = {eArea::pintura,eArea::electrica};
    std::vector<eArea> trabajos3 = {eArea::mecanica,eArea::pintura};

    shared_ptr<ccarro> carro1 = make_shared<ccarro>("B12345",2019,trabajos1);
    shared_ptr<ccarro> carro2 = make_shared<ccarro>("P22344",2020,trabajos2);
    shared_ptr<ccarro> carro3 = make_shared<ccarro>("P44322",1992,trabajos3);


    crepoempleado repo;
    repo.insertar(*carro1.get());
    repo.insertar(*carro2.get());
    repo.insertar(*carro3.get());

    taller.insertar_empleado(e1);
    taller.insertar_empleado(e2);
    taller.insertar_empleado(e3);
    taller.insertar_empleado(e4);

    taller.eliminar_empleado(3);

    taller.insertar_carro(carro1);
    taller.insertar_carro(carro2);
    taller.insertar_carro(carro3);


//    taller.muestra_trabajos_carro_espera("B12345");
//    taller.eliminar_carro_espera("B12345");

    //return 0;
    return a.exec();
}
