#include <iostream>
using namespace std;
/*
#include "Persona.h"
#include "Socio.h"
#include "ArchivoSocios.h"
#include "Profesor.h"
#include "ArchivoProfesor.h"
#include "Disciplina.h"
#include "ArchivoDisciplina.h"
#include "Membresia.h"
#include "ArchivoMembresia.h"
#include "Salon.h"
#include "ArchivoSalon.h"
#include "Rol.h"
#include "ArchivoRol.h"
*/
#include "menu.h"


int main() {
    //MENU
    /*char opcion;

    do {
        menu();
        std::cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case '1':
            submenuSocio();
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

    } while (opcion != '6');*/

    ArchivoClaseAsignada arCla;
    //arCla.guardarClaseAsignada();
    int cantidad = arCla.getCantidad();
    ClaseAsignada* v = new ClaseAsignada[cantidad];
    arCla.leerTodos(v, cantidad);
    for (int x = 0;x < cantidad;x++) {
        v[x].mostrar();
        cout << endl;
    }

  return 0;
}