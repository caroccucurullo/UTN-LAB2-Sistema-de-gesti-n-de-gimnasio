#include "Disciplina.h"

Disciplina::Disciplina(int c, int hi, int hf, const char* n, int id, int s) {
    codigo = c;
    horarioInicio = hi;
    horarioFin = hf;
    strcpy(nombre, n);
    idProfesor = id;
    salon = s;
}

void Disciplina::MostrarDisciplina() {
    std::cout << "Codigo: " << codigo << std::endl;
    std::cout << "Horario inicio: " << horarioInicio << std::endl;
    std::cout << "Horario fin: " << horarioFin << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Id profesor: " << idProfesor << std::endl;
    std::cout << "Salon: " << salon << std::endl;
}
