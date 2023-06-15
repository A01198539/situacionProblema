#ifndef EPISODIO_H
#define EPISODIO_H
#include "Video.h"
#include <string>

using namespace std;

class Episodio: public Video{

    private:
        string idEpisodio;
        string nombreEpisodio;
        int temporada;
        double numeroEpisodio;


    public:

        Episodio();
        Episodio(string id, string nombre,int duracion, string genero, double calificacion,
            string fechaEstreno,string idEpisodio,string nombreEpisodio,int temporada,
            double numeroEpisodio);

        void mostrarInfo();
        bool esEpisodio();
        string getidEpisodio();
        string getnombreEpisodio();
        int getTemporada();
        double getnumeroEpisodio();




};
#endif 