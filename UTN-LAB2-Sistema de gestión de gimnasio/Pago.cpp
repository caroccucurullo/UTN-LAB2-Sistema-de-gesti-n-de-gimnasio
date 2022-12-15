#include "Pago.h"

Pago::Pago(int ns, int idMem, float v, Fecha fPago, int i) {
    nroSocio = ns;
    idMembresia = idMem;
    valor = v;
    fechaDePago = fPago;
	id = i;
}

void Pago::MostrarPago() {
	if (id > 0) std::cout << "ID: " << id << std::endl;
    std::cout << "Nro. Socio: " << nroSocio << std::endl;
    std::cout << "ID Membresia: " << idMembresia << std::endl;
	std::cout << "Valor: " << valor << std::endl;
	std::cout << "Fecha de pago: " << fechaDePago.getDia() << "/" << fechaDePago.getMes() << "/" << fechaDePago.getAnio() << std::endl;
	
}

std::string Pago::MostrarPagosDatos()
{
    std::string cadena;
    cadena = std::to_string(getNroSocio()) + "," + std::to_string(getIdMembresia()) + "," + 
		std::to_string(getValor()) + "," + getFechaDePago().toString();
    return cadena;
}

void Pago::CargarPago()
{
	int ns;
	std::cout << "Numero Socio: ";
	std::cin >> ns;
	setNroSocio(ns);
	std::cout << "ID Membresia: ";
	std::cin >> ns;
	setIdMembresia(ns);
	std::cout << "Valor: ";
	std::cin >> ns;
	setValor(ns);
	fechaDePago.Cargar();
}