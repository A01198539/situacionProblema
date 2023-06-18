#include "Pelicula.h"
#include <iostream>

//Constructor Vacio
Pelicula::Pelicula()
{
}
//Constructor con propiedades de Video
Pelicula::Pelicula(string id, string nombre, int duracion, string genero,
    double calificacion, string fechaEstreno)
    : Video(id, nombre, duracion, genero, calificacion, fechaEstreno)
{
}


//Metodo para mostrar la informacion si es Pelicula que se sobreescribe 
void Pelicula::mostrarInfo()
{
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Género: " << getGenero() << std::endl;
    std::cout << "Calificación: " << getCalificacion() << std::endl;
    std::cout << "Duración: " << getDuracion() << " minutos" << std::endl;
    std::cout << "Fecha de estreno: " << getfechaEstreno() << std::endl;
}

