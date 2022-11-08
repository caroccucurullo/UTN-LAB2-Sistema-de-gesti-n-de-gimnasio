#include <cstring>
#include <iostream>
#include "Salon.h"

Salon::Salon(int i = 0, int c = 0, char n[20]) {
    id = i;
    cupo = c;
    strcpy(nombre, n);
}

void Salon::MostrarSalon() {
    cout << "ID: " << id << endl;
    cout << "Cupo: " << cupo << endl;
    cout << "Nombre: " << nombre << endl;
}
