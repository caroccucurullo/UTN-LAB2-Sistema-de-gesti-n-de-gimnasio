#include "ArchivoClaseAsignada.h"
#include "Socio.h"
#include "ArchivoSocios.h"
#include "Disciplina.h"
#include "ArchivoDisciplina.h"

bool ArchivoClaseAsignada::guardarClaseAsignada(ClaseAsignada& claseAsignada)
{
    FILE* p = fopen("claseasignada.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&claseAsignada, sizeof(ClaseAsignada), 1, p);
    fclose(p);
    return ok;
}

ClaseAsignada ArchivoClaseAsignada::leerClaseAsignada(int nRegistro)
{
    ClaseAsignada claseAsignada;
    FILE* p = fopen("claseasignada.dat", "rb");
    if (p == nullptr) return claseAsignada;
    fseek(p, nRegistro * sizeof(ClaseAsignada), 0);
    bool lejo = fread(&claseAsignada, sizeof(ClaseAsignada), 1, p);
    fclose(p);
    return claseAsignada;
}

bool ArchivoClaseAsignada::leerTodos(ClaseAsignada* claseAsignada, int cantidad)
{
    FILE* p = fopen("claseasignada.dat", "rb");
    if (p == nullptr) return false;
    bool lejo = fread(claseAsignada, sizeof(ClaseAsignada), cantidad, p);
    fclose(p);
    return lejo;
}

bool ArchivoClaseAsignada::modificarClaseAsignada(ClaseAsignada& claseAsignada, int nRegistro)
{
    FILE* p = fopen("claseasignada.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(ClaseAsignada), SEEK_SET);
    bool ok = fwrite(&claseAsignada, sizeof(ClaseAsignada), 1, p);
    fclose(p);
    return ok;
}

int ArchivoClaseAsignada::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("claseasignada.dat", "rb");
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(ClaseAsignada);
    fclose(p);
    return cant;
}

void mostrarPorDisciplina(){
    Socio socio;
    Disciplina disciplina;
    ClaseAsignada claseAsignada;
    ArchivoDisciplina archivoDisciplina;
    ArchivoClaseAsignada archivoClaseAsignada;
    ArchivoSocios archivoSocios;

    int cantClaseAsignada = archivoClaseAsignada.getCantidad();
    int cant = archivoDisciplina.getCantidad();

    for (int i = 0; i < cant; i++) {

        disciplina = archivoDisciplina.leerDisciplina(i);

        for (int j = 0; j < cantClaseAsignada; j++) {

            if(disciplina.getCodigo() == claseAsignada.getCodDisciplina()){
               
                socio = archivoSocios.leerSocio(claseAsignada.getNroSocio());
                socio.MostrarPersona();
            }
        }
    }

}