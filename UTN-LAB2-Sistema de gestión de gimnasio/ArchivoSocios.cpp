#include "ArchivoSocios.h"

//METODOS
bool ArchivoSocios::guardarSocio(Socio& socio)
{
    FILE* p = fopen("socios.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&socio, sizeof(Socio), 1, p);
    fclose(p);
    return ok;
}

void ArchivoSocios::guardarSocio()
{
    Socio socio;
    socio.CargarSocio();
    if (guardarSocio(socio)) std::cout << "Socio " << socio.getNroSocio() << " ingresado exitosamente." << std::endl;
    else std::cout << "Error al ingresar datos." << std::endl;
}

Socio ArchivoSocios::leerSocio(int nRegistro)
{
    Socio socio;
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) return socio;
    fseek(p, nRegistro * sizeof(Socio), 0);
    fread(&socio, sizeof(Socio), 1, p);
    fclose(p);
    return socio;
}

bool ArchivoSocios::leerTodos(Socio* socio, int cantidad)
{
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) return false;
    bool leyo=fread(socio, sizeof(Socio), cantidad, p);
    fclose(p);
    return leyo;
}

bool ArchivoSocios::modificarSocio(Socio& socio, int nRegistro)
{
    FILE* p = fopen("socios.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Socio), SEEK_SET);
    bool ok = fwrite(&socio, sizeof(Socio), 1, p);
    fclose(p);
    return ok;
}

void ArchivoSocios::modificarSocio()
{
    std::string dni;
    std::cout << "Ingrese Dni de socio a modificar: ";
    std::cin.ignore();
    std::getline(std::cin, dni);
    std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
    Socio socio;
    socio.CargarSocio();
    if (modificarSocio(socio, buscarRegPorDni(dni))) std::cout << "Modificado correctamente." << std::endl;
    else std::cout << "Error al modificar." << std::endl;
}

int ArchivoSocios::getCantidad()
{
    int cant=0;
    FILE* p = fopen("socios.dat", "rb");
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(Socio);
    fclose(p);
    return cant;
}
///CONSULTA POR DNI
int ArchivoSocios::buscarRegPorDni(std::string dni)
{
    int cant = getCantidad();
    Socio socio;
    for (int x = 0;x < cant;x++) {
        socio = leerSocio(x);
        if (socio.getDni() == dni) return x;
    }
    return -1;
}

void ArchivoSocios::consultaPorDni()
{
    std::string cadena;
    std::cout << "Ingrese DNI a consultar: ";
    std::cin.ignore();
    std::getline(std::cin, cadena);
    Socio socio=leerSocio(buscarRegPorDni(cadena));
    socio.MostrarSocio();
}


///CONSULTA POR NRO SOCIO
int ArchivoSocios::buscarRegPorNumSocio(int numSocio)
{
    int cant = getCantidad();
    Socio socio;
    for (int x = 0;x < cant;x++) {
        socio = leerSocio(x);
        if (socio.getNroSocio() == numSocio) return x;
    }
    return -1;
}
void ArchivoSocios::consultaPorNumSocio()
{
    int nroSocio;
    std::cout << "Ingrese Numero de Socio: ";
    std::cin >> nroSocio;
    Socio socio = leerSocio(buscarRegPorNumSocio(nroSocio));
    socio.MostrarSocio();
}
///CONSULTA POR EDAD
int ArchivoSocios::getCantidadEdad(int edad)
{
    int cant = getCantidad(), cantEdad=0;
    Socio socio;
    for (int x = 0;x < cant;x++) {
        socio = leerSocio(x);
        if (socio.getEdad()==edad) cantEdad++;
    }
    return cantEdad;
}

void ArchivoSocios::sociosPorEdad()
{
    int edad;
    std::cout << "Ingrese edad: ";
    std::cin >> edad;
    if (edad > 0 && edad <100) {
        int cantEdad = getCantidadEdad(edad);
        Socio* vSocio = new Socio[cantEdad];
        if (vSocio == nullptr) return;
        copiarSocio(vSocio, edad);
        mostrarSocio(vSocio, cantEdad);
        delete[] vSocio;
    }
    else std::cout << "Edad incorrecta." << std::endl;
}

void ArchivoSocios::copiarSocio(Socio* vSocio, int edad)
{
    int cant = getCantidad();
    Socio socio;
    for (int x = 0;x < cant;x++) {
        socio = leerSocio(x);
        if (socio.getEdad() == edad) vSocio[x] = socio;
    }
}

void ArchivoSocios::mostrarSocio(Socio* vSocio, int cantEdad)
{
    for (int x = 0;x < cantEdad;x++) {
        vSocio[x].MostrarSocio();
        std::cout << std::endl;
    }
}
///CONSULTA POR DISCIPLINA
int ArchivoSocios::getCantidadSocioPorDis(std::string nombre)
{
    ArchivoDisciplina arDis;
    Disciplina disciplina = arDis.leerDisciplina(arDis.buscarRegPorNombre(nombre));
    ArchivoClaseAsignada arClA;
    ClaseAsignada clA;
    int cantClA = arClA.getCantidad();
    Socio socio;
    int cantSocio = getCantidad(), cantDis=0;
    for (int x = 0;x < cantSocio;x++) {
        socio = leerSocio(x);
        for (int y = 0;y < cantClA;y++) {
            clA = arClA.leerClaseAsignada(y);
            if (socio.getNroSocio() == clA.getNroSocio() && disciplina.getCodigo()==clA.getCodDisciplina()) cantDis++;
        }
    }
    return cantDis;
}

void ArchivoSocios::sociosPorDis()
{
    std::string cadena;
    std::cout << "Ingrese Disciplina: ";
    std::getline(std::cin, cadena);
    int cantSocioporDis = getCantidadSocioPorDis(cadena);
    Socio* vSocio = new Socio[cantSocioporDis];
    if (vSocio == nullptr) return;
    copiarSocioDis(vSocio, cadena);
    mostrarSocio(vSocio, cantSocioporDis);
    delete[] vSocio;
}

void ArchivoSocios::copiarSocioDis(Socio* vSocio, std::string nombre)
{
    ArchivoDisciplina arDis;
    Disciplina disciplina = arDis.leerDisciplina(arDis.buscarRegPorNombre(nombre));
    ArchivoClaseAsignada arClA;
    ClaseAsignada clA;
    int cantClA = arClA.getCantidad();
    Socio socio;
    int cantSocio = getCantidad();
    for (int x = 0;x < cantSocio;x++) {
        socio = leerSocio(x);
        for (int y = 0;y < cantClA;y++) {
            clA = arClA.leerClaseAsignada(y);
            if (socio.getNroSocio() == clA.getNroSocio() && disciplina.getCodigo() == clA.getCodDisciplina()) vSocio[x] = socio;
        }
    }
}
///CONSULTA POR MEMBRESIA
int ArchivoSocios::getCantidadSocioPorMembresia(int idMem)
{
    Socio socio;
    int cantSocio = getCantidad(), cantMem=0;
    for (int x = 0;x < cantSocio;x++) {
        socio = leerSocio(x);
        if (socio.getIdMembresia() == idMem) cantMem++;
    }
    return cantMem;
}

void ArchivoSocios::sociosPorMembresia()
{
    int idMem;
    std::cout << "Id Membresia: ";
    std::cin >> idMem;
    if (idMem > 0 && idMem < 4) {
        int cantSocioPorMem = getCantidadSocioPorMembresia(idMem);
        Socio* vSocio = new Socio[cantSocioPorMem];
        if (vSocio == nullptr) return;
        copiarSocio(vSocio, idMem);
        mostrarSocio(vSocio, cantSocioPorMem);
        delete[] vSocio;
    }
    else std::cout << "Error en ID membresia." << std::endl;
}

void ArchivoSocios::copiarSocioMembresia(Socio* vSocio, int idMem)
{
    int cantSocio = getCantidad();
    Socio socio;
    for (int x = 0;x < cantSocio;x++) {
        socio = leerSocio(x);
        if (socio.getIdMembresia() == idMem) vSocio[x] = socio;
    }
}

bool ArchivoSocios::bajaLogica(int nRegistro)
{
    Socio socio;
    Fecha fecha;
    fecha.establecerFechaHoy();
    socio = leerSocio(nRegistro);
    bool flag;
    FILE* p = fopen("socios.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Socio), 0);
    socio.setEstado(false);
    socio.setFechaEgreso(fecha);
    flag=fwrite(&socio, sizeof(Socio), 1, p);
    fclose(p);
    return flag;
}

void ArchivoSocios::bajaSocio()
{
    std::string dni;
    std::cout << "Ingrese dni a dar de baja: ";
    std::cin.ignore();
    std::getline(std::cin, dni);
    if (bajaLogica(buscarRegPorDni(dni))) std::cout << "Baja de " << dni << " realizada exitosamente." << std::endl;
    else std::cout << "Baja de " << dni << " erronea. Intente nuevamente." << std::endl;
}


bool ArchivoSocios::altaLogica(int nRegistro)
{
    Socio socio;
    socio = leerSocio(nRegistro);
    Fecha fecha;
    fecha.establecerFechaHoy();
    bool flag;
    FILE* p = fopen("socios.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Socio), 0);
    socio.setEstado(true);
    socio.setFechaIngreso(fecha);
    flag = fwrite(&socio, sizeof(Socio), 1, p);
    fclose(p);
    return flag;
}
void ArchivoSocios::altaSocio()
{
    std::string dni;
    std::cout << "Ingrese dni a dar de alta: ";
    std::cin.ignore();
    std::getline(std::cin, dni);
    if (altaLogica(buscarRegPorDni(dni))) std::cout << "Alta de " << dni << " realizada exitosamente." << std::endl;
    else std::cout << "Alta de " << dni << " erronea. Intente nuevamente." << std::endl;
}
void ArchivoSocios::ordenarPorNombre()
{
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    ordenarPorNombreDescendiente(socios, cantidad);

    mostrarVectorSocios(socios, cantidad);

    delete[] socios;
}

void ArchivoSocios::ordenarPorEdad()
{
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    ordenarPorEdadDescendiente(socios, cantidad);

    mostrarVectorSocios(socios, cantidad);

    delete[] socios;
}

void ArchivoSocios::mostrarPorEstado(){
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getEstado() == true)
        {
            socios[i].MostrarSocio();
        }
    }

    delete[] socios;
}

void ArchivoSocios::mostrarPorAptoMedico(){
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getAptoMed() == true)
        {
            socios[i].MostrarSocio();
        }
    }
    delete[] socios;
}

