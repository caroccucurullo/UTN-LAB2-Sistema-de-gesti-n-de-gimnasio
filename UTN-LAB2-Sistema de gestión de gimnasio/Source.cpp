#include <iostream>
using namespace std;
#include "Persona.h"
#include "Socio.h"
#include "ArchivoSocios.h"
#include "Disciplina.h"
#include "Profesor.h"
#include "Membresia.h"
#include "Salon.h"
#include "Rol.h"
#include "menu.h"


int main() {
    char opcion;
    
    do {
        menu();
        std::cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case '1':
            submenuAlumno();
            break;
        case '2':
            submenuProfesor();
            break;

        case '3':
            submenuAdministracion();
            break;

        case '4':
            submenuDisciplinas();
            break;

        case '5':
            submenuSalon();
            break;
        case '6':
            std::cout << "\n\nSALIR" << std::endl;
            break;
        default:
            std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
            break;
        }
    } while (opcion != '6');
	system("cls");
	
  return 0;
}