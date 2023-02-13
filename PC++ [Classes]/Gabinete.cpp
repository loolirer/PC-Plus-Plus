#include "Gabinete.h"

Gabinete::Gabinete(
    string modelo,
    string marca,
    string ID,
    float preco,
    int quantidade,
    string fatorForma,
    string tamanho,
    bool cooler
): Produto(
    modelo,
    marca,
    ID,
    preco,
    quantidade
) {
    setFatorForma(fatorForma);
    setTamanho(tamanho);
    setCooler(cooler);
}

Gabinete::~Gabinete() {
    cout << "Objeto Gabinete Destruido!" << endl;
}

void Gabinete::serializar(ostream &os) {
    Produto::serializar(os);
    serializarString(os, { &fatorForma, &tamanho });
    serializarAny(cooler, os);
}

void Gabinete::desserializar(istream &is) {
    Produto::desserializar(is);
    desserializarString(is, { &fatorForma, &tamanho });
    setCooler(desserializarAny<bool>(is));
}

void Gabinete::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Fator Forma: " << fatorForma << endl;
    cout << "  | Tamanho: " << tamanho << endl;
    cout << "  | Cooler: " << (cooler ? "Sim" : "Não") << endl;
}

void Gabinete::setFatorForma(string fatorForma) {
    this->fatorForma = fatorForma;
}

void Gabinete::setTamanho(string tamanho) {
    this->tamanho = tamanho;
}

void Gabinete::setCooler(bool cooler)
{
    this->cooler = cooler;
}

string Gabinete::getFatorForma() {
    return fatorForma;
}

string Gabinete::getTamanho() {
    return tamanho;
}

bool Gabinete::getCooler() {
    return cooler;
}
