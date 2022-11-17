#pragma once
#include "Turno.h"

class ArchivoTurno
{
public:
    bool guardarTurno(Turno& turno);
    Turno leerTurno(int nRegistro);
    bool leerTodos(Turno* turno, int cantidad);
    bool modificarTurno(Turno& turno, int nRegistro);
    int getCantidad();
};