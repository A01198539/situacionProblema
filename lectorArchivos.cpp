#include "lectorArchivos.h"
#include <iostream>
using namespace std;

#include<fstream>
#include <sstream> //Flujo de datos en una cadena 
#include <vector>
#include "Video.h"
#include "Pelicula.h"

std::vector<Video *> LectorArchivos::cargarVideosDesdeArchivo(const std::string &nombreArchivo)
{
    std::vector<Video*> videos;

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return videos;
    }
    string linea;
    string id;
    string nombre;
    string genero;
    string calificacion;
    string duracion;
    string fechaEstreno;
    
    while (getline(archivo,linea)){
        vector<Video*> videos;
        stringstream token(linea);
        
        string tipo;
        getline(token,tipo,',');
        getline(token,id,',');
        getline(token,nombre,',');
        getline(token,duracion,',');
        getline(token,genero,',');
        getline(token,calificacion,',');                                                                                                                                    
        getline(token,fechaEstreno,',');

        if(videos.size() == 6){
            cout << "Pelicula";
            videos.push_back(new Pelicula(stoi(id),nombre,stoi(duracion),genero,stoi(calificacion),fechaEstreno));
        }else{
            cout<<"Episodio";
            string idEpisodio;
            string nombreEpisodio;
            string temporada;
            string numeroEpisodio;

            getline(token,idEpisodio,',');
            getline(token,nombreEpisodio,',');
            getline(token,temporada,',');
            getline(token,numeroEpisodio,',');

            videos.push_back(new Episodio(stoi(id),nombre,stoi(duracion),genero,stoi(calificacion),fechaEstreno,
            stoi(idEpisodio),nombreEpisodio,stoi(temporada),stoi(numeroEpisodio)));


              

        }



        
       

    }
    archivo.close();
    return videos;
}