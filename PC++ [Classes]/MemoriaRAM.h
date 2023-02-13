#ifndef MEMORIARAM_H
#define MEMORIARAM_H

#include "Produto.h"

class MemoriaRAM: public Produto {
    private:
        string tipo;
        int capacidade;
        int frequencia;
        int DDR ;
    
    public:
        MemoriaRAM(
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0,
            string tipo = "",
            int capacidade = 0,
            int frequencia = 0,
            int DDR = 0
        );
        ~MemoriaRAM();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;

        void setTipo(string);
        void setCapacidade(int);
        void setFrequencia(int);
        void setDDR(int);

        string getTipo();
        int getCapacidade();
        int getFrequencia();
        int getDDR();

};

#endif