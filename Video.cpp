#include "Video.h"

Video::Video(int id, string nombre, string genero, int calificacion,
        int duracion, string fechaEstreno):ID(id),nombre(nombre),genero(genero),
        calificacion(calificacion),duracion(duracion),fechaEstreno(fechaEstreno)
    
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
