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
    /*ArchivoSocios arSocio;
    Socio s,s2;*/
    /*s.CargarSocio();
    cout << s.MostrarSociosDatos() << endl;*/
    /*if (arSocio.guardarSocio(s)) cout << "Guardado correctamente." << endl;
    else cout << "No guardado." << endl;*/
	
	/*s2 = arSocio.leerSocio(arSocio.buscarRegPorDni("30398741"));
    cout << s2.MostrarSociosDatos() << endl;*/
    /*arSocio.bajaLogica(arSocio.buscarRegPorDni("30398741"));
    s2 = arSocio.leerSocio(arSocio.buscarRegPorDni("30398741"));
    cout << s2.MostrarSociosDatos() << endl;*/
    /*arSocio.altaLogica(arSocio.buscarRegPorDni("30398741"));
    s2 = arSocio.leerSocio(arSocio.buscarRegPorDni("30398741"));
    cout << s2.MostrarSociosDatos() << endl;*/
	
    Profesor profe;
    profe.cargarProfesor();
    cout << endl;
	profe.MostrarProfesor();
	

    /*char opcion;
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
    } while (opcion != '6');*/
  return 0;
}