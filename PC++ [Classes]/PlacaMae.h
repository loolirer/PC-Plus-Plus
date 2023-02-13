#ifndef PLACAMAE_H
#define PLACAMAE_H

#include "Produto.h"

class PlacaMae: public Produto{
    private:
        string plataforma;
        string socket;
        string memoria;
        string chipset;
        string fatorForma;
    
    public:
        PlacaMae(
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0,
            string plataforma = "",
            string socket = "",
            string memoria = "",
            string chipset = "",
            string fatorForma = ""
        );
        ~PlacaMae();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;

        void setPlataforma(string);
        void setSocket(string);
        void setMemoria(string);
        void setChipset(string);
        void setFatorForma(string);

        string getPlataforma ();
        string getSocket();
        string getMemoria();
        string getChipset();
        string getFatorForma();
};

#endif