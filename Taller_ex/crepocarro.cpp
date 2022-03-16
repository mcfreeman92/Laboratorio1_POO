#include "crepocarro.h"
#include "ccarro.h"

crepocarro::crepocarro():m_filename("carros.rep")
{

}

bool crepocarro::insertar(shared_ptr<ccarro> &carro)
{
    int id = generaID();

    carro->setId(id);

    std::ofstream f(m_filename, std::ios::binary | std::ios::app);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekp((id-1)*sizeof (ccarro));
        f.write(reinterpret_cast<char *>(&*carro),sizeof(ccarro));
    }
    f.close();
    return true;
}

bool crepocarro::eliminar(int id)
{
    ccarro carro;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekp((id-1)*sizeof (ccarro));
        f.write(reinterpret_cast<char*>(&carro),sizeof (ccarro));
    }
    f.close();
    return true;
}

bool crepocarro::modificar(shared_ptr<ccarro> &carro)
{
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekp((carro->getId()-1)*sizeof (ccarro));
        f.write(reinterpret_cast<char*>(&*carro),sizeof (ccarro));
    }
    f.close();
    return true;
}

std::list<shared_ptr<ccarro> > crepocarro::leerTodo()
{
    std::list<shared_ptr<ccarro>> list_carros;
    ccarro carro;
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
            f.seekg((id++)*sizeof (ccarro));
            f.read(reinterpret_cast<char*>(&carro),sizeof (ccarro));
            if(carro.getId() != 0)
            {
                list_carros.push_back(make_shared<ccarro>(carro));
                cout<<carro.getId()<<" -> "<<carro.getMatricula()<<" ("<<*(carro.getArea().begin())<<endl;
            }
            f.peek();
        }
    }
    f.close();
    return  list_carros;
}

bool crepocarro::buscar(int id)
{
    ccarro carro;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
        return false;
    }
    else
    {
        f.seekg((id-1)*sizeof (ccarro));
        f.read(reinterpret_cast<char*>(&carro),sizeof (ccarro));

    }
    f.close();

    if((id == carro.getId()) || (carro.getId()==0))
        return true;
    else
        return false;
}

int crepocarro::generaID()
{
    int tam_f = tam_fichero()/sizeof (ccarro);
    tam_f++;
    return tam_f;
}

int crepocarro::tam_fichero()
{
    struct stat sb;
    if (stat(m_filename, &sb) == -1) {
        perror("stat");
    }
    return sb.st_size;
}
