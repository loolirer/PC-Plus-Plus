#include "Cliente.h"

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

Cliente::~Cliente(){

}

void Cliente::serializar(ostream &os) {
    Usuario::serializar(os);
    serializarString(os, { &cpf, &endereco });
    serializarAny(saldo, os);
}

void Cliente::desserializar(istream &is) {
    Usuario::desserializar(is);
    if (is.eof()) return;
    desserializarString(is, { &cpf, &endereco });
    setSaldo(desserializarAny<float>(is));
}

void Cliente::setCpf(string cpf) {
    this->cpf = cpf;
}

void Cliente::setEndereco(string endereco) {
    this->endereco = endereco;
}

void Cliente::setSaldo(float saldo) {
    this->saldo = saldo;
}

string Cliente::getCpf() {
    return cpf;
}

string Cliente::getEndereco() {
    return endereco;
}

float Cliente::getSaldo() {
    return saldo;
}
