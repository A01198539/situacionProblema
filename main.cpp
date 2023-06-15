#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "lectorArchivos.h"
#include "menu.h"



int main(){

    Menu menu;
    menu.menu();
    /*std::vector<Video*> videos;

    LectorArchivos lector;
    std::vector<Video*> videos = lector.cargarVideosDesdeArchivo("DatosPeliculas.csv");

    // Aquí puedes realizar las operaciones deseadas con los videos cargados
    
    // Recorriendo y mostrando información de los videos
    for (Video* video : videos) {
        video->mostrarInfo();
        std::cout << std::endl;
    }

    // Liberando la memoria de los videos
    


    double calificacionMinima;
    std::cout << "Ingrese la calificación mínima: ";
    std::cin >> calificacionMinima;
    //mostrarVideosPorCalificacion(videos, calificacionMinima);

    std::cout << "VIDEOS CON CALIFICACIÓN MAYOR O IGUAL A " << calificacionMinima << ":" << std::endl;
    bool encontrados = false;

    for (Video* video : videos) {
        if (video->getCalificacion() >= calificacionMinima) {
            video->mostrarInfo();
            std::cout << std::endl;
            encontrados = true;
        }
    }

    if (!encontrados) {
        std::cout << "No se encontraron videos con esa calificación." << std::endl;
    }

    for (Video* video : videos) {
        delete video;}*/
     

    


    return 0;
};