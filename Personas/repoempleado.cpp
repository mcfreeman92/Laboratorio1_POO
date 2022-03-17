#include "repoempleado.h"

RepoEmpleado::RepoEmpleado() : m_filename("empleados.rep")
{

}

void RepoEmpleado::insertar_empleado(shared_ptr<cProfesor> &empleado)
{
//    empleados.push_back(empleado);
}

bool RepoEmpleado::guardarEmpleados(shared_ptr<cProfesor> &empleado)
{
   /* int id = generaId();
    empleado->setId(id);

    ofstream f( m_filename, ios::binary | ios::app);
    if ( !f ) // operador ! sobrecargado
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return false;
    } // fin de if

    else
    {
        f.seekp((id-1)*sizeof (cProfesor));
        f.write(reinterpret_cast<char*>(&*empleado),sizeof (cProfesor));

        f.close();
        return  true;
    }*/
}

list<shared_ptr<cProfesor>> RepoEmpleado::leerEmpleados()
{
  /*  list<shared_ptr<cProfesor>> list_empleados;
    cProfesor empleado;
    fstream f(m_filename, ios::binary | ios::out | ios::in);
    if(!f)
    {
        cerr << "No fichero";
    }
    else
    {
        int id = 0;
        while (!(f.eof())) {
            f.seekg((id++)*sizeof (cProfesor));
            f.read(reinterpret_cast<char*>(&empleado),sizeof (cProfesor));
            if(empleado.getId() != 0)
            {
                list_empleados.push_back(make_shared<cProfesor>(empleado));
            }
            f.peek();
        }
    }
    f.close();
    return list_empleados;*/
}

int RepoEmpleado::generaId()
{
    int tam_f = tam_fichero()/sizeof (cProfesor);
    tam_f ++;
    return tam_f;
}

int RepoEmpleado::tam_fichero()
{
    struct stat sb;
    if(stat(m_filename, &sb) == -1)
    {
        perror("stat");
    }
    return sb.st_size;
}

bool RepoEmpleado::eliminar(int id)
{
  /*  cProfesor e;
    fstream f(m_filename, ios::binary | ios::out | ios ::in);
    if(!f)
    {
        cerr<< "No fichero";
        return false;
    }
    else
    {
        f.seekp((id-1)*sizeof (cProfesor));
        f.write(reinterpret_cast<char*>(&e),sizeof (cProfesor));
    }
    f.close();
    return true;*/
}

bool RepoEmpleado::modificar(shared_ptr<cProfesor> &empleado)
{
   /* fstream f(m_filename, ios::binary | ios::out | ios ::in);
    if(!f)
    {
        cerr<< "No fichero";
        return false;
    }
    else
    {
        f.seekp((empleado->getId()-1)*sizeof (cProfesor));
        f.write(reinterpret_cast<char*>(&empleado),sizeof (cProfesor));
    }
    f.close();
    return true;*/
}
