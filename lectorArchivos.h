#ifndef LECTORARCHIVOS_H
#define LECTORARCHIVOS_H

#include <vector>
#include <string>
#include "Video.h"

class LectorArchivos{

public:
    static std::vector<Video*> cargarVideosDesdeArchivo(const std::string& nombreArchivo);


};
#endif