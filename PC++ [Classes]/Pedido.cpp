#include "Pedido.h"

// Métodos de sobrecarga do construtor
Pedido::Pedido() {
  this->cliente = nullptr;
  setPrecoTotal(0.0);
  setData("Pedido em Andamento");
  setPagamento("Pendente");
  setCupom("Pedido Incompleto");
}

Pedido::Pedido(Cliente* cliente) {
  this->cliente = cliente;
  setPrecoTotal(0.0);
  setData("Pedido em Andamento");
  setPagamento("Pendente");
  setCupom("Pedido Incompleto");
}

// Método do destrutor
Pedido::~Pedido() {
  cout << "Objeto Pedido Destruido!" << endl;
}

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
float Pedido::getPrecoTotal() {
  return this->precoTotal;
}

string Pedido::getData() {
  return this->data;
}

string Pedido::getPagamento() {
  return this->pagamento;
}

string Pedido::getCupom() {
  return this->cupom;
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

void Pedido::gerarCupom()
{
  stringstream buffer;

  if (itens.size() == 0) {
    buffer << "Pedido Vazio!" << endl;
  } else {
    buffer << setiosflags(ios::left)
           << setw(28)
           << "> " + data
           << setiosflags(ios::right)
           << setw(42)
           << "[PC++]"
           << resetiosflags(ios::right)
           << string(3, '\n')
           << string(25, ' ')
           << "{DETALHES DO PEDIDO}"
           << string(3, '\n')
           << setiosflags(ios::left)
           << setw(30)
           << "Item"
           << setiosflags(ios::right)
           << setw(10)
           << "Quantidade"
           << setw(19)
           << "Valor Unitário"
           << setw(11)
           << "Subtotal"
           << endl
           << string(70, '_')
           << endl << endl
           << resetiosflags(ios::right);

    for (int i = 0; i < itens.size(); i++) {
      buffer << setiosflags(ios::left)
             << setw(30)
             << to_string(i + 1) + ". " + itens[i].getMarca() + " " + itens[i].getModelo()
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
    buffer << string(70, '_')
           << endl << endl
           << setw(46)
           << "Método de Pagamento: " + pagamento
           << setiosflags(ios::right)
           << setw(13)
           << "Total R$"
           << setw(11)
           << precoTotal
           << endl
           << resetiosflags(ios::right);
  }

  cupom = buffer.str();
}

void Pedido::imprimirPedido() {
  gerarCupom();
  cout << cupom;
}

// Métodos da classe
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

bool Pedido::realizarPedido(string pagamento)
{
  setPagamento(pagamento);
  atualizarData();
  gerarCupom();
  cliente->setSaldo(cliente->getSaldo() + precoTotal);
  return true;
}
