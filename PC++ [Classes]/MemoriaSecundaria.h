#ifndef MEMORIASECUNDARIA_H
#define MEMORIASECUNDARIA_H

#include "Produto.h"

class MemoriaSecundaria: public Produto {
    private:
        string tipo;
        int capacidade;

    public:
        MemoriaSecundaria(
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0,
            string tipo = "",
            int capacidade = 0
        );
        ~MemoriaSecundaria();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;

        void setTipo(string tipo);
        void setCapacidade(int capacidade);

        string getTipo();
        int getCapacidade();

};


#endif
