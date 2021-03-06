#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>
#include <iostream>
#include <stdlib.h>
#define TAM_NOMBRE 20
using namespace std;
class Persona : public QObject
{
    Q_OBJECT
public:
    Persona();
    Persona(Persona &p);
    Persona(const char *nombre, int edad, int ID, int idBD);

    void setNombre(const char* nombre) { memcpy(m_nombre,nombre,TAM_NOMBRE); }
    void setId(int id) { m_ID = id; }
    void setIdBD(int idBD) { m_idBD = idBD; }
    void setEdad(int edad) { m_edad = edad; }
    int   getId() { return m_ID; }
    int   getIdBD() { return m_idBD; }
    int   getEdad() { return m_edad; }
    char* getNombre() { return m_nombre;}

    virtual void mostrar();

protected:
    char m_nombre[TAM_NOMBRE];
    int m_edad;
    int m_ID;
    int m_idBD;
signals:
};
#endif // PERSONA_H
