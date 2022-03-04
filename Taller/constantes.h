#ifndef CONSTANTES_H
#define CONSTANTES_H

#define MAX_EMPLEADOS 5
#define MAX_CARROS_LISTOS 5
#define MAX_CARROS_ESPERA 5
#define TAM_MATRICULA 6

#include <QTimer>
#include <QtCore>
#include <memory> //para puntereos inteligentes
#include <iostream>
#include <chrono> //manejo y medir el tiempo
#include <cstring>
#include <string>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>

#define LOG(x) std::cout<<x<<std::endl

enum eTrabajo{
    ninguno = 0,//solo prara inicializacion
    pintura = 1,
    mecanica = 2,
    electronica = 3,
    servicio = 4
};


#endif // CONSTANTES_H
