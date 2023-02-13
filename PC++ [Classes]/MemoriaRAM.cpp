#include "MemoriaRAM.h"

MemoriaRAM::MemoriaRAM(
    string modelo,
    string marca,
    string ID,
    float preco,
    int quantidade,
    string tipo,
    int capacidade,
    int frequencia,
    int DDR
): Produto(
    modelo,
    marca,
    ID,
    preco,
    quantidade
) {
    setTipo(tipo);
    setCapacidade(capacidade);
    setFrequencia(frequencia);
    setDDR(DDR);
}

MemoriaRAM::~MemoriaRAM(){
    cout << "Objeto MemoriaRAM Destruido!" << endl;
}

void MemoriaRAM::serializar(ostream &os) {
    Produto::serializar(os);
    serializarString(tipo, os);
    serializarAny(capacidade, os);
    serializarAny(frequencia, os);
    serializarAny(DDR, os);
}

void MemoriaRAM::desserializar(istream &is) {
    Produto::desserializar(is);
    desserializarString(is, tipo);
    setCapacidade(desserializarAny<int>(is));
    setFrequencia(desserializarAny<int>(is));
    setDDR(desserializarAny<int>(is));
}

void MemoriaRAM::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Tipo: " << tipo << endl;
    cout << "  | Capacidade: " << capacidade << endl;
    cout << "  | Frequencia: " << frequencia << endl;
    cout << "  | DDR: " << DDR << endl;
}

void MemoriaRAM::setTipo(string tipo) {
    this->tipo = tipo;
}

void MemoriaRAM::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

void MemoriaRAM::setFrequencia(int frequencia) {
    this->frequencia = frequencia;
}

void MemoriaRAM::setDDR(int DDR) {
    this->DDR = DDR;
}

string MemoriaRAM::getTipo() {
    return tipo;
}

int MemoriaRAM::getCapacidade() {
    return capacidade;
}

int MemoriaRAM::getFrequencia() {
    return frequencia;
}

int MemoriaRAM::getDDR() {
    return DDR;
}
