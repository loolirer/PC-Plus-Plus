#ifndef MemoriaSecundaria_H
#define MemoriaSecundaria_H

#include "Produto.h"

class MemoriaSecundaria: public Produto {
  private:
    // Atributos
    string tipo;
    int capacidade;

  public:
    // Métodos de sobrecarga do construtor
    MemoriaSecundaria(
        string modelo = "",
        string marca = "",
        string ID = "",
        float preco = 0,
        int quantidade = 0,
        string tipo = "",
        int capacidade = 0
    );

    // Método do destrutor
    ~MemoriaSecundaria();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setTipo(string tipo);
    void setCapacidade(int capacidade);

    // Métodos de retorno dos atributos
    string getTipo() const;
    int getCapacidade() const;

    // Métodos da classe
    virtual vector<vector<string>> imprimirProduto() override;
};

#endif
