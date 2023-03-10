#ifndef Administrador_H
#define Administrador_H

#include <string>
#include "Usuario.h"

class Administrador: public Usuario {
  public:
    // Métodos de sobrecarga do construtor
    Administrador(
      string email = "",
      string senha = ""
    );

    // Método do destrutor
    ~Administrador();
};

#endif
