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
	std::cout << "0 .- SALIR" << std::endl;
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";


		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.guardarSocio();
			system("pause>nul");
		}
		break;

		case '2': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.bajaSocio();
			system("pause>nul");
		}
		break;

		case '3': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.modificarSocioConOpciones();
			system("pause>nul");
		}
		break;

		case '4':
			submenuPagoMembresia();
			break;

		case '5':
			submenuMostrarSociosLista();
		break;
			
		case '6':
			submenuMostrarSociosConsulta();
		break;
			
		case '7':
			submenuMostrarSociosInforme();
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		//system("pause>nul");
		system("cls");
	} while (opcion != '0');
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.guardarProfesor();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.bajaProfesor();
			system("pause>nul");
		}	
		break;

		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.modificarProfesorConOpciones();
			system("pause>nul");
		}
			break;

		case '4':
			submenuMostrarProfesoresLista();
		break;
			
		case '5':
			submenuMostrarProfesoresConsulta();
		break;
		
		case '6':
			submenuMostrarProfesoresInforme();
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "4 .- MOSTRAR EMPLEADOS CONSULTA" << std::endl;
		std::cout << "5 .- MOSTRAR EMPLEADOS INFORMES" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoRol archivoRol;
			archivoRol.guardarRol();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoRol archivoRol;
			archivoRol.bajaRol();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoRol archivoRol;
			archivoRol.modificarRol();
			system("pause>nul");
		}
		break;

		case '4':
			submenuMostrarAdministracionConsulta();
		break;
			
		case '5':
			submenuMostrarAdministracionInforme();
		break;
		
		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.guardarDisciplina();
			system("pause>nul");
		}
		break;

		case '2':
		{	
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.bajaDisciplina();
			system("pause>nul");
		}	
		break;

		case '3':
		{
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.modificarDisciplina();
			system("pause>nul");
		}
		break;

		case '4':
			submenuMostrarDisciplinasLista();
		break;

		case '5':
			submenuMostrarDisciplinasConsulta();
		break;
	
		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "4 .- MOSTRAR SALONES CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoSalon archivoSalon;
			archivoSalon.guardarSalon();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoSalon archivoSalon;
			archivoSalon.bajaSalon();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoSalon archivoSalon;
			archivoSalon.modificarSalon();
			system("pause>nul");
		}
		break;

		case '4':
			submenuMostrarSalonConsulta();
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;
		
		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "4 .- MOSTRAR PAGOS DEL CORRIENTE MES" << std::endl;
		std::cout << "5 .- MOSTRAR ULTIMO PAGO DE SOCIO" << std::endl;
		std::cout << "6 .- MOSTRAR INFORMES DE RECAUDACION" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.guardarPago();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.consultarPago();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.modificarPago();
			system("pause>nul");
		}
		break;

		case '4':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.pagosDelMes();
			system("pause>nul");
		}
		break;
		
		case '5':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.consultarPago();
			system("pause>nul");
		}
		break;

		case '6':
			submenuInformesRecaudacion();
		break;
			
		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
}

void submenuMostrarSociosLista()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR SOCIOS LISTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ORDENADOS POR NOMBRE" << std::endl;
		std::cout << "2 .- ORDENADOS POR EDAD" << std::endl;
		std::cout << "3 .- ORDENADOS POR ESTADO" << std::endl;
		std::cout << "4 .- ORDENADOS POR APTO MEDICO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.ordenarPorNombre();
			system("pause>nul");
		}
		break;
		
		case '2':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.ordenarPorEdad();
			system("pause>nul");
		}
		break;
		
		case '3':
		{
			/*ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorEstado();
			system("pause>nul");*/
			subSubMenuOrdenarPorEstado();
		}
		break;
	
		case '4':
		{
			/*ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorAptoMedico();
			system("pause>nul");*/
			subSubMenuOrdenarPorAptoMedico();
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		//system("pause>nul");
		system("cls");
	} while (opcion != '0');
	
}

void subSubMenuOrdenarPorEstado()
{
	int opcion;
	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "ORDENADOS POR ESTADO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ACTIVO" << std::endl;
		std::cout << "2 .- INACTIVO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";
		std::cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
		{
			ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorEstadoActivo();
			system("pause>nul");
		}
			break;
		case 2:
		{
			ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorEstadoInactivo();
			system("pause>nul");
		}
			break;
		default:
			break;
		}
		system("cls");
	} while (opcion != 0);
}

void subSubMenuOrdenarPorAptoMedico()
{
	int opcion;
	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "ORDENADOS POR APTO MEDICO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ACTIVO" << std::endl;
		std::cout << "2 .- INACTIVO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";
		std::cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
		{
			ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorAptoMedico();
			system("pause>nul");
		}
		break;
		case 2:
		{
			ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorAptoMedicoNo();
			system("pause>nul");
		}
		break;
		default:
			break;
		}
		system("cls");
	} while (opcion != 0);
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";
		
		std::cin >> opcion;
		system("cls");
		
		switch (opcion)
		{
		case '1':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.consultaPorDni();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.consultaPorNumSocio();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosPorEdad();
			system("pause>nul");
		}
		break;

		case '4':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosPorDisciplina();
			system("pause>nul");
		}
		break;
		
		case '5':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosPorMembresia();
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			//system("cls");
		break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
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
			system("pause>nul");
		}
		break;

		case '2': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosBajasMensuales();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosAltasAnuales();
			system("pause>nul");
		}
		break;
			
		case '4':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosBajasAnuales();
			system("pause>nul");
		}
		break;

		case '5':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosActivosPorMembresia();
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
	
	
}

