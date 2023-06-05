#include "Video.h"

Video::Video(int id, string nombre,int duracion,string genero, int calificacion,
         string fechaEstreno):ID(id),nombre(nombre),duracion(duracion),genero(genero),
        calificacion(calificacion),fechaEstreno(fechaEstreno)
    
    {

    }

    int Video::getID()
    {
        return ID;
    }

    string Video::getNombre()
    {
        return nombre;
    }

    string Video::getGenero()
    {
        return genero;
    }

    int Video::getCalificacion()
    {
        return calificacion;
    }

    int Video::getDuracion()
    {
        return duracion;
    }

    string Video::getfechaEstreno()
    {
        return fechaEstreno;
    }
