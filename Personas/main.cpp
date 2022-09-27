#include <QCoreApplication>
#include "repoprofesor.h"
#include "secretaria.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cSecretaria secretaria;

    shared_ptr<cProfesor> p1 = make_shared<cProfesor>("Alberto",33,509829,1,3000);
    shared_ptr<cProfesor> p2 = make_shared<cProfesor>("Wilfredo",30,554235,2,2345);
    shared_ptr<cProfesor> p3 = make_shared<cProfesor>("Maylin",30,55236,3,1000);

    shared_ptr<cEstudiante> e1 = make_shared<cEstudiante>("Rafael", 34, 495822,5,4.2);
    shared_ptr<cEstudiante> e2 = make_shared<cEstudiante>("Randy", 30, 4564,5,0);
    shared_ptr<cEstudiante> e3 = make_shared<cEstudiante>("Claudia", 26, 78868,6,3.1);

    secretaria.insertar_persona(p1);
    secretaria.insertar_persona(p2);
    secretaria.insertar_persona(p3);
    secretaria.insertar_persona(e1);
    secretaria.insertar_persona(e2);
    secretaria.insertar_persona(e3);
    secretaria.muestra_todos();


    secretaria.eliminar_persona(554235);
    secretaria.muestra_todos_profesores();

    secretaria.modifica_persona(4564);
    secretaria.muestra_todos_estudiantes();

    secretaria.asignarEstudianteTutor();
    secretaria.muestra_todos_profesores();

    secretaria.eliminaTutoria(554235);
    secretaria.muestra_todos_profesores();

    return a.exec();
}
