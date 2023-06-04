#include "Video.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::stringstream;

Video::Video(int ID, string nombre, string genero, int calificacion,
        int duracion, string fechaEstreno)
{
    ifstream videos;
    videos.open("DatosPeliculas.csv");
    string linea;
    string Id;
    string nombre;
    string genero;
    string calificacion;
    string duracion;
    string fechaEstreno;

    while (getline(videos,linea)){
        stringstream token(linea);
        getline(token,Id,',');
        getline(token,nombre,',');
        getline(token,genero,',');
        

    }

}

void Video::displayVideos()
{
}
