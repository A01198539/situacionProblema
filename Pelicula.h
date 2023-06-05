#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"


class Pelicula : public Video{

    private:


    public:

        Pelicula(int id, string nombre,int duracion, string genero, int calificacion,
         string fechaEstreno);

        void mostrarInfo();
        bool esEpisodio();






};
#endif