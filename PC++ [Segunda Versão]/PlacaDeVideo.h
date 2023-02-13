#ifndef PlacaDeVideo_H
#define PlacaDeVideo_H

#include "Produto.h"

class PlacaDeVideo: public Produto {
  private:
    // Atributos
    unsigned short int memoria;
    string tipoMemoria;
    unsigned short int frequencia;
    unsigned short int bits;

  public:
    // Métodos de sobrecarga do construtor
    PlacaDeVideo(
      string modelo = "",
      string marca = "",
      string ID = "",
      float preco = 0,
      int quantidade = 0,
      unsigned short int memoria = 0,
      string tipoMemoria = "",
      unsigned short int frequencia = 0,
      unsigned short int bits = 0
    );

    // Método do destrutor
    ~PlacaDeVideo();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setMemoria(unsigned short int memoria);
    void setTipoMemoria(string tipoMemoria);
    void setFrequencia(unsigned short int frequencia);
    void setBits(unsigned short int bits);

    // Métodos de retorno dos atributos
    unsigned short int getMemoria() const;
    string getTipoMemoria() const;
    unsigned short int getFrequencia() const;
    unsigned short int getBits() const;

    // Métodos da classe
    virtual void imprimirProduto() override;
};

#endif
