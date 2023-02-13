#ifndef MemoriaRAM_H
#define MemoriaRAM_H

#include "Produto.h"

class MemoriaRAM: public Produto {
  private:
    // Atributos
    int capacidade;
    int frequencia;
    int DDR;

  public:
    // Métodos de sobrecarga do construtor
    MemoriaRAM(
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0,
      int capacidade = 0,
      int frequencia = 0,
      int DDR = 0
    );

    // Método do destrutor
    ~MemoriaRAM();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setCapacidade(int);
    void setFrequencia(int);
    void setDDR(int);

    // Métodos de retorno dos atributos
    int getCapacidade() const;
    int getFrequencia() const;
    int getDDR() const;

    // Métodos da classe
    virtual void imprimirProduto() override;
};

#endif
