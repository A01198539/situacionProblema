/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>





//int main(){
    
    vector<Video*> separar(string linea);

    ifstream inputFile;
    inputFile.open("DatosPeliculas.csv");


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
    inputFile.close();
    return 0;

}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



#include <iostream>
using namespace std;

#include<fstream>
#include <sstream> //Flujo de datos en una cadena 
#include <vector>
#include "Video.h"
#include "Pelicula.h"

vector<string> separar(string linea);




int main(int argc, char const *argv[])
{
    vector<string> separar(string linea);

    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea=1;

    while(getline(entrada,linea))
    {
       // cout<<(numeroLinea++)<<"; "<<endl;
       vector <string> datos = separar(linea);
       cout<<(numeroLinea++);
       if (datos.size()==6)
        {
            cout<<"Pelicula";
            //datos.push_back(new Pelicula(stoi(datos)));
        }else{
            cout<<"Episodio:";
            //new Epsiodio(datos)
        }
        cout << endl;
    }
    entrada.close();
    return 0;

}
    


vector<string> separar(string linea)
{
    vector<string>tokens;  //componentes de la linea

    stringstream entrada(linea); //flujo de datos a parrir de una cadena
    string dato;
    int numeroTokens =0;
    while (getline(entrada, dato,','))
    {
        if (dato != "" && dato!="\n" && dato != "\r")
        {
            cout <<dato <<numeroTokens<< endl;
            tokens.push_back(dato); //GUARDAR EN EL VECTOR 
            numeroTokens++;
        }

    }
    //Verificar si se imprime correcto
    //cout<<"Tokens"<<numeroTokens<<endl<<endl;
    return tokens;

    #include <iostream>
#include <vector>
#include <algorithm>
#include "video.h"
#include "episodio.h"
#include "lectorarchivos.h"

void mostrarMenu() {
    std::cout << "MENU" << std::endl;
    std::cout << "1. Cargar el archivo de datos en formato csv." << std::endl;
    std::cout << "2. Mostrar los videos en general con una calificación mayor o igual a un valor tecleado por el usuario." << std::endl;
    std::cout << "3. Mostrar los videos en general con un género tecleado por el usuario." << std::endl;
    std::cout << "4. Mostrar todos los episodios de una determinada serie que teclea el usuario." << std::endl;
    std::cout << "5. Mostrar las películas con una calificación mayor a un número tecleado por el usuario." << std::endl;
    std::cout << "6. Calificar un video." << std::endl;
    std::cout << "7. Calcular el promedio de la calificación de una serie." << std::endl;
    std::cout << "8. Salir." << std::endl;
    std::cout << "Ingrese la opción deseada: ";
}

void mostrarVideos(const std::vector<Video*>& videos) {
    if (videos.empty()) {
        std::cout << "No hay videos para mostrar." << std::endl;
        return;
    }

    std::cout << "VIDEOS:" << std::endl;
    for (const auto& video : videos) {
        video->mostrarInformacion();
        std::cout << std::endl;
    }
}

void mostrarVideosPorCalificacion(const std::vector<Video*>& videos, int calificacionMinima) {
    std::vector<Video*> videosFiltrados;
    std::copy_if(videos.begin(), videos.end(), std::back_inserter(videosFiltrados), [calificacionMinima](const Video* video) {
        return video->getCalificacion() >= calificacionMinima;
    });

    mostrarVideos(videosFiltrados);
}

void mostrarVideosPorGenero(const std::vector<Video*>& videos, const std::string& genero) {
    std::vector<Video*> videosFiltrados;
    std::copy_if(videos.begin(), videos.end(), std::back_inserter(videosFiltrados), [genero](const Video* video) {
        return video->getGenero().find(genero) != std::string::npos;
    });

    mostrarVideos(videosFiltrados);
}

void mostrarEpisodiosSerie(const std::vector<Video*>& videos, const std::string& nombreSerie) {
    std::vector<Video*> episodiosSerie;
    std::copy_if(videos.begin(), videos.end(), std::back_inserter(episodiosSerie), [nombreSerie](const Video* video) {
        const Episodio* episodio = dynamic_cast<const Episodio*>(video);
        return episodio && episodio->getNombre() == nombreSerie;
    });

    mostrarVideos(episodiosSerie);
}

void mostrarPeliculasPorCalificacion(const std::vector<Video*>& videos, int calificacionMinima) {
    std::vector<Video*> peliculasFiltradas;
    std::copy_if(videos.begin(), videos.end(), std::back_inserter(peliculasFiltradas), [calificacionMinima](const Video* video) {
        return dynamic_cast<const Episodio*>(video) == nullptr && video->getCalificacion() >= calificacionMinima;
    });

    mostrarVideos(peliculasFiltradas);
}

void calificarVideo(std::vector<Video*>& videos, const std::string& tituloVideo, int nuevaCalificacion) {
    for (auto& video : videos) {
        if (video->getNombre() == tituloVideo) {
            video->setCalificacion(nuevaCalificacion);
            std::cout << "Se ha actualizado la calificación del video." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró un video con ese título." << std::endl;
}

void calcularPromedioCalificacionSerie(const std::vector<Video*>& videos, const std::string& nombreSerie) {
    int totalCalificaciones = 0;
    int totalEpisodios = 0;

    for (const auto& video : videos) {
        const Episodio* episodio = dynamic_cast<const Episodio*>(video);
        if (episodio && episodio->getNombre() == nombreSerie) {
            totalCalificaciones += episodio->getCalificacion();
            totalEpisodios++;
        }
    }

    if (totalEpisodios > 0) {
        double promedio = static_cast<double>(totalCalificaciones) / totalEpisodios;
        std::cout << "El promedio de calificación para la serie " << nombreSerie << " es: " << promedio << std::endl;
    } else {
        std::cout << "No se encontraron episodios para la serie " << nombreSerie << std::endl;
    }
}

int main() {
    std::vector<Video*> videos;
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombreArchivo;
                std::cout << "Ingrese el nombre del archivo CSV: ";
                std::cin >> nombreArchivo;
                videos = LectorArchivos::cargarVideosDesdeArchivo(nombreArchivo);
                break;
            }
            case 2: {
                int calificacionMinima;
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> calificacionMinima;
                mostrarVideosPorCalificacion(videos, calificacionMinima);
                break;
            }
            case 3: {
                std::string genero;
                std::cout << "Ingrese el género: ";
                std::cin >> genero;
                mostrarVideosPorGenero(videos, genero);
                break;
            }
            case 4: {
                std::string nombreSerie;
                std::cout << "Ingrese el nombre de la serie: ";
                std::cin.ignore();
                std::getline(std::cin, nombreSerie);
                mostrarEpisodiosSerie(videos, nombreSerie);
                break;
            }
            case 5: {
                int calificacionMinima;
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> calificacionMinima;
                mostrarPeliculasPorCalificacion(videos, calificacionMinima);
                break;
            }
            case 6: {
                std::string tituloVideo;
                int nuevaCalificacion;
                std::cout << "Ingrese el título de la película o nombre del episodio: ";
                std::cin.ignore();
                std::getline(std::cin, tituloVideo);
                std::cout << "Ingrese la nueva calificación: ";
                std::cin >> nuevaCalificacion;
                calificarVideo(videos, tituloVideo, nuevaCalificacion);
                break;
            }
            case 7: {
                std::string nombreSerie;
                std::cout << "Ingrese el nombre de la serie: ";
                std::cin.ignore();
                std::getline(std::cin, nombreSerie);
                calcularPromedioCalificacionSerie(videos, nombreSerie);
                break;
            }
            case 8: {
                salir = true;
                break;
            }
            default: {
                std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
                break;
            }
        }

        std::cout << std::endl;
    }

    // Liberar memoria de los videos
    for (const auto& video : videos) {
        delete video;
    }

    return 0;
}



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
        
        
        getline(token,id,',');
        getline(token,nombre,',');
        getline(token,duracion,',');
        getline(token,genero,',');
        getline(token,calificacion,',');                                                                                                                                    
        getline(token,fechaEstreno,',');

        if(videos.size() == 6){
            cout << "Pelicula";
            videos.push_back(new Pelicula(id,nombre,stoi(duracion),genero,stod(calificacion),fechaEstreno));
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

            videos.push_back(new Episodio(id,nombre,stoi(duracion),genero,stod(calificacion),fechaEstreno,
            idEpisodio,nombreEpisodio,stoi(temporada),stod(numeroEpisodio)));


              

        }



        
       

    }
    archivo.close();
    return videos;
}
        void mostrarPeliculasporCalificacion(vector<Video*>videos,double calificacionMinima);

}*/
