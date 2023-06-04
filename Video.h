/*
Autor: Sebatsian Peñafiel A01198539
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video{
    protected:
        int ID;
        string nombre;
        string genero;
        int calificacion;
        int duracion;
        string fechaEstreno;




    public:
        Video(int id, string nombre, string genero, int calificacion,
        int duracion, string fechaEstreno);
        void displayVideos();

        int getID();
        string getNombre();
        string getGenero();
        int getCalificacion();
        int getDuracion();
        string getfechaEstreno();

        virtual void mostrarInfo()=0;
        




};
#endif 