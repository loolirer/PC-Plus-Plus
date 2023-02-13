#ifndef CLIENTE_H // Início do cabeçalho do arquivo CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Usuario.h"

using namespace std;

class Cliente: public Usuario {
    private:
        string cpf;
        string endereco;
        float saldo;

    public:
        Cliente(
            string email = "",
            string senha = "",
            string cpf = "",
            string endereco = "",
            float saldo = 0.0
        );
        ~Cliente();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        void setCpf(string);
        void setEndereco(string);
        void setSaldo(float);

        string getEndereco();
        string getCpf();
        float getSaldo();
};

#endif
