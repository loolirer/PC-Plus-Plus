#ifndef PLACADEVIDEO_H
#define PLACADEVIDEO_H

#include "Produto.h"

class PlacaDeVideo :public Produto{

    private:
        unsigned short int memoria;
        string tipoMemoria;
        unsigned short int frequencia;
        unsigned short int bits;

    public:
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
        ~PlacaDeVideo();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;

        void setMemoria(unsigned short int memoria);
        void setTipoMemoria(string tipoMemoria);
        void setFrequencia(unsigned short int frequencia);
        void setBits(unsigned short int bits);

        unsigned short int getMemoria();
        string getTipoMemoria();
        unsigned short int getFrequencia();
        unsigned short int getBits();

};


#endif
