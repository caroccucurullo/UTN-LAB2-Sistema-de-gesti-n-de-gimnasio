#include "ArchivoClaseAsignada.h"

bool ArchivoClaseAsignada::cargarClaseAsignada()
{
	


	
    return false;
}

bool ArchivoClaseAsignada::guardarClaseAsignada(ClaseAsignada& claseAsignada)
{
    FILE* p = fopen("claseasignada.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&claseAsignada, sizeof(ClaseAsignada), 1, p);
    fclose(p);
    return ok;
}

void ArchivoClaseAsignada::guardarClaseAsignada()
{
    ClaseAsignada clA;
    clA.cargar();
    if (guardarClaseAsignada(clA)) std::cout << "Guardado correctamente." << std::endl;
    else std::cout << "Error al guardar." << std::endl;
    
}

ClaseAsignada ArchivoClaseAsignada::leerClaseAsignada(int nRegistro)
{
    ClaseAsignada claseAsignada;
    FILE* p = fopen("claseasignada.dat", "rb");
    if (p == nullptr) return claseAsignada;
    fseek(p, nRegistro * sizeof(ClaseAsignada), 0);
    fread(&claseAsignada, sizeof(ClaseAsignada), 1, p);
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

void ArchivoClaseAsignada::modificarClaseAsignada()
{
    int codDis, nroSocio;
    std::cout << "Ingrese datos del registro a modificar: " << std::endl;
    std::cout << "Codigo Disciplina: ";
    std::cin >> codDis;
    std::cout << "Nro Socio: ";
    std::cin >> nroSocio;
    std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
    ClaseAsignada clA;
    clA.cargar();
    if (modificarClaseAsignada(clA, buscarPorDisciplinayNroSocio(codDis, nroSocio))) std::cout << "Modificado correctamente." << std::endl;
    else std::cout << "Error al modificar." << std::endl;

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

int ArchivoClaseAsignada::buscarPorDisciplinayNroSocio(int codDisciplina, int nroSocio)
{
    ClaseAsignada clA;
    int cant = getCantidad();
    for (int x = 0;x < cant;x++) {
        clA = leerClaseAsignada(x);
        if (clA.getCodDisciplina() == codDisciplina && clA.getNroSocio() == nroSocio) return x;
    }
    return -1;
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

void ArchivoClaseAsignada::mostrarPorDisciplina(){
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