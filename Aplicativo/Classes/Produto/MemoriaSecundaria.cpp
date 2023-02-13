#include "MemoriaSecundaria.h"
#include <string>

// Métodos de sobrecarga do construtor
MemoriaSecundaria::MemoriaSecundaria(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  string tipo,
  int capacidade
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setTipo(tipo);
  setCapacidade(capacidade);
}

// Método do destrutor
MemoriaSecundaria::~MemoriaSecundaria() {}

// Métodos de salvamento e leitura
void MemoriaSecundaria::serializar(ostream &os) {
  Produto::serializar(os);
  serializarString(os, tipo);
  serializarAny(os, capacidade);
}

void MemoriaSecundaria::desserializar(istream &is) {
  Produto::desserializar(is);
  desserializarString(is, tipo);
  setCapacidade(desserializarAny<int>(is));
}

// Métodos de modificação dos atributos
void MemoriaSecundaria::setTipo(string tipo) {
  this->tipo = tipo;
}
void MemoriaSecundaria::setCapacidade(int capacidade) {
  this->capacidade = capacidade;
}

// Métodos de retorno dos atributos
string MemoriaSecundaria::getTipo() const {
  return tipo;
}

int MemoriaSecundaria::getCapacidade() const {
  return capacidade;
}

// Métodos da classe
vector<vector<string>> MemoriaSecundaria::imprimirProduto() {
  vector<vector<string>> dadosProduto = Produto::imprimirProduto();

  dadosProduto[1].insert(
    dadosProduto[1].end(),
    { 
      "Tipo: " + tipo, 
      "Capacidade: " + to_string(capacidade) + "GB"
    }
  );
  return dadosProduto;
}
