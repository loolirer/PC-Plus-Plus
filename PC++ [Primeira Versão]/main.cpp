#include <windows.h>

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
         << "        _/          _/_/_/          _/          _/      v1.0.0\n"
         << endl << endl
         << "1. Login" << endl
         << "2. Realizar Cadastro" << endl
         << "3. Encerrar Aplicação"<< endl << endl
         << "> Selecionar Comando: ";
    cin >> eventoUsuario;

    switch(eventoUsuario){
      case LOGIN:{
        system("cls");

        string email, senha;

        cout << "LOGIN" << endl << endl;
        cout << "> Insira o seu email: ";
        cin >> email;

        cout << "> Insira a sua senha: ";
        cin >> senha;

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
                 << "6. Encerrar Sessão" << endl << endl
                 << "> Selecionar Opção: ";
            cin >> eventoSessao;

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
                     << "7. Fonte De Alimentação" << endl << endl
                     << "> Selecionar Tipo de Produto: ";

                int tipoProduto = 0;
                cin >> tipoProduto;

                system("cls");

                if (tipoProduto < 1 || tipoProduto > 7) {
                  cout << "Opção Inválida! Cancelando Operação!" << endl << endl;

                  system("pause");
                  break;
                }

                string modelo, marca, ID;
                float preco;
                int quantidade;

                cin.ignore();

                cout << "> Insira o Modelo do Produto: ";
                getline(cin, modelo);

                cout << "> Insira a Marca do Produto: ";
                getline(cin, marca);

                cout << "> Insira o ID do Produto: ";
                getline(cin, ID);

                cout << "> Insira o Preço do Produto: ";
                cin >> preco;

                cout << "> Insira a Quantidade do Produto: ";
                cin >> quantidade;

                switch (tipoProduto - 1) {
                  case PROCESSADOR: {
                    int cores, threads;
                    float frequencia;
                    string socket;

                    cout << "> Insira a Quantidade de Cores do Processador: ";
                    cin >> cores;

                    cout << "> Insira a Quantidade de Threads do Processador: ";
                    cin >> threads;

                    cout << "> Insira a Frequência do Processador: ";
                    cin >> frequencia;

                    cout << "> Insira o Socket do Processador: ";
                    cin.ignore();
                    getline(cin, socket);

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

                    cin.ignore();

                    cout << "> Insira a Plataforma da Placa Mãe: ";
                    getline(cin, plataforma);

                    cout << "> Insira o Socket da Placa Mãe: ";
                    getline(cin, socket);

                    cout << "> Insira o Tipo de Memoria da Placa Mãe: ";
                    getline(cin, memoria);

                    cout << "> Insira o Fator Forma da Placa Mãe: ";
                    getline(cin, fatorForma);

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

                    cout << "> Insira a Capacidade da Memoria RAM: ";
                    cin >> capacidade;

                    cout << "> Insira a Frequencia da Memoria RAM: ";
                    cin >> frequencia;

                    cout << "> Insira o DDR da Memoria RAM: ";
                    cin.ignore();
                    getline(cin, DDR);

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

                    cout << "> Insira a Quantidade de VRAM da Placa De Video: ";
                    cin >> memoria;

                    cout << "> Insira o Tipo de Memória da Placa De Video: ";
                    cin.ignore();
                    getline(cin, tipoMemoria);

                    cout << "> Insira a Frequencia da Placa De Video: ";
                    cin >> frequencia;

                    cout << "> Insira a Quantidade de Bits da Placa De Video: ";
                    cin >> bits;

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

                    cout << "> Insira o Tipo de Memória Secundária: ";
                    cin.ignore();
                    getline(cin, tipo);

                    cout << "> Insira a Capacidade da Memória Secundária: ";
                    cin >> capacidade;

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

                    cin.ignore();

                    cout << "> Insira o Fator Forma do Gabinete: ";
                    getline(cin, fatorForma);

                    cout << "> Insira o Tamanho do Gabinete: ";
                    getline(cin, tamanho);

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

                    cout << "> Insira a Potência da Fonte De Alimentação: ";
                    cin >> potencia;

                    cout << "> Insira o Tamanho da Fonte De Alimentação: ";
                    cin.ignore();
                    getline(cin, fatorForma);

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
                     << "7. Fonte De Alimentação" << endl << endl
                     << "> Selecionar Tipo de Produto: ";

                int tipoProduto = 0;
                cin >> tipoProduto;

                system("cls");

                vector<string> listaIDs = loja.imprimirEstoque(tipoProduto - 1);

                cout << "> Insira o Índice do Produto Desejado: ";

                int indiceProduto = 0;
                cin >> indiceProduto;

                Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                if (produto == nullptr) {
                  cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                  system("pause");
                  break;
                }

                cout << "> Insira a quantidade do Produto a ser adicionada: ";

                int quantidade = 0;
                cin >> quantidade;
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
                     << "7. Fonte De Alimentação" << endl << endl
                     << "> Selecionar Tipo de Produto: ";

                int tipoProduto = 0;
                cin >> tipoProduto;

                system("cls");

                vector<string> listaIDs = loja.imprimirEstoque(tipoProduto - 1);

                cout << "> Insira o Índice do Produto Desejado: ";

                int indiceProduto = 0;
                cin >> indiceProduto;

                Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                if (produto == nullptr) {
                  cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                  system("pause");
                  break;
                }

                int quantidade = 0;
                cout << "> Insira a Quantidade a ser Removida: ";
                cin >> quantidade;

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
                     << "7. Fonte De Alimentação" << endl << endl
                     << "> Selecionar Tipo de Produto: ";

                int tipoProduto = 0;
                cin >> tipoProduto;

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
                cout << "> Insira o seu email empresarial: ";
                cin >> email;

                cout << "> Insira sua senha: ";
                cin >> senha;

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
                 << "4. Encerrar Sessão" << endl << endl
                 << "> Selecionar Opção: ";
            cin >> eventoSessao;

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
                       << "3. Voltar para Área do Cliente" << endl << endl
                       << "> Selecionar Tipo de Pedido: ";
                  cin >> eventoPedido;

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
                             << "5. Cancelar Pedido" << endl << endl
                             << "> Selecionar Ação: ";
                        cin >> eventoSortido;

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
                                 << "7. Fonte De Alimentação" << endl << endl
                                 << "> Selecionar Tipo de Produto: ";

                            int tipoProduto = 0;
                            cin >> tipoProduto;

                            system("cls");

                            vector<string> listaIDs = loja.imprimirEstoque(tipoProduto - 1);

                            cout << "> Insira o Índice do Produto Desejado: ";

                            int indiceProduto = 0;
                            cin >> indiceProduto;

                            Produto* produto = loja.getProduto(listaIDs[indiceProduto - 1]);

                            if (produto == nullptr) {
                              cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                              system("pause");
                              break;
                            }

                            cout << "> Insira a quantidade do Produto a ser adicionada: ";

                            int quantidade = 0;
                            cin >> quantidade;
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
                              cout << "> Insira o Índice do Item a ser Removido: ";

                              int indiceItem = 0;
                              cin >> indiceItem;

                              Produto* produto = pedido.getItem(indiceItem - 1);

                              if (produto == nullptr) {
                                cout << "Este produto não foi encontrado! Cancelando Operação!" << endl << endl;

                                system("pause");
                                break;
                              }

                              cout << "> Insira quantas unidades do Item serão removidas: ";

                              int quantidade = 0;
                              cin >> quantidade;

                              cout << endl;

                              if (pedido.removerItens(*produto, quantidade))
                                cout << produto->getMarca() << " " << produto->getModelo() << " removido do Pedido!" << endl << endl;
                              else
                                cout << "Não foi possível remover o produto do Pedido!" << endl << endl;
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
                                 << "4. Pix" << endl << endl
                                 << "> Confirme a operação selecionando uma forma: ";

                            int forma;
                            cin >> forma;

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

                      string menuProcessador = "PROCESSADOR\n\nO microprocessador, geralmente chamado apenas de processador, é um circuito integrado que realiza as funções de cálculo e tomada de decisão de um computador. Como todos os computadores e equipamentos eletrônicos baseiam-se nele para executar suas funções, pode-se dizer que o processador é o cérebro do computador por realizar todas estas funções.\n\n1. Definir Processador\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ",
                             menuPlacaMae = "PLACA MÃE\n\nA placa-mãe é a parte do computador responsável por conectar e interligar todos os componentes, ou seja, processador com memória RAM, disco rígido, placa gráfica, entre outros. Além de permitir o tráfego de informação, a placa também alimenta alguns periféricos com a energia elétrica que recebe da fonte de alimentação.\n\n1. Definir Placa Mãe\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ",
                             menuMemoriaRAM = "MEMÓRIA RAM\n\nA memória de acesso aleatório (do inglês Random Access Memory, frequentemente abreviado para RAM), também chamado de memória volátil de leitura e escrita, é uma memória temporária computacional de acesso rápido; ou seja, é um local de armazenamento temporário de informações digitais usada pelo processador para armazenar informações temporariamente, utilizada como memória primária em sistemas eletrônicos digitais.\n\n1. Definir Memória RAM\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ",
                             menuPlacaDeVideo = "PLACA DE VÍDEO\n\nA Placa de Vídeo é uma placa de expansão que gera uma saída de alimentação de imagens para um dispositivo de exibição (como um monitor de computador). É responsável por gerar e renderizar gráficos tanto 2D quanto 3D. Frequentemente, estas são anunciadas como placas gráficas discretas ou dedicadas, enfatizando a distinção entre elas e as placas gráficas integradas.\n\n1. Definir Placa de Vídeo\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ",
                             menuMemoriaSecundaria = "MEMÓRIA SECUNDÁRIA\n\nUma Unidade de Disco Rígido, popularmente chamado também de HD, é um dispositivo de armazenamento de dados eletromecânico que armazena e recupera dados digitais usando armazenamento magnético e um ou mais pratos rígidos de rotação rápida revestidos com material magnético.\n\nUma Unidade de Estado Sólido ou SSD é um dispositivo de armazenamento de estado sólido que usa conjuntos de circuitos integrados para armazenar dados de forma persistente, normalmente usando memória flash e funcionando como armazenamento secundário na hierarquia de armazenamento do computador.\n\n1. Definir Memória Secundária\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ",
                             menuGabinete = "GABINETE\n\nUm gabinete de computador, também conhecido como case, caixa, chassis, carcaça ou torre, é o compartimento que contém a maioria dos componentes de um computador, em excessão dos periféricos\n\n1. Definir Gabinete\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ",
                             menuFonteDeAlimentacao = "FONTE DE ALIMENTAÇÃO\n\nA Unidade  de Fonte de Alimentação converte a corrente alternada vinda da rede elétrica em corrente contínua regulada de baixa tensão para os componentes internos de um computador. Os computadores modernos usam universalmente fontes de alimentação comutadas. Algumas fontes de alimentação possuem um interruptor manual para selecionar a tensão de entrada, enquanto outras se adaptam automaticamente à tensão da rede.\n\n1. Definir Fonte de Alimentação\n2. Visualizar Progresso\n3. Cancelar Pedido\n\n> Selecionar Ação: ";


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
                          cin >> eventoKit;

                          switch (eventoKit) {
                            case DEFINIR_KIT: {
                              system("cls");

                              vector<string> listaIDs = loja.imprimirEstoque(tipoProduto);

                              cout << "> Insira o Índice do Produto Desejado: ";

                              int indiceProduto = 0;
                              cin >> indiceProduto;

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
                             << "4. Pix" << endl << endl
                             << "> Confirme a operação selecionando uma forma: ";

                        int forma;
                        cin >> forma;

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
                     << "7. Fonte De Alimentação" << endl << endl
                     << "> Selecionar Tipo de Produto: ";

                int tipoProduto = 0;
                cin >> tipoProduto;

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
        cout << "> Insira o seu email: ";
        cin >> email;

        cout << "> Crie uma senha: ";
        cin >> senha;

        cout << "> Insira o seu CPF: ";
        cin >> cpf;

        cout << "> Insira o seu endereço: ";
        cin >> endereco;

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
