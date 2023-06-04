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
        Video(int ID, string nombre, string genero, int calificacion,
        int duracion, string fechaEstreno);
        void displayVideos();





};
#endif 