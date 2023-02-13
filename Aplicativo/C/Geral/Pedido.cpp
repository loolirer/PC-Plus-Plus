#include "Pedido.h"

// Métodos de sobrecarga do construtor
Pedido::Pedido() {
  setPrecoTotal(0.0);
  setData("Pedido em Andamento");
  setPagamento("Pendente");
  setCupom("Pedido Incompleto");
}

// Método do destrutor
Pedido::~Pedido() {}

// Métodos de modificação dos atributos
void Pedido::setPrecoTotal(float precoTotal) {
  this->precoTotal = precoTotal;
}

void Pedido::setData(string data) {
  this->data = data;
}

void Pedido::setPagamento(string pagamento) {
  this->pagamento = pagamento;
}

void Pedido::setCupom(string cupom) {
  this->cupom = cupom;
}

// Métodos de retorno dos atributos
float Pedido::getPrecoTotal() const {
  return precoTotal;
}

string Pedido::getData() const {
  return data;
}

string Pedido::getPagamento() const {
  return pagamento;
}

// Funções utilitárias
int Pedido::procurarItem(Produto produto) {
	for (unsigned i = 0; i < itens.size(); i++) {
		if (itens[i].getID() == produto.getID()) {
			return i;
		}
	}
	return -1;
}

void Pedido::calcularTotal() {
  float p = 0.0;
  for (auto I : itens) {
    p += I.getQuantidade() * I.getPreco();
  }
  precoTotal = p;
}

void Pedido::atualizarData() {
	time_t now = time(NULL);
	data = string(ctime(&now)).substr(0, 24);
}

void Pedido::gerarCupom() {
  stringstream buffer;

  if (itens.size() == 0) {
    buffer << "Pedido Vazio!" << endl;
  } else {
    buffer << fixed << setprecision(2)
           << setiosflags(ios::left)
           << setw(28)
           << "> " + data
           << setiosflags(ios::right)
           << setw(42)
           << "[PC++]"
           << resetiosflags(ios::right)
           << string(3, '\n')
           << setiosflags(ios::left)
           << setw(30)
           << "Item"
           << setiosflags(ios::right)
           << setw(10)
           << "Quantidade"
           << setw(20)
           << "Valor Unitário"
           << setw(11)
           << "Subtotal"
           << endl
           << "——————————————————————————————————————————————————————————————————————"
           << endl
           << resetiosflags(ios::right);

    for (int i = 0; i < itens.size(); i++) {

      string modelo = to_string(i + 1) + ". " + itens[i].getMarca() + " " + itens[i].getModelo();

      if(modelo.size() >= 29)
        modelo = modelo.substr(0, 26) + "...";

      buffer << setiosflags(ios::left)
             << setw(30)
             << modelo
             << setiosflags(ios::right)
             << setw(10)
             << itens[i].getQuantidade()
             << setw(19)
             << itens[i].getPreco()
             << setw(11)
             << itens[i].getQuantidade() * itens[i].getPreco()
             << endl
             << resetiosflags(ios::right);
    }

    calcularTotal();

    buffer << "——————————————————————————————————————————————————————————————————————"
           << endl
           << setw(51)
           << "Método de Pagamento: " + pagamento
           << setiosflags(ios::right)
           << setw(9)
           << "Total R$"
           << setw(11)
           << precoTotal
           << endl
           << resetiosflags(ios::right);
  }

  cupom = buffer.str();
}

int Pedido::imprimirPedido(InterfaceGrafica interfaceGrafica, bool navegar) {
  interfaceGrafica.limparTela();
  interfaceGrafica.setTelas(vector<dadosTela>{{"DETALHES DO PEDIDO", 1}});
  interfaceGrafica.renderTela();

  vector<dadosTexto> textos;

  gerarCupom();

  string linha;
  for(auto c : cupom) {
    if (c == '\n') {
      textos.push_back({ linha });
      linha.clear();
    } else {
      linha.push_back(c);
    }
  }

  for (unsigned i = 0; i < textos.size(); i++) 
    (i > 4 && i < textos.size() - 2) 
      ? textos[i].navegavel = true 
      : textos[i].navegavel = false;

  interfaceGrafica.renderTexto(
    0,
    textos,
    MEIO,
    MEIO
  );

  if (navegar) {
    interfaceGrafica.renderTexto(
      0,
      {
        { "Selecione um Item para ser Removido do Pedido"},
        { "" },
        { "▲ Mover Para Cima / ▼ Mover para Baixo" }
      },
      MEIO,
      FIM
    );
  } else {
    interfaceGrafica.renderTexto(
      0,
      {
        { "Pressione Enter para Retornar", true },
      },
      MEIO,
      FIM
    );
  }

  int resultadoNavegar = interfaceGrafica.navegar(navegar, false, true);
  return resultadoNavegar;
}

// Métodos da classe
Produto* Pedido::getItem(int indice)
{
  if(indice >= 0  && indice < itens.size())
    return &itens[indice];
  return nullptr;
}

bool Pedido::adicionarItens(Produto produto, int quantidade) {
  int i = procurarItem(produto);

  if (i == -1) {
    if (quantidade > produto.getQuantidade()) {
      return false;
    } else {
      produto.setQuantidade(quantidade);
      itens.emplace_back(produto);
      return true;
    }
  } else {
    if (itens[i].getQuantidade() + quantidade > produto.getQuantidade()) {
      return false;
    } else {
      itens[i].setQuantidade(itens[i].getQuantidade() + quantidade);
      return true;
    }
  }
}

bool Pedido::removerItens(Produto produto, int quantidade) {
  int i = procurarItem(produto);

  if (i == -1) {
    return false;
  } else {
    if (quantidade >= itens[i].getQuantidade()) {
      itens.erase(itens.begin() + i);
    } else {
      itens[i].setQuantidade(itens[i].getQuantidade() - quantidade);
    }
    return true;
  }
}

vector<Produto> Pedido::realizarPedido(Cliente* cliente, string pagamento) {
  setPagamento(pagamento);
  atualizarData();
  gerarCupom();
  cliente->setSaldo(cliente->getSaldo() + precoTotal);

  return itens;
}
