#include "crepocarro.h"
#include "ccarro.h"

crepocarro::crepocarro():m_filename("carros.rep")
{

}

void crepocarro::insertar(std::shared_ptr<ccarro> carro)
{
    carro->setId(generaID());
    std::ofstream f(m_filename, std::ios::binary | std::ios::app);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
    }
    else
    {
        int id = carro.get()->getId();
        std::cout<<id<<" "<<sizeof (ccarro);
          f.seekp((carro->getId()-1)*sizeof (ccarro));
          f.write(reinterpret_cast<char *>(&*carro),sizeof(ccarro));
    }
    f.close();

}

shared_ptr<ccarro> crepocarro::buscar(int id)
{
    ccarro carro;
    std::fstream f(m_filename, std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
    }
    else
    {
          f.seekg((id-1)*sizeof (ccarro));
          f.read((char*)(&carro),sizeof (ccarro));
    }
    f.close();
    return make_shared<ccarro>(carro.getMatricula(),carro.getAnno(),carro.getArea(),carro.getId());
}

int crepocarro::generaID()
{
    struct stat sb;
    if (stat(m_filename, &sb) == -1) {
        perror("stat");
    }

    int id = sb.st_size/sizeof (ccarro);
    id++;

    return id;
}
