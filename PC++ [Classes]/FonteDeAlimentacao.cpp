#include "FonteDeAlimentacao.h"

FonteDeAlimentacao::FonteDeAlimentacao(
    string modelo,
    string marca,
    string ID,
    float preco,
    int quantidade,
    int tensao,
    int potencia,
    string fatorForma
): Produto(
    modelo,
    marca,
    ID,
    preco,
    quantidade
) {
    setTensao(tensao);
    setPotencia(potencia);
    setFatorForma(fatorForma);
}

FonteDeAlimentacao::~FonteDeAlimentacao() {
    cout << "Objeto FonteDeAlimentacao Destruido!" << endl;
}

void FonteDeAlimentacao::serializar(ostream &os) {
    Produto::serializar(os);
    serializarAny(tensao, os);
    serializarAny(potencia, os);
    serializarString(fatorForma, os);
}

void FonteDeAlimentacao::desserializar(istream &is) {
    Produto::desserializar(is);
    setTensao(desserializarAny<int>(is));
    setPotencia(desserializarAny<int>(is));
    desserializarString(is, fatorForma);
}

void FonteDeAlimentacao::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Tensão: " << tensao << endl;
    cout << "  | Potência: " << potencia << endl;
    cout << "  | Fator Forma: " << fatorForma << endl;
}

void FonteDeAlimentacao::setTensao(int tensao) {
    this->tensao = tensao;
}

void FonteDeAlimentacao::setPotencia(int potencia) {
    this->potencia = potencia;
}

void FonteDeAlimentacao::setFatorForma(string fatorForma) {
    this->fatorForma = fatorForma;
}

int FonteDeAlimentacao::getTensao() {
    return tensao;
}

int FonteDeAlimentacao::getPotencia() {
    return potencia;
}

string FonteDeAlimentacao::getFatorForma() {
    return fatorForma;
}