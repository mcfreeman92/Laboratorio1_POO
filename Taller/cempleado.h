#ifndef CEMPLEADO_H
#define CEMPLEADO_H

#include <QTimer>
#include <QObject>
#include <stdlib.h>
#include "ccarro.h"
#include "constantes.h"


class cEmpleado : public QObject
{
    Q_OBJECT
public:
    cEmpleado();
    cEmpleado(char *nombre,int id,int tipo_empleo);

    void setNombre(char *nombre) { memcpy(m_nombre,nombre,20); }
    void setId(int id) { m_id = id; }
    void setTipoEmpleo(int tipo_empleo) { m_tipo_empleo = tipo_empleo; }
    void setCarro(cCarro * carro) { m_carro = carro;
                                    m_reloj.start(m_tipo_empleo);}

    int     getId() { return m_id; }
    int     getTipoEmpleo() { return m_tipo_empleo; }
    bool    getOcupado() { return m_ocupado; }
    char*   getNombre() { return m_nombre; }
    cCarro* getCarro() { return m_carro; }

private:
    char m_nombre[20];
    int m_id;
    int m_tipo_empleo;
    int m_tiempo_trabajo;
    bool m_ocupado;
    cCarro * m_carro;
    QTimer m_reloj;

private slots:
    void terminaTrabajo();
};

#endif // CEMPLEADO_H
