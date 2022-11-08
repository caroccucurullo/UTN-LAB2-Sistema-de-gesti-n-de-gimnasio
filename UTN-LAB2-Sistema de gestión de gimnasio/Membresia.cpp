#include <cstring>
#include <iostream>
#include "Membresia.h"



Membresia::Membresia(char n[20], int cc = 0, float v = 0, int i = 0) {
    strcpy(nombre, n);
    cantidadClases = cc;
    valor = v;
    id = i;
}

void Membresia::MostrarMembresia() {
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad de clases: " << cantidadClases << endl;
    cout << "Valor: " << valor << endl;
    cout << "ID: " << id << endl;
}

