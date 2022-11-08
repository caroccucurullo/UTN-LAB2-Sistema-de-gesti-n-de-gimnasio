#include <cstring>
#include <iostream>
#include "Socio.h"
#include "Persona.h"

using namespace std;

Socio::Socio(int ns, float p, char cm[20], char ce[20], bool am, int id, bool e, Persona persona = Persona()) {
    nroSocio = ns;
    peso = p;
    strcpy(coberturaMedica, cm);
    strcpy(contactoEmergencia, ce);
    aptoMed = am;
    idMembresia = id;
    estado = e;
}

void Socio::MostrarSocio() {
    cout << "Nro. Socio: " << nroSocio << endl;
    cout << "Peso: " << peso << endl;
    cout << "Cobertura Medica: " << coberturaMedica << endl;
    cout << "Contacto de Emergencia: " << contactoEmergencia << endl;
    cout << "Apto Medico: " << aptoMed << endl;
    cout << "ID Membresia: " << idMembresia << endl;
    cout << "Estado: " << estado << endl;
    persona.MostrarPersona();
}

