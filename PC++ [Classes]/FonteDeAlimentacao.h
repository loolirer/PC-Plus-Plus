#ifndef FONTEDEALIMENTACAO_H
#define FONTEDEALIMENTACAO_H

#include "Produto.h"

class FonteDeAlimentacao: public Produto {
    private:
        int tensao;
        int potencia;
        string fatorForma;

    public:
        FonteDeAlimentacao(
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0,
            int tensao = 0,
            int potencia = 0,
            string fatorForma = ""
        );
        ~FonteDeAlimentacao();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;

        void setTensao(int tensao);
        void setPotencia(int potencia);
        void setFatorForma(string fatorForma);

        int getTensao();
        int getPotencia();
        string getFatorForma();
};

#endif