#include "cempleado.h"

cempleado::cempleado(char *nombre, int id, QObject *parent) : QObject(parent)
{
    memcpy(m_nombre,nombre,20);
    m_id = id;
}
