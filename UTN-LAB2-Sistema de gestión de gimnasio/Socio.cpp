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
    std::cout << "Nro. Socio: " << nroSocio << std::endl;
    Persona::MostrarPersona();
    std::cout << "Apto Medico: " << aptoMed << std::endl;
    std::cout << "ID Membresia: " << idMembresia << std::endl;
}

std::string Socio::MostrarSociosDatos()
{
    std::string cadena;
    cadena = std::to_string(getNroSocio()) + "," + Persona::MostrarPersonaFormatoComas() + "," + std::to_string(getIdMembresia()) + "," + getFechaIngreso().toString();
    if (!estado) cadena += "," + _fEgreso.toString();
    return cadena;
}

void Socio::CargarSocio()
{
    int ns;
    std::cout << "Numero Socio: ";
    std::cin >> ns;
    setNroSocio(ns);
    std::cin.ignore();
    Persona::CargarPersona();
    std::cout << "Apto Medico (1=Si/0=No): ";
    std::cin >> ns;
    setAptoMed(ns);
    std::cout << "ID Membresia: ";
    std::cin >> ns;
    setIdMembresia(ns);
    //_fIngreso.Cargar();
}

//std::string Socio::setPrecision(float p)
//{
//    std::string peso(std::to_string(p));
//    peso.resize(5);
//    return peso;
//}
