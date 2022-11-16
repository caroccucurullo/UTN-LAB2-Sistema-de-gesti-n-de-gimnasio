#include "ArchivoSocios.h"

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
    if (p == nullptr) return false;
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

