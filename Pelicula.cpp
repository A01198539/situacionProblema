#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(int id, string nombre, string genero, 
int calificacion, int duracion, string fechaEstreno)
:Video(id,nombre,genero,calificacion,duracion,fechaEstreno)
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
