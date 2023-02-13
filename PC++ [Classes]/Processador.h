#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "Produto.h"

class Processador: public Produto{
    private:
        int cores;
        int threads;
        float frequencia;
        int cache;
        string socket;
    
    public:
        Processador (
            string modelo = "",
            string marca = "",
            string ID = "",
            float preco = 0,
            int quantidade = 0,
            int cores = 0,
            int threads = 0,
            float frequencia = 0,
            int cache = 0,
            string socket = ""
        );
        ~Processador();

        virtual void serializar(ostream &os) override;
        virtual void desserializar(istream &is) override;

        virtual void imprimirProduto(int index) override;

        void setCores(int);
        void setThreads(int);
        void setFrequencia(float);
        void setCache(int);
        void setSocket(string);
        
        int getCores();
        int getThreads();
        float getFrequencia();
        int getCache();
        string getSocket();

};

#endif