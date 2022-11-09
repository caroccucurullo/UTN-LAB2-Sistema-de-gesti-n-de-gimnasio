#include <iostream>
using namespace std;
#include "Persona.h"
#include "Socio.h"
#include "Disciplina.h"
#include "Profesor.h"
#include "Membresia.h"
#include "Salon.h"
#include "Rol.h"


int main() {
	Socio socio;
	socio.CargarSocio();
	std::cout << std::endl;
	socio.MostrarSocio();
  return 0;
}