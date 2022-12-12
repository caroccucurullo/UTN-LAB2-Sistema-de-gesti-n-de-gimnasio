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
    Cargar cargarSocio;
    
    do{
        cargarSocio.CargarSocio(socio);
    } while (!validarDatosSocio(socio));
    
    socio.setNroSocio(ultimoSocio()+1);
    if (guardarSocio(socio)) std::cout << "Socio " << socio.getNroSocio() << " ingresado exitosamente." << std::endl;
    else std::cout << "Error al ingresar datos." << std::endl;
}

bool ArchivoSocios::validarDatosSocio(Socio& socio)
{
    char letra;
    system("cls");
    socio.MostrarSocio();
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
    /*else if (letra == 'y' || letra == 'Y') {
        system("cls");
        return true;
    }*/
    return true;
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
    socio.CargarSocioRegCompleto();
    if (modificarSocio(socio, buscarRegPorDni(dni))) std::cout << "Modificado correctamente." << std::endl;
    else std::cout << "Error al modificar." << std::endl;
}

void ArchivoSocios::modificarSocioConOpciones()
{
    int opcion1, subopcion1, nroSocio, nRegistro=-1;
    std::string dni;
    std::string cadena;
    Fecha fecha;
    Socio socio;
    do {
        std::cout << "Modificar Socio con Opciones" << std::endl;
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
            std::cout << "2) Ingresar Numero de Socio: " << std::endl;
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
                std::cout << "Numero de Socio: ";
                std::cin >> nroSocio;
                nRegistro = buscarRegPorNumSocio(nroSocio);
            }
            break;
            }
            if (nRegistro != -1) {
                socio = leerSocio(nRegistro);
                int subopcion2, subopcion3;
                system("cls");
                do {
                    system("cls");
                    std::cout << "Que desea cambiar?" << std::endl;
                    std::cout << "1) Datos Personales" << std::endl;
                    std::cout << "2) Datos de Socio" << std::endl;
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
                            socio.setNombre(cadena);
                        }
                        break;
                        case 2:
                        {
                            std::cin.ignore();
                            std::cout << "Ingrese Apellido: ";
                            std::getline(std::cin, cadena);
                            socio.setApellido(cadena);
                        }
                        break;
                        case 3:
                        {
                            fecha.Cargar();
                            socio.setFechaNac(fecha);
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
                                contacto = socio.getContacto();
                                contacto.setCalle(cadena);
                                socio.setContacto(contacto);
                            }
                            break;
                            case 2:
                            {
                                std::cin.ignore();
                                std::cout << "Ingrese Numero: ";
                                std::getline(std::cin, cadena);
                                contacto = socio.getContacto();
                                contacto.setNum(cadena);
                                socio.setContacto(contacto);
                            }
                            break;
                            case 3:
                            {
                                std::cin.ignore();
                                std::cout << "Ingrese Localidad: ";
                                std::getline(std::cin, cadena);
                                contacto = socio.getContacto();
                                contacto.setLocalidad(cadena);
                                socio.setContacto(contacto);
                            }
                            break;
                            case 4:
                            {
                                std::cin.ignore();
                                std::cout << "Ingrese Telefono: ";
                                std::getline(std::cin, cadena);
                                contacto = socio.getContacto();
                                contacto.setTel(cadena);
                                socio.setContacto(contacto);
                            }
                            break;
                            case 5:
                            {
                                std::cin.ignore();
                                std::cout << "Ingrese Email: ";
                                std::getline(std::cin, cadena);
                                contacto = socio.getContacto();
                                contacto.setEmail(cadena);
                                socio.setContacto(contacto);
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
                            socio.setDni(cadena);
                        }
                        break;
                        }
                    }
                    break;
                    case 2:
                    {
                        std::cout << "1) Apto Medico" << std::endl;
                        std::cout << "2) Membresia" << std::endl;
                        std::cout << "3) Fecha Ingreso" << std::endl;
                        std::cout << "4) Fecha Egreso" << std::endl;
                        std::cout << "0) Volver" << std::endl;
                        std::cin >> subopcion3;
                        system("cls");
                        switch (subopcion3)
                        {
                        case 1:
                        {
                            char letra;
                            std::cout << "Apto Medico (y/n): ";
                            std::cin >> letra;
                            while (letra != 'y' && letra != 'n' && letra != 'Y' && letra != 'N')
                            {
                                std::cout << "Letra incorrecta. Escriba 'y' o 'n': ";
                                std::cin >> letra;

                            }
                            if (letra == 'y' || letra != 'Y') socio.setAptoMed(true);
                            else if (letra == 'n' || letra != 'N') socio.setAptoMed(false);
                            /*std::cout << "Apto Medico (y/n): ";
                            std::cin >> letra;
                            if (letra == 'y') socio.setAptoMed(true);
                            else socio.setAptoMed(false);*/
                        }
                        break;
                        case 2:
                        {
                            ArchivoMembresia arMem;
                            std::cout << "Nombre Membresia: ";
                            std::cin.ignore();
                            std::getline(std::cin, cadena);

                            while (arMem.buscarRegPorNombre(cadena) == -1) {
                                std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
                                std::getline(std::cin, cadena);
                            }
                            socio.setIdMembresia(arMem.buscarRegPorNombre(cadena) + 1);
                            /*int mem;
                            std::cout << "Ingrese membresia: ";
                            std::cin >> mem;
                            socio.setIdMembresia(mem);*/
                        }
                        break;
                        case 3:
                            std::cout << "Ingrese Fecha de Ingreso: ";
                            fecha.Cargar();
                            socio.setFechaIngreso(fecha);
                            break;
                        case 4:
                            std::cout << "Ingrese Fecha de Egreso: ";
                            fecha.Cargar();
                            socio.setFechaIngreso(fecha);
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
                if (modificarSocio(socio, nRegistro)) std::cout << "Socio " << socio.getNroSocio() << " modificado correctamente." << std::endl;
                else std::cout << "No se pudo modificar socio " << socio.getNroSocio() << "." << std::endl;
                system("pause>nul");
            }
        }
            break;
        }
        system("cls");
    } while (opcion1 != 0);
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
void ArchivoSocios::sociosPorDisciplina()
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
    int CantRegistrosClaseAsignada = arCla.getCantidad();
    if (CantRegistrosClaseAsignada > 0) {
        ClaseAsignada* vClaseAsignada = new ClaseAsignada[CantRegistrosClaseAsignada];
        if (vClaseAsignada == nullptr) {
            std::cout << "No se pudo abrir el archivo de registros." << std::endl;
            return;
        }
        arCla.leerTodos(vClaseAsignada, CantRegistrosClaseAsignada);
        Socio socio;
        bool hay = false;
        std::cout<<"Miembros de "<<disciplina.getNombre() << std::endl;
        for (int x = 0;x < CantRegistrosClaseAsignada;x++) {
            if (vClaseAsignada[x].getCodDisciplina() == disciplina.getCodigo()) {
                hay = true;
                socio = leerSocio(buscarRegPorNumSocio(vClaseAsignada[x].getNroSocio()));
                std::cout << socio.MostrarPersonaFormatoComas() <<std::endl;
            }
        }
        if (!hay) std::cout << "No hay socios registrados en esa disciplina." << std::endl;
    }
    else
    {
        std::cout << "No hay registros en el Archivo o algo malio sal." << std::endl;
    }
}


