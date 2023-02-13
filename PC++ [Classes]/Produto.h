#ifndef PRODUTO_H
#define PRODUTO_H

#include "Serializador.h"
#include <iostream>

class Produto: public Serializador {
    private:
        string modelo;
        string marca;
        string ID;
        float preco;
        int quantidade;

    public:
        Produto(
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0
        );
        virtual ~Produto() = default;

        virtual void serializar(ostream &os);
        virtual void desserializar(istream &is);

        virtual void imprimirProduto(int index);

        void setModelo(string modelo);
        void setMarca(string marca);
        void setID(string ID);
        void setPreco(float preco);
        void setQuantidade(int quantidade);

        string getModelo();
        string getMarca();
        string getID();
        float getPreco();
        int getQuantidade();
};

#endif