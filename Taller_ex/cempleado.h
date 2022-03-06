#ifndef CEMPLEADO_H
#define CEMPLEADO_H
#define TAM_NOMBRE 20

#include <QObject>
#include <QTimer>

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
    void setReloj() { m_reloj = new QTimer(); }
    void relojStart(int ms){m_reloj->start(ms);}
    void relojStop(){m_reloj->stop();}

    int   getId() { return m_id; }
    char* getNombre() { return m_nombre;}
    QTimer *getReloj() { return m_reloj;}

public slots:
    virtual void on_run() = 0;

signals:
    void s_trabajo_terminado();

private:
    char  m_nombre[TAM_NOMBRE];
    int   m_id;
    QTimer *m_reloj;

};

#endif // CEMPLEADO_H