///CONSULTA POR MEMBRESIA
void ArchivoSocios::sociosPorMembresia()
{
    ArchivoMembresia arMem;
    Membresia mem;
    std::string cadena;
    std::cin.ignore();
    std::cout << "Nombre de Membresia: ";
    std::getline(std::cin, cadena);
    while (arMem.buscarRegPorNombre(cadena) == -1) {
        std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
        std::getline(std::cin, cadena);
    }
    system("cls");
    mem = arMem.leerMembresia(arMem.buscarRegPorNombre(cadena));
    int cantidadRegistros = getCantidad();
    if (cantidadRegistros > 0) {
        bool hay = false;
        Socio* vSocio = new Socio[cantidadRegistros];
        if (vSocio == nullptr) {
            std::cout << "No se pudo abrir el archivo de registros." << std::endl;
            return;
        }
        leerTodos(vSocio, cantidadRegistros);
        std::cout << "Miembros " << mem.getNombre() << std::endl;
        for (int x = 0;x < cantidadRegistros;x++) {
            if (vSocio[x].getIdMembresia() == mem.getId()) {
                hay = true;
                std::cout << vSocio[x].MostrarPersonaFormatoComas() << std::endl;
            }
        }
        if (!hay) std::cout << "No hay registros en el Archivo." << std::endl;
        delete[] vSocio;
    }
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
    std::cin.ignore();

    std::cout << "Ingrese dni a dar de baja (8 digitos): ";
    std::getline(std::cin, dni);

    while (!validarDigitosDni(dni)) {
        std::cout << "Numero de digitos incorrectos. Ingrese nuevamente: ";
        std::getline(std::cin, dni);
    }
    while (buscarRegPorDni(dni) == -1) {
        std::cout << "No existe socio con DNI " << dni << " ingrese nuevamente: ";
        std::getline(std::cin, dni);
        while (!validarDigitosDni(dni)) {
            std::cout << "Numero de digitos incorrectos. Ingrese nuevamente: ";
            std::getline(std::cin, dni);
        }
    }
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

void ArchivoSocios::mostrarPorEstadoActivo(){
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];
    bool hay = false;

    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getEstado() == true)
        {
            hay = true;
            socios[i].MostrarSocio();
            std::cout << std::endl;
        }
    }
	if (!hay) std::cout << "No hay socios activos." << std::endl;

    delete[] socios;
}

void ArchivoSocios::mostrarPorEstadoInactivo()
{
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];
    bool hay = false;
    
    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getEstado() == false)
        {
            hay = true;
            socios[i].MostrarSocio();
            std::cout << std::endl;
        }
    }
	if (!hay) std::cout << "No hay socios inactivos." << std::endl;

    delete[] socios;
}

void ArchivoSocios::mostrarPorAptoMedico(){
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];
    bool hay = false;
    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getAptoMed() == true)
        {
            hay = true;
            socios[i].MostrarSocio();
            std::cout << std::endl;
        }
    }
    if (!hay) std::cout << "No hay socios con apto medico." << std::endl;
    delete[] socios;
}

void ArchivoSocios::mostrarPorAptoMedicoNo()
{
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];
    bool hay = false;
    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getAptoMed() == false)
        {
            hay = true;
            socios[i].MostrarSocio();
            std::cout << std::endl;
        }
    }
    if (!hay) std::cout << "No hay socios sin apto medico." << std::endl;
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

//Otras Funciones
int ArchivoSocios::ultimoSocio()
{
    int cantidad = getCantidad();
    return cantidad;
}

bool ArchivoSocios::validarDigitosDni(std::string cadena)
{
    if (cadena.length() == 8) return true;
    else return false;
}
