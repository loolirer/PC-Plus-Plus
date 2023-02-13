#include "Loja.h"

Loja::Loja() {
  lerEstoque();
  lerClientes();
  lerAdministradores();
}

Loja::~Loja() {
  //escreverEstoque();
  escreverClientes();
  escreverAdministradores();

  for (auto produto: produtos)
    delete produto;
}

bool Loja::adicionarProduto(Produto* produto, int quantidade) {
  if (procuraProduto(produto->getID()) != -1) {
    int quantidadeAtual = produto->getQuantidade();
    produto->setQuantidade(quantidadeAtual + quantidade);
    return true;
  }

  produtos.push_back(produto);
  return true;
}

bool Loja::removerProduto(Produto* produto, int quantidade) {
  for (unsigned i = 0; i < produtos.size(); i++)
    if (produto->getID() == produtos[i]->getID()) {
      if(quantidade >= produtos[i]->getQuantidade())
        produtos.erase(produtos.begin() + i);
      else
        produtos[i]->setQuantidade(produtos[i]->getQuantidade() - quantidade);
      return true;
    }
  return false;
}

bool Loja::removerProdutos(vector<Produto> itens) {
  for (auto I : itens)
    if(!removerProduto(&I, I.getQuantidade()))
      return false;
  return true;
}

int Loja::procuraProduto(string ID) {
  for (unsigned i = 0; i < produtos.size(); i++) {
    if (ID == produtos[i]->getID()) {
      return i;
    }
  }

  return -1;
}

Produto* Loja::getProduto(string ID) {
  int indiceProduto = procuraProduto(ID);

  if (indiceProduto == -1)
    return nullptr;

  return produtos[indiceProduto];
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

Cliente* Loja::loginCliente(string email, string senha) {
  for (int c = 0; c < clientes.size(); c++)
    if (email == clientes[c].getEmail())
      if (clientes[c].conferirLogin(email, senha))
        return &clientes[c];
  return nullptr;
}

Administrador* Loja::loginAdministrador(string email, string senha) {
  for (int a = 0; a < administradores.size(); a++)
    if (email == administradores[a].getEmail())
      if (administradores[a].conferirLogin(email, senha))
        return &administradores[a];
  return nullptr;
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

vector<string> Loja::imprimirEstoque(int tipoProduto, int tipoDado, string comparador) {
  this->ordenarPorPreco();
  return imprimirProdutoArr[tipoProduto](this, tipoDado, comparador);
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
