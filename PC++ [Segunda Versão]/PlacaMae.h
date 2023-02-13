#ifndef PlacaMae_H
#define PlacaMae_H

#include "Produto.h"

class PlacaMae: public Produto {
  private:
    // Atributos
    string plataforma;
    string socket;
    string memoria;
    string fatorForma;

  public:
    // Métodos de sobrecarga do construtor
    PlacaMae(
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0,
      string plataforma = "",
      string socket = "",
      string memoria = "",
      string fatorForma = ""
    );

    // Método do destrutor
    ~PlacaMae();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setPlataforma(string plataforma);
    void setSocket(string socket);
    void setMemoria(string memoria);
    void setFatorForma(string fatorForma);

    // Métodos de retorno dos atributos
    string getPlataforma() const;
    string getSocket() const;
    string getMemoria() const;
    string getFatorForma() const;

    // Métodos da classe
    virtual void imprimirProduto() override;
};

#endif
