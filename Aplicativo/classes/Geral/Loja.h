#ifndef Loja_H
#define Loja_H

#include <vector>
#include <typeinfo>
#include <unordered_map>
#include <functional>

#include "../Produto/Produto.h"
#include "../Produto/Processador.h"
#include "../Produto/PlacaMae.h"
#include "../Produto/MemoriaRAM.h"
#include "../Produto/PlacaDeVideo.h"
#include "../Produto/MemoriaSecundaria.h"
#include "../Produto/Gabinete.h"
#include "../Produto/FonteDeAlimentacao.h"

#include "../Usuario/Cliente.h"
#include "../Usuario/Administrador.h"

#include "InterfaceGrafica.h"

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

struct SerializeData final {
  size_t size;
  void *padrao;
};

struct dadosImprimir {
  int initIndex;
  int lastIndex;
  vector<vector<vector<string>>> produtosListados;
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
    static int quantidadeProduto(Loja* self, int tipoDado = -1, string comparador = "") {
      int index = 0;

      for (auto produtoBase: self->produtos)
        if (T *produto = dynamic_cast<T*>(produtoBase))
          if (tipoDado == -1 || self->verificarDadoArr[tipoDado](produto, comparador)) {
            index++;
          }

      return index;
    }

    template <typename T>
    static dadosImprimir imprimirProduto(Loja* self, int quantProdutos, int indexInicio = 0, int tipoDado = -1, string comparador = "") {
      vector<vector<vector<string>>> produtosListados;

      int indexNova = 0;

      for (int i = indexInicio, j = 0; i < self->produtos.size() && j < quantProdutos; i++) {
        if (j == quantProdutos - 1) indexNova = i;

        if (T *produto = dynamic_cast<T*>(self->produtos[i])) {
          if (tipoDado == -1 || self->verificarDadoArr[tipoDado](produto, comparador)) {
            j++;
            produtosListados.push_back(produto->imprimirProduto());
          }
        }
      }

      return {
        indexInicio,
        indexNova + 1,
        produtosListados
      };
    }

    function<int(Loja*, int, string)> quantidadeProdutoArr[7] = {
      quantidadeProduto<Processador>,
      quantidadeProduto<PlacaMae>,
      quantidadeProduto<MemoriaRAM>,
      quantidadeProduto<PlacaDeVideo>,
      quantidadeProduto<MemoriaSecundaria>,
      quantidadeProduto<Gabinete>,
      quantidadeProduto<FonteDeAlimentacao>
    };

    function<dadosImprimir(Loja*, int, int, int, string)> imprimirProdutoArr[7] = {
      imprimirProduto<Processador>,
      imprimirProduto<PlacaMae>,
      imprimirProduto<MemoriaRAM>,
      imprimirProduto<PlacaDeVideo>,
      imprimirProduto<MemoriaSecundaria>,
      imprimirProduto<Gabinete>,
      imprimirProduto<FonteDeAlimentacao>
    };

    unordered_map<string, SerializeData> mapSerializar = {
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
    int getQuantidadeProduto(int tipoProduto, int tipoDado = -1, string comparador = "");
    string visualizarProdutos(InterfaceGrafica interfaceGrafica, int tipoProduto, int tipoDado = -1, string comparador = "");
    dadosImprimir imprimirEstoque(int tipoProduto, int quantProdutos, int indexInicio = 0, int tipoDado = -1, string comparador = "");

    bool escreverEstoque();
    bool escreverClientes();
    bool escreverAdministradores();

    bool lerEstoque();
    bool lerClientes();
    bool lerAdministradores();
};

#endif
