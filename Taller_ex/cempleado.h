#ifndef CEMPLEADO_H
#define CEMPLEADO_H
#define TAM_NOMBRE 20

#include <QObject>

using namespace std;

class cempleado : public QObject
{
    Q_OBJECT

public:
    ~cempleado();
    cempleado(cempleado &e);
    cempleado(const char *nombre, int dni, int id);

    void setNombre(const char* nombre) { memcpy(m_nombre,nombre,TAM_NOMBRE); }
    void setDNI(int dni) { m_dni = dni; }
    void setId(int id) { m_id = id; }

    int   getDNI() { return m_dni; }
    char* getNombre() { return m_nombre;}
    int   getId() { return m_id;}

public slots:
    virtual void termina() =0;

signals:
    void s_trabajo_terminado();

private:
    char  m_nombre[TAM_NOMBRE];
    int   m_dni, m_id;

};

#endif // CEMPLEADO_H
