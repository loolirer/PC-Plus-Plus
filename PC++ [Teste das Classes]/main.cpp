#include <iostream>
#include <vector>
#include <string>

#include "Loja.cpp"
#include "Pedido.cpp"

using namespace std;

vector<string> mensagens;

void adicionarMensagem(bool estado, string classe, string teste, string mensagem = "") {
    string estadoStr = estado ? "PASSOU" : "NÃO PASSOU";
    string msg = (mensagem != "" ? " | " + mensagem : "");
    string resultado = estadoStr + " [ " + classe + " ] " + "Teste: " + teste + msg;

    mensagens.push_back(resultado);
}

void teste_Produto(Produto produto, string classe) {
    try {
        produto.setModelo("Generico");
        produto.setMarca("Generico");
        produto.setID(classe);
        produto.setPreco(999);
        produto.setQuantidade(500);

        produto.getModelo() == "Generico"
        ? adicionarMensagem(true, "Produto | " + classe, "setModelo | getModelo")
        : adicionarMensagem(false, "Produto | " + classe, "setModelo | getModelo");

        produto.getMarca() == "Generico"
        ? adicionarMensagem(true, "Produto | " + classe, "setMarca | getMarca")
        : adicionarMensagem(false, "Produto | " + classe, "setMarca | getMarca");

        produto.getID() == classe
        ? adicionarMensagem(true, "Produto | " + classe, "setID | getID")
        : adicionarMensagem(false, "Produto | " + classe, "setID | getID");

        produto.getPreco() == 999
        ? adicionarMensagem(true, "Produto | " + classe, "setPreco | getPreco")
        : adicionarMensagem(false, "Produto | " + classe, "setPreco | getPreco");

        produto.getQuantidade() == 500
        ? adicionarMensagem(true, "Produto | " + classe, "setQuantidade | getQuantidade")
        : adicionarMensagem(false, "Produto | " + classe, "setQuantidade | getQuantidade");

    } catch (exception error) {
        throw error;
    }
}

void teste_FonteDeAlimentacao(FonteDeAlimentacao fonteDeAlimentacao) {
    string classe = "FonteDeAlimentacao";

    try {
        teste_Produto(fonteDeAlimentacao, classe);

        fonteDeAlimentacao.setTensao(110);
        fonteDeAlimentacao.setPotencia(600);
        fonteDeAlimentacao.setFatorForma("Micro ATX");

        fonteDeAlimentacao.getTensao() == 110
        ? adicionarMensagem(true, classe, "setTensao | getTensao")
        : adicionarMensagem(false, classe, "setTensao | getTensao");

        fonteDeAlimentacao.getPotencia() == 600
        ? adicionarMensagem(true, classe, "setPotencia | getPotencia")
        : adicionarMensagem(false, classe, "setPotencia | getPotencia");

        fonteDeAlimentacao.getFatorForma() == "Micro ATX"
        ? adicionarMensagem(true, classe, "setFatorForma | getFatorForma")
        : adicionarMensagem(false, classe, "setFatorForma | getFatorForma");

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe FonteDeAlimentacao", error.what());
    }
}

void teste_PlacaDeVideo(PlacaDeVideo placaDeVideo) {
    string classe = "placaDeVideo";

    try {
        teste_Produto(placaDeVideo, classe);

        placaDeVideo.setMemoria(8);
        placaDeVideo.setTipoMemoria("GDDR6");
        placaDeVideo.setFrequencia(14000);
        placaDeVideo.setBits(512);

        placaDeVideo.getMemoria() == 8
        ? adicionarMensagem(true, classe, "setMemoria | getMemoria")
        : adicionarMensagem(false, classe, "setMemoria | getMemoria");

        placaDeVideo.getTipoMemoria() == "GDDR6"
        ? adicionarMensagem(true, classe, "setTipoMemoria | getTipoMemoria")
        : adicionarMensagem(false, classe, "setTipoMemoria | getTipoMemoria");

        placaDeVideo.getFrequencia() == 14000
        ? adicionarMensagem(true, classe, "setFrequencia | getFrequencia")
        : adicionarMensagem(false, classe, "setFrequencia | getFrequencia");

        placaDeVideo.getBits() == 512
        ? adicionarMensagem(true, classe, "setBits | getBits")
        : adicionarMensagem(false, classe, "setBits | getBits");

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe PlacaDeVideo", error.what());
    }
}

