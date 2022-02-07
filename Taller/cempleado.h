#ifndef CEMPLEADO_H
#define CEMPLEADO_H
#include <cstring>

class cEmpleado
{
public:
    cEmpleado();

    void setNombre(char *nombre)    {    memcpy(m_nombre,nombre,20) ;  }
    void setId(int id)    {   m_id = id;  }

    int getId() { return m_id; }
    char* getNombre() { return m_nombre; }
private:
    char m_nombre[20];
    int m_id;
};

#endif // CEMPLEADO_H
