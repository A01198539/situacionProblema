#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include <vector>



class Pelicula : public Video {

    private:

        double calificacionMinima;


    public:

        Pelicula();
        Pelicula(string id, string nombre,int duracion, string genero, double calificacion,
        string fechaEstreno);

        void mostrarInfo();






};
#endif