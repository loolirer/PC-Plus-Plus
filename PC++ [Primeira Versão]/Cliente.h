#ifndef Cliente_H
#define Cliente_H

#include "Usuario.h"

class Cliente: public Usuario {
  private:
    // Atributos
    string cpf;
    string endereco;
    float saldo;

  public:
    // Métodos de sobrecarga do construtor
    Cliente(
      string email = "",
      string senha = "",
      string cpf = "",
      string endereco = "",
      float saldo = 0.0
    );

    // Método do destrutor
    ~Cliente();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os) override;
    virtual void desserializar(istream &is) override;

    // Métodos de modificação dos atributos
    void setCpf(string cpf);
    void setEndereco(string endereco);
    void setSaldo(float saldo);

    // Métodos de retorno dos atributos
    string getEndereco() const;
    string getCpf() const;
    float getSaldo() const;
};

#endif
