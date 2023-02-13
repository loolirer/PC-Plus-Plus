#ifndef Pedido_H
#define Pedido_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Produto.h"
#include "Cliente.h"

using namespace std;

class Pedido {
private:
  // Atributos
  Cliente* cliente;
  vector<Produto> itens;
  float precoTotal;
  string data;
  string pagamento;
  string cupom;

  // Funções utilitários
  int procurarItem(Produto produto);
  void calcularTotal();
  void atualizarData();
  void gerarCupom();

public:
  // Métodos de sobrecarga do construtor
  Pedido();
  Pedido(Cliente* cliente);

  // Método do destrutor
  ~Pedido();

  // Métodos de modificação dos atributos
  void setPrecoTotal(float precoTotal);
  void setData(string data);
  void setPagamento(string pagamento);
  void setCupom(string cupom);

  // Métodos de retorno dos atributos
  float getPrecoTotal();
  string getData();
  string getPagamento();
  string getCupom();

  // Métodos da classe
  bool adicionarItens(Produto produto, int quantidade);
  bool removerItens(Produto produto, int quantidade);
  void imprimirPedido();
  bool realizarPedido(string pagamento);
};

#endif
