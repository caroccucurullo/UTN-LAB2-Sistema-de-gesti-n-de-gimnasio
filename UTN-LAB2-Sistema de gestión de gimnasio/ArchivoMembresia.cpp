#include "ArchivoMembresia.h"

bool ArchivoMembresia::guardarMembresia(Membresia& membresia)
{
    FILE* p = fopen("membresias.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&membresia, sizeof(Membresia), 1, p);
    fclose(p);
    return ok;
}

Membresia ArchivoMembresia::leerMembresia(int nRegistro)
{
    Membresia membresia;
    FILE* p = fopen("membresias.dat", "rb");
    if (p == nullptr) return membresia;
    fseek(p, nRegistro * sizeof(Membresia), 0);
    bool leyo = fread(&membresia, sizeof(Membresia), 1, p);
    fclose(p);
    return membresia;
}

bool ArchivoMembresia::leerTodas(Membresia* membresia, int cantidad)
{
    FILE* p = fopen("membresias.dat", "rb");
    if (p == nullptr) return false;
    bool leyo = fread(membresia, sizeof(Membresia), cantidad, p);
    fclose(p);
    return leyo;
}

bool ArchivoMembresia::modificarMembresia(Membresia& membresia, int nRegistro)
{
    FILE* p = fopen("membresias.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Membresia), SEEK_SET);
    bool ok = fwrite(&membresia, sizeof(Membresia), 1, p);
    fclose(p);
    return ok;
}

int ArchivoMembresia::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("membresias.dat", "rb");
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(Membresia);
    fclose(p);
    return cant;
}

int ArchivoMembresia::buscarRegPorNombre(std::string nombre)
{
    int cant = getCantidad();
    Membresia membresia;
    for (int x = 0;x < cant;x++) {
        membresia = leerMembresia(x);
        if (membresia.getNombre() == nombre) return x;
    }
    return -1;
}

bool ArchivoMembresia::bajaLogica(int nRegistro)
{
    Membresia membresia;
    membresia = leerMembresia(nRegistro);
    bool flag;
    FILE* p = fopen("membresias.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Membresia), 0);
    membresia.setEstado(false);
    flag = fwrite(&membresia, sizeof(Membresia), 1, p);
    fclose(p);
    return flag;
}

bool ArchivoMembresia::altaLogica(int nRegistro)
{
    Membresia membresia;
    membresia = leerMembresia(nRegistro);
    bool flag;
    FILE* p = fopen("membresias.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Membresia), 0);
    membresia.setEstado(true);
    flag = fwrite(&membresia, sizeof(Membresia), 1, p);
    fclose(p);
    return flag;
}
