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

Socio ArchivoSocios::leerSocio(int nRegistro)
{
    Socio socio;
    FILE* p = fopen("socios.dat", "rb");
    if (p == nullptr) return socio;
    fseek(p, nRegistro * sizeof(Socio), 0);
    bool leyo = fread(&socio, sizeof(Socio), 1, p);
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

