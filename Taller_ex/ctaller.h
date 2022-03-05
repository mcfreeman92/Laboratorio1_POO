#ifndef CTALLER_H
#define CTALLER_H

#include <QObject>
#include <cempleado.h>

class ctaller : public QObject
{
    Q_OBJECT
public:
    explicit ctaller(QObject *parent = nullptr);

signals:

};

#endif // CTALLER_H
