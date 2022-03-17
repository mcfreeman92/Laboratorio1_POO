#include "secretaria.h"

cSecretaria::cSecretaria() : m_filename("empleados.rep")
{
    if(m_repProfe.existe())
    {
       std::list<shared_ptr<cProfesor>> lista_prof = m_repProfe.leerTodo();
       for(auto p:lista_prof)
           insertar_persona(p);
    }
}

void cSecretaria::insertar_persona(shared_ptr<cProfesor> &profesor)
{
    personas.push_back(profesor);
}

void cSecretaria::insertar_persona(shared_ptr<cEstudiante> &estudiante)
{
    personas.push_back(estudiante);
}

void cSecretaria::eliminar_persona(int id)
{
    for (auto it = personas.begin(); it != personas.end(); it++) {
        shared_ptr<Persona> persona = *it;
        if(persona->getId() == id)
        {
            if(typeid(*it) == typeid(cProfesor)) m_repProfe.eliminar(((cProfesor*)persona.get())->getIdBD());
            persona.reset();
            personas.erase(it);
            break;
        }
    }
}

void cSecretaria::modifica_persona(int id)
{
    muestra_todos();

    char nombre[20] = {""}; int edad;
    for (auto p: personas )
    {
        if(p->getId() == id)
        {
            cout<<"cambiar nombre("<<p->getNombre()<<"): "<<endl;
            cin>>nombre;
            p->setNombre(nombre);

            cout<<"cambiar edad("<<p->getEdad()<<"): "<<endl;
            cin>>edad;
            p->setEdad(edad);
        }
    }
}

bool cSecretaria::asignarEstudianteTutor()
{
    int id_prof, id_est;
    cout<<"Selecione el ID del profesor"<<endl;
    muestra_todos_profesores();
    cin>>id_prof;
    cout<<"Selecione el ID del estudiante"<<endl;
    muestra_todos_estudiantes();
    cin>>id_est;

    for(auto p: personas)
        if(p->getId() == id_prof)
        {
            if(typeid(*p) == typeid(cProfesor))
            {
                for(auto e: personas)
                    if(e->getId() == id_est)
                    {
                        if(typeid(*e) == typeid(cEstudiante))
                        {
                            cProfesor *p_aux = (cProfesor*)p.get();
                            cEstudiante *e_aux = (cEstudiante*)e.get();
                            p_aux->setEstudiante(make_shared<cEstudiante>(*e_aux));
                            return true;
                        }
                    }
            }
        }

    return false;
}

bool cSecretaria::eliminaTutoria(int id)
{
    for (auto p: personas )
    {
        if(typeid(*p) == typeid(cProfesor))
        {
            cProfesor *p_aux = (cProfesor*)p.get();
            p_aux->getEstudiante().reset();
            p_aux->setEstudiante(nullptr);
        }
    }
}

float cSecretaria::solicita_Creditos(int id)
{
    for (auto p: personas )
    {
        if(typeid(*p) == typeid(cProfesor))
        {
            cProfesor *p_aux = (cProfesor*)p.get();
            if((p_aux->getId() == id))
                return p_aux->getCredito();
        }
    }
}

float cSecretaria::solicita_NotaFinal(int id)
{
    for (auto p: personas )
    {
        if(typeid(*p) == typeid(cEstudiante))
        {
            cEstudiante *p_aux = (cEstudiante*)p.get();
            if((p_aux->getId() == id))
                return p_aux->getNotaFinal();
        }
    }
}

void cSecretaria::muestra_todos_profesores()
{
    for (auto p: personas )
    {
        if(typeid(*p) == typeid(cProfesor))
        {
            cProfesor *p_aux = (cProfesor*)p.get();
            cout<<p_aux->getId()<<" "<<p_aux->getNombre();
            if(p_aux->getEstudiante() != nullptr)
                cout<<" tutorea: "<<p_aux->getEstudiante()->getNombre();
            cout<<endl;
        }
    }
    cout<<endl;
}

void cSecretaria::muestra_todos_estudiantes()
{
    for (auto p: personas )
    {
        if(typeid(*p) == typeid(cEstudiante))
        {
            cEstudiante *p_aux = (cEstudiante*)p.get();
            cout<<p_aux->getId()<<" "<<p_aux->getNombre()<<endl;
        }
    }
    cout<<endl;
}

void cSecretaria::muestra_todos()
{
    for (auto p: personas )
    {
        cout<<p->getId()<<" "<<p->getNombre()<<endl;
    }
    cout<<endl;
}
