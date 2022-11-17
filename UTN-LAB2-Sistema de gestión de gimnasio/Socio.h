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
    bool aptoMed;
    int idMembresia;
    Fecha _fIngreso;
    Fecha _fEgreso;
    bool estado;
public:

    Socio(int ns = 0, bool am = false, int idMem = 0, Fecha fIngreso=Fecha(), Fecha fEgreso=Fecha(0,0,0));
    int getNroSocio() { return nroSocio; }
    bool getAptoMed() { return aptoMed; }
    int getIdMembresia() { return idMembresia; }
    Fecha getFechaIngreso() { return _fIngreso; }
	Fecha getFechaEgreso() { return _fEgreso; }
    bool getEstado() { return estado; }

    void setNroSocio(int ns) { nroSocio = ns; }
    void setAptoMed(bool am) { aptoMed = am; }
    void setIdMembresia(int id) { idMembresia = id; }
	void setFechaIngreso(Fecha fIngreso) { _fIngreso = fIngreso; }
	void setFechaEgreso(Fecha fEgreso) { _fEgreso = fEgreso; }
    void setEstado(bool e) { estado = e; }

    void MostrarSocio();
    std::string MostrarSociosDatos();
    void CargarSocio();

    void ordenarPorNombre();
    void ordenarPorEdad();
    void mostrarPorEstado();
    void mostrarPorAptoMedico();
    /*std::string setPrecision(float p);*/
};