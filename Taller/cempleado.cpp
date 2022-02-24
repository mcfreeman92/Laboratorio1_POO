#include "cempleado.h"

cEmpleado::cEmpleado(char *nombre, int id, eTrabajo tipo_empleo):
    m_tiempo_trabajo(5000),
    m_carro(nullptr),
    m_demora(0)
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
//        LOG("tiempo "<<m_carro->getStartTime()<<" carro "<<m_carro->getMatricula());
       if(!m_carro->getStartTime()) m_carro->setStartTime(true);
        m_ocupado = true;
//        _sleep(5000);
        m_reloj.start(m_tiempo_trabajo);
        LOG("empleado "<<m_nombre<<" inicia trabajo "<<m_carro->getMatricula());
    }
}

void cEmpleado::terminaTrabajo()
{

//    LOG("copias "<<m_carro.use_count()<<" carro "<<m_carro->getMatricula());
    LOG("empleado "<<m_nombre<<" termina trabajo "<<m_carro->getMatricula()<<
        " en "<<m_carro->getElapsedTime()<<"ms");
   if(m_demora < m_carro->getElapsedTime()) m_demora = m_carro->getElapsedTime();
    m_carro->setAllTime(0);
    if(m_carro.use_count() == 2)
            LOG("carro "<<m_carro->getMatricula()<<
                " listo en "<<m_carro->getAllTime()<<"ms");
    m_reloj.stop();
    m_carro.reset();
    m_ocupado = false;
    emit s_trabajoTerminado();    
}
