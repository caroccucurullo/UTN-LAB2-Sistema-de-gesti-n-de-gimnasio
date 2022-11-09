#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
/* MEMBRESÍA:
    -Nombre
    -Cantidad de clases
    -Valor
    -ID
 */

class Membresia {
private:
    char nombre[20];
    int cantidadClases;
    float valor;
    int id;
public:
    Membresia(const char* n="", int cc = 0, float v = 0, int i = 0);
    const char *getNombre() { return nombre; }
    int getCantidadClases() { return cantidadClases; }
    float getValor() { return valor; }
    int getId() { return id; }
    void setNombre(const char *n) { strcpy(nombre, n); }
    void setCantidadClases(int cc) { cantidadClases = cc; }
    void setValor(float v) { valor = v; }
    void setId(int i) { id = i; }
    void MostrarMembresia();
};

