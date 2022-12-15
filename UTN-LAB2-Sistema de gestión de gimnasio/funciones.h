#include "ArchivoSocios.h"
#include "ArchivoProfesor.h"
#include "ArchivoDisciplina.h"
#include "ArchivoSalon.h"

void completarVectorSocios(Socio* socios, int cantidad);
void ordenarPorNombreDescendiente(Socio* socios, int cantidad);
void ordenarPorEdadDescendiente(Socio* socios, int cantidad);
void mostrarVectorSocios(Socio* socios, int cantidad);

void completarVector(Profesor* profesor, int cantidad);
void ordenarVectorPorApellido(Profesor* profesor, int cantidad);
void ordenarVectorPorDisciplina(Profesor* profesor, int cantidad);
void mostrarVector(Profesor* profesor, int cantidad);
void ordenarVectorPorSueldo(Profesor* profesor, int cantidad);
void mostrarVectorPorEstado(Profesor* profesor, int cantidad, bool estado);
void mostrarProfesorPorTurno(Profesor* profesor, int cantidad, std::string turno);
void mostrarDisciplinaPorSalon(int cantDisciplina, int cantSalon);
void mostrarVectorDisciplina(Disciplina* disciplina,int cantDisciplina, ClaseAsignada* clase, int cantidadClase);
int cantidadClaseAsignadaPorFecha(ClaseAsignada* clase, int cantidadClase, Fecha& fecha);
void copiarClaseAsignadaPorFecha(ClaseAsignada* clase, ClaseAsignada* vClase,  int cantidadClase, Fecha& fecha);

///OTRAS FUNCIONES
std::string setPrecision(float p, int precision);
