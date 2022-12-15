#include "Socio.h"

Socio::Socio(int ns, bool am, int idMem, Fecha fIngreso, Fecha fEgreso) {
    nroSocio = ns;
    aptoMed = am;
    idMembresia = idMem;
    _fIngreso = fIngreso;
    _fEgreso = fEgreso;
    estado = true;
}

void Socio::MostrarSocio() {
    std::cout << "--------------------------------------" << std::endl;
    if(nroSocio!=0) std::cout << "Nro. Socio: " << nroSocio << std::endl;
    Persona::MostrarPersona();
    std::cout << "Apto Medico: " << aptoMed << std::endl;
    std::cout << "ID Membresia: " << idMembresia << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

std::string Socio::MostrarSociosDatos()
{
    std::string cadena;
    cadena = std::to_string(getNroSocio()) + "," + Persona::MostrarPersonaFormatoComas() + "," + std::to_string(getIdMembresia()) + "," + getFechaIngreso().toString();
    if (!estado) cadena += "," + _fEgreso.toString();
    return cadena;
}

void Socio::CargarSocioRegCompleto()
{
    int ns;
    char letra;
    std::cout << "Numero Socio: ";
    std::cin >> ns;
    setNroSocio(ns);
    Persona::CargarPersona();
    std::cout << "Apto Medico (y/n): ";
    std::cin >> letra;
	if (letra == 'y') setAptoMed(true);
	else setAptoMed(false);
    std::cout << "ID Membresia: ";
    std::cin >> ns;
    setIdMembresia(ns);
}

void Socio::CargarSocio()
{
    int ns;
    char letra;
    Persona::CargarPersona();
    std::cout << "Apto Medico (y/n): ";
    std::cin >> letra;
    if (letra == 'y') setAptoMed(true);
    else setAptoMed(false);
    std::cout << "ID Membresia: ";
    std::cin >> ns;
    setIdMembresia(ns);
}
