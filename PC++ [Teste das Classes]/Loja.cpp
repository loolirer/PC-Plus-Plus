#include <algorithm>
#include <fstream>

#include "Loja.h"

// Remover Futuramente ??
#include <iomanip>
#include <cstring>
#include <sstream>
#include <ctime> 

// Remover Todos Futuramente
// Apenas Para Testes
#include "Serializador.cpp"
#include "Produto.cpp"
#include "Processador.cpp"
#include "PlacaMae.cpp"
#include "MemoriaRAM.cpp"
#include "FonteDeAlimentacao.cpp"
#include "PlacaDeVideo.cpp"
#include "MemoriaSecundaria.cpp"
#include "Gabinete.cpp"
#include "Usuario.cpp"
#include "Administrador.cpp"
#include "Cliente.cpp"

Loja::Loja() {
  lerEstoque();
  lerClientes();
  lerAdministradores();
}

Loja::~Loja() {
  //escreverEstoque();
  escreverClientes();
  escreverAdministradores();
  cout << "Objeto Loja Destruido!" << endl;
}

bool Loja::adicionarProduto(Produto* produto, int quantidade) {  
  if (procuraProduto(produto->getID()) != -1) {
    int quantidadeAtual = produto->getQuantidade();
    produto->setQuantidade(quantidadeAtual);
    return true;
  }
  
  produtos.push_back(produto);
  return true;
}

bool Loja::removerProduto(string ID) {
  for (unsigned i = 0; i < produtos.size(); i++) {
    if (ID == produtos[i]->getID()) {
      produtos.erase(produtos.begin() + i);
      return true;
    }
  }

  return false;
}

int Loja::procuraProduto(string ID) {
  for (unsigned i = 0; i < produtos.size(); i++) {
    if (ID == produtos[i]->getID()) {
      return i;
    }
  }

  return -1;
}

bool Loja::adicionarCliente(Cliente cliente) {
  for (unsigned i = 0; i < clientes.size(); i++) {
    if (cliente.getEmail() == clientes[i].getEmail())
      return false;
  }

  clientes.push_back(cliente);
  return true;
}

bool Loja::adicionarAdministrador(Administrador administrador) {
  for (unsigned i = 0; i < administradores.size(); i++) {
    if (administrador.getEmail() == administradores[i].getEmail())
      return false;
  }

  administradores.push_back(administrador);
  return true;
}

void Loja::ordenarPorPreco() {
  sort(
    produtos.begin(),
    produtos.end(),
    [](Produto *produto1, Produto *produto2) {
      return produto2->getPreco() > produto1->getPreco();
    }
  );
}

vector<string> Loja::imprimirEstoque(int tipoProduto) {
  return imprimirProdutoArr[tipoProduto](this);
}

void Loja::serializar(Produto *produto, ostream &os) {
  const auto &tipo = typeid(*produto);
  string nome = tipo.name();
  Serializador::serializarString(os, nome);
  produto->serializar(os);
}

void Loja::desserializar(Produto **produto, istream &is) {
  string nome;
  Serializador::desserializarString(is, nome);

  if (is.eof()) return;

  auto &data = mapSerializar[nome];
  void* raw = new uint8_t[data.size];
  memcpy(raw, data.padrao, data.size);
  *produto = (Produto*)raw;
  (*produto)->desserializar(is);
}

bool Loja::escreverEstoque() {
  ofstream arquivoProdutos("produtos.bin", ios::out | ios::trunc | ios::binary);

  if (arquivoProdutos.is_open()) {
    for (unsigned i = 0; i < produtos.size(); i++)
      serializar(produtos[i], arquivoProdutos);

    arquivoProdutos.close();
    return true;
  }

  return false;
}

bool Loja::escreverClientes() {
  ofstream arquivoClientes("clientes.bin", ios::out | ios::trunc | ios::binary);

  if (arquivoClientes.is_open()) {
    for (unsigned i = 0; i < clientes.size(); i++)
      clientes[i].serializar(arquivoClientes);

    arquivoClientes.close();
    return true;
  }

  return false;
}

bool Loja::escreverAdministradores() {
  ofstream arquivoAdministradores("administradores.bin", ios::out | ios::trunc | ios::binary);

  if (arquivoAdministradores.is_open()) {
    for (unsigned i = 0; i < clientes.size(); i++)
      administradores[i].serializar(arquivoAdministradores);

    arquivoAdministradores.close();
    return true;
  }

  return false;
}

bool Loja::lerEstoque() {
  ifstream arquivoProdutos("produtos.bin", ios::in | ios::binary);

  if (arquivoProdutos.is_open()) {
    while(!arquivoProdutos.eof()) {
      Produto *produto;
      desserializar(&produto, arquivoProdutos);

      if (arquivoProdutos.eof()) break;

      produtos.push_back(produto);
    }

    arquivoProdutos.close();
    return true;
  }

  return false;
}

bool Loja::lerClientes() {
  ifstream arquivoClientes("clientes.bin", ios::in | ios::binary);

  if (arquivoClientes.is_open()) {
    while(!arquivoClientes.eof()) {
      Cliente cliente;
      cliente.desserializar(arquivoClientes);

      if (arquivoClientes.eof()) break;

      clientes.push_back(cliente);
    }

    arquivoClientes.close();
    return true;
  }

  return false;
}

bool Loja::lerAdministradores() {
  ifstream arquivoAdministradores("administradores.bin", ios::in | ios::binary);

  if (arquivoAdministradores.is_open()) {
    while(!arquivoAdministradores.eof()) {
      Administrador administrador;
      administrador.desserializar(arquivoAdministradores);

      if (arquivoAdministradores.eof()) break;

      administradores.push_back(administrador);
    }

    arquivoAdministradores.close();
  }

  return false;
}