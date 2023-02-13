#include "Produto.h"

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
void Produto::imprimirProduto() {
  cout << marca << " " << modelo << endl;
  cout << "  | ID: " << ID << endl;
  cout << "  | Preço: R$" << preco << endl;
  cout << "  | Quantidade: " << quantidade << endl;
}
