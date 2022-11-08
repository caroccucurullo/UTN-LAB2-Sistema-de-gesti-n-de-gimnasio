#ifndef MEMBRESIA_H_INCLUDED
#define MEMBRESIA_H_INCLUDED

#include <iostream>
#include <string.h>
/* MEMBRESÍA:
    -Nombre
    -Cantidad de clases
    -Valor
    -ID
 */

using namespace std;

class Membresia {
private:
    char nombre[20];
    int cantidadClases;
    float valor;
    int id;
public:
    Membresia(char n[20], int cc = 0, float v = 0, int i = 0);
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

#endif // MEMBRESIA_H_INCLUDED