void teste_Gabinete(Gabinete gabinete) {
    string classe = "Gabinete";

    try {
        teste_Produto (gabinete, classe);

        gabinete.setFatorForma("forma");
        gabinete.setTamanho("40x50x30");
        gabinete.setCooler(true);

        gabinete.getFatorForma() == "forma"
        ? adicionarMensagem(true, classe, "setFatorForma | getFatorForma")
        : adicionarMensagem (false, classe, "setFatorForma | getFatorForma");

        gabinete.getTamanho() == "40x50x30"
        ? adicionarMensagem(true, classe, "setTamanho | getTamanho")
        : adicionarMensagem(false, classe, "setTamanho | getTamanho");

        gabinete.getCooler() == 1
        ? adicionarMensagem(true, classe, "setCooler | getCooler")
        : adicionarMensagem(false, classe, "setCooler | getCooler");

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe Gabinete", error.what());
    }
}

void teste_MemoriaSecundaria(MemoriaSecundaria memoriaSecundaria) {
    string classe = "MemoriaSecundaria";

    try {
        teste_Produto (memoriaSecundaria, classe);

        memoriaSecundaria.setTipo("tipo");
        memoriaSecundaria.setCapacidade(1234);

        memoriaSecundaria.getTipo() == "tipo"
        ? adicionarMensagem(true, classe, "setTipo | getTipo")
        : adicionarMensagem(false, classe, "setTipo | getTipo");

        memoriaSecundaria.getCapacidade() == 1234
        ? adicionarMensagem(true, classe, "setCapacidade | getCapacidade")
        : adicionarMensagem(false, classe, "setCapacidade | getCapacidade");

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe MemoriaSecundaria", error.what());
    }
}

void teste_PlacaMae(PlacaMae placaMae) {
    string classe = "PlacaMae";

    try {
        teste_Produto(placaMae, classe);

        placaMae.setPlataforma("AMD");
        placaMae.setChipset("AMD B450");
        placaMae.setFatorForma("M-ATX");
        placaMae.setMarca("AMD");
        placaMae.setSocket("AM4");

        placaMae.getPlataforma() == "AMD"
        ? adicionarMensagem(true, classe, "setPlataforma | getPlataforma")
        : adicionarMensagem(false, classe,  "setPlataforma | getPlataforma");

        placaMae.getChipset() == "AMD B450"
        ? adicionarMensagem(true, classe, "setChipset | getChipset")
        : adicionarMensagem(false, classe,  "setChipset | getChipset");

        placaMae.getFatorForma() == "M-ATX"
        ? adicionarMensagem(true, classe, "setFatorForma | getFatorForma")
        : adicionarMensagem(false, classe, "setFatorForma | getFatorForma");

        placaMae.getMarca() == "AMD"
        ? adicionarMensagem(true, classe, "setMarca | getMarca")
        : adicionarMensagem(false, classe, "setMarca | getMarca");

        placaMae.getSocket() == "AM4"
        ? adicionarMensagem(true, classe, "setSocket | getSocket")
        : adicionarMensagem(false, classe,  "setSocket | getSocket");

    } catch(exception error) {
        adicionarMensagem(false, classe, "Classe PlacaMae", error.what());
    }
}

