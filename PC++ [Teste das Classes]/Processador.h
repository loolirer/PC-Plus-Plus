#ifndef Processador_H
#define Processador_H

#include "Produto.h"

class Processador: public Produto {
  private:
    // Atributos
    int cores;
    int threads;
    float frequencia;
    int cache;
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
      int cache = 0,
      string socket = ""
    );

    // Método do destrutor
    ~Processador();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setCores(int);
    void setThreads(int);
    void setFrequencia(float);
    void setCache(int);
    void setSocket(string);

    // Métodos de retorno dos atributos
    int getCores() const;
    int getThreads() const;
    float getFrequencia() const;
    int getCache() const;
    string getSocket() const;

    // Métodos da classe
    virtual void imprimirProduto() override;
};

#endif
