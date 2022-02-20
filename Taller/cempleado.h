#ifndef CEMPLEADO_H
#define CEMPLEADO_H

#include <QTimer>
#include <QtCore>

#include "ccarro.h"
#include "constantes.h"

using namespace std;

class cEmpleado : public QObject
{
    Q_OBJECT
public:
    explicit cEmpleado(char *nombre, int id, eTrabajo tipo_empleo);
    ~cEmpleado();
    void setNombre(char *nombre) { memcpy(m_nombre,nombre,20); }
    void setId(int id) { m_id = id; }
    void setTipoEmpleo(eTrabajo tipo_empleo) { m_tipo_empleo = tipo_empleo; }
    void setCarro(shared_ptr<cCarro> carro);

    int      getId() { return m_id; }
    eTrabajo getTipoEmpleo() { if(m_tipo_empleo != eTrabajo::servicio) return m_tipo_empleo; }
    bool     getOcupado() { return m_ocupado; }
    char*    getNombre() { return m_nombre; }
    shared_ptr<cCarro>  getCarro() { return m_carro; }

private:
    char      m_nombre[20];
    int       m_id;
    eTrabajo  m_tipo_empleo;
    int       m_tiempo_trabajo;
    bool      m_ocupado;
    shared_ptr<cCarro>  m_carro;
    QTimer  m_reloj;

private slots:
    void terminaTrabajo();

signals:
    void s_trabajoTerminado();

};

#endif // CEMPLEADO_H
