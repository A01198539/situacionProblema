/*
Autor:Sebastian Peñafiel A01198539 
*/

#include "Video.h"
#include <iostream>
using namespace std;

#include<fstream>
#include <sstream> //Flujo de datos en una cadena 
#include <vector>

Video::Video()
{
}

Video::Video(string id, string nombre, int duracion, string genero, double calificacion,
             string fechaEstreno) : ID(id), nombre(nombre), duracion(duracion), 
             genero(genero),calificacion(calificacion), fechaEstreno(fechaEstreno)
{

}


string Video::getID()
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

double Video::getCalificacion()
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

void Video::setCalificacion(double nuevaCalificacion)
{
    calificacion = nuevaCalificacion;
}
