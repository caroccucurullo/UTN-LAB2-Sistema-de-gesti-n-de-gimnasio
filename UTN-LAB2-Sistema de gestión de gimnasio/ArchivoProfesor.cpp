#include "ArchivoProfesor.h"

bool ArchivoProfesor::guardarProfesor(Profesor& profesor)
{
	FILE* p = fopen("profesores.dat", "ab");
	if (p == nullptr) return false;
	bool ok = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return ok;
}

void ArchivoProfesor::guardarProfesor()
{
	Profesor profesor;
	profesor.cargarProfesor();
	if (guardarProfesor(profesor))
		std::cout << "Profesor guardado correctamente" << std::endl;
	else
		std::cout << "Error al guardar el profesor" << std::endl;
}

Profesor ArchivoProfesor::leerProfesor(int nRegistro)
{
	Profesor profesor;
	FILE* p = fopen("profesores.dat", "rb");
	if (p == nullptr) return profesor;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	bool leyo = fread(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return profesor;
}

bool ArchivoProfesor::leerTodos(Profesor* profesor, int cantidad)
{
	FILE* p = fopen("profesores.dat", "rb");
	if (p == nullptr) return false;
	bool leyo = fread(profesor, sizeof(Profesor), cantidad, p);
	fclose(p);
	return leyo;
}

bool ArchivoProfesor::modificarProfesor(Profesor& profesor, int nRegistro)
{
	FILE* p = fopen("profesores.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), SEEK_SET);
	bool ok = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return ok;
}

void ArchivoProfesor::modificarProfesor()
{
	std::string dni;
	std::cout << "Ingrese Dni de profesor a modificar: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
	Profesor profesor;
	profesor.cargarProfesor();
	if (modificarProfesor(profesor, buscarRegPorDni(dni)))
		std::cout << "Profesor modificado correctamente" << std::endl;
	else
		std::cout << "Error al modificar el profesor" << std::endl;
}

int ArchivoProfesor::getCantidad()
{
	int cant = 0;
	FILE* p = fopen("profesores.dat", "rb");
	fseek(p, 0, 2);
	cant = ftell(p) / sizeof(Profesor);
	fclose(p);
	return cant;
}
//CONSULTA POR DNI
int ArchivoProfesor::buscarRegPorDni(std::string dni)
{
	int cant = getCantidad();
	Profesor profesor;
	for (int x = 0;x < cant;x++) {
		profesor = leerProfesor(x);
		if (profesor.getDni() == dni) return x;
	}
	return -1;
}
void ArchivoProfesor::consultaPorDni()
{
	std::string dni;
	std::cout << "Ingrese Dni: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	Profesor profesor = buscarRegPorDni(dni);
	profesor.MostrarProfesor();
}
//CONSULTA POR DISCIPLINA
int ArchivoProfesor::getCantidadProfePorDis(std::string nombre)
{
	ArchivoDisciplina arDis;
	Disciplina disciplina = arDis.leerDisciplina(arDis.buscarRegPorNombre(nombre));
	int cantProfe = getCantidad(), cantDis=0;
	Profesor profesor;
	for (int x = 0;x < cantProfe;x++) {
		profesor = leerProfesor(x);
		if (profesor.getIdDisciplina() == disciplina.getCodigo()) cantDis++;
	}
	return cantDis;
}

void ArchivoProfesor::ProfePorDis()
{
	std::string cadena;
	std::cout << "Ingrese Disciplina: ";
	std::getline(std::cin, cadena);
	int cantProfePorDis = getCantidadProfePorDis(cadena);
	Profesor* vProfe = new Profesor[cantProfePorDis];
	if (vProfe == nullptr) return;
	copiarProfeDis(vProfe, cadena);
	mostrarProfe(vProfe, cantProfePorDis);
	delete[] vProfe;
}

void ArchivoProfesor::copiarProfeDis(Profesor* vProfe, std::string nombre)
{
	ArchivoDisciplina arDis;
	Disciplina disciplina = arDis.leerDisciplina(arDis.buscarRegPorNombre(nombre));
	Profesor profesor;
	int cantProfe = getCantidad();
	for (int x = 0;x < cantProfe;x++) {
		profesor = leerProfesor(x);
		if (profesor.getIdDisciplina() == disciplina.getCodigo()) {
			vProfe[x] = profesor;
		}
	}
}

void ArchivoProfesor::mostrarProfe(Profesor* vProfe, int cant)
{
	for (int x = 0;x < cant;x++) {
		vProfe[x].MostrarProfesor();
		std::cout << std::endl;
	}
}
//CONSULTA POR Turno
int ArchivoProfesor::getCantidadProfePorTurno(std::string turno)
{
	int cantProfe = getCantidad(), cantHorario = 0;
	Profesor profesor;
	for (int x = 0;x < cantProfe;x++) {
		profesor = leerProfesor(x);
		if (profesor.getTurno() == turno) cantHorario++;
	}
	return cantHorario;

}

void ArchivoProfesor::ProfePorTurno()
{
	std::string cadena;
	std::cout << "Ingrese Turno: ";
	std::getline(std::cin, cadena);
	int cantProfePorTurno = getCantidadProfePorTurno(cadena);
	Profesor* vProfe = new Profesor[cantProfePorTurno];
	if (vProfe == nullptr) return;
	copiarProfeTurno(vProfe, cadena);
	mostrarProfe(vProfe, cantProfePorTurno);
	delete[] vProfe;
}

void ArchivoProfesor::copiarProfeTurno(Profesor* vProfe, std::string turno)
{
	Profesor profesor;
	int cantProfe = getCantidad();
	for (int x = 0;x < cantProfe;x++) {
		profesor = leerProfesor(x);
		if (profesor.getTurno() == turno) {
			vProfe[x] = profesor;
		}
	}
}

bool ArchivoProfesor::bajaLogica(int nRegistro)
{
	Profesor profesor;
	Fecha fecha;
	fecha.establecerFechaHoy();
	profesor = leerProfesor(nRegistro);
	bool flag;
	FILE* p = fopen("profesores.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	profesor.setEstado(false);
	profesor.setFechaEgreso(fecha);
	flag = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return flag;
}

void ArchivoProfesor::bajaProfesor()
{
	std::string dni;
	std::cout << "Ingrese dni a dar de baja: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	if(bajaLogica(buscarRegPorDni(dni))) std::cout<< "Baja de " << dni << " realizada exitosamente." << std::endl;
	else std::cout << "Baja de " << dni << " erronea. Intente nuevamente." << std::endl;
}

bool ArchivoProfesor::altaLogica(int nRegistro)
{
	Profesor profesor;
	profesor = leerProfesor(nRegistro);
	Fecha fecha;
	fecha.establecerFechaHoy();
	bool flag;
	FILE* p = fopen("profesores.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	profesor.setEstado(true);
	profesor.setFechaIngreso(fecha);
	flag = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return flag;
}

void ArchivoProfesor::altaProfesor()
{
	std::string dni;
	std::cout << "Ingrese dni a dar de alta: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	if (altaLogica(buscarRegPorDni(dni))) std::cout << "Alta de " << dni << " realizada exitosamente." << std::endl;
	else std::cout << "Alta de " << dni << " erronea. Intente nuevamente." << std::endl;
}

//INFORMES

void ArchivoProfesor::profesorAltasAnuales(int anio)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	
	int cant = getCantidad();
	Profesor profesor;
	int cantAltas = 0;
	
	for (int x = 0;x < cant;x++) {
		profesor = leerProfesor(x);
		if (profesor.getFechaIngreso().getAnio() == anio && profesor.getEstado() == true) {
			cantAltas++;
		}
	}
	
	std::cout << "El total de altas del anio " << anio << "es de : " << cantAltas << std::endl;

}

void ArchivoProfesor::profesorBajasAnuales(int anio)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Profesor profesor;
	int cantBajas = 0;

	for (int x = 0;x < cant;x++) {
		profesor = leerProfesor(x);
		if (profesor.getFechaEgreso().getAnio() == anio && profesor.getEstado() == false) {
			cantBajas++;
		}
	}

	std::cout << "El total de bajas del anio " << anio << "es de : " << cantBajas << std::endl;
}

void ArchivoProfesor::profesorSueldoAnual(int idP)
{
	std::cout << "Ingrese el codigo de profesor: " << std::endl;
	std::cin >> idP;
	
	int cant = getCantidad();
	Profesor profesor;
	int sueldoAnual = 0;

	for (int x = 0;x < cant;x++) {
		profesor = leerProfesor(x);
		if (profesor.getId() == idP) {
			sueldoAnual = profesor.getSueldo() * 12;
		}
	}

	std::cout << "El sueldo anual del profesor: "<< idP << " es de : " << sueldoAnual << std::endl;
}

void ArchivoProfesor::ordenarPorApellido(){

	int cantidad = getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	ordenarVectorPorApellido(profesores, cantidad);
	mostrarVector(profesores, cantidad);

	delete[] profesores;
}

void ArchivoProfesor::ordenarPorDisciplina() {

	int cantidad = getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	ordenarVectorPorDisciplina(profesores, cantidad);
	mostrarVector(profesores, cantidad);

	delete[] profesores;
}

void ArchivoProfesor::ordenarPorSueldo() {

	int cantidad = getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	ordenarVectorPorSueldo(profesores, cantidad);
	mostrarVector(profesores, cantidad);

	delete[] profesores;
}

void ArchivoProfesor::mostrarProfesoresPorEstado(){

	int cantidad = getCantidad();
	Profesor* profesores = new Profesor[cantidad];
	int estado;
	bool flag = false;

	completarVector(profesores, cantidad);

	std::cout << "Ingese 1 para los Profesores Activos, 0 para Inactivos : " << std::endl;
	std::cin >> estado;

	if(estado == 1) flag = true;

	mostrarVectorPorEstado(profesores, cantidad, flag);
	delete[] profesores;
}

void ArchivoProfesor::mostrarProfesoresPorTurno(std::string turno) {

	int cantidad = getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	mostrarVectorPorTurno(profesores, cantidad, turno);
	delete[] profesores;
}