#include "Produto.h"

Produto::Produto(
    string modelo,
    string marca,
    string ID,
    float preco,
    int quantidade
) {
    setModelo(modelo);
    setMarca(marca);
    setID(ID);
    setPreco(preco);
    setQuantidade(quantidade);
};

/*Produto::~Produto() {
    cout << "Objeto Produto Destruido!" << endl;
}*/

void Produto::serializar(ostream &os) {
    serializarString(os, { &modelo, &marca, &ID });
    serializarAny(preco, os);
    serializarAny(quantidade, os);
}

void Produto::desserializar(istream &is) {
    desserializarString(is, { &modelo, &marca, &ID });
    setPreco(desserializarAny<float>(is));
    setQuantidade(desserializarAny<int>(is));
}

void Produto::imprimirProduto(int index) {
    cout << index << ". " << marca << " " << modelo << endl;
    cout << "  | ID: " << ID << endl;
    cout << "  | Preço: R$" << preco << endl;
    cout << "  | Quantidade: " << quantidade << endl;
}

void Produto::setModelo(string modelo) {
    this->modelo = modelo;
};

void Produto::setMarca(string marca) {
    this->marca = marca;
};

void Produto::setID(string ID) {
    this->ID = ID;
}

void Produto::setPreco(float preco) {
    this->preco = preco;
}

void Produto::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

string Produto::getModelo() {
    return this->modelo;
}

string Produto::getMarca() {
    return this->marca;
}

string Produto::getID() {
    return this->ID;
}

float Produto::getPreco() {
    return this->preco;
}

int Produto::getQuantidade() {
    return this->quantidade;
}