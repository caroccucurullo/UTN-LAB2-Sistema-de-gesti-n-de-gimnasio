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
	if (p == nullptr) return cant;
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
	int nRegistro = buscarRegPorDni(cadena);
	if (nRegistro != -1) {
		Rol rol = leerRol(nRegistro);
		rol.MostrarRol();
	}
	else {
		std::cout << "No se encontro el DNI ingresado." << std::endl;
	}
}

///BUSCAR REGISTRO POR ID
int ArchivoRol::buscarRegPorID(int id)
{
	int cant = getCantidad();
	Rol rol;
	for (int x = 0;x < cant;x++) {
		rol = leerRol(x);
		if (rol.getId() == id) return x;
	}
	return -1;
}

//CONSULTA POR CARGO

void ArchivoRol::rolPorCargo()
{
	int cantCargo = getCantidad();
	if (cantCargo > 0) {
		std::string cadena;
		std::cout << "Ingrese Cargo: ";
		std::cin.ignore();
		std::getline(std::cin, cadena);
		bool hay = false;
		Rol* vRol = new Rol[cantCargo];
		if (vRol == nullptr) {
			std::cout << "No se pudo abrir el archivo de registros." << std::endl;
			return;
		}
		leerTodos(vRol, cantCargo);
		for (int x = 0;x < cantCargo;x++) {
			if (vRol[x].getCargo() == cadena) {
				hay = true;
				vRol[x].MostrarRol();
				std::cout << std::endl;
			}
		}
		if (!hay) std::cout << "No hay adminsitrativos registrados en ese cargo." << std::endl;
		delete[] vRol;
	}
	else {
		std::cout << "No hay registros en el archivo." << std::endl;
	}
}

//CONSULTA POR FECHA DE INGRESO

void ArchivoRol::rolPorFechaIngreso()
{
	int cantCargo = getCantidad();
	if (cantCargo > 0) {
		Fecha fechaIngreso;
		fechaIngreso.Cargar();
		bool hay = false;
		Rol* vRol = new Rol[cantCargo];
		if (vRol == nullptr) {
			std::cout << "No se pudo abrir el archivo de registros." << std::endl;
			return;
		}
		leerTodos(vRol, cantCargo);
		system("cls");
		std::cout << "Ingresos en " << fechaIngreso.toString() << std::endl<<std::endl;
		for (int x = 0;x < cantCargo;x++) {
			if (vRol[x].getFechaIngreso() == fechaIngreso) {
				hay = true;
				vRol[x].MostrarRol();
				std::cout << std::endl;
			}
		}
		if (!hay) std::cout << "No hay administrativos registrados para esa fecha." << std::endl;
		delete[] vRol;
	}
	else {
		std::cout << "No hay registros en el archivo." << std::endl;
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

	std::cout << "El total de altas del anio " << anio << " es de : " << cantAltas << std::endl;

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

	std::cout << "El total de bajas del anio " << anio << " es de : " << cantBajas << std::endl;
}

void ArchivoRol::rolSueldoAnual()
{
	int idR;
	float sueldoAnual = 0;

	std::cout << "Ingrese el codigo de administrativo: " << std::endl;
	std::cin >> idR;
	int nRegistro = buscarRegPorID(idR);
	if (nRegistro != -1) {
		Rol rol = leerRol(nRegistro);
		sueldoAnual = rol.getSueldo() * 12;
		std::cout << "El sueldo anual de profesor/a " << rol.getNombre() << "(ID " << rol.getId() << ")" << " es de : " << setPrecision(sueldoAnual, 10) << std::endl;
	}
	else {
		std::cout << "No existe profesor con ese ID" << std::endl;
	}
}