#ifndef ROL_H_INCLUDED
#define ROL_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

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
    Rol(int i = 0, char c[20], float s = 0, char fi[20]);
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

#endif // ROL_H_INCLUDED