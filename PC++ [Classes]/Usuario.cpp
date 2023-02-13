#include "Usuario.h"

Usuario::Usuario(string email, string senha){
    setEmail(email);
    setSenha(senha);
}

#include <iostream>

void Usuario::serializar(ostream &os) {
    serializarString(os, { &email, &senha });
}

void Usuario::desserializar(istream &is) {
    desserializarString(is, { &email, &senha });
    if (is.eof()) return;
}

void Usuario::setEmail(string email){
    this->email = email;
}

void Usuario::setSenha(string senha){
    this->senha = senha;
}

string Usuario::getEmail(){
    return email;
}

bool Usuario::conferirLogin(string email, string senha){
    if (this->email != email || this->senha != senha){
        return false;
    }
    return true;
}

Usuario::~Usuario(){
    
}

