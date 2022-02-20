#include "ccarro.h"
#include <QDebug>

cCarro::cCarro()
{

}

cCarro::cCarro(int anno, const char matricula[])
{
    memcpy(m_matricula,matricula,TAM_MATRICULA) ;
    m_anno = anno;
    cout<<"crea carro "<<m_matricula<<endl;
}

cCarro::~cCarro()
{
   cout<<"termina carro "<<m_matricula<<endl;
}
