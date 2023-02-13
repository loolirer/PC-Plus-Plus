#include "PlacaMae.h"

// Métodos de sobrecarga do construtor
PlacaMae::PlacaMae(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  string plataforma,
  string socket,
  string memoria,
  string fatorForma
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setPlataforma(plataforma);
  setSocket(socket);
  setMemoria(memoria);
  setFatorForma(fatorForma);
}

// Método do destrutor
PlacaMae::~PlacaMae() {}

// Métodos de salvamento e leitura
void PlacaMae::serializar(ostream &os) {
  Produto::serializar(os);
  serializarString(os, { &plataforma, &socket, &memoria, &fatorForma });
}

void PlacaMae::desserializar(istream &is) {
  Produto::desserializar(is);
  desserializarString(is, {&plataforma, &socket, &memoria, &fatorForma});
}

// Métodos de modificação dos atributos
void PlacaMae::setPlataforma(string plataforma) {
  this->plataforma = plataforma;
}

void PlacaMae::setSocket(string socket) {
  this->socket = socket;
}

void PlacaMae::setMemoria(string memoria) {
  this->memoria = memoria;
}

void PlacaMae::setFatorForma(string fatorForma) {
  this->fatorForma = fatorForma;
}

// Métodos de retorno dos atributos
string PlacaMae::getPlataforma() const {
  return plataforma;
}

string PlacaMae::getSocket() const {
  return socket;
}

string PlacaMae::getMemoria() const {
  return memoria;
}

string PlacaMae::getFatorForma() const {
  return fatorForma;
}

vector<vector<string>> PlacaMae::imprimirProduto() {
  vector<vector<string>> dadosProduto = Produto::imprimirProduto();

  dadosProduto[1].insert(
    dadosProduto[1].end(),
    {
      "Plataforma: " + plataforma,
      "Socket: " + socket,
      "Tipo de Memória: " + memoria,
      "Fator Forma: " + fatorForma
    }
  );
  return dadosProduto;
}
