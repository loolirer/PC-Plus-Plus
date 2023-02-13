#include "Processador.h"

// Métodos de sobrecarga do construtor
Processador::Processador(
  string modelo,
  string marca,
  string ID,
  float preco,
  int quantidade,
  int cores,
  int threads,
  float frequencia,
  string socket
): Produto(
  modelo,
  marca,
  ID,
  preco,
  quantidade
) {
  setCores(cores);
  setThreads(threads);
  setFrequencia(frequencia);
  setSocket(socket);
}

// Método do destrutor
Processador::~Processador () {}

// Métodos de salvamento e leitura
void Processador::serializar(ostream &os) {
  Produto::serializar(os);
  serializarAny(os, cores);
  serializarAny(os, threads);
  serializarAny(os, frequencia);
  serializarString(os, socket);
}

void Processador::desserializar(istream &is) {
  Produto::desserializar(is);
  setCores(desserializarAny<int>(is));
  setThreads(desserializarAny<int>(is));
  setFrequencia(desserializarAny<float>(is));
  desserializarString(is, socket);
}

// Métodos de modificação dos atributos
void Processador::setCores(int cores) {
  this->cores = cores;
}

void Processador::setThreads(int threads) {
  this->threads = threads;
}

void Processador::setFrequencia(float frequencia) {
  this->frequencia = frequencia;
}

void Processador::setSocket(string socket) {
  this->socket = socket;
}

// Métodos de retorno dos atributos
int Processador::getCores() const {
  return cores;
}

int Processador::getThreads() const {
  return threads;
}

float Processador::getFrequencia() const {
  return frequencia;
}

string Processador::getSocket() const {
  return socket;
}

// Métodos da classe
void Processador::imprimirProduto() {
  Produto::imprimirProduto();
  cout << "  | Cores: " << cores << "\n";
  cout << "  | Threads: " << threads << "\n";
  cout << "  | Frequencia: " << frequencia << "\n";
  cout << "  | Socket: " << socket << "\n\n";
}
