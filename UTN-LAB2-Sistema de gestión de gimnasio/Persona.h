/* Persona:
Nombre
Apellido
F. nac.
Edad
Género
Teléfono
DNI
Dirección
 */
#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Persona {
protected:
    char nombre[20];
    char apellido[20];
    char fechaNacimiento[20];
    int edad;
    char genero[20];
    char telefono[20];
    char dni[20];
    char direccion[20];
public:

    Persona(char n[20], char a[20], char fn[20], int e, char g[20], char t[20], char d[20]);
    const char *getNombre() { return nombre; }
    const char *getApellido() { return apellido; }
    const char *getFechaNacimiento() { return fechaNacimiento; }
    int getEdad() { return edad; }
    const char *getGenero() { return genero; }
    const char *getTelefono() { return telefono; }
    const char *getDni() { return dni; }
    const char *getDireccion() { return direccion; }
    void setNombre(const char *n) { strcpy(nombre, n); }
    void setApellido(const char *a) { strcpy(apellido, a); }
    void setFechaNacimiento(const char *fn) { strcpy(fechaNacimiento, fn); }
    void setEdad(int e) { edad = e; }
    void setGenero(const char *g) { strcpy(genero, g); }
    void setTelefono(const char *t) { strcpy(telefono, t); }
    void setDni(const char *d) { strcpy(dni, d); }
    void setDireccion(const char *dir) { strcpy(direccion, dir); }
    void MostrarPersona();
    void personaCargar();
};

#endif // PERSONA_H_INCLUDED
