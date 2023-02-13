#ifndef GABINETE_H
#define GABINETE_H

#include "Produto.h"

class Gabinete :public Produto{
    private:
        string fatorForma;
        string tamanho;
        bool cooler;

    public:
        Gabinete(
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0,
            string fatorForma = "",
            string tamanho = "",
            bool cooler = 0
        );
        ~Gabinete();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;
        
        void setFatorForma(string);
        void setTamanho(string);
        void setCooler(bool);

        string getFatorForma();
        string getTamanho();
        bool getCooler();

};


#endif
