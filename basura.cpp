/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>





//int main(){
    
    vector<Video*> separar(string linea);

    ifstream inputFile;
    inputFile.open("DatosPeliculas.csv");


    if(!inputFile){
        cout<<"Error al abrir el archivo verifique que sea un archivo valido"<<endl;
        return;
    }


    string linea;
    string id;
    string nombre;
    string genero;
    string calificacion;
    string duracion;
    string fechaEstreno;
    
    while (getline(inputFile,linea)){
        vector<Video*> videos;
        stringstream token(linea);
        
        string tipo;
        getline(token,tipo,',');
        getline(token,id,',');
        getline(token,nombre,',');
        getline(token,duracion,',');
        getline(token,genero,',');
        getline(token,calificacion,',');                                                                                                                                    
        getline(token,fechaEstreno,',');

        if(videos.size() == 6){
            cout << "Pelicula";
            videos.push_back(new Pelicula(stoi(id),nombre,stoi(duracion),genero,stoi(calificacion),fechaEstreno));
        }else{
            cout<<"Episodio";
            string idEpisodio;
            string nombreEpisodio;
            string temporada;
            string numeroEpisodio;

            getline(token,idEpisodio,',');
            getline(token,nombreEpisodio,',');
            getline(token,temporada,',');
            getline(token,numeroEpisodio,',');

            videos.push_back(new Episodio(stoi(id),nombre,stoi(duracion),genero,stoi(calificacion),fechaEstreno,
            stoi(idEpisodio),nombreEpisodio,stoi(temporada),stoi(numeroEpisodio)));


              

        }



        
       

    }
    inputFile.close();
    return 0;

}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



#include <iostream>
using namespace std;

#include<fstream>
#include <sstream> //Flujo de datos en una cadena 
#include <vector>
#include "Video.h"
#include "Pelicula.h"

vector<string> separar(string linea);




int main(int argc, char const *argv[])
{
    vector<string> separar(string linea);

    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea=1;

    while(getline(entrada,linea))
    {
       // cout<<(numeroLinea++)<<"; "<<endl;
       vector <string> datos = separar(linea);
       cout<<(numeroLinea++);
       if (datos.size()==6)
        {
            cout<<"Pelicula";
            //datos.push_back(new Pelicula(stoi(datos)));
        }else{
            cout<<"Episodio:";
            //new Epsiodio(datos)
        }
        cout << endl;
    }
    entrada.close();
    return 0;

}
    


vector<string> separar(string linea)
{
    vector<string>tokens;  //componentes de la linea

    stringstream entrada(linea); //flujo de datos a parrir de una cadena
    string dato;
    int numeroTokens =0;
    while (getline(entrada, dato,','))
    {
        if (dato != "" && dato!="\n" && dato != "\r")
        {
            cout <<dato <<numeroTokens<< endl;
            tokens.push_back(dato); //GUARDAR EN EL VECTOR 
            numeroTokens++;
        }

    }
    //Verificar si se imprime correcto
    //cout<<"Tokens"<<numeroTokens<<endl<<endl;
    return tokens;

    
}*/
