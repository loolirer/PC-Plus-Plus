#include "Produto.h"
#include <sstream>

// Métodos de sobrecarga do construtor
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

// Métodos de salvamento e leitura
void Produto::serializar(ostream &os) {
  serializarString(os, { &modelo, &marca, &ID });
  serializarAny(os, preco);
  serializarAny(os, quantidade);
}

void Produto::desserializar(istream &is) {
  desserializarString(is, { &modelo, &marca, &ID });
  setPreco(desserializarAny<float>(is));
  setQuantidade(desserializarAny<int>(is));
}

// Métodos de modificação dos atributos
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

// Métodos de retorno dos atributos
string Produto::getModelo() const {
  return modelo;
}

string Produto::getMarca() const {
  return marca;
}

string Produto::getID() const {
  return ID;
}

float Produto::getPreco() const {
  return preco;
}

int Produto::getQuantidade() const {
  return quantidade;
}

// Métodos da classe
vector<vector<string>> Produto::imprimirProduto() {
  stringstream precoStream;
  precoStream << fixed << setprecision(2) << preco;

  return vector<vector<string>> {
    { marca + " " + modelo },
    { 
      "Marca: " + marca, 
      "Modelo: " + modelo, 
      "ID: " + ID, 
      "Preço: R$" + precoStream.str(), 
      "Quantidade: " + to_string(quantidade)
    }
  };
}
