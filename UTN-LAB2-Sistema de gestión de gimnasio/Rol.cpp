#include <cstring>
#include <iostream>
#include "Rol.h"


Rol::Rol(int i = 0, char c[20], float s = 0, char fi[20]) {
    id = i;
    strcpy(cargo, c);
    sueldo = s;
    strcpy(fechaIngreso, fi);
}

void Rol::MostrarRol() {
    cout << "ID: " << id << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "Sueldo: " << sueldo << endl;
    cout << "Fecha de ingreso: " << fechaIngreso << endl;
}

