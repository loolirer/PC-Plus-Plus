#include <Windows.h>

#include "./classes/Geral/Serializador.cpp"
#include "./classes/Geral/Loja.cpp"
#include "./classes/Geral/Pedido.cpp"
#include "./classes/Geral/InterfaceGrafica.cpp"

#include "./classes/Produto/Produto.cpp"
#include "./classes/Produto/Processador.cpp"
#include "./classes/Produto/PlacaMae.cpp"
#include "./classes/Produto/MemoriaRAM.cpp"
#include "./classes/Produto/FonteDeAlimentacao.cpp"
#include "./classes/Produto/PlacaDeVideo.cpp"
#include "./classes/Produto/MemoriaSecundaria.cpp"
#include "./classes/Produto/Gabinete.cpp"

#include "./classes/Usuario/Usuario.cpp"
#include "./classes/Usuario/Administrador.cpp"
#include "./classes/Usuario/Cliente.cpp"

int main() {
  system("mode con: cols=100 lines=30"); // Define o tamanho da janela do CMD

  // Cabeçalho da loja imprimível
  vector<dadosTexto> cabecalhoLoja {
    { "    _/_/_/      _/_/_/          _/          _/  " },
    { "   _/    _/  _/                _/          _/   " },
    { "  _/_/_/    _/            _/_/_/_/_/  _/_/_/_/_/" },
    { " _/        _/                _/          _/     " },
    { "_/          _/_/_/          _/          _/      " },
  };

  Loja loja;
  InterfaceGrafica interfaceGrafica;

  // Administrador mestre cadastrado pelo sistema
  loja.adicionarAdministrador(Administrador("mestre@adm.pcplusplus.com", "oadmtaon"));

  int eventoUsuario;
  enum menuUsuario { LOGIN,
                     CADASTRO,
                     ENCERRAR_APLICACAO };

  do {
    // Atualiza tela
    interfaceGrafica.limparTela();
    interfaceGrafica.setTelas(1);
    interfaceGrafica.renderTela();

    interfaceGrafica.renderTexto(
        0,
        cabecalhoLoja,
        MEIO
    );

    // Cria texto navegável
    interfaceGrafica.renderTexto(
      0,
      vector<dadosTexto> {
        { "1. Login", true },
        { "2. Realizar Cadastro", true },
        { "3. Encerrar Programa", true }
      },
      MEIO,
      MEIO
    );

    interfaceGrafica.renderTexto(
        0,
        vector<dadosTexto> {
            { "▲ Mover Para Cima / ▼ Mover para Baixo" }
        },
        MEIO,
        FIM
    );

    eventoUsuario = interfaceGrafica.navegar();

    switch(eventoUsuario) {
      case LOGIN: {
        // Atualiza tela
        interfaceGrafica.limparTela();
        interfaceGrafica.setTelas(vector<dadosTela>{{"LOGIN", 1}});
        interfaceGrafica.renderTela();

        interfaceGrafica.renderTexto(
          0,
          cabecalhoLoja,
          MEIO
        );

        interfaceGrafica.renderTexto(
          0,
          vector<dadosTexto> {
            { "> Insira o seu e-mail: ", false, true },
            { "> Insira a sua senha: ", false, true }
          },
          INICIO,
          MEIO
        );

        string email = interfaceGrafica.input();
        string senha = interfaceGrafica.input();

        // Ponteiros de usuário
        Administrador* administrador = loja.loginAdministrador(email, senha);
        Cliente* cliente = loja.loginCliente(email, senha);

        if(administrador != nullptr) { // Caso administrador for encontrado

          string adm = administrador->getEmail();

          int sessaoAdmin;
          enum menuSessao { ADICIONAR_PRODUTO,
                            REPOR_PRODUTO,
                            REMOVER_PRODUTO,
                            VISUALIZAR_ESTOQUE,
                            CADASTRAR_ADM,
                            ENCERRAR_SESSAO };

          do {
            // Atualiza tela
            interfaceGrafica.limparTela();
            interfaceGrafica.setTelas(vector<dadosTela>{{"ÁREA DO ADMINISTRADOR", 1}});
            interfaceGrafica.renderTela();

            vector<dadosTexto> c = cabecalhoLoja;
            vector<dadosTexto> e = {{ "" }, { "" }, { "[" + adm + "]" }};
            c.insert(c.end(), e.begin(), e.end() );

            interfaceGrafica.renderTexto(
              0,
              c,
              MEIO
            );

            // Cria texto navegável
            interfaceGrafica.renderTexto(
              0,
              vector<dadosTexto> {
                { "1. Adicionar Produto", true },
                { "2. Repor Produto", true },
                { "3. Remover Produto", true },
                { "4. Visualizar Estoque", true },
                { "5. Cadastrar Administrador", true },
                { "6. Encerrar Sessão", true },
              },
              MEIO,
              MEIO
            );

            interfaceGrafica.renderTexto(
              0,
              vector<dadosTexto> {
                  dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
              },
              MEIO,
              FIM
            );

            sessaoAdmin = interfaceGrafica.navegar();

            switch (sessaoAdmin) {
              case ADICIONAR_PRODUTO: {
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"ADICIONAR PRODUTO", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                // Cria texto navegável
                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "1. Processador", true },
                    { "2. Placa Mãe", true },
                    { "3. Memória RAM", true },
                    { "4. Placa de Vídeo", true },
                    { "5. Memória Secundaria", true },
                    { "6. Gabinete", true },
                    { "7. Fonte de Alimentação", true }
                  },
                  MEIO,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                      dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                  },
                  MEIO,
                  FIM
                );

                int tipoProduto = interfaceGrafica.navegar();

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"ADICIONAR PRODUTO - DADOS GERAIS", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "> Insira o Modelo do Produto: ", false, true },
                    { "> Insira a Marca do Produto: ", false, true },
                    { "> Insira o ID do Produto: ", false, true },
                    { "> Insira o Preço do Produto: ", false, true },
                    { "> Insira a Quantidade do Produto: ", false, true }
                  },
                  INICIO,
                  MEIO
                );

                string modelo = interfaceGrafica.input();
                string marca = interfaceGrafica.input();
                string ID = interfaceGrafica.input();
                float preco = interfaceGrafica.inputNumber<float>();
                int quantidade = interfaceGrafica.inputNumber<int>();

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"ADICIONAR PRODUTO - DADOS ESPECÍFICOS", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                bool sucesso;

                // Recebe dados específicos de cada produto
                switch (tipoProduto) {
                  case PROCESSADOR: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira a Quantidade de Cores do Processador: ", false, true },
                        { "> Insira a Quantidade de Threads do Processador: ", false, true },
                        { "> Insira a Frequência do Processador em GHz: ", false, true },
                        { "> Insira o Socket do Processador: ", false, true }
                      },
                      INICIO,
                      MEIO
                    );

                    int cores = interfaceGrafica.inputNumber<int>();
                    int threads = interfaceGrafica.inputNumber<int>();
                    float frequencia = interfaceGrafica.inputNumber<float>();
                    string socket = interfaceGrafica.input();

                    sucesso = loja.adicionarProduto(new Processador(
                      modelo, marca, ID, preco, quantidade,
                      cores, threads, frequencia, socket
                    ));

                    break;
                  }
                  case PLACAMAE: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira a Plataforma da Placa Mãe: ", false, true },
                        { "> Insira o Socket da Placa Mãe: ", false, true },
                        { "> Insira o Tipo de Memoria da Placa Mãe: ", false, true },
                        { "> Insira o Fator Forma da Placa Mãe: ", false, true },
                      },
                      INICIO,
                      MEIO
                    );

                    string plataforma = interfaceGrafica.input();
                    string socket = interfaceGrafica.input();
                    string memoria = interfaceGrafica.input();
                    string fatorForma = interfaceGrafica.input();

                    sucesso = loja.adicionarProduto(new PlacaMae(
                      modelo, marca, ID, preco, quantidade,
                      plataforma, socket, memoria, fatorForma
                    ));

                    break;
                  }
                  case MEMORIARAM: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira a Capacidade da Memória RAM: ", false, true },
                        { "> Insira a Frequência da Memória RAM em MHz: ", false, true },
                        { "> Insira o DDR da Memoria RAM: ", false, true },
                      },
                      INICIO,
                      MEIO
                    );

                    int capacidade = interfaceGrafica.inputNumber<int>();
                    int frequencia = interfaceGrafica.inputNumber<int>();
                    string DDR = interfaceGrafica.input();

                    sucesso = loja.adicionarProduto(new MemoriaRAM(
                      modelo, marca, ID, preco, quantidade,
                      capacidade, frequencia, DDR
                    ));

                    break;
                  }
                  case PLACADEVIDEO: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira a Quantidade de VRAM da Placa De Vídeo: ", false, true },
                        { "> Insira o Tipo de Memória da Placa De Vídeo: ", false, true },
                        { "> Insira a Frequência da Placa De Vídeo em MHz: ", false, true },
                        { "> Insira a Quantidade de Bits da Placa De Vídeo: ", false, true }
                      },
                      INICIO,
                      MEIO
                    );

                    unsigned short int memoria = interfaceGrafica.inputNumber<int>();
                    unsigned short int frequencia = interfaceGrafica.inputNumber<int>();
                    unsigned short int bits = interfaceGrafica.inputNumber<int>();
                    string tipoMemoria = interfaceGrafica.input();

                    sucesso = loja.adicionarProduto(new PlacaDeVideo(
                      modelo, marca, ID, preco, quantidade,
                      memoria, tipoMemoria, frequencia, bits
                    ));

                    break;
                  }
                  case MEMORIASECUNDARIA: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira o Tipo de Memória Secundária: ", false, true },
                        { "> Insira a Capacidade da Memória Secundária: ", false, true }
                      },
                      INICIO,
                      MEIO
                    );

                    string tipo = interfaceGrafica.input();
                    int capacidade = interfaceGrafica.inputNumber<int>();

                    sucesso = loja.adicionarProduto(new MemoriaSecundaria(
                      modelo, marca, ID, preco, quantidade,
                      tipo, capacidade
                    ));

                    break;
                  }
                  case GABINETE: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira o Fator Forma do Gabinete: ", false, true },
                        { "> Insira o Tamanho do Gabinete: ", false, true }
                      },
                      INICIO,
                      MEIO
                    );

                    string fatorForma = interfaceGrafica.input();
                    string tamanho = interfaceGrafica.input();

                    sucesso = loja.adicionarProduto(new Gabinete(
                      modelo, marca, ID, preco, quantidade,
                      fatorForma, tamanho
                    ));

                    break;
                  }
                  case FONTEDEALIMENTACAO: {
                    interfaceGrafica.renderTexto(
                      0,
                      vector<dadosTexto> {
                        { "> Insira a Potência da Fonte De Alimentação: ", false, true },
                        { "> Insira o Tamanho da Fonte De Alimentação: ", false, true }
                      },
                      INICIO,
                      MEIO
                    );

                    int potencia = interfaceGrafica.inputNumber<int>();
                    string fatorForma = interfaceGrafica.input();

                    sucesso = loja.adicionarProduto(new FonteDeAlimentacao(
                      modelo, marca, ID, preco, quantidade,
                      potencia, fatorForma
                    ));

                    break;
                  }
                }

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                if (sucesso) {
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto foi adicionado com sucesso!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );

                } else {

                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto não pôde ser adicionado!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );
                }

                Sleep(5000);
                break;
              }

              case REPOR_PRODUTO: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"REPOR PRODUTO", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                // Cria texto navegável
                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "1. Processador", true },
                    { "2. Placa Mãe", true },
                    { "3. Memória RAM", true },
                    { "4. Placa de Vídeo", true },
                    { "5. Memória Secundaria", true },
                    { "6. Gabinete", true },
                    { "7. Fonte de Alimentação", true }
                  },
                  MEIO,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                      { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                  },
                  MEIO,
                  FIM
                );

                int tipoProduto = interfaceGrafica.navegar();
                string idProduto = loja.visualizarProdutos(interfaceGrafica, tipoProduto);

                if (idProduto == "")
                  break;

                Produto* produto = loja.getProduto(idProduto);

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{produto->getMarca() + " " + produto->getModelo(), 1}});
                interfaceGrafica.renderTela();

                if (produto == nullptr) { // Caso produto não for encontrado
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto não pôde ser adicionado!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );

                  Sleep(5000);
                  break;
                }

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "> Insira a quantidade do Produto a ser adicionada: ", false, true },
                  },
                  INICIO,
                  MEIO
                );

                int quantidade = interfaceGrafica.inputNumber<int>();

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                if (loja.adicionarProduto(produto, quantidade)) {
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto " + produto->getMarca() + " " + produto->getModelo() + " foi reposto!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );
                } else {
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "Não foi possível repor o Produto!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );
                }

                Sleep(5000);
                break;
              }

              case REMOVER_PRODUTO: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"REMOVER PRODUTO", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                // Cria texto navegável
                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "1. Processador", true },
                    { "2. Placa Mãe", true },
                    { "3. Memória RAM", true },
                    { "4. Placa de Vídeo", true },
                    { "5. Memória Secundaria", true },
                    { "6. Gabinete", true },
                    { "7. Fonte de Alimentação", true }
                  },
                  MEIO,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                      { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                  },
                  MEIO,
                  FIM
                );

                int tipoProduto = interfaceGrafica.navegar();
                string idProduto = loja.visualizarProdutos(interfaceGrafica, tipoProduto);

                if (idProduto == "")
                  break;

                Produto* produto = loja.getProduto(idProduto);

                if (produto == nullptr) {
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto não pôde ser removido!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );

                  Sleep(5000);
                  break;
                }

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{produto->getMarca() + " " + produto->getModelo(), 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "> Insira a quantidade do Produto a ser removida: ", false, true },
                  },
                  INICIO,
                  MEIO
                );

                int quantidade = interfaceGrafica.inputNumber<int>();

                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                bool sucesso = loja.removerProduto(produto, quantidade);

                if (sucesso) {
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto foi Removido com Sucesso!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );
                } else {
                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "O Produto não pôde ser Removido!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );
                }

                Sleep(5000);
                break;
              }

              case VISUALIZAR_ESTOQUE: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"ESTOQUE", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                // Cria texto navegável
                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "1. Processador", true },
                    { "2. Placa Mãe", true },
                    { "3. Memória RAM", true },
                    { "4. Placa de Vídeo", true },
                    { "5. Memória Secundaria", true },
                    { "6. Gabinete", true },
                    { "7. Fonte de Alimentação", true }
                  },
                  MEIO,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                      { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                  },
                  MEIO,
                  FIM
                );

                int tipoProduto = interfaceGrafica.navegar();
                loja.visualizarProdutos(interfaceGrafica, tipoProduto);
                break;
              }

              case CADASTRAR_ADM: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"CADASTRO DE ADMINISTRADOR", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "> Insira o e-mail empresarial: ", false, true },
                    { "> Insira a senha: ", false, true }
                  },
                  INICIO,
                  MEIO
                );

                string email = interfaceGrafica.input();
                string senha = interfaceGrafica.input();


                if (loja.adicionarAdministrador(Administrador(email, senha))) {
                  // Atualiza tela
                  interfaceGrafica.limparTela();
                  interfaceGrafica.setTelas(1);
                  interfaceGrafica.renderTela();

                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "Cadastro realizado com sucesso!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );

                } else {
                  // Atualiza tela
                  interfaceGrafica.limparTela();
                  interfaceGrafica.setTelas(1);
                  interfaceGrafica.renderTela();

                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "E-mail já cadastrado!" },
                      { "" },
                      { "Voltando para a Área do Administrador em 5 Segundos..." }
                    },
                    MEIO,
                    MEIO
                  );
                }

                Sleep(5000);
                break;
              }

              case ENCERRAR_SESSAO: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "Sessão encerrada!" },
                    { "" },
                    { "Voltando para a Tela Inicial em 5 Segundos..." }
                  },
                  MEIO,
                  MEIO
                );

                Sleep(5000);
                break;
              }

              default: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "Comando não reconhecido!" },
                    { "" },
                    { "Voltando para a Área do Administrador em 5 Segundos..." }
                  },
                  MEIO,
                  MEIO
                );

                Sleep(5000);
                break;
              }
            }

          } while (sessaoAdmin != ENCERRAR_SESSAO);

        } else if (cliente != nullptr) {
          int sessaoCliente;
          enum menuSessao { ACESSAR_PERFIL,
                            REALIZAR_PEDIDO,
                            VISUALIZAR_ESTOQUE,
                            ENCERRAR_SESSAO };

          do {
            // Atualiza tela
            interfaceGrafica.limparTela();
            interfaceGrafica.setTelas(vector<dadosTela>{{"ÁREA DO CLIENTE", 1}});
            interfaceGrafica.renderTela();

            interfaceGrafica.renderTexto(
              0,
              cabecalhoLoja,
              MEIO
            );

            // Cria texto navegável
            interfaceGrafica.renderTexto(
              0,
              vector<dadosTexto> {
                { "1. Acessar Perfil", true },
                { "2. Realizar Pedido", true },
                { "3. Visualizar Estoque", true },
                { "4. Encerrar Sessão", true },
              },
              MEIO,
              MEIO
            );

            interfaceGrafica.renderTexto(
              0,
              vector<dadosTexto> {
                  dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
              },
              MEIO,
              FIM
            );

            sessaoCliente = interfaceGrafica.navegar();

            switch (sessaoCliente) {
              case ACESSAR_PERFIL: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"PERFIL", 1}});
                interfaceGrafica.renderTela();

                string strSaldo = to_string(cliente->getSaldo());

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "E-mail: " + cliente->getEmail() },
                    { "CPF: " + cliente->getCpf() },
                    { "Endereço: " + cliente->getEndereco() },
                    { "Saldo: R$" + strSaldo.substr(0, strSaldo.find(".")+3) }
                  },
                  MEIO,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "Pressione Enter para Retornar", true }
                  },
                  MEIO,
                  FIM
                );

                interfaceGrafica.navegar(false);
                break;
              }

              case REALIZAR_PEDIDO: {
                int eventoPedido;
                enum menuPedido { SORTIDO,
                                  KIT,
                                  CANCELAR_PEDIDO };

                do {
                  // Atualiza tela
                  interfaceGrafica.limparTela();
                  interfaceGrafica.setTelas(vector<dadosTela>{{"PEDIDO", 1}});
                  interfaceGrafica.renderTela();

                  interfaceGrafica.renderTexto(
                    0,
                    cabecalhoLoja,
                    MEIO
                  );

                  // Cria texto navegável
                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                      { "1. Realizar pedido Sortido", true },
                      { "2. Realizar pedido de um Kit", true },
                      { "3. Voltar para Área do Cliente", true },
                    },
                    MEIO,
                    MEIO
                  );

                  interfaceGrafica.renderTexto(
                    0,
                    vector<dadosTexto> {
                        dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                    },
                    MEIO,
                    FIM
                  );

                  eventoPedido = interfaceGrafica.navegar();

                  Pedido pedido;

                  switch (eventoPedido) {
                    case SORTIDO: {
                      int eventoSortido;
                      enum menuSortido { ADICIONAR_SORTIDO,
                                         REMOVER_SORTIDO,
                                         VISUALIZAR_SORTIDO,
                                         REALIZAR_SORTIDO,
                                         CANCELAR_SORTIDO };

                      do {
                        // Atualiza tela
                        interfaceGrafica.limparTela();
                        interfaceGrafica.setTelas(vector<dadosTela>{{"PEDIDO - SORTIDO", 1}});
                        interfaceGrafica.renderTela();

                        interfaceGrafica.renderTexto(
                          0,
                          cabecalhoLoja,
                          MEIO
                        );

                        // Cria texto navegável
                        interfaceGrafica.renderTexto(
                          0,
                          vector<dadosTexto> {
                            { "1. Adicionar um Item", true },
                            { "2. Remover um Item", true },
                            { "3. Visualizar Pedido", true },
                            { "4. Realizar Pedido", true },
                            { "5. Cancelar Pedido", true }
                          },
                          MEIO,
                          MEIO
                        );

                        interfaceGrafica.renderTexto(
                          0,
                          vector<dadosTexto> {
                              dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                          },
                          MEIO,
                          FIM
                        );

                        eventoSortido = interfaceGrafica.navegar();

                        switch (eventoSortido) {
                          case ADICIONAR_SORTIDO: {
                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(vector<dadosTela>{{"ADICIONAR PRODUTO", 1}});
                            interfaceGrafica.renderTela();

                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            // Cria texto navegável
                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "1. Processador", true },
                                { "2. Placa Mãe", true },
                                { "3. Memória RAM", true },
                                { "4. Placa de Video", true },
                                { "5. Memória Secundaria", true },
                                { "6. Gabinete", true },
                                { "7. Fonte de Alimentação", true },
                              },
                              MEIO,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                  dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                              },
                              MEIO,
                              FIM
                            );

                            int tipoProduto = interfaceGrafica.navegar();
                            string idProduto = loja.visualizarProdutos(interfaceGrafica, tipoProduto);

                            if (idProduto == "") {
                              eventoSortido = CANCELAR_SORTIDO;
                              break;
                            }

                            Produto* produto = loja.getProduto(idProduto);

                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(1);
                            interfaceGrafica.renderTela();

                            if (produto == nullptr) {
                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {
                                  { "Este produto não foi encontrado! Cancelando Operação!" },
                                  { "" },
                                  { "Retornando em 5 Segundos..." }
                                },
                                MEIO,
                                MEIO
                              );

                              Sleep(5000);
                              break;
                            }

                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(vector<dadosTela>{{produto->getMarca() + " " + produto->getModelo(), 1}});
                            interfaceGrafica.renderTela();

                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "> Insira a quantidade do Produto a ser adicionada: ", false, true },
                              },
                              INICIO,
                              MEIO
                            );

                            int quantidade = interfaceGrafica.inputNumber<int>();

                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(1);
                            interfaceGrafica.renderTela();

                            if (pedido.adicionarItens(*produto, quantidade)) {
                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {{ produto->getMarca() + " " + produto->getModelo() + " adicionado ao Pedido!" },
                                                    { "" },
                                                    { "Retornando em 5 Segundos..." }},
                                MEIO,
                                MEIO
                              );

                            } else {
                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {
                                  { "Não foi possível adicionar o produto ao Pedido!" },
                                  { "" },
                                  { "Retornando em 5 Segundos..." }
                                },
                                MEIO,
                                MEIO
                              );
                            }

                            Sleep(5000);
                            break;
                          }

                          case REMOVER_SORTIDO: {
                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(vector<dadosTela>{{"REMOVER PRODUTO", 1}});
                            interfaceGrafica.renderTela();

                            int indiceItem = pedido.imprimirPedido(interfaceGrafica, true);

                            if(pedido.getItem(0) != nullptr) { // Caso o produto existir
                              Produto* produto = pedido.getItem(indiceItem);

                              // Atualiza tela
                              interfaceGrafica.limparTela();
                              interfaceGrafica.renderTela();

                              if (produto == nullptr) {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {
                                    { "Este produto não foi encontrado! Cancelando Operação!" },
                                    { "" },
                                    { "Retornando em 5 Segundos..." }
                                  },
                                  MEIO,
                                  MEIO
                                );

                                Sleep(5000);
                                break;
                              }

                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {
                                  { "> Insira quantas unidades do Item serão removidas: ", false, true },
                                },
                                INICIO,
                                MEIO
                              );

                              int quantidade = interfaceGrafica.inputNumber<int>();

                              // Atualiza tela
                              interfaceGrafica.limparTela();
                              interfaceGrafica.renderTela();

                              if (pedido.removerItens(*produto, quantidade)) {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {{ produto->getMarca() + " " + produto->getModelo() + " removido do Pedido!" },
                                                      { "" },
                                                      { "Retornando em 5 Segundos..." }},
                                  MEIO,
                                  MEIO
                                );

                              } else {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {
                                    { "Não foi possível remover o item do Pedido!" },
                                    { "" },
                                    { "Retornando em 5 Segundos..." }
                                  },
                                  MEIO,
                                  MEIO
                                );
                              }
                            }

                            Sleep(5000);
                            break;
                          }

                          case VISUALIZAR_SORTIDO: {
                            pedido.imprimirPedido(interfaceGrafica, false);
                            break;
                          }

                          case REALIZAR_SORTIDO: {
                            string pagamento[] = {"Crédito", "Débito", "Boleto", "Pix"};

                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(vector<dadosTela>{{"PAGAMENTO", 1}});
                            interfaceGrafica.renderTela();


                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            // Cria texto navegável
                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "1. Crédito", true },
                                { "2. Débito", true },
                                { "3. Boleto", true },
                                { "4. Pix", true }
                              },
                              MEIO,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                  dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                              },
                              MEIO,
                              FIM
                            );

                            int forma = interfaceGrafica.navegar();

                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(1);
                            interfaceGrafica.renderTela();

                            if(forma >= 0 && forma <= 3) {
                              if(loja.removerProdutos(pedido.realizarPedido(cliente, pagamento[forma]))) {
                                pedido.imprimirPedido(interfaceGrafica);
                                eventoSortido = CANCELAR_SORTIDO;

                                // Atualiza tela
                                interfaceGrafica.limparTela();
                                interfaceGrafica.setTelas(1);
                                interfaceGrafica.renderTela();

                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {
                                    { "Obrigado por comprar na PC++. Volte Sempre!" },
                                    { "" },
                                    { "Retornando em 5 Segundos..." }
                                  },
                                  MEIO,
                                  MEIO
                                );

                                Sleep(5000);
                              } else {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {
                                    { "Houve um problema na realização do Kit!" },
                                    { "" },
                                    { "Retornando em 5 Segundos..." }
                                  },
                                  MEIO,
                                  MEIO
                                );

                                Sleep(5000);
                              }

                            } else {
                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {
                                  { "Comando não reconhecido! Tente novamente." },
                                  { "" },
                                  { "Retornando em 5 Segundos..." }
                                },
                                MEIO,
                                MEIO
                              );

                            Sleep(5000);
                            }

                            break;
                          }

                          case CANCELAR_SORTIDO: {
                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(1);
                            interfaceGrafica.renderTela();

                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "Pedido cancelado!" },
                                { "" },
                                { "Retornando em 5 Segundos..." }
                              },
                              MEIO,
                              MEIO
                            );

                            Sleep(5000);
                            break;
                          }

                          default: {
                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "Comando não reconhecido! Tente novamente." },
                                { "" },
                                { "Retornando em 5 Segundos..." }
                              },
                              MEIO,
                              MEIO
                            );

                            Sleep(5000);
                            break;
                          }
                        }
                      } while (eventoSortido != CANCELAR_SORTIDO);

                      break;
                    }

                    case KIT: {
                      // Atualiza tela
                      interfaceGrafica.limparTela();
                      interfaceGrafica.setTelas(vector<dadosTela>{{"PEDIDO - KIT", 1}});
                      interfaceGrafica.renderTela();

                      interfaceGrafica.renderTexto(
                        0,
                        cabecalhoLoja,
                        MEIO
                      );

                      // Cria texto navegável
                      interfaceGrafica.renderTexto(
                        0,
                        vector<dadosTexto> {
                          { "Para montar o Kit, percorreremos as seguintes etapas:" },
                          { "" },
                          { "1. Processador" },
                          { "2. Placa Mãe" },
                          { "3. Memória RAM" },
                          { "4. Placa De Vídeo" },
                          { "5. Memória Secundaria" },
                          { "6. Gabinete" },
                          { "7. Fonte De Alimentação" }
                        },
                        MEIO,
                        MEIO
                      );

                      interfaceGrafica.renderTexto(
                        0,
                        vector<dadosTexto> {
                          { "Pressione Enter para Continuar", true }
                        },
                        MEIO,
                        FIM
                      );

                      interfaceGrafica.navegar(false);

                      int eventoKit;
                      string comparador = "";
                      string fatorForma = "";
                      int tipoDado = -1;
                      enum menuKit { DEFINIR_KIT,
                                     VISUALIZAR_KIT,
                                     CANCELAR_KIT };

                      // Estrutura para facilitar o acesso e impressão na interface
                      struct menuKitProdutos {
                        string titulo;
                        vector<string> linhas;
                      };

                      // Menu de cada produto
                      menuKitProdutos menu[] = {
                        {
                          "PROCESSADOR",
                          {
                            "O microprocessador, chamado também de Processador, é um circuito integrado que realiza",
                            "as funções de cálculo e tomada de decisão de um computador. Como todos os computadores e",
                            "equipamentos eletrônicos baseiam-se nele para executar suas funções, pode-se dizer que o",
                            "processador é o cérebro do computador por realizar todas estas funções."
                          }
                        },
                        {
                          "PLACA MÃE",
                          {
                            "A placa-mãe é a parte do computador responsável por conectar e interligar todos os",
                            "componentes, ou seja, processador com memória RAM, disco rígido, placa gráfica",
                            "entre outros. Além de permitir o tráfego de informação, a placa também alimenta",
                            "alguns periféricos com a energia elétrica que recebe da fonte de alimentação."
                          }
                        },
                        {
                          "MEMÓRIA RAM",
                          {
                            "A memória de acesso aleatório (do inglês Random Access Memory ou apenas RAM),",
                            "também chamado de memória volátil, é uma memória temporária computacional de acesso",
                            "rápido é uma memória temporária computacional de acesso rápido, ou seja, um local de",
                            "armazenamento temporário de informações digitais usada pelo processador"
                          }
                        },
                        {
                          "PLACA DE VÍDEO",
                          {
                            "A Placa de Vídeo é uma placa de expansão que gera uma saída de alimentação de imagens",
                            "para um dispositivo de exibição. É responsável por gerar e renderizar gráficos tanto 2D",
                            "quanto 3D. Frequentemente, estas são anunciadas como placas gráficas discretas ou",
                            "dedicadas, enfatizando a dinstinção entre elas e as placas gráficas integradas."
                          }
                        },
                        {
                          "MEMÓRIA SECUNDÁRIA",
                          {
                            "Memórias Secundárias são os componentes responsáveis por armazenar dados",
                            "permanentemente. Estas memórias secundárias mantêm os dados guardados mesmo após o",
                            "desligamento do computador."
                          }
                        },
                        {
                          "GABINETE",
                          {
                            "Um gabinete de computador, também conhecido como case, caixa, chassis, carcaça ou torre,",
                            "é o compartimento que contém a maioria dos componentes de um computador, em excessão",
                            "dos periféricos."
                          }
                        },
                        {
                          "FONTE DE ALIMENTAÇÃO",
                          {
                            "A Unidade de Fonte de Alimentação converte a corrente alternada vinda da rede elétrica em",
                            "corrente contínua regulada para os componentes internos de um computador. Os computadores",
                            "modernos usam universalmente fontes de alimentação comutadas. Algumas fontes de alimentação",
                            "possuem um interruptor manual para selecionar a tensão de entrada, enquanto outras se",
                            "adaptam automaticamente à tensão da rede."
                          }
                        }
                      };

                      // Percorre por cada produto em sequência
                      for(int tipoProduto = 0; tipoProduto < 7; tipoProduto++) {
                        bool prosseguirKit = false;

                        do {
                          // Atualiza tela
                          interfaceGrafica.limparTela();
                          interfaceGrafica.setTelas(vector<dadosTela>{{menu[tipoProduto].titulo, 1}});
                          interfaceGrafica.renderTela();

                          interfaceGrafica.renderTexto(
                            0,
                            cabecalhoLoja,
                            MEIO
                          );

                          vector<dadosTexto> texto;


                          for (auto linha: menu[tipoProduto].linhas)
                            texto.push_back({ linha });

                          // Cria texto navegável
                          texto.insert(
                            texto.end(),
                            {
                              { "" },
                              { "1. Definir " + menu[tipoProduto].titulo, true },
                              { "2. Visualizar Progresso", true },
                              { "3. Cancelar Pedido", true },
                            }
                          );

                          interfaceGrafica.renderTexto(
                              0,
                              texto,
                              MEIO,
                              MEIO
                          );

                          interfaceGrafica.renderTexto(
                            0,
                            vector<dadosTexto> {
                                { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                            },
                            MEIO,
                            FIM
                          );

                          eventoKit = interfaceGrafica.navegar();

                          switch (eventoKit) {
                            case DEFINIR_KIT: {
                              string idProduto = loja.visualizarProdutos(interfaceGrafica, tipoProduto, tipoDado, comparador);

                              if (idProduto == "") {
                                eventoKit = CANCELAR_KIT;
                                break;
                              };

                              Produto* produto = loja.getProduto(idProduto);

                              // Realiza a filtragem para cada tipo que necessita dependência de um produto anterior
                              switch (tipoProduto) {
                                case 0:
                                  tipoDado = 0;
                                  if (Processador *processador = dynamic_cast<Processador*>(produto))
                                    comparador = processador->getSocket();
                                  break;

                                case 1:
                                  tipoDado = 1;
                                  if (PlacaMae *placaMae = dynamic_cast<PlacaMae*>(produto)) {
                                    comparador = placaMae->getMemoria();
                                    fatorForma = placaMae->getFatorForma();
                                  }
                                  break;

                                case 4:
                                  tipoDado = 2;
                                  comparador = fatorForma;
                                  break;

                                case 5:
                                  tipoDado = 3;
                                  comparador = fatorForma;
                                  break;

                                default:
                                  tipoDado = -1;
                                  break;
                              }

                              // Atualiza tela
                              interfaceGrafica.limparTela();
                              interfaceGrafica.setTelas(1);
                              interfaceGrafica.renderTela();

                              if (produto == nullptr) {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {
                                    { "Este produto não foi encontrado! Cancelando operação." },
                                    { "" },
                                    { "Retornando em 5 Segundos..." }
                                  },
                                  MEIO,
                                  MEIO
                                );

                                Sleep(5000);
                                break;
                              }

                              if (pedido.adicionarItens(*produto, 1)) {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {{ produto->getMarca() + " " + produto->getModelo() + " adicionado ao Kit!" },
                                                      { "" },
                                                      { "Retornando em 5 Segundos..." }},
                                  MEIO,
                                  MEIO
                                );

                                prosseguirKit = true;
                              } else {
                                interfaceGrafica.renderTexto(
                                  0,
                                  cabecalhoLoja,
                                  MEIO
                                );

                                interfaceGrafica.renderTexto(
                                  0,
                                  vector<dadosTexto> {
                                    { "Não foi possível adicionar o produto ao Kit!" },
                                    { "" },
                                    { "Retornando em 5 Segundos..." }
                                  },
                                  MEIO,
                                  MEIO
                                );
                              }

                              Sleep(5000);
                              break;
                            }

                            case VISUALIZAR_KIT: {
                              pedido.imprimirPedido(interfaceGrafica);
                              break;
                            }

                            case CANCELAR_KIT: {
                              // Atualiza tela
                              interfaceGrafica.limparTela();
                              interfaceGrafica.setTelas(1);
                              interfaceGrafica.renderTela();

                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {
                                  { "Pedido cancelado!" },
                                  { "" },
                                  { "Retornando em 5 Segundos..." }
                                },
                                MEIO,
                                MEIO
                              );

                              Sleep(5000);
                              break;
                            }

                            default: {
                              // Atualiza tela
                              interfaceGrafica.limparTela();
                              interfaceGrafica.renderTela();

                              interfaceGrafica.renderTexto(
                                0,
                                cabecalhoLoja,
                                MEIO
                              );

                              interfaceGrafica.renderTexto(
                                0,
                                vector<dadosTexto> {
                                  { "Comando não reconhecido! Tente novamente." },
                                  { "" },
                                  { "Retornando em 5 Segundos..." }
                                },
                                MEIO,
                                MEIO
                              );

                              Sleep(5000);
                              break;
                            }
                          }

                        } while (eventoKit != CANCELAR_KIT && !prosseguirKit);

                        if(eventoKit == CANCELAR_KIT)
                          break;
                      }

                      if(eventoKit != CANCELAR_KIT) {
                        // Atualiza tela
                        interfaceGrafica.limparTela();
                        interfaceGrafica.setTelas(vector<dadosTela>{{"PAGAMENTO", 1}});
                        interfaceGrafica.renderTela();

                        interfaceGrafica.renderTexto(
                          0,
                          cabecalhoLoja,
                          MEIO
                        );

                        // Cria texto navegável
                        interfaceGrafica.renderTexto(
                          0,
                          vector<dadosTexto> {
                            { "1. Crédito", true },
                            { "2. Débito", true },
                            { "3. Boleto", true },
                            { "4. Pix", true }
                          },
                          MEIO,
                          MEIO
                        );

                        interfaceGrafica.renderTexto(
                          0,
                          vector<dadosTexto> {
                              dadosTexto { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                          },
                          MEIO,
                          FIM
                        );

                        int forma = interfaceGrafica.navegar();

                        string pagamento[] = {"Crédito", "Débito", "Boleto", "Pix"};

                        // Atualiza tela
                        interfaceGrafica.limparTela();
                        interfaceGrafica.setTelas(1);
                        interfaceGrafica.renderTela();

                        if(forma >= 0 && forma <= 3) {
                          if(loja.removerProdutos(pedido.realizarPedido(cliente, pagamento[forma]))) {
                            pedido.imprimirPedido(interfaceGrafica);

                            // Atualiza tela
                            interfaceGrafica.limparTela();
                            interfaceGrafica.setTelas(1);
                            interfaceGrafica.renderTela();

                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "Obrigado por comprar na PC++. Volte Sempre!" },
                                { "" },
                                { "Retornando em 5 Segundos..." }
                              },
                              MEIO,
                              MEIO
                            );

                            Sleep(5000);
                          } else {
                            interfaceGrafica.renderTexto(
                              0,
                              cabecalhoLoja,
                              MEIO
                            );

                            interfaceGrafica.renderTexto(
                              0,
                              vector<dadosTexto> {
                                { "Houve um erro na realização do Kit!" },
                                { "" },
                                { "Retornando em 5 Segundos..." }
                              },
                              MEIO,
                              MEIO
                            );

                            Sleep(5000);
                          }
                        } else {
                          interfaceGrafica.renderTexto(
                            0,
                            cabecalhoLoja,
                            MEIO
                          );

                          interfaceGrafica.renderTexto(
                            0,
                            vector<dadosTexto> {
                              { "Comando não reconhecido! Tente novamente." },
                              { "" },
                              { "Retornando em 5 Segundos..." }
                            },
                            MEIO,
                            MEIO
                          );

                          Sleep(5000);
                        }
                      }

                      break;
                    }

                    case CANCELAR_PEDIDO: {
                      // Atualiza tela
                      interfaceGrafica.limparTela();
                      interfaceGrafica.setTelas(1);
                      interfaceGrafica.renderTela();

                      interfaceGrafica.renderTexto(
                        0,
                        cabecalhoLoja,
                        MEIO
                      );

                      interfaceGrafica.renderTexto(
                        0,
                        vector<dadosTexto> {
                          { "Pedido cancelado!" },
                          { "" },
                          { "Retornando em 5 Segundos..." }
                        },
                        MEIO,
                        MEIO
                      );

                      Sleep(5000);
                      break;
                    }

                    default: {
                      // Atualiza tela
                      interfaceGrafica.limparTela();
                      interfaceGrafica.renderTela();

                      interfaceGrafica.renderTexto(
                        0,
                        cabecalhoLoja,
                        MEIO
                      );

                      interfaceGrafica.renderTexto(
                        0,
                        vector<dadosTexto> {
                          { "Comando não reconhecido! Tente novamente." },
                          { "" },
                          { "Retornando em 5 Segundos..." }
                        },
                        MEIO,
                        MEIO
                      );

                      Sleep(5000);
                      break;
                    }
                  }

                } while (eventoPedido != CANCELAR_PEDIDO);

                break;
              }

              case VISUALIZAR_ESTOQUE: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(vector<dadosTela>{{"ESTOQUE", 1}});
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                // Cria texto navegável
                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "1. Processador", true },
                    { "2. Placa Mãe", true },
                    { "3. Memória RAM", true },
                    { "4. Placa de Vídeo", true },
                    { "5. Memória Secundaria", true },
                    { "6. Gabinete", true },
                    { "7. Fonte de Alimentação", true }
                  },
                  MEIO,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                      { "▲ Mover Para Cima / ▼ Mover para Baixo" }
                  },
                  MEIO,
                  FIM
                );

                int tipoProduto = interfaceGrafica.navegar();
                loja.visualizarProdutos(interfaceGrafica, tipoProduto);
                break;
              }

              case ENCERRAR_SESSAO: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "Sessão encerrada!" },
                    { "" },
                    { "Retornando a Tela Inicial em 5 Segundos..." }
                  },
                  MEIO,
                  MEIO
                );

                Sleep(5000);
                break;
              }

              default: {
                // Atualiza tela
                interfaceGrafica.limparTela();
                interfaceGrafica.setTelas(1);
                interfaceGrafica.renderTela();

                interfaceGrafica.renderTexto(
                  0,
                  cabecalhoLoja,
                  MEIO
                );

                interfaceGrafica.renderTexto(
                  0,
                  vector<dadosTexto> {
                    { "Comando não reconhecido! Tente novamente." },
                    { "" },
                    { "Retornando em 5 Segundos..." }
                  },
                  MEIO,
                  MEIO
                );

                Sleep(5000);
                break;
              }
            }

          } while (sessaoCliente != ENCERRAR_SESSAO);

        } else {
          // Atualiza tela
          interfaceGrafica.limparTela();
          interfaceGrafica.setTelas(1);
          interfaceGrafica.renderTela();

          interfaceGrafica.renderTexto(
            0,
            cabecalhoLoja,
            MEIO
          );

          interfaceGrafica.renderTexto(
            0,
            vector<dadosTexto> {
              { "E-mail ou senha incorretos! Tente novamente." },
              { "" },
              { "Retornando a Tela Inicial em 5 Segundos..." }
            },
            MEIO,
            MEIO
          );

          Sleep(5000);
        }

        break;
      }

      case CADASTRO:{
        // Atualiza tela
        interfaceGrafica.limparTela();
        interfaceGrafica.setTelas(vector<dadosTela>{{"CADASTRO", 1}});
        interfaceGrafica.renderTela();

        interfaceGrafica.renderTexto(
          0,
          cabecalhoLoja,
          MEIO
        );

        interfaceGrafica.renderTexto(
          0,
          vector<dadosTexto> {
            { "> Insira o seu e-mail: ", false, true },
            { "> Insira a sua senha: ", false, true },
            { "> Insira o seu CPF: ", false, true },
            { "> Insira o seu endereço: ", false, true }
          },
          INICIO,
          MEIO
        );

        string email = interfaceGrafica.input();
        string senha = interfaceGrafica.input();
        string cpf = interfaceGrafica.input();
        string endereco = interfaceGrafica.input();

        if (loja.adicionarCliente(Cliente(email, senha, cpf, endereco))) {
          // Atualiza tela
          interfaceGrafica.limparTela();
          interfaceGrafica.setTelas(1);
          interfaceGrafica.renderTela();

          interfaceGrafica.renderTexto(
            0,
            cabecalhoLoja,
            MEIO
          );

          interfaceGrafica.renderTexto(
            0,
            vector<dadosTexto> {
              { "Cadastro realizado com sucesso!" },
              { "" },
              { "Retornando a Tela Inicial em 5 Segundos..." }
            },
            MEIO,
            MEIO
          );

        } else {
          // Atualiza tela
          interfaceGrafica.limparTela();
          interfaceGrafica.setTelas(1);
          interfaceGrafica.renderTela();

          interfaceGrafica.renderTexto(
            0,
            cabecalhoLoja,
            MEIO
          );

          interfaceGrafica.renderTexto(
            0,
            vector<dadosTexto> {
              { "E-mail já cadastrado!" },
              { "" },
              { "Retornando a Tela Inicial em 5 Segundos..." }
            },
            MEIO,
            MEIO
          );
        }

        Sleep(5000);
        break;
      }

      case ENCERRAR_APLICACAO: {
        // Atualiza tela
        interfaceGrafica.limparTela();
        interfaceGrafica.renderTela();

        interfaceGrafica.renderTexto(
          0,
          cabecalhoLoja,
          MEIO
        );

        interfaceGrafica.renderTexto(
          0,
          vector<dadosTexto> {
            { "Obrigado por usar nosso aplicativo!" },
            { "" },
            { "Encerrando o aplicativo em 5 Segundos..." }
          },
          MEIO,
          MEIO
        );

        Sleep(5000);
        break;
      }

      default: {
        // Atualiza tela
        interfaceGrafica.limparTela();
        interfaceGrafica.setTelas(1);
        interfaceGrafica.renderTela();

        interfaceGrafica.renderTexto(
          0,
          cabecalhoLoja,
          MEIO
        );

        interfaceGrafica.renderTexto(
          0,
          vector<dadosTexto> {
            { "Comando não reconhecido! Tente novamente." },
            { "" },
            { "Retornando em 5 Segundos..." }
          },
          MEIO,
          MEIO
        );

        Sleep(5000);
        break;
      }
    }

  } while (eventoUsuario != ENCERRAR_APLICACAO);

  return 0;
}
