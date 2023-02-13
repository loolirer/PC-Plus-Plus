#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H

#include <fstream>
#include <string>

using namespace std;

class Serializador {
    public:
        virtual void serializar(ostream &os) = 0;
        virtual void desserializar(istream &is) = 0;

        template <typename T>
        static void serializarAny(T value, ostream &os) {
            os.write((char*)&value, sizeof(T));
        }

        template <typename T>
        static T desserializarAny(istream &is) {
            T result;
            is.read((char*)&result, sizeof(T));
            return result;
        }

        static void serializarString(const string &str, ostream &os);
        static void serializarString(ostream &os, initializer_list<string*> strings);
        
        static void desserializarString(istream &is, string& str);
        static void desserializarString(istream &is, initializer_list<string*> strings);
};

#endif