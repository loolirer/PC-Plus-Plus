#ifndef Produto_H
#define Produto_H

#include "Serializador.h"
#include <iostream>

class Produto: public Serializador {
  private:
    // Atributos
    string modelo;
    string marca;
    string ID;
    float preco;
    int quantidade;

  public:
    // Métodos de sobrecarga do construtor
    Produto(
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0
    );

    // Método virtual do destrutor
    virtual ~Produto() = default;

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os);
    virtual void desserializar(istream &is);

    // Métodos de modificação dos atributos
    void setModelo(string modelo);
    void setMarca(string marca);
    void setID(string ID);
    void setPreco(float preco);
    void setQuantidade(int quantidade);

    // Métodos de retorno dos atributos
    string getModelo() const;
    string getMarca() const;
    string getID() const;
    float getPreco() const;
    int getQuantidade() const;

    // Métodos da classe
    virtual void imprimirProduto();
};

#endif
