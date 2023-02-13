#ifndef MemoriaRAM_H
#define MemoriaRAM_H

#include "Produto.h"

class MemoriaRAM: public Produto {
  private:
    // Atributos
    int capacidade;
    int frequencia;
    string DDR;

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
      string DDR = ""
    );

    // Método do destrutor
    ~MemoriaRAM();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setCapacidade(int capacidade);
    void setFrequencia(int frequencia);
    void setDDR(string DDR);

    // Métodos de retorno dos atributos
    int getCapacidade() const;
    int getFrequencia() const;
    string getDDR() const;

    // Métodos da classe
    virtual vector<vector<string>> imprimirProduto() override;
};

#endif
