#include "MemoriaRAM.h"

// Métodos de sobrecarga do construtor
MemoriaRAM::MemoriaRAM(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  int capacidade,
  int frequencia,
  string DDR
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setCapacidade(capacidade);
  setFrequencia(frequencia);
  setDDR(DDR);
}

// Método do destrutor
MemoriaRAM::~MemoriaRAM() {}

// Métodos de salvamento e leitura
void MemoriaRAM::serializar(ostream &os) {
  Produto::serializar(os);
  serializarAny(os, capacidade);
  serializarAny(os, frequencia);
  serializarString(os, DDR);
}

void MemoriaRAM::desserializar(istream &is) {
  Produto::desserializar(is);
  setCapacidade(desserializarAny<int>(is));
  setFrequencia(desserializarAny<int>(is));
  desserializarString(is, DDR);
}

// Métodos de modificação dos atributos
void MemoriaRAM::setCapacidade(int capacidade) {
  this->capacidade = capacidade;
}

void MemoriaRAM::setFrequencia(int frequencia) {
  this->frequencia = frequencia;
}

void MemoriaRAM::setDDR(string DDR) {
  this->DDR = DDR;
}

// Métodos de retorno dos atributos
int MemoriaRAM::getCapacidade() const {
  return capacidade;
}

int MemoriaRAM::getFrequencia() const {
  return frequencia;
}

string MemoriaRAM::getDDR() const {
  return DDR;
}

// Métodos da classe
void MemoriaRAM::imprimirProduto() {
  Produto::imprimirProduto();
  cout << "  | Capacidade: " << capacidade << "\n";
  cout << "  | Frequencia: " << frequencia << "\n";
  cout << "  | DDR: " << DDR << "\n\n";
}
