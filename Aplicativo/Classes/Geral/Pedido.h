#ifndef Pedido_H
#define Pedido_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

#include "InterfaceGrafica.h"

#include "../Produto/Produto.h"
#include "../Usuario/Cliente.h"

using namespace std;

class Pedido {
  private:
    // Atributos
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

    // Método do destrutor
    ~Pedido();

    // Métodos de modificação dos atributos
    void setPrecoTotal(float precoTotal);
    void setData(string data);
    void setPagamento(string pagamento);
    void setCupom(string cupom);

    // Métodos de retorno dos atributos
    float getPrecoTotal() const;
    string getData() const;
    string getPagamento() const;

    // Métodos da classe
    Produto* getItem(int indice);
    bool adicionarItens(Produto produto, int quantidade);
    bool removerItens(Produto produto, int quantidade);
    int imprimirPedido(InterfaceGrafica interfaceGrafica, bool navegar = false);
    vector<Produto> realizarPedido(Cliente* cliente, string pagamento);
};

#endif
