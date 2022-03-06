#ifndef CEMPLEADO_H
#define CEMPLEADO_H
#define TAM_NOMBRE 20

#include <QObject>

using namespace std;

class cempleado : public QObject
{
    Q_OBJECT

public:
    cempleado();
    cempleado(cempleado &e);
    cempleado(const char *nombre, int id);

    void setNombre(const char* nombre) { memcpy(m_nombre,nombre,TAM_NOMBRE); }
    void setId(int id) { m_id = id; }

    int   getId() { return m_id; }
    char* getNombre() { return m_nombre;}

public slots:
    virtual void termina() =0;

signals:
    void s_trabajo_terminado();

private:
    char  m_nombre[TAM_NOMBRE];
    int   m_id;

};

#endif // CEMPLEADO_H