//INFORMES

void ArchivoSocios::sociosAltasMensuales()
{
    int anio, mes;
	
    std::cout << "Ingrese el anio: " << std::endl;
    std::cin >> anio;
    std::cout << "Ingrese el mes: " << std::endl;
    std::cin >> mes;

    int cant = getCantidad();
    Socio socio;
    int cantAltas = 0;

    for (int x = 0;x < cant;x++) {
        socio = leerSocio(x);
		if (socio.getFechaIngreso().getAnio() == anio && socio.getFechaIngreso().getMes() == mes 
            && socio.getEstado() == true){
            cantAltas++;
        }
    }
	
    std::cout << "El total de altas del mes " << mes << " del anio " << anio << "es de : " << cantAltas << std::endl;
}

void ArchivoSocios::sociosBajasMensuales()
{
    int anio, mes;
	
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout << "Ingrese el mes: " << std::endl;
	std::cin >> mes;

	int cant = getCantidad();
	Socio socio;
	int cantBajas = 0;

	for (int x = 0;x < cant;x++) {
		socio = leerSocio(x);
		if (socio.getFechaEgreso().getAnio() == anio && socio.getFechaEgreso().getMes() == mes
			&& socio.getEstado() == false) {
			cantBajas++;
		}
	}

	std::cout << "El total de bajas del mes " << mes << " del anio " << anio << "es de : " << cantBajas << std::endl;
}

