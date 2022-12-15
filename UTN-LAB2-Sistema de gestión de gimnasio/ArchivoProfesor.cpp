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
	Cargar cargarProfesor;

	do {
		cargarProfesor.cargarProfesor(profesor);
	} while (!validarDatosProfesor(profesor));
	
	profesor.setId(ultimoProfesor() + 1);
	
	if (guardarProfesor(profesor))
		std::cout << "Profesor guardado correctamente" << std::endl;
	else
		std::cout << "Error al guardar el profesor" << std::endl;
}

bool ArchivoProfesor::validarDatosProfesor(Profesor& profesor)
{
	char letra;
	system("cls");
	profesor.MostrarProfesor();
	std::cout << std::endl << "Datos ingresados correctamente?(y/n): ";
	std::cin >> letra;
	while (letra != 'y' && letra != 'n' && letra != 'Y' && letra != 'N')
	{
		std::cout << "Letra incorrecta. Escriba 'y' o 'n': ";
		std::cin >> letra;
	}
	if (letra == 'n' || letra == 'N') {
		system("cls");
		return false;
	}
	return true;
}

Profesor ArchivoProfesor::leerProfesor(int nRegistro)
{
	Profesor profesor;
	FILE* p = fopen("profesores.dat", "rb");
	if (p == nullptr) return profesor;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	fread(&profesor, sizeof(Profesor), 1, p);
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

void ArchivoProfesor::modificarProfesorConOpciones()
{
	int opcion1, subopcion1, idProfesor, nRegistro = -1;
	std::string dni;
	std::string cadena;
	Fecha fecha;
	Profesor profesor;
	do {
		std::cout << "Modificar Profesor con Opciones" << std::endl;
		std::cout << "1) Ingresar modificaciones" << std::endl;
		std::cout << "2) Aplicar modificaciones" << std::endl;
		std::cout << "0) Salir." << std::endl;
		std::cin >> opcion1;
		system("cls");
		switch (opcion1)
		{
			case 1:
			{
				std::cout << "1) Ingresar DNI: " << std::endl;
				std::cout << "2) Ingresar ID profesor: " << std::endl;
				std::cout << "0) Volver." << std::endl;
				std::cin >> subopcion1;
				system("cls");
				switch (subopcion1)
				{
				case 1:
				{
					std::cout << "Dni: ";
					std::cin.ignore();
					std::getline(std::cin, dni);
					nRegistro = buscarRegPorDni(dni);
				}
				break;
				case 2:
				{
					std::cout << "ID profesor: ";
					std::cin >> idProfesor;
					nRegistro = buscarRegPorID(idProfesor);
				}
				break;
				}
				if (nRegistro != -1) {
					profesor = leerProfesor(nRegistro);
					int subopcion2, subopcion3;
					system("cls");
					do {
						system("cls");
						std::cout << "Que desea cambiar?" << std::endl;
						std::cout << "1) Datos Personales" << std::endl;
						std::cout << "2) Datos de Profesor" << std::endl;
						std::cout << "0) Volver." << std::endl;
						std::cin >> subopcion2;
						system("cls");
						switch (subopcion2)
						{
							case 1:
							{
								std::cout << "1) Nombre" << std::endl;
								std::cout << "2) Apellido" << std::endl;
								std::cout << "3) Fecha de Nacimiento" << std::endl;
								std::cout << "4) Contacto" << std::endl;
								std::cout << "5) DNI" << std::endl;
								std::cout << "0) Volver" << std::endl;
								std::cin >> subopcion3;
								system("cls");
								switch (subopcion3)
								{
									case 1:
									{
										std::cin.ignore();
										std::cout << "Ingrese Nombre: ";
										std::getline(std::cin, cadena);
										profesor.setNombre(cadena);
									}
									break;
									case 2:
									{
										std::cin.ignore();
										std::cout << "Ingrese Apellido: ";
										std::getline(std::cin, cadena);
										profesor.setApellido(cadena);
									}
									break;
									case 3:
									{
										fecha.Cargar();
										profesor.setFechaNac(fecha);
									}
									break;
									case 4:
									{
										int subopcion4;
										Contacto contacto;
										std::cout << "Contacto" << std::endl;
										std::cout << "1) Calle" << std::endl;
										std::cout << "2) Numero" << std::endl;
										std::cout << "3) Localidad" << std::endl;
										std::cout << "4) Telefono" << std::endl;
										std::cout << "5) Email" << std::endl;
										std::cout << "0) Volver" << std::endl;
										std::cin >> subopcion4;
										system("cls");
										switch (subopcion4)
										{
										case 1:
										{
											std::cin.ignore();
											std::cout << "Ingrese Calle: ";
											std::getline(std::cin, cadena);
											contacto = profesor.getContacto();
											contacto.setCalle(cadena);
											profesor.setContacto(contacto);
										}
										break;
										case 2:
										{
											std::cin.ignore();
											std::cout << "Ingrese Numero: ";
											std::getline(std::cin, cadena);
											contacto = profesor.getContacto();
											contacto.setNum(cadena);
											profesor.setContacto(contacto);
										}
										break;
										case 3:
										{
											std::cin.ignore();
											std::cout << "Ingrese Localidad: ";
											std::getline(std::cin, cadena);
											contacto = profesor.getContacto();
											contacto.setLocalidad(cadena);
											profesor.setContacto(contacto);
										}
										break;
										case 4:
										{
											std::cin.ignore();
											std::cout << "Ingrese Telefono: ";
											std::getline(std::cin, cadena);
											contacto = profesor.getContacto();
											contacto.setTel(cadena);
											profesor.setContacto(contacto);
										}
										break;
										case 5:
										{
											std::cin.ignore();
											std::cout << "Ingrese Email: ";
											std::getline(std::cin, cadena);
											contacto = profesor.getContacto();
											contacto.setEmail(cadena);
											profesor.setContacto(contacto);
										}
										break;
										default:
											break;
										}
									}
									break;
									case 5:
									{
										std::cin.ignore();
										std::cout << "Ingrese DNI: ";
										std::getline(std::cin, cadena);
										profesor.setDni(cadena);
									}
									break;
								}
							}
							break;
							case 2:
							{
								std::cout << "1) Disciplina" << std::endl;
								std::cout << "2) Turno" << std::endl;
								std::cout << "3) Sueldo" << std::endl;
								std::cout << "4) Fecha Ingreso" << std::endl;
								std::cout << "5) Fecha Egreso" << std::endl;
								std::cout << "0) Volver" << std::endl;
								std::cin >> subopcion3;
								system("cls");
								switch (subopcion3)
								{
									case 1:
									{
										ArchivoDisciplina arDis;
										std::cout << "Nombre de Disciplina: ";
										std::cin.ignore();
										std::getline(std::cin, cadena);
										while (arDis.buscarRegPorNombre(cadena) == -1) {
											std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
											std::getline(std::cin, cadena);
										}
										profesor.setIdDisciplina(arDis.buscarRegPorNombre(cadena) + 1);
									}
									break;
									case 2:
									{
										std::cout << "Turno: ";
										std::cin.ignore();
										std::getline(std::cin, cadena);
										profesor.setTurno(cadena);
									}
									break;
									case 3:
									{
										float sueldo;
										std::cout << "Sueldo: ";
										std::cin >> sueldo;
										profesor.setSueldo(sueldo);
									}
									break;
									case 4:
									{
										std::cout << "Ingrese Fecha de Ingreso: ";
										fecha.Cargar();
										profesor.setFechaIngreso(fecha);
									}
									break;
									case 5:
									{
										std::cout << "Ingrese Fecha de Egreso: ";
										fecha.Cargar();
										profesor.setFechaIngreso(fecha);
									}
									break;
								}
							}
							break;
						}
					} while (subopcion2 != 0);
				}
				else
				{
					std::cout << "No existe el registro." << std::endl;
					system("pause>nul");
				}
			}
			break;
			case 2:
			{
				if (nRegistro != -1) {
					if (modificarProfesor(profesor, nRegistro)) std::cout << "Socio " << profesor.getId() << " modificado correctamente." << std::endl;
					else std::cout << "No se pudo modificar socio " << profesor.getId() << "." << std::endl;
					system("pause>nul");
				}
			}
			break;
		}
		system("cls");
	} while (opcion1 != 0);
}

int ArchivoProfesor::getCantidad()
{
	int cant = 0;
	FILE* p = fopen("profesores.dat", "rb");
	if (p == nullptr) return cant;
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
	int nRegistro = buscarRegPorDni(dni);
	if (nRegistro != -1) {
		Profesor profesor = leerProfesor(nRegistro);
		profesor.MostrarProfesor();
	}
	else {
		std::cout << "No se encontro el DNI ingresado." << std::endl;
	}
	
}

//CONSULTA POR ID
int ArchivoProfesor::buscarRegPorID(int id)
{
	int cant = getCantidad();
	Profesor profesor;
	for (int x = 0;x < cant;x++) {
		profesor = leerProfesor(x);
		if (profesor.getId()==id) return x;
	}
	return -1;
}

//CONSULTA POR DISCIPLINA
void ArchivoProfesor::profePorDisciplina()
{
	std::string cadena;
	ArchivoDisciplina arDis;
	std::cin.ignore();
	std::cout << "Ingrese nombre de disciplina a evaluar: ";
	std::getline(std::cin, cadena);
	while (arDis.buscarRegPorNombre(cadena) == -1) {
		std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
		std::getline(std::cin, cadena);
	}
	system("cls");
	Disciplina disciplina = arDis.leerDisciplina(arDis.buscarRegPorNombre(cadena));
	ArchivoClaseAsignada arCla;
	int cantRegistrosClaseAsignada = arCla.getCantidad();
	int cantRegProfesores = getCantidad();
	if (cantRegistrosClaseAsignada > 0 && cantRegProfesores > 0) {
		ClaseAsignada* vClaseAsignada = new ClaseAsignada[cantRegistrosClaseAsignada];
		if (vClaseAsignada == nullptr) {
			std::cout << "No se pudo abrir el archivo de registros." << std::endl;
			return;
		}
		bool* vIdDisciplina = new bool[cantRegProfesores] {};
		if (vIdDisciplina == nullptr) return;
		arCla.leerTodos(vClaseAsignada, cantRegistrosClaseAsignada);
		Profesor profesor;
		bool hay = false;
		std::cout << "Profesores de " << disciplina.getNombre() << std::endl;
		for (int x = 0;x < cantRegistrosClaseAsignada;x++) {
			if (!vIdDisciplina[vClaseAsignada[x].getIdProfesor()-1] && vClaseAsignada[x].getCodDisciplina() == disciplina.getCodigo()) {
				hay = true;
				vIdDisciplina[vClaseAsignada[x].getIdProfesor() - 1] = true;
				profesor = leerProfesor(buscarRegPorID(vClaseAsignada[x].getIdProfesor()));
				std::cout << profesor.MostrarPersonaFormatoComas() << std::endl;
			}
		}
		if (!hay) std::cout << "No hay profesores registrados en esa disciplina." << std::endl;
		delete[] vClaseAsignada;
		delete[] vIdDisciplina;
	}
	else
	{
		std::cout << "No hay registros en el Archivo o algo malio sal." << std::endl;
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
void ArchivoProfesor::profePorTurno()
{
	std::string cadena;
	std::cout << "Ingrese Turno: ";
	std::cin.ignore();
	std::getline(std::cin, cadena);
	system("cls");
	int cantRegProfes = getCantidad();
	if (cantRegProfes > 0) {
		Profesor* vProfes = new Profesor[cantRegProfes];
		bool hay=false;
		if (vProfes == nullptr) {
			std::cout << "No se pudo abrir el archivo de registros." << std::endl;
			return;
		}
		leerTodos(vProfes, cantRegProfes);
		std::cout << "Profesores de turno " << cadena <<":"<< std::endl;
		for (int x = 0;x < cantRegProfes;x++) {
			if (vProfes[x].getTurno() == cadena) {
				hay = true;
				std::cout << vProfes[x].MostrarPersonaFormatoComas() << std::endl;
			}
		}
		if (!hay) std::cout << "No hay profesores de turno " << cadena << std::endl;
		delete[] vProfes;
	}
	else {
		std::cout << "No hay registros en el archivo de profores."<<std::endl;
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
	Cargar cargar;
	std::cin.ignore();

	std::cout << "Ingrese dni a dar de baja (8 digitos): ";
	std::getline(std::cin, dni);

	while (!cargar.validarDigitosDni(dni)) {
		std::cout << "Numero de digitos incorrectos. Ingrese nuevamente: ";
		std::getline(std::cin, dni);
	}
	while (buscarRegPorDni(dni) == -1) {
		std::cout << "No existe socio con DNI " << dni << " ingrese nuevamente: ";
		std::getline(std::cin, dni);
		while (!cargar.validarDigitosDni(dni)) {
			std::cout << "Numero de digitos incorrectos. Ingrese nuevamente: ";
			std::getline(std::cin, dni);
		}
	}
	if (bajaLogica(buscarRegPorDni(dni))) std::cout << "Baja de " << dni << " realizada exitosamente." << std::endl;
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

void ArchivoProfesor::profesorAltasAnuales()
{
	int anio;
	
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

void ArchivoProfesor::profesorBajasAnuales()
{
	int anio;
	
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

	std::cout << "El total de bajas del anio " << anio << " es de : " << cantBajas << std::endl;
}

void ArchivoProfesor::profesorSueldoAnual()
{
	int idP;
	float sueldoAnual = 0;
	
	std::cout << "Ingrese el codigo de profesor: " << std::endl;
	std::cin >> idP;
	int nRegistro = buscarRegPorID(idP);
	if (nRegistro != -1) {
		Profesor profesor = leerProfesor(nRegistro);
		sueldoAnual = profesor.getSueldo() * 12;
		std::cout << "El sueldo anual de profesor/a " << profesor.getNombre() << "(ID " << profesor.getId() << ")" << " es de : " << setPrecision(sueldoAnual,10) << std::endl;
	}
	else {
		std::cout << "No existe profesor con ese ID" << std::endl;
	}
}

//LISTADO
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
	//mostrarVector(profesores, cantidad);

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

	std::cout << "Ingrese 1 para los Profesores Activos, 0 para Inactivos : " << std::endl;
	std::cin >> estado;

	if(estado == 1) flag = true;

	mostrarVectorPorEstado(profesores, cantidad, flag);
	delete[] profesores;
}

void ArchivoProfesor::mostrarProfesoresPorTurno() {

	std::string turno;
	std::cout << "Ingrese Turno: ";
	std::cin.ignore();
	std::getline(std::cin, turno);

	int cantidad = getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	mostrarProfesorPorTurno(profesores, cantidad, turno);
	delete[] profesores;
}

//Otras funciones
int ArchivoProfesor::ultimoProfesor()
{
	int cantidad = getCantidad();
	return cantidad;
}
