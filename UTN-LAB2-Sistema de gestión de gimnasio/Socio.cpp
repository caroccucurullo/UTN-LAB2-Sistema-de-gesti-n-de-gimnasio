#include "Socio.h"
#include "ArchivoSocios.h"

Socio::Socio(int ns, bool am, int idMem, Fecha fIngreso, Fecha fEgreso) {
    nroSocio = ns;
    aptoMed = am;
    idMembresia = idMem;
    _fIngreso = fIngreso;
    _fEgreso = fEgreso;
    estado = true;
}

void Socio::MostrarSocio() {
    std::cout << "Nro. Socio: " << nroSocio << std::endl;
    Persona::MostrarPersona();
    std::cout << "Apto Medico: " << aptoMed << std::endl;
    std::cout << "ID Membresia: " << idMembresia << std::endl;
}

std::string Socio::MostrarSociosDatos()
{
    std::string cadena;
    cadena = std::to_string(getNroSocio()) + "," + Persona::MostrarPersonaFormatoComas() + "," + std::to_string(getIdMembresia()) + "," + getFechaIngreso().toString();
    if (!estado) cadena += "," + _fEgreso.toString();
    return cadena;
}

void Socio::CargarSocio()
{
    int ns;
    std::cout << "Numero Socio: ";
    std::cin >> ns;
    setNroSocio(ns);
    std::cin.ignore();
    Persona::CargarPersona();
    std::cout << "Apto Medico (1=Si/0=No): ";
    std::cin >> ns;
    setAptoMed(ns);
    std::cout << "ID Membresia: ";
    std::cin >> ns;
    setIdMembresia(ns);
    //_fIngreso.Cargar();
}

void Socio::ordenarPorNombre()
{
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    ordenarPorNombreDescendiente(socios, cantidad);

    mostrarVectorSocios(socios, cantidad);

    delete[] socios;
}

void Socio::ordenarPorEdad()
{
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    ordenarPorEdadDescendiente(socios, cantidad);

    mostrarVectorSocios(socios, cantidad);

    delete[] socios;
}

void Socio::mostrarPorEstado(){
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getEstado() == true)
        {
            socios[i].MostrarSocio();
        }
    }

    delete[] socios;
}

void Socio::mostrarPorAptoMedico(){
    ArchivoSocios archivoSocios;
    int cantidad = archivoSocios.getCantidad();
    Socio* socios = new Socio[cantidad];

    completarVectorSocios(socios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (socios[i].getAptoMed() == true)
        {
            socios[i].MostrarSocio();
        }
    }

    delete[] socios;
}

//Funciones auxiliares de la clase

void completarVectorSocios(Socio* socios, int cantidad)
{
    ArchivoSocios archivoSocios;

    for (int i = 0; i < cantidad; i++)
    {
        socios[i] = archivoSocios.leerSocio(i);
    }
}

void ordenarPorNombreDescendiente(Socio* socios, int cantidad){
    Socio aux;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            if (strcmp(socios[j].getNombre().c_str(), socios[j + 1].getNombre().c_str()) < 0)
            {
                aux = socios[j];
                socios[j] = socios[j + 1];
                socios[j + 1] = aux;
            }
        }
    }
}

void ordenarPorEdadDescendiente(Socio* socios, int cantidad)
{
    Socio aux;

    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            if (socios[j].getEdad() < socios[j + 1].getEdad())
            {
                aux = socios[j];
                socios[j] = socios[j + 1];
                socios[j + 1] = aux;
            }
        }
    }
}

void mostrarVectorSocios(Socio* socios, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        socios[i].MostrarSocio();
    }
}


//std::string Socio::setPrecision(float p)
//{
//    std::string peso(std::to_string(p));
//    peso.resize(5);
//    return peso;
//}
