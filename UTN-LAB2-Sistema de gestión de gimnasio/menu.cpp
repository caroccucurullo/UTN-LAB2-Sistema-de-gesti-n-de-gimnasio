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
		}
		break;

		case '2': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.bajaSocio();
		}
		break;

		case '3': 
		{
			ArchivoSocios archivoSocios;
			archivoSocios.modificarSocio();
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
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '0');
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
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.bajaProfesor();
		}	
		break;

		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.modificarProfesor();
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
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '0');
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
		}
		break;

		case '2':
		{
			ArchivoRol archivoRol;
			archivoRol.bajaRol();
		}
		break;

		case '3':
		{
			ArchivoRol archivoRol;
			archivoRol.modificarRol();
		}
		break;

		case '4':
			submenuMostrarAdministracionConsulta();
		break;
			
		case '5':
			submenuMostrarAdministracionInforme();
		break;
		
		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

	} while (opcion != '0');
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
		}
		break;

		case '2':
		{	
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.bajaDisciplina();
		}	
		break;

		case '3':
		{
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.modificarDisciplina();
		}
		break;

		case '4':
			submenuMostrarDisciplinasLista();
		break;

		case '5':
			submenuMostrarDisciplinasConsulta();
		break;
	
		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

	} while (opcion != '0');
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
		}
		break;

		case '2':
		{
			ArchivoSalon archivoSalon;
			archivoSalon.bajaSalon();
		}
		break;

		case '3':
		{
			ArchivoSalon archivoSalon;
			archivoSalon.modificarSalon();
		}
		break;

		case '4':
			submenuMostrarSalonConsulta();
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;
		
		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
		}
		break;

		case '2':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.consultarPago();
		}
		break;

		case '3':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.modificarPago();
		}
		break;

		case '4':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.pagosDelMes();
		}
		break;
		
		case '5':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.consultarPago();
		}
		break;

		case '6':
			submenuInformesRecaudacion();
		break;
			
		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
		}
		break;
		
		case '2':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.ordenarPorEdad();
		}
		break;
		
		case '3':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorEstado();
		}
		break;
	
		case '4':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.mostrarPorAptoMedico();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

	} while (opcion != '0');
	
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
		}
		break;

		case '2':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.consultaPorNumSocio();
		}
		break;

		case '3':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosPorEdad();
		}
		break;

		case '4':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosPorDis();
		}
		break;
		
		case '5':
		{
			ArchivoSocios archivoSocios;
			archivoSocios.sociosPorMembresia();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ordenarPorDisciplina();
		}
		break;

		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ordenarPorSueldo();
		}
		break;

		case '4':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.mostrarProfesoresPorEstado();
		}
		break;
		
		case '5':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.mostrarProfesoresPorTurno();
		}
		break;
		
		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;
			
		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

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
		}
		break;

		case '2':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ProfePorDis();
		}
		break;

		case '3':
		{
			ArchivoProfesor archivoProfesor;
			archivoProfesor.ProfePorTurno();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

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

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
		}
		break;

		case '2':
		{
			ArchivoRol archivoRol;
			archivoRol.rolPorCargo();
		}
		break;

		case '3':
		{
			ArchivoRol archivoRol;
			archivoRol.rolPorFechaIngreso();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

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

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
			break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
			break;
		}

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
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.ordenarPorDisciplina();
		}
		break;

		case '2':
		{
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.mostrarPorHorarioAscendente();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.disciplinasPorSalon();
		}
		break;
		
		case '2':
		{
			ArchivoDisciplina archivoDisciplina;
			archivoDisciplina.disciplinasPorHorario();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
			ArchivoSalon archivoSalon;
			archivoSalon.SalonPorCupoHorario();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

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
		}
		break;
		
		case '2':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.recaudacionPorMembresia();
		}
		break;
		
		case '3':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.recaudacionAnual();
		}
		break;
		
		case '4':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.recaudacionMensual();
		}
		break;
		
		case '5':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMasVendidaAnual();
		}
		break;
		
		case '6':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMasVendidaMensual();
		}
		break;
		
		case '7':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMenosVendidaAnual();
		}
		break;
		
		case '8':
		{
			ArchivoPagos archivoPagos;
			archivoPagos.membresiaMenosVendidaMensual();
		}
		break;

		case '0':
			std::cout << "\n\nVolver al menu principal" << std::endl;
		break;

		default:
			std::cout << "\n\nNO ES UNA OPCION VALIDA" << std::endl;
		break;
		}

	} while (opcion != '0');
}