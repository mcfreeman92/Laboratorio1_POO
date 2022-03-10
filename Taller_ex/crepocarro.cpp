#include "crepocarro.h"
#include "ccarro.h"

crepocarro::crepocarro():m_filename("carros.rep")
{
//    ccarro carro;
//    std::ofstream f(m_filename, std::ios::binary);
//    if(!f)
//    {
//        std::cerr<<"El archivo no se puede abrir";
//    }
//    else
//    {
//        for (int i = 0 ; i < 200; ++i) {
//          f.write(reinterpret_cast<char *>(&carro),sizeof (ccarro));}
//    }
//    f.close();
}

void crepocarro::insertar(std::shared_ptr<ccarro> carro)
{
    carro->setId(generaID());
    std::ofstream f(m_filename, std::ios::binary);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
    }
    else
    {
        f.seekp(sizeof (carro));
          f.write(reinterpret_cast<char *>(&carro),sizeof (ccarro));
    }
    f.close();

    std::cout<<sizeof (ccarro);
    generaID();
}

shared_ptr<ccarro> crepocarro::buscar(int id)
{
    shared_ptr<ccarro> carro;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
    }
    else
    {
          f.seekp(id * sizeof (ccarro));
          f.read(reinterpret_cast<char *>(&carro),sizeof (ccarro));
    }
    f.close();
    return carro;
}

int crepocarro::generaID()
{
    struct stat sb;
    if (stat(m_filename, &sb) == -1) {
        perror("stat");
    }
    std::cout<<sb.st_size;
    int id = sb.st_size/sizeof (ccarro);
    id++;
    return id;
}
