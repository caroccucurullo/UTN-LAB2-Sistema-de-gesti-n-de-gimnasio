#include <iostream>
#include "menu.h"


int main() {
    //MENU
    char opcion;

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

            case '0':
            break;

            default:
                std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
            break;
        }

    } while (opcion != '0');
	
	
  return 0;
}