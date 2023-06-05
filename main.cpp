#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"

void cargarDatos(string archivo,vector<Video*> videos){

    ifstream inputFile(archivo);
    if(!inputFile){
        cout<<"Error al abrir el archivo verifique que sea un archivo valido"<<endl;
        return;
    }


    string linea;
    string id;
    string nombre;
    string genero;
    string calificacion;
    string duracion;
    string fechaEstreno;
    
    while (getline(inputFile,linea)){
        stringstream token(linea);

        string tipo;
        getline(token,tipo,',');
        getline(token,id,',');
        getline(token,nombre,',');
        getline(token,duracion,',');
        getline(token,genero,',');
        getline(token,calificacion,',');
        getline(token,fechaEstreno,',');

        if(tipo == "Pelicula"){
            videos.push_back(new Pelicula(stoi(id),nombre,stoi(duracion),genero,stoi(calificacion),fechaEstreno));
        }else if(tipo=="Episodio"){
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
}