#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "ctaller.h"
#include "crepocarro.h"
#include "crepoempareapro.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ctaller taller("bartolete","playa");
//    crepocarro repo;
    crepoempareapro repo;

    shared_ptr<ceareaproductiva> e1= make_shared<ceareaproductiva>("pintor",1,eArea::pintura);
    shared_ptr<ceareaproductiva> e2= make_shared<ceareaproductiva>("electrico",2,eArea::electrica);
    shared_ptr<ceareaproductiva> e4= make_shared<ceareaproductiva>("mecanico",4,eArea::mecanica);

    std::vector<eArea> trabajos1 = {eArea::mecanica, eArea::pintura, eArea::electrica};
    std::vector<eArea> trabajos2 = {eArea::pintura,eArea::electrica};
    std::vector<eArea> trabajos3 = {eArea::electrica,eArea::pintura};

    shared_ptr<ccarro> carro1 = make_shared<ccarro>("B12345",2019,trabajos1);
    shared_ptr<ccarro> carro2 = make_shared<ccarro>("P22344",2020,trabajos2,5);
    shared_ptr<ccarro> carro3 = make_shared<ccarro>("P44322",1992,trabajos3);

   /* repo.insertar(carro1);
    repo.insertar(carro2);
    repo.insertar(carro3);
    repo.leerTodo();
    repo.eliminar(5);
    repo.leerTodo();
    carro2->setMatricula("5555AA");
    repo.modificar(carro2);
    repo.leerTodo();*/

//     repo.insertar(e1);
//     repo.insertar(e2);
//     repo.insertar(e4);
     repo.leerTodo();
     /*repo.eliminar(5);
     repo.leerTodo();
     carro2->setMatricula("5555AA");
     repo.modificar(carro2);
     repo.leerTodo();*/

    /*taller.insertar_empleado(e1);
    taller.insertar_empleado(e2);
    taller.insertar_empleado(e4);

    taller.insertar_carro(carro1);
    taller.insertar_carro(carro2);
    taller.insertar_carro(carro3);

    taller.muestra_trabajos_carro_espera("B12345");
    taller.eliminar_carro_espera("B12345");*/

    //return 0;
    return a.exec();
}
