#ifndef CCARRO_H
#define CCARRO_H

#define TAM_MATRICULA 6

#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

enum eArea
{
   mecanica = 1,//0001
   pintura = 2,//0010
   electrica = 4//0100
};

class ccarro
{
public:
    ccarro();
    ccarro(ccarro &);
    ccarro(const char *matricula, int anno, const std::vector<eArea> &areas);
    ~ccarro();

    void setMatricula(const char *matricula) { memcpy(m_matricula,matricula,TAM_MATRICULA); }
    void setAnno(int anno) { m_anno = anno; }
    void setId(int id) { m_id = id; }

    int     getAnno() { return m_anno; }
    int     getId() { return m_id; }
    const char*   getMatricula() { return m_matricula; }
    std::vector<eArea>   getArea();

    void iniciaTiempo();
    void setAllTime(){m_allTime += elapsedTime(m_tinicio);}

    double getAllTime(){return m_allTime;}
    double getTiempoArea(){return elapsedTime(m_tiniArea);}


private:
    unsigned short m_area;
    char m_matricula[TAM_MATRICULA];
    int  m_anno;
    int  m_id;

    std::chrono::system_clock::time_point m_tinicio, m_tiniArea;
    bool m_iniciaTiempo;
    double m_allTime;

    double  elapsedTime(std::chrono::system_clock::time_point tini){auto tfin = std::chrono::system_clock::now();
                            return double(std::chrono::duration_cast<std::chrono::milliseconds>(tfin - tini).count());}
};

#endif // CCARRO_H
