#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "fecha.h"

/* PAGO:
    -NroSocio
	-IDMembresia
    -Valor
	-FechaDePago
	-ID
 */

class Pago {
private:
    int nroSocio;
	int idMembresia;
    float valor;
	Fecha fechaDePago;
	int id;
	
public:
	Pago(int ns = 0, int im = 0, float v = 0, Fecha fechaDePago = Fecha(), int i = 0);
  
    int getNroSocio() { return nroSocio; }
    int getIdMembresia() { return idMembresia; }
    float getValor() { return valor; }
    void setFechaAsignada(Fecha fP) { fechaDePago = fP; }
	int getId() { return id; }

    void setNroSocio(int ns) { nroSocio = ns; }
	void setIdMembresia(int im) { idMembresia = im; }
    void setValor(float v) { valor = v; }
	Fecha getFechaDePago() { return fechaDePago; }
	void setId(int i) { id = i; }

    void MostrarPago();
    std::string MostrarPagosDatos();
    void CargarPago();
};
