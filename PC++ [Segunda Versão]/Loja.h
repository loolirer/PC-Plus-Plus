#ifndef Loja_H
#define Loja_H

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

enum tiposDeProdutos {
  PROCESSADOR,
  PLACAMAE,
  MEMORIARAM,
  PLACADEVIDEO,
  MEMORIASECUNDARIA,
  GABINETE,
  FONTEDEALIMENTACAO
};

enum verificarDados {
  PROCESSADORSOCKET,
  DDR,
  GABINETEFATORFORMA,
  FONTEFATORFORMA
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
      return { typeid(T).name(), { sizeof(T), new T{} } };
    }

    template <typename T>
    static vector<string> imprimirProduto(Loja* self, int tipoDado = -1, string comparador = "") {
      vector<string> produtosListados;
      int index = 1;

      for (auto produtoBase: self->produtos) {
        if (T *produto = dynamic_cast<T*>(produtoBase)) {
          if (tipoDado == -1 || self->verificarDadoArr[tipoDado](produto, comparador)) {
            cout << index++ << ". ";
            produto->imprimirProduto();
            produtosListados.push_back(produto->getID());
          }
        }
      }

      return produtosListados;
    }

    function<vector<string>(Loja*, int, string)> imprimirProdutoArr[7] = {
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

    function<bool(Produto*, string)> verificarDadoArr[4] = {
      function<bool(Produto*, string)>([] (Produto* produto, string comparador) {
        if (PlacaMae *placaMae = dynamic_cast<PlacaMae*>(produto))
          return placaMae->getSocket() == comparador;
        return false;
      }),
      function<bool(Produto*, string)>([] (Produto* produto, string comparador) {
        if (MemoriaRAM *memoriaRAM = dynamic_cast<MemoriaRAM*>(produto))
          return memoriaRAM->getDDR() == comparador;
        return false;
      }),
      function<bool(Produto*, string)>([] (Produto* produto, string comparador) {
        if (Gabinete *gabinete = dynamic_cast<Gabinete*>(produto))
          return gabinete->getFatorForma() == comparador;
        return false;
      }),
      function<bool(Produto*, string)>([] (Produto* produto, string comparador) {
        if (FonteDeAlimentacao *fonteDeAlimentacao = dynamic_cast<FonteDeAlimentacao*>(produto))
          return fonteDeAlimentacao->getFatorForma() == comparador;
        return false;
      })
    };

    void serializar(Produto *produto, ostream &os);

    void desserializar(Produto **produto, istream &is);

  public:
    Loja();
    ~Loja();

    bool adicionarProduto(Produto* produto, int quantidade = 0);
    bool removerProduto(Produto* produto, int quantidade = 0);
    bool removerProdutos(vector<Produto> itens);
    int procuraProduto(string ID);
    Produto* getProduto(string ID);

    bool adicionarCliente(Cliente cliente);
    bool adicionarAdministrador(Administrador administrador);

    Cliente* loginCliente(string email, string senha);
    Administrador* loginAdministrador(string email, string senha);

    void ordenarPorPreco();
    vector<string> imprimirEstoque(int tipoProduto, int tipoDado = -1, string comparador = "");

    bool escreverEstoque();
    bool escreverClientes();
    bool escreverAdministradores();

    bool lerEstoque();
    bool lerClientes();
    bool lerAdministradores();
};

#endif
