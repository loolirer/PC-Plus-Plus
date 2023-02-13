#include "Serializador.h"
#include <initializer_list>
#include <vector>

void Serializador::serializarString(const string &str, ostream &os) {
    int tamanhoString = str.length();
    os.write((char*)&tamanhoString, sizeof(tamanhoString));
    os.write(str.data(), tamanhoString * sizeof(char));
}

void Serializador::serializarString(ostream &os, initializer_list<string*> strings) {
    for (auto it = strings.begin(); it != strings.end(); ++it) {
        serializarString(**it, os);
    }
};

void Serializador::desserializarString(istream &is, string &str) {
    int tamanhoString;
    is.read((char*)&tamanhoString, sizeof(tamanhoString));
    if (is.eof()) return;
    new (&str) string(tamanhoString, '\0');
    is.read(&str[0], tamanhoString * sizeof(char));
}

void Serializador::desserializarString(istream &is, initializer_list<string*> strings) {
    for (auto it = strings.begin(); it != strings.end(); ++it) {
        desserializarString(is, **it);
    }
}