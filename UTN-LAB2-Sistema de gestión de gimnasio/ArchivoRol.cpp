#include "ArchivoRol.h"

bool ArchivoRol::guardarRol(Rol& rol)
{
	FILE* p = fopen("roles.dat", "ab");
	if (p == nullptr) return false;
	bool ok = fwrite(&rol, sizeof(Rol), 1, p);
	fclose(p);
	return ok;
}

void ArchivoRol::guardarRol()
{
	Rol rol;
	rol.CargarRol();
	if (guardarRol(rol))
		std::cout << "Rol guardado correctamente" << std::endl;
	else
		std::cout << "Error al guardar el rol" << std::endl;
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

void ArchivoRol::modificarRol()
{
	std::string dni;
	std::cout << "Ingrese Dni de socio a modificar: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
	Rol rol;
	rol.CargarRol();
	if (modificarRol(rol, buscarRegPorDni(dni)))
		std::cout << "Rol modificado correctamente" << std::endl;
	else
		std::cout << "Error al modificar el rol" << std::endl;
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
void ArchivoRol::consultaPorDni()
{
	std::string cadena;
	std::cout << "Ingrese DNI a consultar: ";
	std::cin.ignore();
	std::getline(std::cin, cadena);
	Rol rol = leerRol(buscarRegPorDni(cadena));
	rol.MostrarRol();
}
//CONSULTA POR CARGO
int ArchivoRol::getCantidadPorCargo(std::string cargo)
{
	int cant = getCantidad(), cantCargo = 0;
	Rol rol;
	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getCargo() == cargo) cantCargo++;
	}
	return cantCargo;
}

void ArchivoRol::rolPorCargo()
{
	std::string cadena;
	std::cout << "Ingrese Cargo: ";
	std::getline(std::cin, cadena);
	int cantCargo = getCantidadPorCargo(cadena);
	Rol* vRol = new Rol[cantCargo];
	if (vRol == nullptr) return;
	copiarRolCargo(vRol, cadena);
	mostrarRol(vRol, cantCargo);
}

void ArchivoRol::copiarRolCargo(Rol* vRol, std::string cargo)
{
	int cant = getCantidad();
	Rol rol;
	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getCargo() == cargo) vRol[x] = rol;
	}
}

void ArchivoRol::mostrarRol(Rol* vRol, int cant)
{
	for (int x = 0;x < cant;x++) {
		vRol[x].MostrarRol();
		std::cout << std::endl;
	}

}
//CONSULTA POR FECHA DE INGRESO
int ArchivoRol::getCantidadPorFechaIngreso(Fecha fechaIngreso)
{
	int cant = getCantidad(), cantFechaIngreso = 0;
	Rol rol;
	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getFechaIngreso() == fechaIngreso) cantFechaIngreso++;
	}
	return cantFechaIngreso;
}

void ArchivoRol::rolPorFechaIngreso()
{
	Fecha fechaIngreso;
	fechaIngreso.Cargar();
	int cantFechaIngreso = getCantidadPorFechaIngreso(fechaIngreso);
	Rol* vRol = new Rol[cantFechaIngreso];
	if (vRol == nullptr) return;
	copiarRolFechaIngreso(vRol, fechaIngreso);
	mostrarRol(vRol, cantFechaIngreso);
	delete[] vRol;
}

void ArchivoRol::copiarRolFechaIngreso(Rol* vRol, Fecha fechaIngreso)
{
	int cant = getCantidad();
	Rol rol;
	for (int x = 0;x < cant;x++) {
		if (rol.getFechaIngreso() == fechaIngreso) vRol[x] = rol;
	}
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

void ArchivoRol::bajaRol()
{
	std::string dni;
	std::cout << "Ingrese DNI de rol a dar de baja: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	if (bajaLogica(buscarRegPorDni(dni)))
		std::cout << "Rol dado de baja correctamente" << std::endl;
	else
		std::cout << "Error al dar de baja el rol" << std::endl;
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

void ArchivoRol::altaRol()
{
	std::string dni;
	std::cout << "Ingrese DNI de rol a dar de alta: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	if (altaLogica(buscarRegPorDni(dni)))
		std::cout << "Rol dado de alta correctamente" << std::endl;
	else
		std::cout << "Error al dar de alta el rol" << std::endl;
}
