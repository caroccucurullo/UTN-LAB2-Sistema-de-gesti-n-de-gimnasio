/* Persona:
Nombre
Apellido
F. nac.
Edad
Genero
Telefono
DNI
Direccion
 */
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Fecha.h"
#include "Direccion.h"

class Persona {
protected:
    char nombre[20];
    char apellido[20];
    Fecha _fnac;
    int edad;
    char genero[20];
    char telefono[20];
    char dni[20];
    Direccion _dir;
public:

    Persona(const char* n = "", const char* a = "", Fecha nac = Fecha(), int e = 0, const char* g = "", const char* t = "",const char* d="", Direccion dir = Direccion());
    std::string getNombre() { std::string n(nombre); return n; }
    std::string getApellido() { std::string a(apellido); return a; }
    Fecha getFechaNac() { return _fnac; }
    int getEdad() { return edad; }
    std::string getGenero() { std::string g(genero); return g; }
    std::string getTelefono() { std::string t(telefono); return t; }
    std::string getDni() { std::string d(dni); return d; }
    Direccion getDireccion() { return _dir; }
    void setNombre(std::string n) { strcpy(nombre, n.c_str()); }
    void setApellido(std::string a) { strcpy(apellido, a.c_str()); }
    void setFechaNac(Fecha fnac) { _fnac = fnac; }
    void setEdad(int e) { edad = e; }
    void setGenero(std::string g) { strcpy(genero, g.c_str()); }
    void setTelefono(std::string t) { strcpy(telefono, t.c_str()); }
    void setDni(std::string d) { strcpy(dni, d.c_str()); }
    void setDireccion(Direccion dir) { _dir=dir; }
    std::string MostrarPersona();
    void personaCargar();
};
