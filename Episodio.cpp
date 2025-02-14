#include "Episodio.h"
#include <iostream>
using namespace std;

Episodio::Episodio()
{
}

Episodio::Episodio(string id, string nombre, int duracion, string genero,
                double calificacion, string fechaEstreno, string idEpisodio, string nombreEpisodio,
                int temporada, double numeroEpisodio) : Video(id, nombre, duracion,
                genero, calificacion, fechaEstreno),idEpisodio(idEpisodio),
                nombreEpisodio(nombreEpisodio), temporada(temporada), numeroEpisodio(numeroEpisodio){}


void Episodio::mostrarInfo()
{
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Género: " << getGenero() << std::endl;
    std::cout << "Calificación: " << getCalificacion() << std::endl;
    std::cout << "Duración: " << getDuracion() << " minutos" << std::endl;
    std::cout << "Fecha de estreno: " << getfechaEstreno() << std::endl;
    std::cout << "ID Episodio: " << idEpisodio << std::endl;
    std::cout << "Nombre Episodio:" << nombreEpisodio << std::endl;
    std::cout << "Temporada: " << temporada << std::endl;
    std::cout << "Número de episodio: " << numeroEpisodio << std::endl;
}

bool Episodio::esEpisodio()
{
    return true;
}

string Episodio::getidEpisodio()
{
    return idEpisodio;
}

string Episodio::getnombreEpisodio()
{
    return nombreEpisodio;
}

int Episodio::getTemporada()
{
    return temporada;
}

double Episodio::getnumeroEpisodio()
{
    return numeroEpisodio;
}

Episodio &Episodio::operator+=(int calificacion)
{
    setCalificacion(getCalificacion() + calificacion);
    return *this;
}