void teste_Processador(Processador processador) {
    string classe = "Processador";

    try {
        teste_Produto(processador, classe);

        processador.setCores(6);
        processador.setThreads(12);
        processador.setFrequencia(2.9);
        processador.setCache(12);
        processador.setSocket("FCLGA1200");

        processador.getCores() == 6
        ? adicionarMensagem(true, classe, "setCapacidade | getCapacidade")
        : adicionarMensagem(false, classe, "setCapacidade | getCapacidade");

        processador.getThreads() == 12
        ? adicionarMensagem(true, classe, "setDDR | getDDR")
        : adicionarMensagem(false, classe, "setDDR | getDDR");

        abs(processador.getFrequencia() - 2.9) < 1e-7
        ? adicionarMensagem(true, classe, "setFrequencia | getFrequencia")
        : adicionarMensagem(false, classe, "setFrequencia | getFrequencia");

        processador.getCache() == 12
        ? adicionarMensagem(true, classe, "setCache | getCache")
        : adicionarMensagem(false, classe, "setCache | getCache");

        processador.getSocket() == "FCLGA1200"
        ? adicionarMensagem(true, classe, "setSocket | getSocket")
        : adicionarMensagem(false, classe, "setSocket | getSocket");

        } catch(exception error) {
            adicionarMensagem(false, classe, "Classe MemoriaRAM", error.what());
        }
}

void teste_MemoriaRAM(MemoriaRAM memoriaRAM) {
    string classe = "MemoriaRAM";

    try {
        teste_Produto(memoriaRAM, classe);

        memoriaRAM.setCapacidade(8);
        memoriaRAM.setDDR(3);
        memoriaRAM.setFrequencia(2666);

        memoriaRAM.getCapacidade() == 8
        ? adicionarMensagem(true, classe, "setCapacidade | getCapacidade")
        : adicionarMensagem(false, classe, "setCapacidade | getCapacidade");

        memoriaRAM.getDDR() == 3
        ? adicionarMensagem(true, classe, "setDDR | getDDR")
        : adicionarMensagem(false, classe, "setDDR | getDDR");

        memoriaRAM.getFrequencia() == 2666
        ? adicionarMensagem(true, classe, "setFrequencia | getFrequencia")
        : adicionarMensagem(false, classe, "setFrequencia | getFrequencia");

    } catch(exception error) {
        adicionarMensagem(false, classe, "Classe MemoriaRAM", error.what());
    }
}

void teste_Loja(Loja loja, FonteDeAlimentacao fonteDeAlimentacao) {
    string classe = "Loja";

    try {
        loja.adicionarProduto(&fonteDeAlimentacao)
        ? adicionarMensagem(true, classe, "adicionarProduto")
        : adicionarMensagem(false, classe, "adicionarProduto");

        loja.procuraProduto(fonteDeAlimentacao.getID()) != -1
        ? adicionarMensagem(true, classe, "procuraProduto")
        : adicionarMensagem(false, classe, "procuraProduto");

        loja.removerProduto(fonteDeAlimentacao.getID())
        ? adicionarMensagem(true, classe, "removerProduto", "Conseguiu remover o produto fonteDeAlimentacao")
        : adicionarMensagem(true, classe, "removerProduto", "Não conseguiu remover o produto fonteDeAlimentacao");

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe Loja", error.what());
    }
}

void teste_Usuario(Usuario usuario, string classe) {
    try {
        usuario.setEmail("Generico@gmail.com");
        usuario.setSenha("Generico");

        usuario.getEmail() == "Generico@gmail.com"
        ? adicionarMensagem(true, "Usuario | " + classe, "setEmail | getEmail")
        : adicionarMensagem(false, "Usuario | " + classe, "setEmail | getEmail");

        usuario.conferirLogin("Generico@gmail.com","Generico") != false
        ? adicionarMensagem(true, classe, "conferirLogin")
        : adicionarMensagem(false, classe, "conferirLogin");

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe Usuario", error.what());
    }
}

void teste_Cliente(Cliente cliente) {
    string classe = "Cliente";

    try {
        teste_Usuario(cliente, classe);

        cliente.setCpf("345.231.523-13");
        cliente.setEndereco("Rua B");
        cliente.setSaldo(6000);

        cliente.getCpf() == "345.231.523-13"
        ? adicionarMensagem(true, classe, "setCpf | getCpf")
        : adicionarMensagem(false, classe, "setCpf | getCpf");

        cliente.getEndereco() == "Rua B"
        ? adicionarMensagem(true, classe, "setEndereco | getEndereco")
        : adicionarMensagem(false, classe, "setEndereco | getEndereco");

        cliente.getSaldo() == 6000
        ? adicionarMensagem(true, classe, "setSaldo | getSaldo")
        : adicionarMensagem(false, classe, "setSaldo | getSaldo");
    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe Cliente", error.what());
    }
}

