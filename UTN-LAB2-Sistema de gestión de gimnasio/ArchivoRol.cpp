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
