#include "Serializador.h"
#include <initializer_list>
#include <vector>

// Métodos da classe
void Serializador::serializarString(ostream &os, const string &str) {
  int tamanhoString = str.length();
  os.write((char*)&tamanhoString, sizeof(tamanhoString));
  os.write(str.data(), tamanhoString * sizeof(char));
}


void Serializador::serializarString(ostream &os, initializer_list<string*> strings) {
  for (auto it = strings.begin(); it != strings.end(); ++it) {
    serializarString(os, **it);
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
