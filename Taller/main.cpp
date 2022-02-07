#include <iostream>
#include "ctaller.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    CTaller taller;

    cEmpleado empleado1("lolo",1,eTrabajo::pintura);
    cEmpleado empleado2("lala",2,eTrabajo::mecanica);
    cEmpleado empleado3("lulu",3,eTrabajo::electronica);

    cCarro carro1(2019,"b12345");
    cCarro carro2(2020,"b54321");

    taller.insertar_nuevo_empleado(&empleado1);
    taller.insertar_nuevo_empleado(&empleado2);
    taller.insertar_nuevo_empleado(&empleado3);

    taller.insertar_nuevo_carro(&carro1,eTrabajo::pintura,eTrabajo::mecanica);
    taller.insertar_nuevo_carro(&carro2,eTrabajo::electronica);







    return 0;
}
