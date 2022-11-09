#include "Socio.h"

Socio::Socio(int ns, float p, const char* cm, const char* ce, bool am, int id, bool e) {
    nroSocio = ns;
    peso = p;
    strcpy(coberturaMedica, cm);
    strcpy(contactoEmergencia, ce);
    aptoMed = am;
    idMembresia = id;
    estado = e;
}

void Socio::MostrarSocio() {
    std::cout<<Persona::MostrarPersona()<<std::endl;
    std::cout << "Nro. Socio: " << nroSocio << std::endl;
    std::cout <<std::fixed<< std::setprecision(2) << "Peso: " << peso << std::endl;
    std::cout << "Cobertura Medica: " << coberturaMedica << std::endl;
    std::cout << "Contacto de Emergencia: " << contactoEmergencia << std::endl;
    std::cout << "Apto Medico: " << aptoMed << std::endl;
    std::cout << "ID Membresia: " << idMembresia << std::endl;
    std::cout << "Estado: " << estado << std::endl;
}

std::string Socio::MostrarSociosDatos()
{
    std::string cadena;
    cadena = Persona::MostrarPersona() + "," + std::to_string(getNroSocio()) + "," + setPrecision(getPeso()) + "," + getCoberturaMedica() + "," + getContactoEmergencia() + "," + std::to_string(getIdMembresia());
    return cadena;
}

void Socio::CargarSocio()
{
    std::string cadena;
    int ns;
    float p;
    Persona::personaCargar();
    std::cout << "Numero Socio: ";
    std::cin >> ns;
    setNroSocio(ns);
    std::cout << "Peso: ";
    std::cin >> p;
    setPeso(p);
    std::cout << "Cobertura Medica: ";
    std::cin.ignore();
    std::getline(std::cin, cadena);
    setCoberturaMedica(cadena);
    std::cout << "Contacto Emergencia: ";
    std::getline(std::cin, cadena);
    setContactoEmergencia(cadena);
    std::cout << "Apto Medico (1=Si/0=No): ";
    std::cin >> ns;
    setAptoMed(ns);
    std::cout << "ID Membresia: ";
    std::cin >> ns;
    setIdMembresia(ns);
    setEstado(true);
}

std::string Socio::setPrecision(float p)
{
    std::string peso(std::to_string(p));
    peso.resize(5);
    return peso;
}
