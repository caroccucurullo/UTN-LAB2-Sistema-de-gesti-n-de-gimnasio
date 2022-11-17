#include "ArchivoClaseAsignada.h"

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
    bool leyo = fread(&claseAsignada, sizeof(ClaseAsignada), 1, p);
    fclose(p);
    return claseAsignada;
}

bool ArchivoClaseAsignada::leerTodos(ClaseAsignada* claseAsignada, int cantidad)
{
    FILE* p = fopen("claseasignada.dat", "rb");
    if (p == nullptr) return false;
    bool leyo = fread(claseAsignada, sizeof(ClaseAsignada), cantidad, p);
    fclose(p);
    return leyo;
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

//INFORMES

void ArchivoClaseAsignada::sociosPorDisciplinaActivos(int idD)
{
    std::cout << "Ingrese codigo de la disciplina: " << std::endl;
    std::cin >> idD;
	
	int cant = getCantidad(), cantSocios = 0;
	ClaseAsignada claseAsignada;
	
	for (int x = 0;x < cant;x++) {
		claseAsignada = leerClaseAsignada(x);
        if (claseAsignada.getCodDisciplina() == idD && claseAsignada.getEstado() == true) {
            cantSocios++;
        }
	}

	std::cout << "Cantidad de socios activos en la disciplina: " << cantSocios << std::endl;
}