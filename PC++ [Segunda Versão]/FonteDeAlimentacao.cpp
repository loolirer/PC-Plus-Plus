#include "FonteDeAlimentacao.h"

// Métodos de sobrecarga do construtor
FonteDeAlimentacao::FonteDeAlimentacao(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  int potencia,
  string fatorForma
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setPotencia(potencia);
  setFatorForma(fatorForma);
}

// Método do destrutor
FonteDeAlimentacao::~FonteDeAlimentacao() {}

// Métodos de salvamento e leitura
void FonteDeAlimentacao::serializar(ostream &os) {
  Produto::serializar(os);
  serializarAny(os, potencia);
  serializarString(os, fatorForma);
}

void FonteDeAlimentacao::desserializar(istream &is) {
  Produto::desserializar(is);
  setPotencia(desserializarAny<int>(is));
  desserializarString(is, fatorForma);
}

// Métodos de modificação dos atributos
void FonteDeAlimentacao::setPotencia(int potencia) {
  this->potencia = potencia;
}

void FonteDeAlimentacao::setFatorForma(string fatorForma) {
  this->fatorForma = fatorForma;
}

// Métodos de retorno dos atributos
int FonteDeAlimentacao::getPotencia() const {
  return potencia;
}

string FonteDeAlimentacao::getFatorForma() const {
  return fatorForma;
}

// Métodos da classe
void FonteDeAlimentacao::imprimirProduto() {
  Produto::imprimirProduto();
  cout << "  | Potência: " << potencia << "\n";
  cout << "  | Fator Forma: " << fatorForma << "\n\n";
}
