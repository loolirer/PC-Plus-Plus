#include "Processador.h"
#include <sstream>

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
vector<vector<string>> Processador::imprimirProduto() {
  vector<vector<string>> dadosProduto = Produto::imprimirProduto();

  stringstream frequenciaStream;
  frequenciaStream << fixed << setprecision(2) << frequencia;

  dadosProduto[1].insert(
    dadosProduto[1].end(),
    {
      "Quantidade de Núcleos: " + to_string(cores),
      "Quantidade de Threads: " + to_string(threads),
      "Frequência: " + frequenciaStream.str() + "GHz",
      "Socket: " + socket
    }
  );
  return dadosProduto;
}
