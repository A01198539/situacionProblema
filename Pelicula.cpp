#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(int id, string nombre,int duracion, string genero, 
int calificacion,  string fechaEstreno)
:Video(id,nombre,duracion,genero,calificacion,fechaEstreno)
{
}

void Pelicula::mostrarInfo()
{
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Género: " << getGenero() << std::endl;
    std::cout << "Calificación: " << getCalificacion() << std::endl;
    std::cout << "Duración: " << getDuracion() << " minutos" << std::endl;
    std::cout << "Fecha de estreno: " << getfechaEstreno() << std::endl;
}

bool Pelicula::esEpisodio()
{
    return false;
}
