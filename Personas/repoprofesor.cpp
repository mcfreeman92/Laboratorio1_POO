#include "repoprofesor.h"

RepoProfesor::RepoProfesor() : m_filename("profesor.rep")
{

}

int RepoProfesor::generaID()
{
    int tam_f = tam_fichero()/sizeof (cProfesor);
    tam_f++;
    return tam_f;
}

bool RepoProfesor::insertar(shared_ptr<cProfesor> &profe)
{
    std::ofstream f(m_filename, std::ios::binary | std::ios::app);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        int id = generaID();
        profe->setIdBD(id);
        f.seekp((id-1)*sizeof (cProfesor));
        f.write(reinterpret_cast<char *>(&*profe),sizeof(cProfesor));
    }
    f.close();
    return true;
}

int RepoProfesor::tam_fichero()
{
    struct stat sb;
    if(stat(m_filename, &sb) == -1)
    {
        perror("stat");
    }
    return sb.st_size;
}

bool RepoProfesor::eliminar(int id)
{
    cProfesor prof;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekp((id-1)*sizeof (cProfesor));
        f.write(reinterpret_cast<char*>(&prof),sizeof (cProfesor));
    }
    f.close();
    return true;
}

bool RepoProfesor::existe()
{
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        return false;
    }
    else
     return true;
}

bool RepoProfesor::modificar(shared_ptr<cProfesor> &empleado)
{
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekp((empleado->getIdBD()-1)*sizeof (cProfesor));
        f.write(reinterpret_cast<char*>(&*empleado),sizeof (cProfesor));
    }
    f.close();
    return true;
}

std::list<shared_ptr<cProfesor> > RepoProfesor::leerTodo()
{
    std::list<shared_ptr<cProfesor>> list_carros;
    cProfesor prof;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
    }
    else
    {
        int id = 0;
        while (!(f.eof()))
        {
            f.seekg((id++)*sizeof (cProfesor));
            f.read(reinterpret_cast<char*>(&prof),sizeof (cProfesor));
            if(prof.getIdBD() != 0)
            {
                list_carros.push_back(make_shared<cProfesor>(prof));
                cout<<prof.getId()<<" -> "<<prof.getNombre()<<"  "<<prof.getEdad()<<endl;
            }
            f.peek();
        }
    }
    f.close();
    return  list_carros;
}
