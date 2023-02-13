#include "Administrador.h"

// Métodos de sobrecarga do construtor
Administrador::Administrador(
  string email,
  string senha
): Usuario(
  email,
  senha
) {}

// Método do destrutor
Administrador::~Administrador() {}
