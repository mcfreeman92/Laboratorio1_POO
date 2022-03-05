#ifndef CEMPLEADO_H
#define CEMPLEADO_H

#include <QObject>

class cempleado : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId);
    Q_PROPERTY(char* nombre READ getNombre WRITE setNombre);

public:
    explicit cempleado(char *nombre, int id, QObject *parent = nullptr);

    void setNombre(char* nombre) { memcpy(m_nombre,nombre,20); }
    void setId(int id) { m_id = id; }

    int   getId() { return m_id; }
    char* getNombre() { return m_nombre;}

private:
    char  m_nombre[20];
    int   m_id;
};

#endif // CEMPLEADO_H
