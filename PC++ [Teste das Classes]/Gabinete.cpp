#include "Gabinete.h"

// Métodos de sobrecarga do construtor
Gabinete::Gabinete(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  string fatorForma,
  string tamanho,
  bool cooler
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setFatorForma(fatorForma);
  setTamanho(tamanho);
  setCooler(cooler);
}

// Método do destrutor
Gabinete::~Gabinete() {}

// Métodos de salvamento e leitura
void Gabinete::serializar(ostream &os) {
  Produto::serializar(os);
  serializarString(os, { &fatorForma, &tamanho });
  serializarAny(os, cooler);
}

void Gabinete::desserializar(istream &is) {
  Produto::desserializar(is);
  desserializarString(is, { &fatorForma, &tamanho });
  setCooler(desserializarAny<bool>(is));
}

// Métodos de modificação dos atributos
void Gabinete::setFatorForma(string fatorForma) {
  this->fatorForma = fatorForma;
}

void Gabinete::setTamanho(string tamanho) {
  this->tamanho = tamanho;
}

void Gabinete::setCooler(bool cooler)
{
  this->cooler = cooler;
}

// Métodos de retorno dos atributos
string Gabinete::getFatorForma() const {
  return fatorForma;
}

string Gabinete::getTamanho() const {
  return tamanho;
}

bool Gabinete::getCooler() const {
  return cooler;
}

// Métodos da classe
void Gabinete::imprimirProduto() {
  Produto::imprimirProduto();
  cout << "  | Fator Forma: " << fatorForma << endl;
  cout << "  | Tamanho: " << tamanho << endl;
  cout << "  | Cooler: " << (cooler ? "Sim" : "Não") << endl;
}
