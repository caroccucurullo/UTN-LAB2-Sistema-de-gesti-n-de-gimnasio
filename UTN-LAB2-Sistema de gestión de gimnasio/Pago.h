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
 */

class Pago {
private:
    int nroSocio;
	int idMembresia;
    float valor;
	Fecha fechaDePago;
	
public:
    Pago(int ns = 0, int im=0, float v = 0, Fecha fechaDePago = Fecha());
  
    int getNroSocio() { return nroSocio; }
    int getIdMembresia() { return idMembresia; }
    float getValor() { return valor; }
    void setFechaAsignada(Fecha fP) { fechaDePago = fP; }

    void setNroSocio(int ns) { nroSocio = ns; }
	void setIdMembresia(int im) { idMembresia = im; }
    void setValor(float v) { valor = v; }
	Fecha getFechaDePago() { return fechaDePago; }

    void MostrarPago();
    std::string MostrarPagosDatos();
    void CargarPago();
};
