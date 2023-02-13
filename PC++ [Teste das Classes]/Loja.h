#ifndef LOJA_H
#define LOJA_H

#include <vector>
#include <typeinfo>
#include <unordered_map>
#include <functional>

#include "Produto.h"
#include "Processador.h"
#include "PlacaMae.h"
#include "MemoriaRAM.h"
#include "PlacaDeVideo.h"
#include "MemoriaSecundaria.h"
#include "Gabinete.h"
#include "FonteDeAlimentacao.h"

#include "Cliente.h"
#include "Administrador.h"

using namespace std;

enum tiposDeProdutos {
  PROCESSADOR,
  PLACAMAE,
  MEMORIARAM,
  PLACADEVIDEO,
  MEMORIASECUNDARIA,
  GABINETE,
  FONTEDEALIMENTACAO
};

struct SerializeData final{
  size_t size;
  void *padrao;
};

class Loja {
  private:
    vector<Produto*> produtos;
    vector<Cliente> clientes;
    vector<Administrador> administradores;

    template <typename T>
    pair<string, SerializeData> genSerialize(){
      return {typeid(T).name(), {sizeof(T), new T{}}};
    }

    template <typename T>
    static vector<string> imprimirProduto(Loja* self) {
      vector<string> produtosListados;
      int index = 1;
      
      for (auto produtoBase: self->produtos) {
        if (T *produto = dynamic_cast<T*>(produtoBase)) {
          cout << index++ << ". ";
          produto->imprimirProduto();
          produtosListados.push_back(produto->getID());
        }
      }

      return produtosListados;
    }

    function<vector<string>(Loja*)> imprimirProdutoArr[7] = {
      imprimirProduto<Processador>,
      imprimirProduto<PlacaMae>,
      imprimirProduto<MemoriaRAM>,
      imprimirProduto<PlacaDeVideo>,
      imprimirProduto<MemoriaSecundaria>,
      imprimirProduto<Gabinete>,
      imprimirProduto<FonteDeAlimentacao>
    };

    unordered_map<std::string, SerializeData> mapSerializar = {
      genSerialize<Processador>(),
      genSerialize<PlacaMae>(),
      genSerialize<MemoriaRAM>(),
      genSerialize<PlacaDeVideo>(),
      genSerialize<MemoriaSecundaria>(),
      genSerialize<Gabinete>(),
      genSerialize<FonteDeAlimentacao>(),
    };

    void serializar(Produto *produto, ostream &os);

    void desserializar(Produto **produto, istream &is);

  public:
    Loja();
    ~Loja();

    bool adicionarProduto(Produto* produto, int quantidade = 0);
    bool removerProduto(string ID);
    int procuraProduto(string ID);

    bool adicionarCliente(Cliente cliente);
    bool adicionarAdministrador(Administrador administrador);

    void ordenarPorPreco();
    vector<string> imprimirEstoque(int tipoProduto);

    bool escreverEstoque();
    bool escreverClientes();
    bool escreverAdministradores();

    bool lerEstoque();
    bool lerClientes();
    bool lerAdministradores();
};

#endif