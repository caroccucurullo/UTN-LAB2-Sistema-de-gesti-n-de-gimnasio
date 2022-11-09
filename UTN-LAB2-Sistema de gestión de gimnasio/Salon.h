#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
/* SALON:
    -ID
-Cupo
-Nombre */
class Salon {
private:
    int id;
    int cupo;
    char nombre[20];
public:
    Salon(int i = 0, int c = 0, const char* n="");
    int getId() { return id; }
    int getCupo() { return cupo; }
    const char *getNombre() { return nombre; }
    void setId(int i) { id = i; }
    void setCupo(int c) { cupo = c; }
    void setNombre(char n[20]) { strcpy(nombre, n); }
    void MostrarSalon();
};

