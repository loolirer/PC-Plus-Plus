#include "Processador.h"

Processador::Processador(
    string modelo,
    string marca,
    string ID,
    float preco,
    int quantidade,
    int cores,
    int threads,
    float frequencia,
    int cache,
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
    setCache(cache);
    setSocket(socket);
}

Processador::~Processador (){
    cout << "Objeto Processador Destruido!" << endl;
}

void Processador::serializar(ostream &os) {
    Produto::serializar(os);
    serializarAny(cores, os);
    serializarAny(threads, os);
    serializarAny(frequencia, os);
    serializarAny(cache, os);
    serializarString(socket, os);
}

void Processador::desserializar(istream &is) {
    Produto::desserializar(is);
    setCores(desserializarAny<int>(is));
    setThreads(desserializarAny<int>(is));
    setFrequencia(desserializarAny<float>(is));
    setCache(desserializarAny<int>(is));
    desserializarString(is, socket);
}

void Processador::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Cores: " << cores << endl;
	cout << "  | Threads: " << threads << endl;
	cout << "  | Frequencia: " << frequencia << endl;
	cout << "  | Cache: " << cache << endl;
	cout << "  | Socket: " << socket << endl << endl;
}

void Processador::setCores(int cores){
    this->cores = cores;
}

void Processador::setThreads(int threads){
    this->threads = threads;
}

void Processador::setFrequencia(float frequencia){
    this->frequencia = frequencia;
}

void Processador::setCache(int cache){
    this->cache = cache;
}

void Processador::setSocket(string socket){
    this->socket = socket;
}

int Processador::getCores(){
    return cores;
}

int Processador::getThreads(){
    return threads;
}

float Processador::getFrequencia(){
    return frequencia;
}

int Processador::getCache(){
    return cache;
}

string Processador::getSocket(){
    return socket;
}