#ifndef Gabinete_H
#define Gabinete_H

#include "Produto.h"

class Gabinete: public Produto {
  private:
    // Atributos
    string fatorForma;
    string tamanho;
    bool cooler;

  public:
    // Métodos de sobrecarga do construtor
    Gabinete(
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0,
      string fatorForma = "",
      string tamanho = "",
      bool cooler = 0
    );

    // Método do destrutor
    ~Gabinete();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setFatorForma(string);
    void setTamanho(string);
    void setCooler(bool);

    // Métodos de retorno dos atributos
    string getFatorForma() const;
    string getTamanho() const;
    bool getCooler() const;

    // Métodos da classe
    virtual void imprimirProduto() override;
};

#endif
