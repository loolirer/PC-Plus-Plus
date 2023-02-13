#ifndef USUARIO_H
#define USUARIO_H

#include "Serializador.h"
#include <string>

using namespace std;

class Usuario: public Serializador {
    protected:
        string email;
        string senha;
    public:
        Usuario(
            string email = "",
            string senha = ""
        );
        virtual ~Usuario();
        
        virtual void serializar(ostream &os);
        virtual void desserializar(istream &is);

        bool conferirLogin(string, string);
        
        void setEmail(string);
        void setSenha(string);

        string getEmail();
};

#endif