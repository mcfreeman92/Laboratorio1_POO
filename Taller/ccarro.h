#ifndef CCARRO_H
#define CCARRO_H

#include "constantes.h"

using namespace std;

class cCarro
{
public:
    cCarro();
    cCarro(int anno, const char matricula[6]);
    ~cCarro();
    void setMatricula(char *matricula) { memcpy(m_matricula,matricula,6); }
    void setAnno(int anno) { m_anno = anno; }

    int   getAnno() { return m_anno; }
    char* getMatricula() { return m_matricula; }

private:
    char m_matricula[6];
    int  m_anno;
};

#endif // CCARRO_H
