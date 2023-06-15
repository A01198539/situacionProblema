#include "menu.h"
#include "lectorArchivos.h"

string Menu::menu()
{
    LectorArchivos lector;
    std::vector<Video*> videos = lector.cargarVideosDesdeArchivo("DatosPeliculas.csv");
    int opcion = 1;

    while (opcion != 7) {
        cout << "1. Cargar archivo de datos." << endl;
        cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género." << endl;
        cout << "3. Mostrar los episodios de una determinada serie ." << endl;
        cout << "4. Mostrar las películas con una cierta calificacion." << endl;
        cout << "5. Calificar un video." << endl;
        cout << "6. Calcular el promedio de la calificación de una serie." << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;

        if (opcion == 1)
            cargarDatos(videos);
        if (opcion == 2)
            videosGenCalificacionGenero(videos);
        if (opcion == 3)
            mostrarEpisodiosSerie(videos);
        if (opcion == 4)
            mostrarPeliculasCalfMayor(videos);
        if (opcion == 5)
            CalificarVideo(videos);
        if (opcion == 6)
            CalcularPromedioCalfSerie(videos);  
        if(opcion == 7)
          cout << "Ha salido de el programa" <<endl; }
}

void Menu::cargarDatos(const std::vector<Video*>& videos)
{
    //LectorArchivos lector;
    //std::vector<Video*> videos = lector.cargarVideosDesdeArchivo("DatosPeliculas.csv");
}




void Menu::videosGenCalificacionGenero(const std::vector<Video*>& videos)
{
    double calificacionMinima;
    std::cout << "Ingrese la calificación mínima: ";
    std::cin >> calificacionMinima;
    std::cout << std::endl;

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
}



void Menu::mostrarEpisodiosSerie(const std::vector<Video*>& videos)
{
    string serie;
    std::cout << "Ingrese el nombre de una serie para mostrar los episodios: ";
    std::cin.ignore();
    std::getline(std::cin, serie);
    std::cout << std::endl;

    std::cout << "Episodios de la serie que solicito " << serie << ":" << std::endl;
    bool encontrados = false;

    for (Video* video : videos) {
        if (video->getNombre() == serie) {
            if (Episodio* episodio = dynamic_cast<Episodio*>(video)) {
            episodio ->mostrarInfo();
            std::cout << std::endl;
            encontrados = true;
        }
    }
    }
    if (!encontrados) {
        std::cout << "No se encontraro la serie que usted ingreso." << std::endl;
    }

}



void Menu::mostrarPeliculasCalfMayor(const std::vector<Video*>& videos)
{
    double calificacionMinima;
    std::cout << "Ingrese la calificación mínima: ";
    std::cin >> calificacionMinima;
    std::cout << std::endl;

    //mostrarVideosPorCalificacion(videos, calificacionMinima);

    std::cout << "VIDEOS CON CALIFICACIÓN MAYOR O IGUAL A " << calificacionMinima << ":" << std::endl;
    bool encontrados = false;

    for (Video* video : videos) {
        if (video->getCalificacion() >= calificacionMinima) {
            if (Pelicula* pelicula = dynamic_cast<Pelicula*>(video)) {
                pelicula->mostrarInfo();
                std::cout << std::endl;
                encontrados = true;
            }
        }
    }

    if (!encontrados) {
        std::cout << "No se encontraron Peliculas con esa calificación." << std::endl;
    }
    
}

void Menu::CalificarVideo(const std::vector<Video*>& videos)
{
}

void Menu::CalcularPromedioCalfSerie(const std::vector<Video*>& videos)
{
}
