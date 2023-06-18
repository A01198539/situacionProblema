#include "lectorArchivos.h"
#include <iostream>
using namespace std;

#include<fstream>
#include <sstream> //Flujo de datos en una cadena 
#include <vector>
#include "Episodio.h"
#include "Pelicula.h"


std::vector<Video *> LectorArchivos::cargarVideosDesdeArchivo(const std::string &nombreArchivo)
{
    std::vector<Video*> videos;  //Inicializando vector videos

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return videos;
    }
    string headerLine;
    getline(archivo, headerLine); //Que no lea la primera linea de el csv.

    std::string linea;
    while (getline(archivo, linea)) {
        std::stringstream token(linea);

        std::string id;
        std::string nombre;
        std::string duracion;
        std::string genero;
        std::string calificacion;
        std::string fechaEstreno;
        std::string idEpisodio;
        std::string nombreEpisodio;
        std::string temporada;
        std::string numEpisodio;

        getline(token, id, ',');
        getline(token, nombre, ',');
        getline(token, duracion, ',');
        getline(token, genero, ',');
        getline(token, calificacion, ',');
        getline(token, fechaEstreno, ',');
        getline(token, idEpisodio, ',');

        if (!idEpisodio.empty()) {             //Si la variable de idEpsiodio no esta vacia entonces se obtienen
            getline(token, nombreEpisodio, ',');                          //las variables restantes de Epsiodio 
            getline(token, temporada, ',');                               //para luego guardarse en el vector.
            getline(token, numEpisodio, ',');

            videos.push_back(new Episodio(id, nombre, stoi(duracion), genero, stod(calificacion), fechaEstreno,
                idEpisodio, nombreEpisodio, stoi(temporada), stoi(numEpisodio)));
        }
        else {
            videos.push_back(new Pelicula(id, nombre, stoi(duracion), genero, stod(calificacion), fechaEstreno));
        }
    }
    archivo.close();
    return videos;   //Devolviendo los videos almacenados
}