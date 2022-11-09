#pragma once
#include <iostream>
#include <string.h>
#include <cstring>

/* 	-ID
    -cargo(rol)
    -Sueldo
    -Fecha de ingreso */

class Rol {
private:
    int id;
    char cargo[20];
    float sueldo;
    char fechaIngreso[20];
public:
    Rol(int i = 0, const char* c="", float s = 0, const char* fi="");
    int getId() { return id; }
    const char *getCargo() { return cargo; }
    float getSueldo() { return sueldo; }
    const char *getFechaIngreso() { return fechaIngreso; }
    void setId(int i) { id = i; }
    void setCargo(const char *c) { strcpy(cargo, c); }
    void setSueldo(float s) { sueldo = s; }
    void setFechaIngreso(const char *fi) { strcpy(fechaIngreso, fi); }
    void MostrarRol();
};
