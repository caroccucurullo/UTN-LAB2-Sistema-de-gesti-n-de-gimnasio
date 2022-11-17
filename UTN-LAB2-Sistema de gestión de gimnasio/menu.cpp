#include "menu.h"

void menu()
{
	std::cout << "---------------------------------" << std::endl;
	std::cout << "MENU PRINCIPAL" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "1 .- SOCIO" << std::endl;
	std::cout << "2 .- PROFESOR" << std::endl;
	std::cout << "3 .- ADMINISTRACION" << std::endl;
	std::cout << "4 .- DISCIPLINAS" << std::endl;
	std::cout << "5 .- SALON" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "6 .- SALIR" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Ingrese una opcion: ";

}

void submenuSocio()
{
	char opcion;

	do {
		std::cout << "---------------------------------" << std::endl;
		std::cout << "SOCIO" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO SOCIO" << std::endl;
		std::cout << "2 .- DAR DE BAJA SOCIO" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE SOCIO" << std::endl;
		std::cout << "4 .- PAGO MEMBRESIA" << std::endl;
		std::cout << "5 .- MOSTRAR SOCIO LISTA" << std::endl;
		std::cout << "6 .- MOSTRAR SOCIO CONSULTA" << std::endl;
		std::cout << "7 .- MOSTRAR SOCIO INFORMES" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "8 .- Volver al menu principal" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";


		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1': {
					Socio socio;
					ArchivoSocios archivosSocio;
					socio.CargarSocio();
					archivosSocio.guardarSocio(socio);
		}
			break;

		case '2': {
			std::string dni;
			std::cout << "Ingrese el DNI del socio a dar de baja: ";
			std::cin.ignore();
			std::getline(std::cin, dni);
			
			ArchivoSocios archivosSocio;
			archivosSocio.bajaLogica(archivosSocio.buscarRegPorDni(dni));
			if (archivosSocio.bajaLogica(archivosSocio.buscarRegPorDni(dni))) {
				std::cout << "Se relizo la baja del socio correctamente" << std::endl;
				
			}
			else {
				std::cout << "No se pudo realizar la baja del socio" << std::endl;
			}
			

		}
			
			break;

		case '3': {
	
		}
			
			break;

		case '4':
			std::cout << "\n\nMOSTRAR ALUMNOS LISTA" << std::endl;
			break;

		case '5':
			std::cout << "\n\nMOSTRAR ALUMNOS CONSULTA" << std::endl;
			break;
			
		case '6':
			
			break;
			
		case '7':
			submenuMostrarSociosInforme();
			break;

		case '8':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '8');
	system("cls");
}

void submenuProfesor()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "PROFESOR" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO PROFESOR" << std::endl;
		std::cout << "2 .- DAR DE BAJA PROFESOR" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE PROFESOR" << std::endl;
		std::cout << "4 .- MOSTRAR PROFESORES LISTA" << std::endl;
		std::cout << "5 .- MOSTRAR PROFESORES CONSULTA" << std::endl;
		std::cout << "6 .- MOSTRAR PROFESORES INFORMES" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "7 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			std::cout << "\n\nINGRESAR NUEVO PROFESOR" << std::endl;
			break;

		case '2':
			std::cout << "\n\nDAR DE BAJA PROFESOR" << std::endl;
			break;

		case '3':
			std::cout << "\n\nMODIFICAR DATOS DE PROFESOR" << std::endl;
			break;

		case '4':
			std::cout << "\n\nMOSTRAR PROFESORES POR FILTRO" << std::endl;
			break;

		case '5':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '5');
	system("cls");


}

void submenuAdministracion()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "ADMINISTRACION" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO EMPLEADO" << std::endl;
		std::cout << "2 .- DAR DE BAJA EMPLEADO" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE EMPLEADO" << std::endl;
		std::cout << "4 .- MOSTRAR EMPLEADOS LISTA" << std::endl;
		std::cout << "5 .- MOSTRAR EMPLEADOS CONSULTA" << std::endl;
		std::cout << "6 .- MOSTRAR EMPLEADOS INFORMES" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "7 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			std::cout << "\n\nINGRESAR NUEVO EMPLEADO" << std::endl;
			break;

		case '2':
			std::cout << "\n\nDAR DE BAJA EMPLEADO" << std::endl;
			break;

		case '3':
			std::cout << "\n\nMODIFICAR DATOS DE EMPLEADO" << std::endl;
			break;

		case '4':
			std::cout << "\n\nMOSTRAR EMPLEADOS POR FILTRO" << std::endl;
			break;

		case '5':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '5');
	system("cls");
}

void submenuDisciplinas()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "DISCIPLINAS" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVA DISCIPLINA" << std::endl;
		std::cout << "2 .- DAR DE BAJA UNA DISCIPLINA" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE UNA DISCIPLINA" << std::endl;
		std::cout << "4 .- MOSTRAR DISCIPLINAS LISTA" << std::endl;
		std::cout << "5 .- MOSTRAR DISCIPLINAS CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "6 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			std::cout << "\n\nINGRESAR NUEVA DISCIPLINA" << std::endl;
			break;

		case '2':
			std::cout << "\n\nDAR DE BAJA UNA DISCIPLINA" << std::endl;
			break;

		case '3':
			std::cout << "\n\nMODIFICAR DATOS DE UNA DISCIPLINA" << std::endl;
			break;

		case '4':
			std::cout << "\n\nMOSTRAR DISCIPLINAS POR FILTRO" << std::endl;
			break;

		case '5':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '5');
	system("cls");
}

