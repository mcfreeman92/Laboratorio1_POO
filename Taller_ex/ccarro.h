#ifndef CCARRO_H
#define CCARRO_H

#define TAM_MATRICULA 6

#include <QObject>

using namespace std;

class ccarro
{
public:
    enum eArea
    {
       mecanica = 1,
       pintura = 2,
       electrica = 3
    };

    ccarro();
    ccarro(ccarro &);
    ccarro(const char *matricula, int anno,const std::vector<eArea> areas);
    ~ccarro();

    void setMatricula(char *matricula) { memcpy(m_matricula,matricula,TAM_MATRICULA); }
    void setAnno(int anno) { m_anno = anno; }

    int     getAnno() { return m_anno; }
    const char*   getMatricula() { return m_matricula; }
    std::vector<eArea>   getArea() { return m_area; }



    void setStartTime(bool timeStart){m_timeStart = timeStart;
                                     startTime = std::chrono::system_clock::now();}
    void setAllTime(double t){allTime += getElapsedTime();}

    bool    getStartTime(){return m_timeStart;}
    double  getElapsedTime(){auto end = std::chrono::system_clock::now();
                            return double(std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime).count());}
    double getAllTime(){return  allTime;}


private:
    std::vector<eArea> m_area;
    char m_matricula[TAM_MATRICULA];
    int  m_anno;
    int  m_id;

    std::chrono::system_clock::time_point startTime;
    bool m_timeStart;
    double allTime;
};

#endif // CCARRO_H
