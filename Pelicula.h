#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include "lectorArchivos.h"


class Pelicula : public Video{

    private:

        double calificacionMinima;


    public:

        Pelicula();
        Pelicula(int id, string nombre,int duracion, string genero, int calificacion,
         string fechaEstreno);

        void mostrarPeliculasporCalificacion(vector<Video*>videos,double calificacionMinima);

        void mostrarInfo();






};
#endif