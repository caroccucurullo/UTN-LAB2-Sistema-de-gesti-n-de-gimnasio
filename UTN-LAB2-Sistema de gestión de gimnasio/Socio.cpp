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
    Persona::MostrarPersona();
    std::cout << "Nro. Socio: " << nroSocio << std::endl;
    std::cout << "Peso: " << peso << std::endl;
    std::cout << "Cobertura Medica: " << coberturaMedica << std::endl;
    std::cout << "Contacto de Emergencia: " << contactoEmergencia << std::endl;
    std::cout << "Apto Medico: " << aptoMed << std::endl;
    std::cout << "ID Membresia: " << idMembresia << std::endl;
    std::cout << "Estado: " << estado << std::endl;
}
