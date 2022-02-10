#include "cempleado.h"

cEmpleado::cEmpleado(char *nombre, int id, eTrabajo tipo_empleo):
    m_tiempo_trabajo(5000),
    m_carro(nullptr)
{
    m_reloj = new QTimer(this);
    connect(m_reloj,SIGNAL(timeout()),this,SLOT(terminaTrabajo()));

    memcpy(m_nombre,nombre,20);
    m_id = id;
    m_tipo_empleo = tipo_empleo;
    m_ocupado = false;
}

cEmpleado::~cEmpleado()
{
    delete m_reloj;
    delete m_carro;
}

void cEmpleado::setCarro(cCarro *carro)
{
    if(m_tipo_empleo != eTrabajo::servicio)
    {
        m_carro = carro;
        m_ocupado = true;
        m_reloj->start(m_tiempo_trabajo);
    }
}

void cEmpleado::terminaTrabajo()
{
    m_reloj->stop();
    m_ocupado = false;
    emit s_trabajoTerminado(m_carro);
    m_carro = nullptr;
}
