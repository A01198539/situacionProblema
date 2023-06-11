#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "lectorArchivos.h"


int main(){

    std::vector<Video*> videos;


    videos = LectorArchivos::cargarVideosDesdeArchivo("DatosPeliculas.csv");


    Pelicula pelicula;
    int calificacionMinima;
    std::cout << "Ingrese la calificación mínima: ";
    std::cin >> calificacionMinima;
    pelicula.mostrarPeliculasporCalificacion(videos, calificacionMinima);
     




    return 0;
};