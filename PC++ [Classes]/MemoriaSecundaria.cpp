#include "MemoriaSecundaria.h"

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

MemoriaSecundaria::~MemoriaSecundaria(){
    cout << "Objeto MemoriaSecundaria Destruido!" << endl;
}

void MemoriaSecundaria::serializar(ostream &os) {
    Produto::serializar(os);
    serializarString(tipo, os);
    serializarAny(capacidade, os);
}

void MemoriaSecundaria::desserializar(istream &is) {
    Produto::desserializar(is);
    desserializarString(is, tipo);
    setCapacidade(desserializarAny<int>(is));
}

void MemoriaSecundaria::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Tipo: " << tipo << endl;
    cout << "  | Capacidade: " << capacidade << endl;
}

void MemoriaSecundaria::setTipo(string tipo) {
    this->tipo = tipo;
}
void MemoriaSecundaria::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

string MemoriaSecundaria::getTipo() {
    return tipo;
}

int MemoriaSecundaria::getCapacidade() {
    return capacidade;
}

