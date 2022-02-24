#include <QCoreApplication>

#include "ctaller.h"

using namespace std::chrono;

int main(int argc, char *argv[])
{

//         seconds s(1);
//        cout << duration_cast<microseconds>(s);
//        cout << duration_cast<nanoseconds>(s) ;

    QCoreApplication a(argc, argv);

    cout << "Taller Hola Mundo FORD" << endl;

    CTaller taller("Bartolete","Playa");

    cEmpleado empleado1("lolo",1,eTrabajo::pintura);
    cEmpleado empleado2("lala",2,eTrabajo::mecanica);
    cEmpleado empleado3("lulu",3,eTrabajo::electronica);

    shared_ptr<cCarro> carro1 = make_shared<cCarro>(2019,"b12345");
    shared_ptr<cCarro> carro2 = make_shared<cCarro>(2020,"b54322");
    shared_ptr<cCarro> carro3 = make_shared<cCarro>(1992,"b88926");
    shared_ptr<cCarro> carro4 = make_shared<cCarro>(2000,"b87777");
    shared_ptr<cCarro> carro5 = make_shared<cCarro>(1500,"b78551");

    taller.insertar_empleado(&empleado1);
    taller.insertar_empleado(&empleado2);
    taller.insertar_empleado(&empleado3);

    taller.insertar_nuevo_carro(carro1,eTrabajo::pintura,eTrabajo::mecanica);
    taller.insertar_nuevo_carro(carro2,eTrabajo::pintura);
    taller.insertar_nuevo_carro(carro3,eTrabajo::electronica);
    taller.insertar_nuevo_carro(carro4,eTrabajo::electronica,eTrabajo::pintura,eTrabajo::mecanica);
    taller.insertar_nuevo_carro(carro5,eTrabajo::mecanica);

    return a.exec();
}
