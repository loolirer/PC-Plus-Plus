#include "Usuario.h"
#include <iostream>

// Métodos de sobrecarga do construtor
Usuario::Usuario(string email, string senha) {
  setEmail(email);
  setSenha(senha);
}

// Método do destrutor
Usuario::~Usuario() {}

// Métodos de salvamento e leitura
void Usuario::serializar(ostream &os) {
  serializarString(os, { &email, &senha });
}

void Usuario::desserializar(istream &is) {
  desserializarString(is, { &email, &senha });
  if (is.eof()) return;
}

// Métodos de modificação dos atributos
void Usuario::setEmail(string email) {
  this->email = email;
}

void Usuario::setSenha(string senha) {
  this->senha = senha;
}

// Métodos de retorno dos atributos
string Usuario::getEmail() const {
  return email;
}

// Métodos da classe
bool Usuario::conferirLogin(string email, string senha) const {
  if (this->email != email || this->senha != senha) {
    return false;
  }
  return true;
}
