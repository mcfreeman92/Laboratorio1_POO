#include "crepoempareapro.h"
#include "ceareaproductiva.h"

crepoempareapro::crepoempareapro(): m_filename("empleadoAP.rep")
{

}

bool crepoempareapro::insertar(shared_ptr<ceareaproductiva> &empl)
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
        empl->setId(id);
        f.seekp((id-1)*sizeof (ceareaproductiva));
        f.write(reinterpret_cast<char *>(&*empl),sizeof(ceareaproductiva));
    }
    f.close();
    return  true;
}

bool crepoempareapro::eliminar(int id)
{
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        ceareaproductiva empl;
        f.seekp((id-1)*sizeof (ceareaproductiva));
        f.write(reinterpret_cast<char*>(&empl),sizeof (ceareaproductiva));
    }
    f.close();
    return true;
}

bool crepoempareapro::modificar(shared_ptr<ceareaproductiva> &empl)
{
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekp((empl->getId()-1)*sizeof (ceareaproductiva));
        f.write(reinterpret_cast<char*>(&*empl),sizeof (ceareaproductiva));
    }
    f.close();
    return true;
}

std::vector<shared_ptr<cempleado> > crepoempareapro::leerTodo()
{
    std::vector<shared_ptr<cempleado> > list_empleadosAP;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir"<<endl;
    }
    else
    {
        int id = 0;
        while (!(f.eof()))
        {
            ceareaproductiva *empl = new ceareaproductiva();
            f.seekg((id++)*sizeof (ceareaproductiva));
            f.read(reinterpret_cast<char*>(&*empl),sizeof (ceareaproductiva));
            if(empl->getId() != 0)
            {
//                list_empleadosAP.push_back(make_shared<ceareaproductiva>(empl));
                cout<<empl->getId()<<" -> "<<empl->getNombre()<<" "<<empl->getArea()<<endl;
            }
            f.peek();
            delete empl;

        }


    }
    f.close();
    return list_empleadosAP;
}

int crepoempareapro::generaID()
{
    int tam_f = tam_fichero()/sizeof (ccarro);
    tam_f++;
    return tam_f;
}

int crepoempareapro::tam_fichero()
{
    struct stat sb;
    if (stat(m_filename, &sb) == -1) {
        perror("stat");
    }
    return sb.st_size;
}
