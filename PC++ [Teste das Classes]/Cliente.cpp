#include "Cliente.h"

// Métodos de sobrecarga do construtor
Cliente::Cliente(
  string email,
  string senha,
  string cpf,
  string endereco,
  float saldo
): Usuario(
    email,
    senha
) {
  setCpf(cpf);
  setEndereco(endereco);
  setSaldo(saldo);
}

// Método do destrutor
Cliente::~Cliente() {}

// Métodos de salvamento e leitura
void Cliente::serializar(ostream &os) {
  Usuario::serializar(os);
  serializarString(os, { &cpf, &endereco });
  serializarAny(os, saldo);
}

void Cliente::desserializar(istream &is) {
  Usuario::desserializar(is);
  if (is.eof()) return;
  desserializarString(is, { &cpf, &endereco });
  setSaldo(desserializarAny<float>(is));
}

// Métodos de modificação dos atributos
void Cliente::setCpf(string cpf) {
  this->cpf = cpf;
}

void Cliente::setEndereco(string endereco) {
  this->endereco = endereco;
}

void Cliente::setSaldo(float saldo) {
  this->saldo = saldo;
}

// Métodos de retorno dos atributos
string Cliente::getCpf() const {
  return cpf;
}

string Cliente::getEndereco() const {
  return endereco;
}

float Cliente::getSaldo() const {
  return saldo;
}
