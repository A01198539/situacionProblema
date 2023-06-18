#include "menu.h"
#include "lectorArchivos.h"
#include <limits>


//Funcion del menu que usa un ciclo para que se repita 
string Menu::menu()
{
    string nombreArchivo;
    LectorArchivos lector;
    std::vector<Video*> videos;
    int opcion = 0;

    while (opcion != 7) {

        cout << "Nota:DEBE PRESIONAR 1 PARA CARGAR EL ARCHIVO DE DATOS"<<endl;
        std::cout << std::endl;

        cout << "1. Cargar archivo de datos." << endl;
        cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género." << endl;
        cout << "3. Mostrar los episodios de una determinada serie." << endl;
        cout << "4. Mostrar las películas con una cierta calificacion." << endl;
        cout << "5. Calificar un video." << endl;
        cout << "6. Calcular el promedio de la calificación de una serie." << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;

        bool opcionValida = true;

        if (opcion == 1){
            cargarDatos(videos);
        cout << "ARCHIVO DE DATOS CARGADO CORRECTAMENTE" << endl;}
        else if (opcion == 2)
            videosGenCalificacionGenero(videos);
        else if (opcion == 3)
            mostrarEpisodiosSerie(videos);
        else if (opcion == 4)
            mostrarPeliculasCalfMayor(videos);
        else if (opcion == 5)
            CalificarVideo(videos);
        else if (opcion == 6)
            CalcularPromedioCalfSerie(videos);  
        else if(opcion == 7)
          cout << "Ha salido del programa" <<endl; 
        else {
            opcionValida = false;
            }
            
        if(!opcionValida){cout<<"INTRODUZCA UNA OPCION VALIDA" << endl;
            std::cout << std::endl;

            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');}
          }
}

//Funcion para cargar el archivo de datos al presionar 1
void Menu::cargarDatos(std::vector<Video*>& videos)
{
    LectorArchivos lector;
     videos = lector.cargarVideosDesdeArchivo("DatosPeliculas.csv"); 
}


//Funcion que pregunta si el usuario quiere ver los videos por calificacion o por genero y usa dos ciclos for uno para cada opcion.

void Menu::videosGenCalificacionGenero(const std::vector<Video*>& videos)
{
    std::string opc;
    bool opcionValida = false;
    std::getline(std::cin, opc);
    do {
        std::cout << "Deseas ver los videos por calificacion o por genero? (1) Calificacion (2) Genero: ";
        std::getline(std::cin, opc);

        try {
            if (opc == "1" || opc == "2") {
                opcionValida = true;
            } else {
                std::cout << "Opcion invalida. Por favor, seleccione 1 para calificacion o 2 para genero." << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "Entrada no valida. Por favor, ingrese un numero valido." << std::endl;
        }

    } while (!opcionValida);

    if(opc == "1"){
        double calificacionMinima;
        std::cout << "Ingrese la calificación mínima: ";
        std::cin >> calificacionMinima;
        std::cout << std::endl;

        std::cout << "VIDEOS CON CALIFICACIÓN MAYOR O IGUAL A " << calificacionMinima << ":" << std::endl;
        bool encontrados = false;

//Ciclo que recorre el vector de apuntadores
        for (Video* video : videos) {
            //Si es mayor o igual la calificacion del archivo a la que introdujo el usuario, Se muestra la Informacion.
            if (video->getCalificacion() >= calificacionMinima) {
                video->mostrarInfo();
                std::cout << std::endl;
                //Si hay alguna coincidencia la variable encontrados se marca como true
                encontrados = true;
                }   
            }
//Si no hay ninguna coincidencia sale un mensaje a pantalla 
    if (!encontrados) {
        std::cout << "No se encontraron videos con esa calificación." << std::endl;
            }
    }

    else if(opc == "2"){                            
        string genero;
        std::cout << "Ingrese el nombre de un genero para filtrarlo ";
        std::getline(std::cin, genero);
        std::cout << std::endl;
        bool encontrado = false;

     for (Video* video : videos) {
            if (video->getGenero() == genero) {
                video ->mostrarInfo();
                std::cout << std::endl;
                encontrado = true;
            }
        }
    
        if (!encontrado) {
            std::cout << "No se encontro el genero que usted ingreso." << std::endl;
            }
        }
    
}







//Funcion para mostrar los Epsiodios de una serie

void Menu::mostrarEpisodiosSerie(const std::vector<Video*>& videos)
{
    string serie;
    std::cout << "Ingrese el nombre de una serie para mostrar los episodios: ";
    std::cin.ignore();
    std::getline(std::cin, serie);
    std::cout << std::endl;

    std::cout << "Episodios de la serie que solicito " << serie << ":" << std::endl;
    bool encontrados = false;

//Recorrer el vector con ciclo for y si el nombre de la serie es igual al ingresado se usa downcasting para que sea Episodio y se imprima.
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


//Funcion para mostrar las peliculas en base a calificacion
void Menu::mostrarPeliculasCalfMayor(const std::vector<Video*>& videos)
{
    double calificacionMinima;
    std::cout << "Ingrese la calificación mínima: ";
    std::cin >> calificacionMinima;
    std::cout << std::endl;


    std::cout << "VIDEOS CON CALIFICACIÓN MAYOR O IGUAL A " << calificacionMinima << ":" << std::endl;
    bool encontrados = false;                                   

//ciclo que recorre el vector y si es mayor o igual la calificacion a la puesta por el usuario hace downcasting a Pelicula y se muestra la info

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


//Calificar una pelicula o un episodio de una serie y actualizar la calificacion
void Menu::CalificarVideo(const std::vector<Video*>& videos)
{
    string tituloVideo;
    std::cout << "Ingrese el nombre de una pelicula o un episodio para calificar: ";
    std::cin.ignore();
    std::getline(std::cin, tituloVideo);
    std::cout << std::endl;
    double nuevaCalificacion;


     for (auto& video : videos) {
        if (video->getNombre() == tituloVideo) {
            if (Pelicula* pelicula = dynamic_cast<Pelicula*>(video)) { //Downcasting para Pelicula si es una pelicula 

            std::cout << "Ingrese la nueva calificacion para asignar al Video previamente seleccionado: ";
            std::cin >> nuevaCalificacion;
            pelicula->setCalificacion(nuevaCalificacion);
            std::cout << std::endl;

            video->mostrarInfo();

            std::cout << "Se ha actualizado la calificación del video." << std::endl;
            return;
        }
    }
        else if(Episodio* episodio = dynamic_cast<Episodio*>(video)){   //Upcasting para Epsiodio
            if(episodio->getnombreEpisodio() == tituloVideo){
                std::cout << "Ingrese la nueva calificacion para asignar al Video previamente seleccionado: ";
                std::cin >> nuevaCalificacion;
                episodio->setCalificacion(nuevaCalificacion);
                std::cout << std::endl;

                video->mostrarInfo();

                std::cout << "Se ha actualizado la calificación del video." << std::endl;
                return;
        }
    }
}
    std::cout << "No se encontró un video con ese título." << std::endl;
}


//Funcion para calcular el promedio de todos los episodios de una serie 
void Menu::CalcularPromedioCalfSerie(const std::vector<Video*>& videos)
{
    double totalCalificaciones = 0;
    double totalEpisodios = 0;
    string nombreSerie;
    std::cout << "Ingrese el nombre de una serie para calcular el promedio de calificacion de los epsiodios: ";
    std::cin.ignore();
    std::getline(std::cin, nombreSerie);

    for (Video* video : videos) {
        if (video->getNombre() == nombreSerie) {
            if (Episodio* episodio = dynamic_cast<Episodio*>(video)) {
            totalCalificaciones += episodio->getCalificacion(); //Usar sobrecarga de operador += 
            totalEpisodios++; //Incremento
                }
            }
        }

    if (totalEpisodios > 0) {
        double promedio = static_cast<double>(totalCalificaciones) / totalEpisodios;
        std::cout << "El promedio de calificación para la serie: " << nombreSerie << " es: " << promedio << std::endl;
    } else {
        std::cout << "No se encontraron episodios para la serie: " << nombreSerie << std::endl;
    }
}
