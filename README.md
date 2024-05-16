"Quem Poupa Tem"**

**Objetivo:**
  O objetivo deste projeto é desenvolver um banco em C capaz de armazenar informações como CPF, nome, sobrenome, tipo de conta, saldo e senha para cada contato. Este projeto foi criado como parte de um trabalho universitário.

**Funcionalidades:**
- Adicionar clientes ao banco, inserindo CPF, nome, senha,  valor inicial e tipo de conta(comum e plus).
- Listar todos os clientes adicionados.
- Deletar clientes utilizando o CPF.
- Débito de conta pelo CPF
- Depósito na conta pelo CPF
- Imprimir extrato de cada conta em um arquivo .txt pelo CPF
- Transferência entre contas
- Salvar clientes e extrato em um arquivo binário.
- Carregar clientes e extrato a partir de um arquivo binário.
- O número de clientes é limitado a 1000.

**Compilação/Execução:**
Após abrir o código em um programa capaz de executá-lo, utilize o seguinte comando no terminal:
```
gcc *.c && ./a.out
```
Isso permitirá compilar e executar o código.

**Como usar:**

Ao executar o programa, um menu será exibido na tela, permitindo que você escolha uma opção. 

- Para adicionar um cliente, siga as instruções na tela, inserindo o CPF, nome, senha, valor inicial e tipo da conta do contato quando solicitado. 
- O programa verifica se o tamanho total do contato não excede o limite permitido antes de adicioná-lo ao banco.
- Após adicionar um cliente, você voltará ao menu para adicionar outro cliente, deletar, listar, debitar, depositar, transferir, salvar ou carregar.