void submenuSalon()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "SALON" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO SALON" << std::endl;
		std::cout << "2 .- DAR DE BAJA SALON" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE SALON" << std::endl;
		std::cout << "4 .- MOSTRAR SALONES LISTA" << std::endl;
		std::cout << "5 .- MOSTRAR SALONES CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "6 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			std::cout << "\n\nINGRESAR NUEVO SALON" << std::endl;
			break;

		case '2':
			std::cout << "\n\nDAR DE BAJA SALON" << std::endl;
			break;

		case '3':
			std::cout << "\n\nMODIFICAR DATOS DE SALON" << std::endl;
			break;

		case '4':
			std::cout << "\n\nMOSTRAR SALONES POR FILTRO" << std::endl;
			break;

		case '5':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '5');
}

void submenuPagoMembresia()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "PAGO DE MEMBRESIA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- CARGAR PAGO" << std::endl;
		std::cout << "2 .- CONSULTAR PAGO" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE PAGO" << std::endl;
		std::cout << "4 .- MOSTRAR PAGO DE MEMBRESIA LISTA" << std::endl;
		std::cout << "5 .- MOSTRAR PAGO DE MEMBRESIA CONSULTA" << std::endl;
		std::cout << "6 .- MOSTRAR PAGO DE MEMBRESIA INFORMES" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "7 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			
			break;

		case '2':
			
			break;

		case '3':
			
			break;

		case '4':
			
			break;
		case '5':

			break;

		case '6':

			break;
			
		case '7':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '7');
}

void submenuMostrarSociosLista()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR SOCIOS LISTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- " << std::endl;
		std::cout << "2 .-" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "3 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			std::cout << "\n\nMOSTRAR TODOS LOS SOCIOS" << std::endl;
			break;

		case '2':
			std::cout << "\n\nMOSTRAR SOCIOS POR FILTRO" << std::endl;
			break;

		case '3':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '3');
	
}

void submenuMostrarSociosConsulta()
{
	char opcion;
	
	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR SOCIOS CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- CONSULTA POR DNI" << std::endl;
		std::cout << "2 .- CONSULTA POR NUMERO DE SOCIO" << std::endl;
		std::cout << "3 .- CONSULTA POR EDAD" << std::endl;
		std::cout << "4 .- CONSULTA POR DISCIPLINA" << std::endl;
		std::cout << "5 .- CONSULTA POR MEMBRESIA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "6 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";
		
		std::cin >> opcion;
		system("cls");
		
		switch (opcion)
		{
		case '1':
			
			break;

		case '2':
			
			break;

		case '3':
			break;

		case '4':
			break;
		
		case '5':
			break;

		case '6':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '6');
}

void submenuMostrarSociosInforme()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR SOCIOS INFORME" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ALTAS MENSUALES" << std::endl;
		std::cout << "2 .- BAJAS MENSUALES" << std::endl;
		std::cout << "3 .- ALTAS ANUALES" << std::endl;
		std::cout << "4 .- BAJAS ANUALES" << std::endl;
		std::cout << "5 .- ACTIVOS POR MEMBRESIA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "6 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosAltasMensuales();
		}
		break;

		case '2': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosBajasMensuales();
		}
		break;

		case '3':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosAltasAnuales();
		}
		break;
			
		case '4':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosBajasAnuales();
		}
		break;

		case '5':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosActivosPorMembresia();
		}
		break;

		case '6':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

	} while (opcion != '6');
	
	
}

void submenuMostrarProfesoresLista()
{
	
}

void submenuMostrarProfesoresConsulta()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR PROFESORES CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- CONSULTA POR DNI" << std::endl;
		std::cout << "2 .- CONSULTA POR DISCIPLINA" << std::endl;
		std::cout << "3 .- CONSULTA POR HORARIO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "4 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':

			break;

		case '2':

			break;

		case '3':
			break;

		case '4':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '4');
	
	

}

void submenuMostrarProfesoresInforme()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR PROFESORES INFORME" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ALTAS ANUALES" << std::endl;
		std::cout << "2 .- BAJAS ANUALES" << std::endl;
		std::cout << "3 .- SUELDO ANUAL" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "4 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.profesorAltasAnuales();
		}
			break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.profesorBajasAnuales();
		}
			break;
			
		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.profesorSueldoAnual();
		}	
			break;

		case '4':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '4');
	
}

void submenuMostrarAdministracionLista()
{
	
}
void submenuMostrarAdministracionConsulta()
{
	
}
void submenuMostrarAdministracionInforme()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR ADMINISTRACION INFORME" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ALTAS ANUALES" << std::endl;
		std::cout << "2 .- BAJAS ANUALES" << std::endl;
		std::cout << "3 .- SUELDO ANUAL" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "4 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoRol archivoRol;
			archivoRol.rolAltasAnuales();
		}
		break;

		case '2':
		{
			ArchivoRol archivoRol;
			archivoRol.rolBajasAnuales();
		}
		break;

		case '3':
		{
			ArchivoRol archivoRol;
			archivoRol.rolSueldoAnual();
		}
		break;

		case '4':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '4');

}
void submenuMostrarDisciplinasLista()
{

}
void submenuMostrarDisciplinasConsulta()
{

}
void submenuMostrarSalonLista()
{

}
void submenuMostrarSalonConsulta()
{

}