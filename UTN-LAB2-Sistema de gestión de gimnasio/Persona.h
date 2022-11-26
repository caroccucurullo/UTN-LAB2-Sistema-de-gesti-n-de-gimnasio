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
#include "Contacto.h"

class Persona {
protected:
    char _nombre[20];
    char _apellido[20];
    Fecha _fnac;
    int _edad;
    char _dni[20];
    Contacto _contacto;
    bool _estado;
public:

    Persona(std::string n = "", std::string a = "", Fecha nac = Fecha(), std::string d="", Contacto contacto=Contacto());
    std::string getNombre() { std::string n(_nombre); return n; }
    std::string getApellido() { std::string a(_apellido); return a; }
    Fecha getFechaNac() { return _fnac; }
    int getEdad() { return _edad; }
    std::string getDni() { std::string d(_dni); return d; }
    Contacto getContacto() { return _contacto; }
	bool getEstado() { return _estado; }
	
    void setNombre(std::string n) { strcpy(_nombre, n.c_str()); }
    void setApellido(std::string a) { strcpy(_apellido, a.c_str()); }
    void setFechaNac(Fecha fnac) { _fnac = fnac; }
    void setEdad(int e) { _edad = e; }
    void setDni(std::string d) { strcpy(_dni, d.c_str()); }
    void setContacto(Contacto contacto) { _contacto = contacto; }
	void setEstado(bool estado) { _estado = estado; }

    int calcularEdad();

    void MostrarPersona();
    std::string MostrarPersonaFormatoComas();
    void CargarPersona();
};
