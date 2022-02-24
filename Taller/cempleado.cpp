#include "cempleado.h"

cEmpleado::cEmpleado(char *nombre, int id, eTrabajo tipo_empleo):
    m_tiempo_trabajo(5000),
    m_carro(nullptr)
{
    memcpy(m_nombre,nombre,20);
    m_id = id;
    m_tipo_empleo = tipo_empleo;
    m_ocupado = false;
    connect(&m_reloj,SIGNAL(timeout()),this,SLOT(terminaTrabajo()));
    LOG("empleado "<<m_nombre<<" creado");
}

cEmpleado::~cEmpleado()
{
    LOG("empleado "<<m_nombre<<" destruido");
}

void cEmpleado::setCarro(shared_ptr<cCarro> carro)
{
    if(m_tipo_empleo != eTrabajo::servicio)
    {
        m_carro = carro;
        m_ocupado = true;
        m_reloj.start(m_tiempo_trabajo);
        LOG("empleado "<<m_nombre<<" inicia trabajo "<<m_carro->getMatricula());
    }
}

void cEmpleado::terminaTrabajo()
{
    LOG("empleado "<<m_nombre<<" termina trabajo "<<m_carro->getMatricula());
    m_reloj.stop();
    m_carro.reset();
    m_ocupado = false;
    emit s_trabajoTerminado();    
}
