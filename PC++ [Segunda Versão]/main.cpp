#include <windows.h>
#include <conio.h>
#include <type_traits>

#include "Serializador.cpp"
#include "Loja.cpp"
#include "Pedido.cpp"

#include "Produto.cpp"
#include "Processador.cpp"
#include "PlacaMae.cpp"
#include "MemoriaRAM.cpp"
#include "FonteDeAlimentacao.cpp"
#include "PlacaDeVideo.cpp"
#include "MemoriaSecundaria.cpp"
#include "Gabinete.cpp"

#include "Usuario.cpp"
#include "Administrador.cpp"
#include "Cliente.cpp"

wstring strToWideStr(const char*);

void apaga(int);
int selecionar(string, int, int);
string linha(string);

template <typename T>
T entrada(string, string);

int main() {
  SetConsoleOutputCP(65001);
  system("color 06");
  system("mode con: cols=70 lines=30");

  cout << fixed << setprecision(2);

  Loja loja;
  loja.adicionarAdministrador(Administrador("mestre@adm.pcplusplus.com", "oadmtaon"));

  int eventoUsuario;
  enum menuUsuario { LOGIN = 1,
                     CADASTRO,
                     ENCERRAR_APLICACAO };

  do {
    system("cls");

    cout << endl
         << "            _/_/_/      _/_/_/          _/          _/\n"
         << "           _/    _/  _/                _/          _/\n"
         << "          _/_/_/    _/            _/_/_/_/_/  _/_/_/_/_/\n"
         << "         _/        _/                _/          _/\n"
         << "        _/          _/_/_/          _/          _/      v2.0.0\n"
         << endl << endl
         << "1. Login" << endl
         << "2. Realizar Cadastro" << endl
         << "3. Encerrar Aplicação"<< endl << endl;
    eventoUsuario = selecionar("> Selecionar Comando: ", 1, 3);

    switch(eventoUsuario){
      case LOGIN:{
        system("cls");

        string email, senha;

        cout << "LOGIN" << endl << endl;

        email = linha("> Insira o seu email: ");
        cout << endl;

        senha = linha("> Insira sua senha: ");
        cout << endl;

        Administrador* administrador = loja.loginAdministrador(email, senha);
        Cliente* cliente = loja.loginCliente(email, senha);

        if(administrador != nullptr) {

          int eventoSessao;
          enum menuSessao { ADICIONAR_PRODUTO = 1,
                            REPOR_PRODUTO,
                            REMOVER_PRODUTO,
                            VISUALIZAR_ESTOQUE,
                            CADASTRAR_ADM,
                            ENCERRAR_SESSAO };

          do {
            system("cls");

            cout << "ÁREA DO ADMINISTRADOR - " << administrador->getEmail() << endl << endl
                 << "1. Adicionar Produto" << endl
                 << "2. Repor Produto" << endl
                 << "3. Remover Produto" << endl
                 << "4. Visualizar Estoque" << endl
                 << "5. Cadastrar Administrador" << endl
                 << "6. Encerrar Sessão" << endl << endl;
            eventoSessao = selecionar("> Selecionar Opção: ", 1, 6);

            switch (eventoSessao) {
              case ADICIONAR_PRODUTO: {
                system("cls");

                cout << "ADICIONAR PRODUTO" << endl << endl
                     << "1. Processador" << endl
                     << "2. Placa Mãe" << endl
                     << "3. Memória RAM" << endl
                     << "4. Placa De Vídeo" << endl
                     << "5. Memória Secundaria" << endl
                     << "6. Gabinete" << endl
                     << "7. Fonte De Alimentação" << endl << endl;
                int tipoProduto = selecionar("> Selecionar Tipo de Produto: ", 1, 7);

                system("cls");

                string modelo, marca, ID;
                float preco;
                int quantidade;

                modelo = linha("> Insira o Modelo do Produto: ");
                cout << endl;

                marca = linha("> Insira a Marca do Produto: ");
                cout << endl;

                ID = linha("> Insira o ID do Produto: ");
                cout << endl;

                preco = entrada<float>("> Insira o Preço do Produto: ", "Entrada Inválida!");

                quantidade = entrada<int>("> Insira a Quantidade do Produto: ", "Entrada Inválida!");

                switch (tipoProduto - 1) {
                  case PROCESSADOR: {
                    int cores, threads;
                    float frequencia;
                    string socket;

                    cores = entrada<int>("> Insira a Quantidade de Cores do Processador: ", "Entrada Inválida!");

                    threads = entrada<int>("> Insira a Quantidade de Threads do Processador: ", "Entrada Inválida!");

                    frequencia = entrada<float>("> Insira a Frequência do Processador em GHz: ", "Entrada Inválida!");

                    socket = linha("> Insira o Socket do Processador: ");
                    cout << endl;

                    bool sucesso = loja.adicionarProduto(new Processador(
                      modelo, marca, ID, preco, quantidade,
                      cores, threads, frequencia, socket
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                  case PLACAMAE: {
                    string plataforma, socket, memoria, fatorForma;

                    plataforma = linha("> Insira a Plataforma da Placa Mãe: ");
                    cout << endl;

                    socket = linha("> Insira o Socket da Placa Mãe: ");
                    cout << endl;

                    memoria = linha("> Insira o Tipo de Memoria da Placa Mãe: ");
                    cout << endl;

                    fatorForma = linha("> Insira o Fator Forma da Placa Mãe: ");
                    cout << endl;

                    PlacaMae placaMae(
                      modelo, marca, ID, preco, quantidade,
                      plataforma, socket, memoria, fatorForma
                    );

                    bool sucesso = loja.adicionarProduto(new PlacaMae(
                      modelo, marca, ID, preco, quantidade,
                      plataforma, socket, memoria, fatorForma
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                  case MEMORIARAM: {
                    int capacidade, frequencia;
                    string DDR;

                    capacidade = entrada<int>("> Insira a Capacidade da Memória RAM: ", "Entrada Inválida!");

                    frequencia = entrada<int>("> Insira a Frequência da Memória RAM em MHz: ", "Entrada Inválida!");

                    DDR = linha("> Insira o DDR da Memoria RAM: ");
                    cout << endl;

                    bool sucesso = loja.adicionarProduto(new MemoriaRAM(
                      modelo, marca, ID, preco, quantidade,
                      capacidade, frequencia, DDR
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                  case PLACADEVIDEO: {
                    unsigned short int memoria, frequencia, bits;
                    string tipoMemoria;

                    memoria = entrada<int>("> Insira a Quantidade de VRAM da Placa De Vídeo: ", "Entrada Inválida!");

                    tipoMemoria = linha("> Insira o Tipo de Memória da Placa De Vídeo: ");
                    cout << endl;

                    frequencia = entrada<int>("> Insira a Frequência da Placa De Vídeo em MHz: ", "Entrada Inválida!");

                    bits = entrada<int>("> Insira a Quantidade de Bits da Placa De Vídeo: ", "Entrada Inválida!");

                    bool sucesso = loja.adicionarProduto(new PlacaDeVideo(
                      modelo, marca, ID, preco, quantidade,
                      memoria, tipoMemoria, frequencia, bits
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                  case MEMORIASECUNDARIA: {
                    string tipo;
                    int capacidade;

                    tipo = linha("> Insira o Tipo de Memória Secundária: ");
                    cout << endl;

                    capacidade = entrada<int>("> Insira a Capacidade da Memória Secundária: ", "Entrada Inválida!");

                    bool sucesso = loja.adicionarProduto(new MemoriaSecundaria(
                      modelo, marca, ID, preco, quantidade,
                      tipo, capacidade
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                  case GABINETE: {
                    string fatorForma, tamanho;

                    fatorForma = linha("> Insira o Fator Forma do Gabinete: ");
                    cout << endl;

                    tamanho = linha("> Insira o Tamanho do Gabinete: ");
                    cout << endl;

                    bool sucesso = loja.adicionarProduto(new Gabinete(
                      modelo, marca, ID, preco, quantidade,
                      fatorForma, tamanho
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                  case FONTEDEALIMENTACAO: {
                    int potencia;
                    string fatorForma;

                    potencia = entrada<int>("> Insira a Potência da Fonte De Alimentação: ", "Entrada Inválida!");

                    fatorForma = linha("> Insira o Tamanho da Fonte De Alimentação: ");
                    cout << endl;

                    bool sucesso = loja.adicionarProduto(new FonteDeAlimentacao(
                      modelo, marca, ID, preco, quantidade,
                      potencia, fatorForma
                    ));

                    if (sucesso)
                      cout << "O Produto foi adicionado com sucesso!" << endl << endl;
                    else
                      cout << "O Produto não pôde ser adicionado!" << endl << endl;
                    break;
                  }
                }

                system("pause");
                break;
              }
              case REPOR_PRODUTO: {
                system("cls");

                cout << "REPOR PRODUTO" << endl << endl
                     << "1. Processador" << endl
                     << "2. Placa Mãe" << endl
                     << "3. Memória RAM" << endl
                     << "4. Placa De Vídeo" << endl
                     << "5. Memória Secundaria" << endl
                     << "6. Gabinete" << endl
                     << "7. Fonte De Alimentação" << endl << endl;
                int tipoProduto = selecionar("> Selecionar Tipo de Produto: ", 1, 7);

                system("cls");

                vector<string> listaIDs = loja.imprimirEstoque(tipoProduto - 1);

                int indiceProduto = entrada<int>("> Insira o Índice do Produto Desejado: ", "Entrada Inválida!");

                Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                if (produto == nullptr) {
                  cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                  system("pause");
                  break;
                }

                cout << "> Insira a quantidade do Produto a ser adicionada: ";

                int quantidade = selecionar("> Insira a quantidade do Produto a ser adicionada: ", 1, produto->getQuantidade());
                cout << endl;

                if (loja.adicionarProduto(produto, quantidade))
                  cout << produto->getMarca() << " " << produto->getModelo() << " foi reposto!" << endl << endl;
                else
                  cout << "Não foi possível repor o Produto!" << endl << endl;

                break;
              }
              case REMOVER_PRODUTO: {
                system("cls");

                cout << "REMOVER PRODUTO" << endl << endl
                     << "1. Processador" << endl
                     << "2. Placa Mãe" << endl
                     << "3. Memória RAM" << endl
                     << "4. Placa De Vídeo" << endl
                     << "5. Memória Secundaria" << endl
                     << "6. Gabinete" << endl
                     << "7. Fonte De Alimentação" << endl << endl;
                int tipoProduto = selecionar("> Selecionar Tipo de Produto: ", 1, 7);

                system("cls");

                vector<string> listaIDs = loja.imprimirEstoque(tipoProduto - 1);

                int indiceProduto = entrada<int>("> Insira o Índice do Produto Desejado: ", "Entrada Inválida!");

                Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                if (produto == nullptr) {
                  cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                  system("pause");
                  break;
                }

                int quantidade = selecionar("> Insira a quantidade do Produto a ser adicionada: ", 1, produto->getQuantidade());

                bool sucesso = loja.removerProduto(produto, quantidade);

                system("cls");

                if (sucesso)
                  cout << "O Produto foi Removido com Sucesso!" << endl;
                else
                  cout << "O Produto não pôde ser Removido!" << endl;

                system("pause");
                break;
              }

              case VISUALIZAR_ESTOQUE: {
                system("cls");

                cout << "VISUALIZAR ESTOQUE" << endl << endl
                     << "1. Processador" << endl
                     << "2. Placa Mãe" << endl
                     << "3. Memória RAM" << endl
                     << "4. Placa De Vídeo" << endl
                     << "5. Memória Secundaria" << endl
                     << "6. Gabinete" << endl
                     << "7. Fonte De Alimentação" << endl << endl;
                int tipoProduto = selecionar("> Selecionar Tipo de Produto: ", 1, 7);

                system("cls");
                loja.imprimirEstoque(tipoProduto - 1);

                cout << endl;
                system("pause");
                break;
              }

              case CADASTRAR_ADM: {
                system("cls");

                string email, senha;

                cout << "CADASTRAR ADMINSTRADOR" << endl << endl;

                email = linha("> Insira o seu email empresarial: ");
                cout << endl;

                senha = linha("> Insira sua senha: ");
                cout << endl;

                Administrador administrador(email, senha);

                if (loja.adicionarAdministrador(administrador))
                  cout << endl << "Cadastro realizado com sucesso!" << endl << endl;
                else
                  cout << endl << "E-mail já cadastrado!" << endl << endl;

                system("pause");
                break;
              }

              case ENCERRAR_SESSAO: {
                cout << endl << "Sessão Encerrada!" << endl << endl;

                system("pause");
                break;
              }

              default: {
                cout << endl << "Comando não reconhecido! Tente novamente." << endl << endl;

                system("pause");
                break;
              }
            }

          } while (eventoSessao != ENCERRAR_SESSAO);

        } else if (cliente != nullptr) {

          int eventoSessao;
          enum menuSessao { ACESSAR_PERFIL = 1,
                            REALIZAR_PEDIDO,
                            VISUALIZAR_ESTOQUE,
                            ENCERRAR_SESSAO };

          do {
            system("cls");

            cout << "ÁREA DO CLIENTE" << endl << endl
                 << "1. Acessar Perfil" << endl
                 << "2. Realizar Pedido" << endl
                 << "3. Visualizar Estoque" << endl
                 << "4. Encerrar Sessão" << endl << endl;
            eventoSessao = selecionar("> Selecionar Opção: ", 1, 4);

            switch (eventoSessao) {
              case ACESSAR_PERFIL: {
                system("cls");

                cout << "INFORMAÇÕES DO CLIENTE" << endl << endl
                     << "E-mail: " << cliente->getEmail() << endl
                     << "CPF: " << cliente->getCpf() << endl
                     << "Endereço: " << cliente->getEndereco() << endl
                     << "Saldo: R$" << cliente->getSaldo() << endl << endl;

                system("pause");
                break;
              }

              case REALIZAR_PEDIDO: {
                int eventoPedido;
                enum menuPedido { SORTIDO = 1,
                                  KIT,
                                  CANCELAR_PEDIDO };

                do {
                  system("cls");

                  cout << "REALIZAR PEDIDO" << endl << endl
                       << "1. Realizar pedido Sortido" << endl
                       << "2. Realizar pedido de um Kit" << endl
                       << "3. Voltar para Área do Cliente" << endl << endl;
                  eventoPedido = selecionar("> Selecionar Tipo de Pedido: ", 1, 3);

                  Pedido pedido;

                  switch (eventoPedido) {
                    case SORTIDO: {
                      int eventoSortido;
                      enum menuSortido { ADICIONAR_SORTIDO = 1,
                                         REMOVER_SORTIDO,
                                         VISUALIZAR_SORTIDO,
                                         REALIZAR_SORTIDO,
                                         CANCELAR_SORTIDO };

                      do {
                        system("cls");

                        cout << "PEDIDO SORTIDO" << endl << endl
                             << "1. Adicionar um Item" << endl
                             << "2. Remover um Item" << endl
                             << "3. Visualizar Pedido" << endl
                             << "4. Realizar Pedido" << endl
                             << "5. Cancelar Pedido" << endl << endl;
                        eventoSortido = selecionar("> Selecionar Ação: ", 1, 5);

                        switch (eventoSortido) {
                          case ADICIONAR_SORTIDO: {
                            system("cls");

                            cout << "ADICIONAR ITEM AO PEDIDO" << endl << endl
                                 << "1. Processador" << endl
                                 << "2. Placa Mãe" << endl
                                 << "3. Memória RAM" << endl
                                 << "4. Placa De Vídeo" << endl
                                 << "5. Memória Secundaria" << endl
                                 << "6. Gabinete" << endl
                                 << "7. Fonte De Alimentação" << endl << endl;
                            int tipoProduto = selecionar("> Selecionar Tipo de Produto: ", 1, 7);

                            system("cls");

                            vector<string> listaIDs = loja.imprimirEstoque(tipoProduto - 1);

                            int indiceProduto = entrada<int>("> Insira o Índice do Produto Desejado: ", "Entrada Inválida!");

                            Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                            if (produto == nullptr) {
                              cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                              system("pause");
                              break;
                            }

                            int quantidade = selecionar("> Insira a quantidade do Produto a ser adicionada: ", 1, produto->getQuantidade());
                            cout << endl;

                            if (pedido.adicionarItens(*produto, quantidade))
                              cout << produto->getMarca() << " " << produto->getModelo() << " adicionado ao Pedido!" << endl << endl;
                            else
                              cout << "Não foi possível adicionar o produto ao Pedido!" << endl << endl;

                            system("pause");
                            break;
                          }

                          case REMOVER_SORTIDO: {
                            system("cls");

                            pedido.imprimirPedido();
                            cout << endl;

                            if(pedido.getItem(0) != nullptr)
                            {
                              int indiceItem = entrada<int>("> Insira o Índice do Item a ser removido: ", "Entrada Inválida!");

                              Produto* produto = pedido.getItem(indiceItem - 1);

                              if (produto == nullptr) {
                                cout << "Este item não foi encontrado! Cancelando Operação!" << endl << endl;

                                system("pause");
                                break;
                              }

                              int quantidade = selecionar("> Insira quantas unidades do Item serão removidas: ", 1, produto->getQuantidade());
                              cout << endl;

                              if (pedido.removerItens(*produto, quantidade))
                                cout << produto->getMarca() << " " << produto->getModelo() << " removido do Pedido!" << endl << endl;
                              else
                                cout << "Não foi possível remover o item do Pedido!" << endl << endl;
                            }

                            system("pause");
                            break;
                          }

                          case VISUALIZAR_SORTIDO: {
                            system("cls");

                            pedido.imprimirPedido();

                            cout << endl;

                            system("pause");
                            break;
                          }

                          case REALIZAR_SORTIDO: {
                            system("cls");

                            string pagamento[] = {"Crédito", "Débito", "Boleto", "Pix"};

                            cout << "DEFINIR MÉTODO DE PAGAMENTO" << endl << endl
                                 << "1. Crédito" << endl
                                 << "2. Débito" << endl
                                 << "3. Boleto" << endl
                                 << "4. Pix" << endl << endl;

                            int forma = selecionar("> Confirme a operação selecionando uma forma: ", 1, 4);

                            if(forma >= 1 && forma <= 4) {
                              if(loja.removerProdutos(pedido.realizarPedido(cliente, pagamento[forma - 1]))) {
                                system("cls");

                                pedido.imprimirPedido();
                                eventoSortido = CANCELAR_SORTIDO;

                                cout << endl << "Obrigado por Comprar na PC++. Volte Sempre!" << endl << endl;

                                system("pause");
                              } else {
                                cout << endl << "Houve um erro na realização do Pedido :(" << endl << endl;

                                system("pause");
                              }

                            } else {
                              cout << endl << "Comando não reconhecido! Tente novamente." << endl << endl;

                              system("pause");
                            }

                            break;
                          }

                          case CANCELAR_SORTIDO: {
                            cout << endl << "Pedido Cancelado!" << endl << endl;

                            system("pause");
                            break;
                          }

                          default: {
                            cout << endl << "Comando não reconhecido! Tente novamente." << endl << endl;

                            system("pause");
                            break;
                          }
                        }
                      } while (eventoSortido != CANCELAR_SORTIDO);

                      break;
                    }

                    case KIT: {
                      system("cls");

                      cout << "Para montar seu kit você preisará passar pelas seguintes etapas:" << endl << endl
                           << "1. Processador" << endl
                           << "↓" << endl
                           << "2. Placa Mãe" << endl
                           << "↓" << endl
                           << "3. Memória RAM" << endl
                           << "↓" << endl
                           << "4. Placa De Vídeo" << endl
                           << "↓" << endl
                           << "5. Memória Secundaria" << endl
                           << "↓" << endl
                           << "6. Gabinete" << endl
                           << "↓" << endl
                           << "7. Fonte De Alimentação" << endl << endl;

                      system("pause");
                      system("cls");

                      int eventoKit;
                      enum menuKit { DEFINIR_KIT = 1,
                                     VISUALIZAR_KIT,
                                     CANCELAR_KIT };

                      string menuProcessador = "PROCESSADOR\n\nO microprocessador, geralmente chamado apenas de processador, é um circuito integrado que realiza as funções de cálculo e tomada de decisão de um computador. Como todos os computadores e equipamentos eletrônicos baseiam-se nele para executar suas funções, pode-se dizer que o processador é o cérebro do computador por realizar todas estas funções.\n\n1. Definir Processador\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n",
                             menuPlacaMae = "PLACA MÃE\n\nA placa-mãe é a parte do computador responsável por conectar e interligar todos os componentes, ou seja, processador com memória RAM, disco rígido, placa gráfica, entre outros. Além de permitir o tráfego de informação, a placa também alimenta alguns periféricos com a energia elétrica que recebe da fonte de alimentação.\n\n1. Definir Placa Mãe\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n",
                             menuMemoriaRAM = "MEMÓRIA RAM\n\nA memória de acesso aleatório (do inglês Random Access Memory, frequentemente abreviado para RAM), também chamado de memória volátil de leitura e escrita, é uma memória temporária computacional de acesso rápido; ou seja, é um local de armazenamento temporário de informações digitais usada pelo processador para armazenar informações temporariamente, utilizada como memória primária em sistemas eletrônicos digitais.\n\n1. Definir Memória RAM\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n",
                             menuPlacaDeVideo = "PLACA DE VÍDEO\n\nA Placa de Vídeo é uma placa de expansão que gera uma saída de alimentação de imagens para um dispositivo de exibição (como um monitor de computador). É responsável por gerar e renderizar gráficos tanto 2D quanto 3D. Frequentemente, estas são anunciadas como placas gráficas discretas ou dedicadas, enfatizando a distinção entre elas e as placas gráficas integradas.\n\n1. Definir Placa de Vídeo\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n",
                             menuMemoriaSecundaria = "MEMÓRIA SECUNDÁRIA\n\nUma Unidade de Disco Rígido, popularmente chamado também de HD, é um dispositivo de armazenamento de dados eletromecânico que armazena e recupera dados digitais usando armazenamento magnético e um ou mais pratos rígidos de rotação rápida revestidos com material magnético.\n\nUma Unidade de Estado Sólido ou SSD é um dispositivo de armazenamento de estado sólido que usa conjuntos de circuitos integrados para armazenar dados de forma persistente, normalmente usando memória flash e funcionando como armazenamento secundário na hierarquia de armazenamento do computador.\n\n1. Definir Memória Secundária\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n",
                             menuGabinete = "GABINETE\n\nUm gabinete de computador, também conhecido como case, caixa, chassis, carcaça ou torre, é o compartimento que contém a maioria dos componentes de um computador, em excessão dos periféricos\n\n1. Definir Gabinete\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n",
                             menuFonteDeAlimentacao = "FONTE DE ALIMENTAÇÃO\n\nA Unidade  de Fonte de Alimentação converte a corrente alternada vinda da rede elétrica em corrente contínua regulada de baixa tensão para os componentes internos de um computador. Os computadores modernos usam universalmente fontes de alimentação comutadas. Algumas fontes de alimentação possuem um interruptor manual para selecionar a tensão de entrada, enquanto outras se adaptam automaticamente à tensão da rede.\n\n1. Definir Fonte de Alimentação\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n";


                      string menu[] = { menuProcessador,
                                        menuPlacaMae,
                                        menuMemoriaRAM,
                                        menuPlacaDeVideo,
                                        menuMemoriaSecundaria,
                                        menuGabinete,
                                        menuFonteDeAlimentacao };

                      for(int tipoProduto = 0; tipoProduto < 7; tipoProduto++) {
                        bool prosseguirKit = false;

                        do {
                          system("cls");

                          cout << menu[tipoProduto];
                          eventoKit = selecionar("> Selecionar Ação: ", 1, 3);

                          switch (eventoKit) {
                            case DEFINIR_KIT: {
                              system("cls");

                              vector<string> listaIDs = loja.imprimirEstoque(tipoProduto);

                              int indiceProduto = entrada<int>("> Insira o Índice do Produto Desejado: ", "Entrada Inválida!");

                              Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                              if (produto == nullptr) {
                                cout << "Este produto não foi encontrado! Cancelando Operação!" << endl;
                                break;
                              }

                              cout << endl;

                              if (pedido.adicionarItens(*produto, 1)) {
                                cout << produto->getMarca() << " " << produto->getModelo() << " adicionado ao Kit!" << endl << endl;
                                prosseguirKit = true;
                              } else {
                                cout << "Não foi possível adicionar o produto ao Kit! Tente novamente." << endl << endl;
                              }

                              system("pause");
                              break;
                            }

                            case VISUALIZAR_KIT: {
                              system("cls");

                              pedido.imprimirPedido();

                              cout << endl;

                              system("pause");
                              break;
                            }

                            case CANCELAR_KIT: {
                              cout << endl << "Pedido Cancelado!" << endl << endl;

                              system("pause");
                              break;
                            }

                            default: {
                              cout << endl << "Comando não reconhecido! Tente novamente." << endl << endl;

                              system("pause");
                              break;
                            }
                          }

                        } while (eventoKit != CANCELAR_KIT && !prosseguirKit);

                        if(eventoKit == CANCELAR_KIT)
                          break;
                      }

                      if(eventoKit != CANCELAR_KIT) {
                        system("cls");

                        cout << "DEFINIR MÉTODO DE PAGAMENTO" << endl << endl
                             << "1. Crédito" << endl
                             << "2. Débito" << endl
                             << "3. Boleto" << endl
                             << "4. Pix" << endl << endl;

                        int forma = selecionar("> Confirme a operação selecionando uma forma: ", 1, 4);

                        string pagamento[] = {"Crédito", "Débito", "Boleto", "Pix"};

                        if(forma >= 1 && forma <= 4) {
                          if(loja.removerProdutos(pedido.realizarPedido(cliente, pagamento[forma - 1]))) {
                            system("cls");

                            pedido.imprimirPedido();

                            cout << endl << "Obrigado por Comprar na PC++. Volte Sempre!" << endl << endl;

                            system("pause");
                          } else {
                            cout << endl << "Houve um erro na realização do Kit :(" << endl;

                            system("pause");
                          }
                        } else {
                          cout << endl << "Comando não reconhecido! Tente novamente." << endl;

                          system("pause");
                        }
                      }

                      break;
                    }

                    case CANCELAR_PEDIDO: {
                      cout << endl << "Voltando para Área do Cliente..." << endl << endl;

                      system("pause");
                      break;
                    }

                    default: {
                      cout << endl << "Comando não reconhecido! Tente novamente." << endl  << endl;

                      system("pause");
                      break;
                    }
                  }

                } while (eventoPedido != CANCELAR_PEDIDO);

                break;
              }

              case VISUALIZAR_ESTOQUE: {
                system("cls");

                cout << "VISUALIZAR ESTOQUE" << endl << endl
                     << "1. Processador" << endl
                     << "2. Placa Mãe" << endl
                     << "3. Memória RAM" << endl
                     << "4. Placa De Vídeo" << endl
                     << "5. Memória Secundaria" << endl
                     << "6. Gabinete" << endl
                     << "7. Fonte De Alimentação" << endl << endl;
                int tipoProduto = selecionar("> Selecionar Tipo de Produto: ", 1, 7);

                system("cls");
                loja.imprimirEstoque(tipoProduto - 1);

                cout << endl;
                system("pause");
                break;
              }

              case ENCERRAR_SESSAO: {
                cout << endl << "Sessão Encerrada!" << endl << endl;

                system("pause");
                break;
              }

              default: {
                cout << endl << "Comando não reconhecido! Tente novamente." << endl << endl;

                system("pause");
                break;
              }
            }

          } while (eventoSessao != ENCERRAR_SESSAO);

        } else {
          cout << endl << "E-mail ou senha incorretos! Tente novamente." << endl << endl;
          system("pause");
        }

        break;
      }

      case CADASTRO:{
        system("cls");

        string email, senha, cpf, endereco;

        cout << "CADASTRO" << endl << endl;
        email = linha("> Insira o seu email: ");
        cout << endl;

        senha = linha("> Insira sua senha: ");
        cout << endl;

        cpf = linha("> Insira o seu CPF: ");
        cout << endl;

        endereco = linha("> Insira o seu endereço: ");
        cout << endl;

        Cliente cliente(email, senha, cpf, endereco);

        if (loja.adicionarCliente(cliente))
          cout << endl << "Cadastro realizado com sucesso!" << endl << endl;
        else
          cout << endl << "E-mail já cadastrado!" << endl << endl;

        system("pause");
        break;
      }

      case ENCERRAR_APLICACAO: {
        cout << endl << "Encerrando Aplicação..." << endl << endl;

        system("pause");
        break;
      }

      default: {
        cout << endl << "Comando não reconhecido! Tente novamente." << endl << endl;

        system("pause");
        break;
      }
    }

  } while (eventoUsuario != ENCERRAR_APLICACAO);

  return 0;
}

wstring strToWideStr(const char* utf8Bytes) {
    const string& str(utf8Bytes);
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

void apaga(int c) {
  cout << string(c, '\b') + string(c, ' ') + string(c, '\b');
}

int selecionar(string msg, int min = 0, int max = 0) {
  char com;
  int count = min;

  cout << msg;
  while (true) {
    cout << count;
    com = _getch();

    if(com != '\n' && com != '\r') {
      apaga(to_string(count).size());
      if (com == 77 && count < max) {
        count++;
      } else if (com == 75 && count > min) {
        count--;
      }
    } else {
      cout << endl;
      return count;
    }
  }
}

string linha(string msg) {
  wchar_t ch;
  string buf;

  cout << msg;
  while (true) {
    ch = _getwch();

    if (!(ch == 72 || ch == 75 || ch == 77 || ch == 80 || ch == 224)) {
      if (ch != '\n' && ch != '\r') {
        if (ch == '\b') {
          if (!buf.empty()) {
            buf.pop_back();
            apaga(1);
          }
        } else {
          buf.push_back(char(ch));
          _putwch(ch);
        }
      } else {
        return buf;
      }
    }
  }
}

template <typename T>
T entrada(string msg, string err) {
  T saida;

  cout << msg;
  while (true) {
    string buf = linha("");
    try {
      if (is_integral<T>())
        saida = stoi(buf, nullptr, 10);
      else if (is_floating_point<T>())
        saida = stof(buf);
      cout << endl;
      return saida;
    } catch (...) {
      apaga(strToWideStr(buf.c_str()).size());
      cout << err;
      _getch();
      apaga(strToWideStr(err.c_str()).size());
    }
  }
}
