#include "menu.h"


void menu()
{
	std::cout << "MENU PRINCIPAL" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "1 .- ALUMNO" << std::endl;
	std::cout << "2 .- PROFESOR" << std::endl;
	std::cout << "3 .- ADMINISTRACION" << std::endl;
	std::cout << "4 .- DISCIPLINAS" << std::endl;
	std::cout << "5 .- SALON" << std::endl;
	std::cout << "6 .- SALIR" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Ingrese una opcion: ";
}

void submenuAlumno()
{
	char opcion;

	do {
		std::cout << "ALUMNO" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO ALUMNO" << std::endl;
		std::cout << "2 .- DAR DE BAJA ALUMNO" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE ALUMNO" << std::endl;
		std::cout << "4 .- MOSTRAR ALUMNOS POR FILTRO" << std::endl;
		std::cout << "5 .- Volver al menu principal" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
			std::cout << "\n\nINGRESAR NUEVO ALUMNO" << std::endl;
			break;

		case '2':
			std::cout << "\n\nDAR DE BAJA ALUMNO" << std::endl;
			break;

		case '3':
			std::cout << "\n\nMODIFICAR DATOS DE ALUMNO" << std::endl;
			break;

		case '4':
			std::cout << "\n\nMOSTRAR ALUMNOS POR FILTRO" << std::endl;
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

void submenuProfesor()
{
	char opcion;

	do {
		std::cout << "PROFESOR" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO PROFESOR" << std::endl;
		std::cout << "2 .- DAR DE BAJA PROFESOR" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE PROFESOR" << std::endl;
		std::cout << "4 .- MOSTRAR PROFESORES POR FILTRO" << std::endl;
		std::cout << "5 .- Volver al menu principal" << std::endl;
		std::cout << "-----------------------" << std::endl;
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
		std::cout << "ADMINISTRACION" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO EMPLEADO" << std::endl;
		std::cout << "2 .- DAR DE BAJA EMPLEADO" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE EMPLEADO" << std::endl;
		std::cout << "4 .- MOSTRAR EMPLEADOS POR FILTRO" << std::endl;
		std::cout << "5 .- Volver al menu principal" << std::endl;
		std::cout << "-----------------------" << std::endl;
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
		std::cout << "DISCIPLINAS" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVA DISCIPLINA" << std::endl;
		std::cout << "2 .- DAR DE BAJA UNA DISCIPLINA" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE UNA DISCIPLINA" << std::endl;
		std::cout << "4 .- MOSTRAR DISCIPLINAS POR FILTRO" << std::endl;
		std::cout << "5 .- Volver al menu principal" << std::endl;
		std::cout << "-----------------------" << std::endl;
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
		std::cout << "SALON" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "1 .- INGRESAR NUEVO SALON" << std::endl;
		std::cout << "2 .- DAR DE BAJA SALON" << std::endl;
		std::cout << "3 .- MODIFICAR DATOS DE SALON" << std::endl;
		std::cout << "4 .- MOSTRAR SALONES POR FILTRO" << std::endl;
		std::cout << "5 .- Volver al menu principal" << std::endl;
		std::cout << "-----------------------" << std::endl;
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
	system("cls");
}
