#ifndef EPISODIO_H
#define EPISODIO_H
#include "Video.h"



class Episodio: public Video{

    private:
        int idEpisodio;
        string nombreEpisodio;
        int temporada;
        int numeroEpisodio;


    public:

        Episodio(int id, string nombre,int duracion, string genero, int calificacion,
            string fechaEstreno,int idEpisodio,string nombreEpisodio,int temporada,
            int numeroEpisodio);

        void mostrarInformacion();
        bool esEpisodio();
        int getidEpisodio();
        string getnombreEpisodio();
        int getTemporada();
        int getnumeroEpisodio();




};
#endif 