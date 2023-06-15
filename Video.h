/*
Autor: Sebatsian Peñafiel A01198539
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>

using namespace std;

class Video {
    protected:
        string ID;
        string nombre;
        string genero;
        double calificacion;
        int duracion;
        string fechaEstreno;




    public:

        Video();
        Video(string id, string nombre,int duracion, string genero, double calificacion,
         string fechaEstreno);

        string getID();
        string getNombre();
        string getGenero();
        double getCalificacion();
        int getDuracion();
        string getfechaEstreno();

        virtual void mostrarInfo()=0;
        



};
#endif