void submenuMostrarProfesoresLista()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR PROFESORES LISTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- POR APELLIDO" << std::endl;
		std::cout << "2 .- POR DISCIPLINA" << std::endl;
		std::cout << "3 .- POR SUELDO" << std::endl;
		std::cout << "4 .- POR ESTADO" << std::endl;
		std::cout << "5 .- POR TURNO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ordenarPorApellido();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ordenarPorDisciplina();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ordenarPorSueldo();
			system("pause>nul");
		}
		break;

		case '4':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.mostrarProfesoresPorEstado();
			system("pause>nul");
		}
		break;
		
		case '5':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.mostrarProfesoresPorTurno();
			system("pause>nul");
		}
		break;
		
		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;
			
		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		system("cls");
	} while (opcion != '0');
	
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.consultaPorDni();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.profePorDisciplina();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ProfePorTurno();
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
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
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.profesorBajasAnuales();
			system("pause>nul");
		}
		break;
			
		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.profesorSueldoAnual();
			system("pause>nul");
		}	
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
	
}

void submenuMostrarAdministracionConsulta()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR ADMINISTRACION CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- CONSULTA POR DNI" << std::endl;
		std::cout << "2 .- CONSULTA POR CARGO" << std::endl;
		std::cout << "3 .- CONSULTA POR FECHA DE INGRESO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoRol archivoRol;
			archivoRol.consultaPorDni();
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoRol archivoRol;
			archivoRol.rolPorCargo();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoRol archivoRol;
			archivoRol.rolPorFechaIngreso();
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		system("cls");
	} while (opcion != '0');
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
		std::cout << "0 .- Volver al menu principal" << std::endl;
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
			system("pause>nul");
		}
		break;

		case '2':
		{
			ArchivoRol archivoRol;
			archivoRol.rolBajasAnuales();
			system("pause>nul");
		}
		break;

		case '3':
		{
			ArchivoRol archivoRol;
			archivoRol.rolSueldoAnual();
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
			break;
		}
		system("cls");
	} while (opcion != '0');
}

void submenuMostrarDisciplinasLista()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR DISCIPLINAS LISTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- ORDENAR POR DICIPLINAS" << std::endl;
		std::cout << "2 .- MOSTRAR HORARIOS" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			/*ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.ordenarPorDisciplina();*/
			system("pause>nul");
		}
		break;

		case '2':
		{
			/*ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.mostrarPorHorarioAscendente();*/
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
}

void submenuMostrarDisciplinasConsulta()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR DISCIPLINAS CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- CONSULTA POR SALONES" << std::endl;
		std::cout << "2 .- CONSULTA POR HORARIOS" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			/*ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.disciplinasPorSalon();*/
			system("pause>nul");
		}
		break;
		
		case '2':
		{
			/*ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.disciplinasPorHorario();*/
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
}

void submenuMostrarSalonConsulta()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "MOSTRAR SALON CONSULTA" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- CONSULTA POR CUPO" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			/*ArchivoSalon archivoSalon;
			archivoSalon.SalonPorCupoHorario();*/
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
}

void submenuInformesRecaudacion()
{
	char opcion;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "INFORMES RECAUDACION" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 .- PAGOS ANUALES DE UN SOCIO" << std::endl;
		std::cout << "2 .- RECAUDACION POR MEMBRESIA" << std::endl;
		std::cout << "3 .- RECAUDACION ANUAL" << std::endl;
		std::cout << "4 .- RECAUDACION MENSUAL" << std::endl;
		std::cout << "5 .- MEMBRESIA MAS VENDIDA ANUAL" << std::endl;
		std::cout << "6 .- MEMBRESIA MAS VENDIDA MENSUAL" << std::endl;
		std::cout << "7 .- MEMBRESIA MENOS VENDIDA ANUAL" << std::endl;
		std::cout << "8 .- MEMBRESIA MENOS VENDIDA MENSUAL" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "0 .- Volver al menu principal" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Ingrese una opcion: ";

		std::cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case '1':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.pagosAnualesSocio();
			system("pause>nul");
		}
		break;
		
		case '2':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.recaudacionPorMembresia();
			system("pause>nul");
		}
		break;
		
		case '3':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.recaudacionAnual();
			system("pause>nul");
		}
		break;
		
		case '4':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.recaudacionMensual();
			system("pause>nul");
		}
		break;
		
		case '5':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMasVendidaAnual();
			system("pause>nul");
		}
		break;
		
		case '6':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMasVendidaMensual();
			system("pause>nul");
		}
		break;
		
		case '7':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMenosVendidaAnual();
			system("pause>nul");
		}
		break;
		
		case '8':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMenosVendidaMensual();
			system("pause>nul");
		}
		break;

		case '0':
			//std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			system("pause>nul");
		break;
		}
		system("cls");
	} while (opcion != '0');
}