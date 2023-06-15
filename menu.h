#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "lectorArchivos.h"
using namespace std;


class Menu{

private:
/*Cargar el archivo donde se leen los datos*/
    void cargarDatos(const std::vector<Video*>& videos);

/*Mostrar los videos en general con Una calificacion mayor o 
igual a un valor tecleado por el usuario o un genero tecleado por el usuario*/
    void videosGenCalificacionGenero(const std::vector<Video*>& videos);

/*Mostrar todos los episodios de una determinada serie que teclea el usuario.*/
    void mostrarEpisodiosSerie(const std::vector<Video*>& videos);

/*Mostrar las películas con una calificacion mayor a un número tecleado por el usuario.*/
    void mostrarPeliculasCalfMayor(const std::vector<Video*>& videos);

/*Pedir titulo de película o nombre del capítulo de la serie a calificar,Pedir valor otorgado y asignarlo (reemplaza la calificación anterior).
*/
    void CalificarVideo(const std::vector<Video*>& videos);

/*Calcular el promedio de la calificación de una serie (promedio de todos los episodios).*/
    void CalcularPromedioCalfSerie(const std::vector<Video*>& videos);

public:

    string menu();






};
#endif 