void teste_Administrador(Administrador administrador) {
    string classe = "Administrador";

    try {
        teste_Usuario(administrador, classe);

    } catch (exception error) {
        adicionarMensagem(false, classe, "Classe Administrador", error.what());
    }
}

void teste_Pedido(Pedido pedido, Cliente* cliente, FonteDeAlimentacao fonteDeAlimentacao) {
	string classe = "Pedido";

	try {
        pedido.getPrecoTotal() == 0.00
        ? adicionarMensagem(true, classe, "setPrecoTotal | getPrecoTotal")
        : adicionarMensagem(false, classe, "setPrecoTotal | getPrecoTotal");

        pedido.getCupom() == "Pedido Incompleto"
        ? adicionarMensagem(true, classe, "setCupom | getCupom")
        : adicionarMensagem(false, classe, "setCupom | getCupom");

        pedido.getData() == "Pedido em Andamento"
        ? adicionarMensagem(true, classe, "setData | getData")
        : adicionarMensagem(false, classe, "setData | getData");

        pedido.getPagamento() == "Pendente"
        ? adicionarMensagem(true, classe, "setPagamento | getPagamento")
        : adicionarMensagem(false, classe, "setPagamento | getPagamento");

        pedido.adicionarItens(fonteDeAlimentacao, 1)
        ? adicionarMensagem(true, classe, "adicionarItens | procurarPedido")
        : adicionarMensagem(false, classe, "adicionarItens | procurarPedido");

        pedido.adicionarItens(fonteDeAlimentacao, 2)
        ? adicionarMensagem(true, classe, "adicionarItens | procurarPedido")
        : adicionarMensagem(false, classe, "adicionarItens | procurarPedido");

        pedido.removerItens(fonteDeAlimentacao, 2)
        ? adicionarMensagem(true, classe, "removerItens | procurarPedido")
        : adicionarMensagem(false, classe, "removerItens | procurarPedido");

        pedido.realizarPedido(cliente, "Boleto");

        pedido.getCupom() != "Pedido Incompleto"
        ? adicionarMensagem(true, classe, "gerarCupom")
        : adicionarMensagem(false, classe, "gerarCupom");

        pedido.getData() != "Pedido em Andamento"
        ? adicionarMensagem(true, classe, "atualizarData")
        : adicionarMensagem(false, classe, "atualizarData");

        pedido.getPrecoTotal() == fonteDeAlimentacao.getPreco()
        ? adicionarMensagem(true, classe, "calcularTotal")
        : adicionarMensagem(false, classe, "calcularTotal");

        cliente->getSaldo() == pedido.getPrecoTotal()
        ? adicionarMensagem(true, classe, "realizarPedido")
        : adicionarMensagem(false, classe, "realizarPedido");

	} catch (exception error) {
        adicionarMensagem(false, classe, "Classe Pedido", error.what());
	}
}

int main() {
    FonteDeAlimentacao fonteDeAlimentacao("CX430", "Corsair", "430", 299, 50, 220, 430, "ATX");
    PlacaDeVideo placaDeVideo;
    Gabinete gabinete;
    MemoriaSecundaria memoriaSecundaria;
    PlacaMae placaMae;
    Processador processador;
    MemoriaRAM memoriaRAM;

    Loja loja;

    Cliente cliente;
    Administrador administrador;

    Pedido pedido;

    teste_FonteDeAlimentacao(fonteDeAlimentacao);
    teste_PlacaDeVideo(placaDeVideo);
    teste_Gabinete(gabinete);
    teste_MemoriaSecundaria(memoriaSecundaria);
    teste_PlacaMae(placaMae);
    teste_Processador(processador);
    teste_MemoriaRAM(memoriaRAM);

    teste_Loja(loja, fonteDeAlimentacao);

    teste_Administrador(administrador);
    teste_Cliente(cliente);

    teste_Pedido(pedido, &cliente, fonteDeAlimentacao);

    for (unsigned i = 0; i < mensagens.size(); i++) {
        cout << mensagens[i] << endl;
    }

    return 0;
}
