#include <cstring>
#include <iostream>
#include "Persona.h"

Persona::Persona(char n[20], char a[20], char fn[20], int e, char g[20], char t[20], char d[20]) {
    strcpy(nombre, n);
    strcpy(apellido, a);
    strcpy(fechaNacimiento, fn);
    edad = e;
    strcpy(genero, g);
    strcpy(telefono, t);
    strcpy(dni, d);
    strcpy(direccion, d);
}

void Persona::MostrarPersona() {
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
    cout << "Edad: " << edad << endl;
    cout << "Genero: " << genero << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "DNI: " << dni << endl;
    cout << "Direccion: " << direccion << endl;
}

void Persona::personaCargar() {
		cout << "Ingrese nombre: ";
		cin >> nombre;
		cout << "Ingrese apellido: ";
		cin >> apellido;
		cout << "Ingrese fecha de nacimiento: ";
		cin >> fechaNacimiento;
		cout << "Ingrese edad: ";
		cin >> edad;
		cout << "Ingrese genero: ";
		cin >> genero;
		cout << "Ingrese telefono: ";
		cin >> telefono;
		cout << "Ingrese DNI: ";
		cin >> dni;
		cout << "Ingrese direccion: ";
		cin >> direccion;
	
}
