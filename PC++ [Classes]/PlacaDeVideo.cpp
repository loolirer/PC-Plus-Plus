#include "PlacaDeVideo.h"

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

PlacaDeVideo::~PlacaDeVideo() {
    cout << "Objeto PlacaDeVideo Destruido!" << endl;
}

void PlacaDeVideo::serializar(ostream &os) {
    Produto::serializar(os);
    serializarAny(memoria, os);
    serializarString(tipoMemoria, os);
    serializarAny(frequencia, os);
    serializarAny(bits, os);
}

void PlacaDeVideo::desserializar(istream &is) {
    Produto::desserializar(is);
    setMemoria(desserializarAny<unsigned short int>(is));
    desserializarString(is, tipoMemoria);
    setFrequencia(desserializarAny<unsigned short int>(is));
    setBits(desserializarAny<unsigned short int>(is));
}

void PlacaDeVideo::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Memória: " << memoria << endl;
    cout << "  | DDR: " << tipoMemoria << endl;
    cout << "  | Frequência: " << frequencia << endl;
    cout << "  | Bits: " << bits << endl;
}

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

unsigned short int PlacaDeVideo::getMemoria() {
    return memoria;
}

string PlacaDeVideo::getTipoMemoria() {
    return tipoMemoria;
}

unsigned short int PlacaDeVideo::getFrequencia() {
    return frequencia;
}

unsigned short int PlacaDeVideo::getBits() {
    return bits;
}
