#include <iostream>
using namespace std;
#include "Persona.h"
#include "Socio.h"
#include "ArchivoSocios.h"
#include "Disciplina.h"
#include "Profesor.h"
#include "Membresia.h"
#include "Salon.h"
#include "Rol.h"


int main() {
	Socio socio, socio2;
	ArchivoSocios arSocios;
	/*socio.CargarSocio();
	std::cout << std::endl;
	cout<<socio.MostrarSociosDatos();
	arSocios.guardarSocio(socio);
	socio2 = arSocios.leerSocio(0);
	std::cout << std::endl;
	cout<<socio2.MostrarSociosDatos();*/
	/*int cant = arSocios.getCantidad();
	cout << cant << endl;
	Socio* p = new Socio[cant];
	if (p == nullptr) exit(150);
	for (int x = 0;x < cant;x++) {
		 p[x]=socio = arSocios.leerSocio(x);
		 
	}
	for (int x = 0;x < cant;x++) {
		cout << p[x].MostrarSociosDatos() << endl;
	}
	delete[] p;*/
	/*socio.CargarSocio();
	arSocios.modificarSocio(socio,arSocios.buscarRegPorDni("38392431"));*/

  return 0;
}