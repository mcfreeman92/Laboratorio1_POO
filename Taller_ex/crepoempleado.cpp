#include "crepoempleado.h"
#include "ccarro.h"

crepoempleado::crepoempleado()
{

}

void crepoempleado::insertar(ccarro carro)
{
  std::ofstream f("carros.rep", std::ios::binary | std::ios::app);
  if(!f)
  {
      std::cerr<<"El archivo no se puede abrir";
  }
  else
  {
        f.write(reinterpret_cast<char *>(&carro),sizeof (ccarro));
  }
  f.close();
}

ccarro crepoempleado::buscar(int id)
{
    std::ofstream f("carros.rep", std::ios::binary | std::ios::out | std::ios::in);
    if(!f)
    {
        std::cerr<<"El archivo no se puede abrir";
    }
    else
    {
//          f.write(reinterpret_cast<char *>(&carro),sizeof (ccarro));
    }
    f.close();
}
