#ifndef SALON_H_INCLUDED
#define SALON_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

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
    Salon(int i = 0, int c = 0, char n[20]);
    int getId() { return id; }
    int getCupo() { return cupo; }
    const char *getNombre() { return nombre; }
    void setId(int i) { id = i; }
    void setCupo(int c) { cupo = c; }
    void setNombre(char n[20]) { strcpy(nombre, n); }
    void MostrarSalon();
};

#endif // SALON_H_INCLUDED
