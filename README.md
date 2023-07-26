# PC++ 🖥️

Repositório dedicado ao desenvolvimento do projeto final da matéria de Técnicas de Programação do curso de Engenharia Elétrica da UFCG.

O projeto tem como objetivo a criação de um aplicativo em C++ que simula o controle de estoque e ambiente de compra de uma loja de peças de computadores.

Os integrantes desse projeto são:
- Ana Júlia Fernandes de Brito Ameno ([@anajufba](https://github.com/anajufba))
- Joab da Silva Bezerra ([@joabzicg](https://github.com/joabzicg))
- Lorenzo Carrera de Oliveira ([@loolirer](https://github.com/loolirer))
- Nívea Calébia Félix dos Santos ([@Calebia](https://github.com/Calebia))
- Vitor Hugo Gomes Alexandre Amaro ([@vitorhugobrn](https://github.com/vitorhugobrn))

O projeto foi monitorado por Gustavo Figueiredo e apresentado ao professor Marcus Salerno de Aquino em 2022.

## Acesso

O usuário pode acessar o programa como um administrador ou cliente. Já existe um administrador pré-cadastrado no sistema de login:
- E-mail: mestre@adm.pcplusplus.com
- Senha: oadmtaon

Como administrador, o usuário pode:
- Acessar seu perfil
- Conferir o estoque
- Modificar o estoque (adicionar e retirar produtos)
- Criar a conta de outros administradores

Como cliente, o usuário pode:
- Acessar seu perfil
- Conferir o estoque
- Fazer pedidos
  - Sortido: seleção a gosto do cliente dos itens disponíveis no estoque
  - Kit: montagem guiada de um computador funcional com um filtro de seleção para a escolha de somente peças compatíveis umas com as outras

## Estoque

Todos os dados de estoque e dos usuários são salvos após modificações.

A loja tem uma vasta disponibilidade de produtos necessários para que o usuário monte seu computador ideal. Os produtos vendidos são:
- Processador
- Placa Mãe
- Memória RAM
- Placa de Vídeo
- Memória Secundária
- Gabinete
- Fonte de Alimentação

Todo o estoque fictício presente nos binários do programa foram coletados por meio de javascript [deste domínio](https://pcpartpicker.com).

## Funcionalidades

O sistema foi programado utilizado a linguagem de programação C++ focado na programação orientada a objeto. Só está disponível para máquinas Windows.

Para o salvamento das classes em binário foi desenvolvido um método específico de serialização para a leitura e escrita de dados nesses arquivos.

Para a interação com o usuário foi desenvolvida uma interface gráfica utilizando a API disponibilizada pela Windows.

---
