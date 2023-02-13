#include "Gabinete.h"

// Métodos de sobrecarga do construtor
Gabinete::Gabinete(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  string fatorForma,
  string tamanho
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setFatorForma(fatorForma);
  setTamanho(tamanho);
}

// Método do destrutor
Gabinete::~Gabinete() {}

// Métodos de salvamento e leitura
void Gabinete::serializar(ostream &os) {
  Produto::serializar(os);
  serializarString(os, { &fatorForma, &tamanho });
}

void Gabinete::desserializar(istream &is) {
  Produto::desserializar(is);
  desserializarString(is, { &fatorForma, &tamanho });
}

// Métodos de modificação dos atributos
void Gabinete::setFatorForma(string fatorForma) {
  this->fatorForma = fatorForma;
}

void Gabinete::setTamanho(string tamanho) {
  this->tamanho = tamanho;
}

// Métodos de retorno dos atributos
string Gabinete::getFatorForma() const {
  return fatorForma;
}

string Gabinete::getTamanho() const {
  return tamanho;
}

// Métodos da classe
vector<vector<string>> Gabinete::imprimirProduto() {
  vector<vector<string>> dadosProduto = Produto::imprimirProduto();

  dadosProduto[1].insert(
    dadosProduto[1].end(),
    { 
      "Fator Forma: " + fatorForma, 
      "Tamanho: " + tamanho 
    }
  );
  return dadosProduto;
}
