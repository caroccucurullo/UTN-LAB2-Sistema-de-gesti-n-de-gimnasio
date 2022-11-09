#pragma once
#include "Persona.h"

/* Socio : Persona:
  -Nro. socio
  -Peso
  -Cobertura Medica
-Contacto de emergencia
-Apto med
-ID-Membresia
-Estado */

class Socio : public Persona {
private:
    int nroSocio;
    float peso;
    char coberturaMedica[20];
    char contactoEmergencia[20];
    bool aptoMed;
    int idMembresia;
    bool estado;
public:

    Socio(int ns = 0, float p = 0, const char* cm = " ", const char* ce = " ", bool am = 0, int id = 0, bool e = 0);
    int getNroSocio() { return nroSocio; }
    float getPeso() { return peso; }
    std::string getCoberturaMedica() { std::string cm(coberturaMedica) ;return cm; }
    std::string getContactoEmergencia() { std::string ce(contactoEmergencia); return ce; }
    bool getAptoMed() { return aptoMed; }
    int getIdMembresia() { return idMembresia; }
    bool getEstado() { return estado; }

    void setNroSocio(int ns) { nroSocio = ns; }
    void setPeso(float p) { peso = p; }
    void setCoberturaMedica(std::string cm) { strcpy(coberturaMedica, cm.c_str()); }
    void setContactoEmergencia(std::string ce) { strcpy(contactoEmergencia, ce.c_str()); }
    void setAptoMed(bool am) { aptoMed = am; }
    void setIdMembresia(int id) { idMembresia = id; }
    void setEstado(bool e) { estado = e; }

    void MostrarSocio();
    std::string MostrarSociosDatos();
    void CargarSocio();

    std::string setPrecision(float p);
};