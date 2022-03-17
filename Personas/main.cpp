#include <QCoreApplication>
#include "repoprofesor.h"
#include "secretaria.h"

void menu(cSecretaria &secretaria){
    cout<<"Menu secretaria"<<endl;
    cout<<"1 - insertar persona"<<endl;
    cout<<"2 - eliminar persona"<<endl;
    cout<<"3 - modificar persona"<<endl;
    cout<<"4 - asignar tutor"<<endl;
    cout<<"5 - ver nota final"<<endl;
    cout<<"6 - ver creditos tutor"<<endl;
    cout<<"0 - salir"<<endl;


    char nombre[20];
    int edad, dni;
    int opc;

    cin>>opc;
    switch (opc) {
    case 1:
        bool tipo;
        cout<<"Selecione tipo (0)profesor, (1)estudiante ";
        cin>>tipo;
        cout<<"inserte nombre : ";
        cin>>nombre;
        cout<<"inserte edad : ";
        cin>>edad;
        cout<<"inserte dni : ";
        cin>>dni;
        cout<<endl;
        if(tipo){
            shared_ptr<cProfesor> p = make_shared<cProfesor>(nombre,edad,dni);
            secretaria.insertar_persona(p);
        }
        else
        {
//            shared_ptr<cEstudiante> e = make_shared<cEstudiante>(nombre,edad,dni);
//            secretaria.insertar_persona(e);
        }
        secretaria.muestra_todos();
        break;
    case 2:
        cout<<"selecione el dni de la persona a eliminar"<<endl;
        secretaria.muestra_todos();
        cin>>dni;
        secretaria.eliminar_persona(dni);
        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 0:

        break;
    }
}

int main(int argc, char *argv[])
{
        QCoreApplication a(argc, argv);

//    cSecretaria secretaria;
//    while (true) {
//        menu(secretaria);
//    }
        shared_ptr<cProfesor> p1 = make_shared<cProfesor>("Alberto",33,509829,1,3000);
        shared_ptr<cProfesor> p2 = make_shared<cProfesor>("Wilfredo",30,554235,2,2345);

//    shared_ptr<cEstudiante> e1 = make_shared<cEstudiante>("Rafael", 34, 495822,3,4.2);
//    shared_ptr<cEstudiante> e2 = make_shared<cEstudiante>("Randy", 30, 4564,4,0);
//    shared_ptr<cEstudiante> e3 = make_shared<cEstudiante>("Claudia", 26, 78868,5,3.1);

//    secretaria.insertar_persona(p1);
    //    secretaria.insertar_persona(p2);
    //    secretaria.insertar_persona(e1);
    //    secretaria.insertar_persona(e2);
    //    secretaria.insertar_persona(e3);
//    secretaria.muestra_todos();

        RepoProfesor r;
//        r.insertar(p1);
//        r.insertar(p2);
//        p2->setNombre("WILLY");
//        p2->setId(456231);
//        r.insertar(p2);
        r.leerTodo();
//        secretaria.eliminar_persona(554235);
    //    secretaria.muestra_todos_profesores();

    //    secretaria.modifica_persona(4564);
    //    secretaria.muestra_todos_estudiantes();

    //    secretaria.asignarEstudianteTutor();
    //    secretaria.muestra_todos_profesores();

    //    secretaria.eliminaTutoria(554235);
    //    secretaria.muestra_todos_profesores();

//    return 0;
        return a.exec();
}
