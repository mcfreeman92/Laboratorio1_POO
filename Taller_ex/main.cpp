#include <QCoreApplication>
#include <QDebug>
#include "ctaller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ctaller taller("bartolete","playa");

    shared_ptr<ceareaproductiva> e1= make_shared<ceareaproductiva>("lala",1,ceareaproductiva::eArea::pintura);
    shared_ptr<ceareaproductiva> e2= make_shared<ceareaproductiva>("lele",2,ceareaproductiva::eArea::electrica);
    shared_ptr<ceareaproductiva> e3= make_shared<ceareaproductiva>("lolo",3,ceareaproductiva::eArea::pintura);
    shared_ptr<ceareaproductiva> e4= make_shared<ceareaproductiva>("lulu",4,ceareaproductiva::eArea::mecanica);

    std::vector<ccarro::eArea> trabajos =  {ccarro::eArea::mecanica,ccarro::eArea::electrica,ccarro::eArea::pintura};
    std::vector<ccarro::eArea> trabajos1 = {ccarro::eArea::pintura,ccarro::eArea::mecanica};
    std::vector<ccarro::eArea> trabajos2 = {ccarro::eArea::electrica};
    shared_ptr<ccarro> carro1 = make_shared<ccarro>("B12345",2019,trabajos);
    shared_ptr<ccarro> carro2 = make_shared<ccarro>("P22344",2020,trabajos1);
    shared_ptr<ccarro> carro3 = make_shared<ccarro>("P44322",1992,trabajos2);

    taller.insertar_empleado(e1);
    taller.insertar_empleado(e2);
    taller.insertar_empleado(e3);
    taller.insertar_empleado(e4);

    taller.eliminar_empleado(3);

    e2->setCarro(carro3);
    taller.eliminar_empleado(2);

    taller.insertar_carro(carro1);
    taller.insertar_carro(carro2);
    taller.insertar_carro(carro3);

    taller.muestra_trabajos_carro_espera("B12345");
    taller.eliminar_carro_espera("B12345");


    return a.exec();
}
