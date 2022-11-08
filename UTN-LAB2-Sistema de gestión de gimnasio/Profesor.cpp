#include <cstring>
#include <iostream>
#include "Profesor.h"

using namespace std;

Profesor::Profesor(int i, char d[20], int he, int hs, char fi[20], float s, Persona persona = Persona()) {
    id = i;
    strcpy(disciplina, d);
    horarioEntrada = he;
    horarioSalida = hs;
    strcpy(fechaIngreso, fi);
    sueldo = s;
}

void Profesor::MostrarProfesor() {
    cout << "ID: " << id << endl;
    cout << "Disciplina: " << disciplina << endl;
    cout << "Horario de entrada: " << horarioEntrada << endl;
    cout << "Horario de salida: " << horarioSalida << endl;
    cout << "Fecha de ingreso: " << fechaIngreso << endl;
    cout << "Sueldo: " << sueldo << endl;
    persona.MostrarPersona();
}

void Profesor::cargarProfesor() {
	Persona::personaCargar();
	
		cout << "Ingrese el ID: ";
		cin >> id;
		cout << "Ingrese la disciplina: ";
		cin >> disciplina;
		cout << "Ingrese el horario de entrada: ";
		cin >> horarioEntrada;
		cout << "Ingrese el horario de salida: ";
		cin >> horarioSalida;
		cout << "Ingrese la fecha de ingreso: ";
		cin >> fechaIngreso;
		cout << "Ingrese el sueldo: ";
		cin >> sueldo;
}
