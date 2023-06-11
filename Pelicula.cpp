#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula()
{
}

Pelicula::Pelicula(int id, string nombre, int duracion, string genero,
                   int calificacion, string fechaEstreno)
    : Video(id, nombre, duracion, genero, calificacion, fechaEstreno)
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

void Pelicula::mostrarPeliculasporCalificacion(vector<Video *> videos, double calificacionMinima)
{
    std::cout << "PELÍCULAS CON CALIFICACIÓN MAYOR O IGUAL A " << calificacionMinima << ":" << std::endl;
    bool encontradas = false;

    for (const auto& video : videos) {
        if (dynamic_cast<const Pelicula*>(video) && video->getCalificacion() >= calificacionMinima) {
            video->mostrarInfo();
            std::cout << std::endl;
            encontradas = true;
        }
    }

    if (!encontradas) {
        std::cout << "No se encontraron películas con esa calificación." << std::endl;
    }
}

