#include "PlacaMae.h"

PlacaMae::PlacaMae(
    string modelo,
    string marca,
    string ID,
    float preco,
    int quantidade,
    string plataforma,
    string socket,
    string memoria,
    string chipset,
    string fatorForma
): Produto(
    modelo,
    marca,
    ID,
    preco,
    quantidade
) {
    setPlataforma(plataforma);
    setSocket(socket);
    setMemoria(memoria);
    setChipset(chipset);
    setFatorForma(fatorForma);
}

PlacaMae::~PlacaMae(){
    cout << "Objeto PlacaMae Destruido!" << endl;
}

void PlacaMae::serializar(ostream &os) {
    Produto::serializar(os);
    serializarString(os, { &plataforma, &socket, &memoria, &chipset, &fatorForma });
}

void PlacaMae::desserializar(istream &is) {
    Produto::desserializar(is);
    desserializarString(is, {&plataforma, &socket, &memoria, &chipset, &fatorForma});
}

void PlacaMae::imprimirProduto(int index) {
    Produto::imprimirProduto(index);
    cout << "  | Plataforma: " << plataforma << endl;
	cout << "  | Socket: " << socket << endl;
	cout << "  | Memoria: " << memoria << endl;
	cout << "  | Chipset: " << chipset << endl;
	cout << "  | Fator Forma: " << fatorForma << endl;
}

void PlacaMae::setPlataforma(string plataforma){
    this->plataforma = plataforma;
}

void PlacaMae::setSocket(string socket){
    this->socket = socket;
}

void PlacaMae::setMemoria(string memoria){
    this->memoria = memoria;
}

void PlacaMae::setChipset(string chipset){
    this->chipset = chipset;
}

void PlacaMae::setFatorForma(string fatorForma){
    this->fatorForma = fatorForma;
}

string PlacaMae::getPlataforma(){
    return plataforma;
}

string PlacaMae::getSocket(){
    return socket;
}

string PlacaMae::getMemoria(){
    return memoria;
}

string PlacaMae::getChipset(){
    return chipset;
}

string PlacaMae::getFatorForma(){
    return fatorForma;
}