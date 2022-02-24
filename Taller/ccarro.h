#ifndef CCARRO_H
#define CCARRO_H

#include "constantes.h"

using namespace std;

class cCarro
{
public:
    cCarro();
    cCarro(int anno, const char *matricula);
    ~cCarro();
    void setMatricula(char *matricula) { memcpy(m_matricula,matricula,TAM_MATRICULA); }
    void setAnno(int anno) { m_anno = anno; }
    void setStartTime(bool timeStart){m_timeStart = timeStart;
                                     startTime = std::chrono::system_clock::now();}
    void setAllTime(double t){allTime += getElapsedTime();}

    int   getAnno() { return m_anno; }
    char* getMatricula() { return m_matricula; }
    bool  getStartTime(){return m_timeStart;}
    double  getElapsedTime(){auto end = std::chrono::system_clock::now();
                            return double(std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime).count());}
    double getAllTime(){return  allTime;}


private:
    std::chrono::system_clock::time_point startTime;
    char m_matricula[TAM_MATRICULA];
    int  m_anno;
    bool m_timeStart;
    double allTime;
};

#endif // CCARRO_H
