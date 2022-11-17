#include "ArchivoRol.h"

bool ArchivoRol::guardarRol(Rol& rol)
{
	FILE* p = fopen("roles.dat", "ab");
	if (p == nullptr) return false;
	bool ok = fwrite(&rol, sizeof(Rol), 1, p);
	fclose(p);
	return ok;
}

Rol ArchivoRol::leerRol(int nRegistro)
{
	Rol rol;
	FILE* p = fopen("roles.dat", "rb");
	if (p == nullptr) return rol;
	fseek(p, nRegistro * sizeof(Rol), 0);
	bool leyo = fread(&rol, sizeof(Rol), 1, p);
	fclose(p);
	return rol;
}

bool ArchivoRol::leerTodos(Rol* rol, int cantidad)
{
	FILE* p = fopen("roles.dat", "rb");
	if (p == nullptr) return false;
	bool leyo = fread(rol, sizeof(Rol), cantidad, p);
	fclose(p);
	return leyo;
}

bool ArchivoRol::modificarRol(Rol& rol, int nRegistro)
{
	FILE* p = fopen("roles.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Rol), SEEK_SET);
	bool ok = fwrite(&rol, sizeof(Rol), 1, p);
	fclose(p);
	return ok;
}

int ArchivoRol::getCantidad()
{
	int cant = 0;
	FILE* p = fopen("roles.dat", "rb");
	fseek(p, 0, 2);
	cant = ftell(p) / sizeof(Rol);
	fclose(p);
	return cant;
}

int ArchivoRol::buscarRegPorDni(std::string dni)
{
	int cant = getCantidad();
	Rol rol;
	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getDni() == dni) return x;
	}
	return -1;
}

bool ArchivoRol::bajaLogica(int nRegistro)
{
	Rol rol;
	Fecha fecha;
	fecha.establecerFechaHoy();
	rol = leerRol(nRegistro);
	bool flag;
	FILE* p = fopen("roles.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Rol), 0);
	rol.setEstado(false);
	rol.setFechaEgreso(fecha);
	flag = fwrite(&rol, sizeof(Rol), 1, p);
	fclose(p);
	return flag;
}

bool ArchivoRol::altaLogica(int nRegistro)
{
	Rol rol;
	rol = leerRol(nRegistro);
	Fecha fecha;
	fecha.establecerFechaHoy();
	bool flag;
	FILE* p = fopen("roles.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Rol), 0);
	rol.setEstado(true);
	rol.setFechaIngreso(fecha);
	flag = fwrite(&rol, sizeof(Rol), 1, p);
	fclose(p);
	return flag;
}

//INFORMES

void ArchivoRol::rolAltasAnuales()
{
	int anio;

	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Rol rol;
	int cantAltas = 0;

	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getFechaIngreso().getAnio() == anio && rol.getEstado() == true) {
			cantAltas++;
		}
	}

	std::cout << "El total de altas del anio " << anio << "es de : " << cantAltas << std::endl;

}

void ArchivoRol::rolBajasAnuales()
{
	int anio;

	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Rol rol;
	int cantBajas = 0;

	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getFechaEgreso().getAnio() == anio && rol.getEstado() == false) {
			cantBajas++;
		}
	}

	std::cout << "El total de bajas del anio " << anio << "es de : " << cantBajas << std::endl;
}

void ArchivoRol::rolSueldoAnual()
{
	int idR;

	std::cout << "Ingrese el codigo de profesor: " << std::endl;
	std::cin >> idR;

	int cant = getCantidad();
	Rol rol;
	float sueldoAnual = 0;

	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getId() == idR) {
			sueldoAnual = rol.getSueldo() * 12;
		}
	}

	std::cout << "El sueldo anual del profesor: " << idR << " es de : " << sueldoAnual << std::endl;
}
