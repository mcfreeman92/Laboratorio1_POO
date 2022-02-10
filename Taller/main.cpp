#include <QCoreApplication>
#include <iostream>
#include "ctaller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Taller Hola Mundo FORD" << endl;

    CTaller taller("Bartolete","Playa");

    cEmpleado empleado1("lolo",1,eTrabajo::pintura);
    cEmpleado empleado2("lala",2,eTrabajo::mecanica);
    cEmpleado empleado3("lulu",3,eTrabajo::electronica);
    cEmpleado empleado4("lili",2,eTrabajo::pintura);

    cCarro carro1(2019,"b12345");
    cCarro carro2(2020,"b54325");
    cCarro carro3(2026,"b88925");

    cout<</*boolalpha<<*/taller.insertar_empleado(&empleado1);
    cout<<taller.insertar_empleado(&empleado2);
    cout<<taller.insertar_empleado(&empleado3);
    cout<<taller.insertar_empleado(&empleado4)<<endl;

    cout<<taller.insertar_nuevo_carro(&carro1,eTrabajo::pintura,eTrabajo::mecanica);
    cout<<taller.insertar_nuevo_carro(&carro2,eTrabajo::pintura);
    cout<<taller.insertar_nuevo_carro(&carro2,eTrabajo::electronica);
    cout<<taller.eliminar_empleado(&empleado4)<<endl;


    return a.exec();
}
