#include "Cargar.h"

void Cargar::CargarPersona(Socio& socio)
{
	//std::cout << "CARGAR.CARGARPERSONA" << std::endl;
	ArchivoSocios arSocio;
	Fecha fnac;
	Contacto contacto;
	std::string cadena;
	std::cin.ignore();
	std::cout << "Nombre: ";
	std::getline(std::cin, cadena);
	socio.setNombre(cadena);
	std::cout << "Apellido: ";
	std::getline(std::cin, cadena);
	socio.setApellido(cadena);
	std::cout << "Fecha de nacimiento: " << std::endl;
	fnac.Cargar();
	socio.setFechaNac(fnac);
	socio.setEdad(socio.calcularEdad());
	std::cin.ignore();
	std::cout << "DNI: ";
	std::getline(std::cin, cadena);
	while (arSocio.buscarRegPorDni(cadena) != -1) {
		//std::cout << arSocio.buscarRegPorDni(cadena) << std::endl;
		std::cout << "Ya existe socio con DNI " << cadena << " ingrese nuevamente: ";
		std::getline(std::cin, cadena);
	}
	//std::cout << arSocio.buscarRegPorDni(cadena) << std::endl;
	socio.setDni(cadena);
	std::cout << "Contacto: " << std::endl;
	contacto.cargar();
	socio.setContacto(contacto);
}

void Cargar::CargarSocio(Socio& socio)
{
	//std::cout << "CARGAR.CARGARSOCIO" << std::endl;
	//Socio socio;
	ArchivoMembresia arMem;
	char letra;
	std::string cadena;
	CargarPersona(socio);
	std::cout << "Apto Medico (y/n): ";
	std::cin >> letra;
	while (letra != 'y' && letra != 'n' && letra != 'Y' && letra != 'N')
	{
		std::cout << "Letra incorrecta. Escriba 'y' o 'n': ";
		std::cin >> letra;

	}
	if (letra == 'y'|| letra != 'Y') socio.setAptoMed(true);
	else if (letra == 'n' || letra != 'N') socio.setAptoMed(false);
	std::cout << "Nombre Membresia: ";
	std::cin.ignore();
	std::getline(std::cin, cadena);
	
	while (arMem.buscarRegPorNombre(cadena) == -1) {
		std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
		std::getline(std::cin, cadena);
	}
	socio.setIdMembresia(arMem.buscarRegPorNombre(cadena)+1);

	/*system("cls");
	socio.MostrarSocio();
	std::cout << std::endl;
	std::cout << "Datos ingresados correctamente?(y/n): ";
	std::cin >> letra;
	while (letra != 'y' && letra != 'n' && letra != 'Y' && letra != 'N')
	{
		std::cout << "Letra incorrecta. Escriba 'y' o 'n': ";
		std::cin >> letra;

	}
	if (letra == 'n' || letra == 'N') {
		system("cls");
		CargarSocio(socio);
	}
	else {
		return;
	}*/
}
