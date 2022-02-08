#include <QCoreApplication>
#include <iostream>
#include "ctaller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Taller Hola Mundo FORD" << endl;

    CTaller taller("Bartolete","Playa",&a);

    cEmpleado empleado1("lolo",1,eTrabajo::pintura,&a);
    cEmpleado empleado2("lala",2,eTrabajo::mecanica,&a);
    cEmpleado empleado3("lulu",3,eTrabajo::electronica,&a);
    cEmpleado empleado4("lili",4,eTrabajo::pintura,&a);
    cEmpleado empleado5("lele",5,eTrabajo::electronica,&a);
    cEmpleado empleado6("pupu",5,eTrabajo::mecanica,&a);

    cCarro carro1(2019,"b12345");
    cCarro carro2(2020,"b54321");
    cCarro carro3(2026,"b00021");

    cout<<taller.insertar_empleado(&empleado1);
    cout<<taller.insertar_empleado(&empleado2);
    cout<<taller.insertar_empleado(&empleado3);
    cout<<taller.insertar_empleado(&empleado4);
    cout<<taller.insertar_empleado(&empleado5);
    cout<<taller.insertar_empleado(&empleado6);

    cout<<taller.insertar_nuevo_carro(&carro1,eTrabajo::pintura,eTrabajo::mecanica)<<endl;
    cout<<taller.insertar_nuevo_carro(&carro2,eTrabajo::electronica)<<endl;
    cout<<taller.eliminar_empleado(&empleado3)<<endl;
    cout<<taller.insertar_nuevo_carro(&carro3,eTrabajo::electronica)<<endl;
    cout<<taller.eliminar_empleado(&empleado1)<<endl;
    cout<<taller.insertar_nuevo_carro(&carro3,eTrabajo::electronica)<<endl;

    return a.exec();
}