void ArchivoSocios::sociosAltasAnuales()
{
    int anio;
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Socio socio;
	int cantAltas = 0;

	for (int x = 0;x < cant;x++) {
		socio = leerSocio(x);
		if (socio.getFechaIngreso().getAnio() == anio && socio.getEstado() == true) {
			cantAltas++;
		}
	}

	std::cout << "El total de altas del anio " << anio << "es de : " << cantAltas << std::endl;
}

void ArchivoSocios::sociosBajasAnuales()
{
    int anio;
	
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Socio socio;
	int cantBajas = 0;

	for (int x = 0;x < cant;x++) {
		socio = leerSocio(x);
		if (socio.getFechaEgreso().getAnio() == anio && socio.getEstado() == false) {
			cantBajas++;
		}
	}

	std::cout << "El total de bajas del anio " << anio << "es de : " << cantBajas << std::endl;
}

void ArchivoSocios::sociosActivosPorMembresia()
{
    int idM;
    std::cout << "Ingrese codigo de la membresia: " << std::endl;
	std::cin >> idM;
	
	int cant = getCantidad();
	Socio socio;
	int cantSocios = 0;

	for (int x = 0;x < cant;x++) {
		socio = leerSocio(x);
		if (socio.getIdMembresia() == idM && socio.getEstado() == true) {
			cantSocios++;
		}
	}

	std::cout << "El total de socios activos con la membresia " << idM << "es de : " << cantSocios << std::endl;
}
  
