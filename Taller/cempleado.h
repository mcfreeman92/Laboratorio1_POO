#ifndef CEMPLEADO_H
#define CEMPLEADO_H

#include <QTimer>
#include <QtCore>
#include <stdlib.h>
#include "ccarro.h"
#include "constantes.h"


class cEmpleado : public QObject
{
    Q_OBJECT
public:
    explicit cEmpleado(char *nombre, int id, eTrabajo tipo_empleo ,QObject *parent = nullptr);
    ~cEmpleado();
    void setNombre(char *nombre) { memcpy(m_nombre,nombre,20); }
    void setId(int id) { m_id = id; }
    void setTipoEmpleo(eTrabajo tipo_empleo) { m_tipo_empleo = tipo_empleo; }
    void setCarro(cCarro * carro);

    int      getId() { return m_id; }
    eTrabajo getTipoEmpleo() { return m_tipo_empleo; }
    bool     getOcupado() { return m_ocupado; }
    char*    getNombre() { return m_nombre; }
    cCarro*  getCarro() { return m_carro; }

private:
    char      m_nombre[20];
    int       m_id;
    eTrabajo  m_tipo_empleo;
    int       m_tiempo_trabajo;
    bool      m_ocupado;
    cCarro*   m_carro;
    QTimer*    m_reloj;

private slots:
    void terminaTrabajo();

signals:
    void s_trabajoTerminado(cCarro*);

};

#endif // CEMPLEADO_H
