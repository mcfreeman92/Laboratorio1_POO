#ifndef CCARRO_H
#define CCARRO_H

#define TAM_MATRICULA 6

#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

enum eArea
{
   mecanica = 1,
   pintura = 2,
   electrica = 3
};

class ccarro
{
public:
    ccarro();
    ccarro(ccarro &);
    ccarro(const char *matricula, int anno,const std::vector<eArea> areas);
    ~ccarro();

    void setMatricula(char *matricula) { memcpy(m_matricula,matricula,TAM_MATRICULA); }
    void setAnno(int anno) { m_anno = anno; }

    int     getAnno() { return m_anno; }
    const char*   getMatricula() { return m_matricula; }
    std::vector<eArea>   getArea() { return m_area; }

    void iniciaTiempo();
    void setAllTime(){allTime += elapsedTime(tinicio);}

    double getAllTime(){return allTime;}
    double getTiempoArea(){return elapsedTime(tiniArea);}


private:
    std::vector<eArea> m_area;
    char m_matricula[TAM_MATRICULA];
    int  m_anno;
    int  m_id;

    std::chrono::system_clock::time_point tinicio, tiniArea;
    bool m_iniciaTiempo;
    double allTime;

    double  elapsedTime(std::chrono::system_clock::time_point tini){auto tfin = std::chrono::system_clock::now();
                            return double(std::chrono::duration_cast<std::chrono::milliseconds>(tfin - tini).count());}
};

#endif // CCARRO_H
