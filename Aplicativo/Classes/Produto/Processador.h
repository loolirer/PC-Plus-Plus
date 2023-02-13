#ifndef Processador_H
#define Processador_H

#include "Produto.h"

class Processador: public Produto {
  private:
    // Atributos
    int cores;
    int threads;
    float frequencia;
    string socket;

  public:
    // Métodos de sobrecarga do construtor
    Processador (
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0,
      int cores = 0,
      int threads = 0,
      float frequencia = 0,
      string socket = ""
    );

    // Método do destrutor
    ~Processador();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setCores(int cores);
    void setThreads(int threads);
    void setFrequencia(float frequencia);
    void setSocket(string socket);

    // Métodos de retorno dos atributos
    int getCores() const;
    int getThreads() const;
    float getFrequencia() const;
    string getSocket() const;

    // Métodos da classe
    virtual vector<vector<string>> imprimirProduto() override;
};

#endif
