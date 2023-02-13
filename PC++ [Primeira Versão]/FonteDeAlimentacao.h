#ifndef FonteDeAlimentacao_H
#define FonteDeAlimentacao_H

#include "Produto.h"

class FonteDeAlimentacao: public Produto {
  private:
    // Atributos
    int potencia;
    string fatorForma;

  public:
    // Métodos de sobrecarga do construtor
    FonteDeAlimentacao(
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0,
      int potencia = 0,
      string fatorForma = ""
    );

    // Método do destrutor
    ~FonteDeAlimentacao();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setPotencia(int potencia);
    void setFatorForma(string fatorForma);

    // Métodos de retorno dos atributos
    int getPotencia() const;
    string getFatorForma() const;

    // Métodos da classe
    virtual void imprimirProduto() override;
};

#endif
