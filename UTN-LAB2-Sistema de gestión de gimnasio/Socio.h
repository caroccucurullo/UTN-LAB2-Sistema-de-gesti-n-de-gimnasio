#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include <iostream>
#include "Socio.h"
#include "Persona.h"

using namespace std;

/* Socio : Persona:
        -Nro. socio
    -Peso
    -Cobertura Médica
-Contacto de emergencia
-Apto med
-ID-Membresía
-Estado */

class Socio {
private:
    int nroSocio;
    float peso;
    char coberturaMedica[20];
    char contactoEmergencia[20];
    bool aptoMed;
    int idMembresia;
    bool estado;
    Persona persona;
public:

    Socio(int ns = 0, float p = 0, char cm[20], char ce[20], bool am = 0, int id = 0, bool e = 0, Persona persona = Persona());
    int getNroSocio() { return nroSocio; }
    float getPeso() { return peso; }
    const char *getCoberturaMedica() { return coberturaMedica; }
    const char *getContactoEmergencia() { return contactoEmergencia; }
    bool getAptoMed() { return aptoMed; }
    int getIdMembresia() { return idMembresia; }
    bool getEstado() { return estado; }
    void setNroSocio(int ns) { nroSocio = ns; }
    void setPeso(float p) { peso = p; }
    void setCoberturaMedica(const char *cm) { strcpy(coberturaMedica, cm); }
    void setContactoEmergencia(const char *ce) { strcpy(contactoEmergencia, ce); }
    void setAptoMed(bool am) { aptoMed = am; }
    void setIdMembresia(int id) { idMembresia = id; }
    void setEstado(bool e) { estado = e; }
    void MostrarSocio();
};

#endif // SOCIO_H_INCLUDED