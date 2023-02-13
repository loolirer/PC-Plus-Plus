#ifndef Usuario_H
#define Usuario_H

#include "Serializador.h"
#include <string>

using namespace std;

class Usuario: public Serializador {
  private:
    // Atributos
    string email;
    string senha;

  public:
    // Métodos de sobrecarga do construtor
    Usuario(
      string email = "",
      string senha = ""
    );

    // Método do destrutor
    virtual ~Usuario();

    // Métodos de salvamento e leitura
    virtual void serializar(ostream &os);
    virtual void desserializar(istream &is);

    // Métodos de modificação dos atributos
    void setEmail(string);
    void setSenha(string);

    // Métodos de retorno dos atributos
    string getEmail() const;

    // Métodos da classe
    bool conferirLogin(string, string) const;
};

#endif
