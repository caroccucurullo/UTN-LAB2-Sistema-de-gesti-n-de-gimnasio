#include "ArchivoSocios.h"

//METODOS
bool ArchivoSocios::guardarSocio(Socio& socio)
{
    FILE* pSocio = fopen("socios.dat", "ab");
    if (pSocio == nullptr) return false;
    bool ok = fwrite(&socio, sizeof(Socio), 1, pSocio);
    fclose(pSocio);
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
    FILE* pSocio = fopen("socios.dat", "rb");
    if (pSocio == nullptr) return socio;
    fseek(pSocio, nRegistro * sizeof(Socio), 0);
    fread(&socio, sizeof(Socio), 1, pSocio);
    fclose(pSocio);
    return socio;
}

bool ArchivoSocios::leerTodos(Socio* socio, int cantidad)
{
    FILE* pSocio = fopen("socios.dat", "rb");
    if (pSocio == nullptr) return false;
    bool leyo=fread(socio, sizeof(Socio), cantidad, pSocio);
    fclose(pSocio);
    return leyo;
}

bool ArchivoSocios::modificarSocio(Socio& socio, int nRegistro)
{
    FILE* pSocio = fopen("socios.dat", "rb+");
    if (pSocio == nullptr) return false;
    fseek(pSocio, nRegistro * sizeof(Socio), SEEK_SET);
    bool ok = fwrite(&socio, sizeof(Socio), 1, pSocio);
    fclose(pSocio);
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
    FILE* pSocio = fopen("socios.dat", "rb");
    fseek(pSocio, 0, 2);
    cant = ftell(pSocio) / sizeof(Socio);
    fclose(pSocio);
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
    int nRegistro = buscarRegPorDni(cadena);
    if (nRegistro != -1) {
        Socio socio = leerSocio(nRegistro);
        socio.MostrarSocio();
    }
    else
    {
        std::cout << "No se encontro el DNI ingresado." << std::endl;
    }
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
    int nRegistro = buscarRegPorNumSocio(nroSocio);
    if (nRegistro != -1) {
        Socio socio = leerSocio(nRegistro);
        socio.MostrarSocio();
    }
    else
    {
        std::cout << "No se encontro el Numero de Socio ingresado." << std::endl;
    }
}
///CONSULTA POR EDAD
void ArchivoSocios::sociosPorEdad()
{
    int edad;
    std::cout << "Ingrese edad: ";
    std::cin >> edad;
    if (edad > 14 && edad <90) {
        int cant = getCantidad();
        if (cant > 0) {
            bool hay = false;
            Socio* listaCompleta = new Socio[cant];
            if (listaCompleta == nullptr) {
                std::cout << "No se pudo abrir el archivo de registros." << std::endl;
                return;
            }
            leerTodos(listaCompleta, cant);
            for (int x = 0;x < cant;x++) {
                if (listaCompleta[x].getEdad() == edad) {
                    hay = true;
                    std::cout << listaCompleta[x].MostrarPersonaFormatoComas() << std::endl;
                }
            }
			if(!hay) std::cout << "No hay socios de esa edad." << std::endl;
            delete[] listaCompleta;
        }
    }
    else std::cout << "Edad incorrecta." << std::endl;
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
    std::cin.ignore();
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
void ArchivoSocios::mostrarSocio(Socio* vSocio, int cantidad)
{
    for (int x = 0;x < cantidad;x++) {
        std::cout<<vSocio[x].MostrarSociosDatos()<<std::endl;
    }
}
///CONSULTA POR MEMBRESIA
void ArchivoSocios::sociosPorMembresia()
{
    int idMem;
    std::cout << "Id Membresia: ";
    std::cin >> idMem;
    if (idMem > 0 && idMem < 4) {
        int cantidadRegistros = getCantidad();
        if (cantidadRegistros > 0) {
            bool hay = false;
            Socio* vSocio = new Socio[cantidadRegistros];
            if (vSocio == nullptr) {
                std::cout << "No se pudo abrir el archivo de registros." << std::endl;
                return;
            }
            leerTodos(vSocio, cantidadRegistros);
            for (int x = 0;x < cantidadRegistros;x++) {
                if (vSocio[x].getIdMembresia() == idMem) {
                    hay = true;
                    std::cout << vSocio[x].MostrarPersonaFormatoComas() << std::endl;
                }
            }
			if(!hay) std::cout << "No hay registros en el Archivo." << std::endl;
            delete[] vSocio;
        }
    }
    else std::cout << "Error en ID membresia." << std::endl;
}

bool ArchivoSocios::bajaLogica(int nRegistro)
{
    Socio socio;
    Fecha fecha;
    fecha.establecerFechaHoy();
    socio = leerSocio(nRegistro);
    bool flag;
    FILE* pSocio = fopen("socios.dat", "rb+");
    if (pSocio == nullptr) return false;
    fseek(pSocio, nRegistro * sizeof(Socio), 0);
    socio.setEstado(false);
    socio.setFechaEgreso(fecha);
    flag=fwrite(&socio, sizeof(Socio), 1, pSocio);
    fclose(pSocio);
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
    FILE* pSocio = fopen("socios.dat", "rb+");
    if (pSocio == nullptr) return false;
    fseek(pSocio, nRegistro * sizeof(Socio), 0);
    socio.setEstado(true);
    socio.setFechaIngreso(fecha);
    flag = fwrite(&socio, sizeof(Socio), 1, pSocio);
    fclose(pSocio);
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

int ArchivoSocios::ultimoSocio()
{
    return 0;
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
  
