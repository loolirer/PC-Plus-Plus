#ifndef ADMINISTRADOR_H // Início do cabeçalho do arquivo ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>
#include "Usuario.h"

using namespace std;

class Administrador: public Usuario {
    public:
        Administrador(
            string = "",
            string = ""
        );
        ~Administrador();
};

#endif