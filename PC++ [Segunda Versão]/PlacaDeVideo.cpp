#include "PlacaDeVideo.h"

// Métodos de sobrecarga do construtor
PlacaDeVideo::PlacaDeVideo(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  unsigned short int memoria,
  string tipoMemoria,
  unsigned short int frequencia,
  unsigned short int bits
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setMemoria(memoria);
  setTipoMemoria(tipoMemoria);
  setFrequencia(frequencia);
  setBits(bits);
}

// Método do destrutor
PlacaDeVideo::~PlacaDeVideo() {}

// Métodos de salvamento e leitura
void PlacaDeVideo::serializar(ostream &os) {
  Produto::serializar(os);
  serializarAny(os, memoria);
  serializarString(os, tipoMemoria);
  serializarAny(os, frequencia);
  serializarAny(os, bits);
}

void PlacaDeVideo::desserializar(istream &is) {
  Produto::desserializar(is);
  setMemoria(desserializarAny<unsigned short int>(is));
  desserializarString(is, tipoMemoria);
  setFrequencia(desserializarAny<unsigned short int>(is));
  setBits(desserializarAny<unsigned short int>(is));
}

// Métodos de modificação dos atributos
void PlacaDeVideo::setMemoria(unsigned short int memoria) {
  this->memoria = memoria;
}

void PlacaDeVideo::setTipoMemoria(string tipoMemoria) {
  this->tipoMemoria = tipoMemoria;
}

void PlacaDeVideo::setFrequencia(unsigned short int frequencia) {
  this->frequencia = frequencia;
}

void PlacaDeVideo::setBits(unsigned short int bits) {
  this->bits = bits;
}

// Métodos de retorno dos atributos
unsigned short int PlacaDeVideo::getMemoria() const {
  return memoria;
}

string PlacaDeVideo::getTipoMemoria() const {
  return tipoMemoria;
}

unsigned short int PlacaDeVideo::getFrequencia() const {
  return frequencia;
}

unsigned short int PlacaDeVideo::getBits() const {
  return bits;
}

// Métodos da classe
void PlacaDeVideo::imprimirProduto() {
  Produto::imprimirProduto();
  cout << "  | Memória: " << memoria << "\n";
  cout << "  | DDR: " << tipoMemoria << "\n";
  cout << "  | Frequência: " << frequencia << "\n";
  cout << "  | Bits: " << bits << "\n\n";
}
