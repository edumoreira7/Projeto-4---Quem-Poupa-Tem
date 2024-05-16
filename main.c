#include <stdio.h>
#include "banco.h"

int main(){
  int pos = 0;
  int posE = 0;
  Cliente clientes[TOTAL];
  Extrato extratoC[TOTAL_EXTRATO];

  Erro e = carregarC(clientes, TOTAL, &pos);
  if(e == ABRIR)
    printf("Erro ao abrir arquivo\n");
  else if(e == LER)
    printf("Erro ao ler arquivo\n");
  else if(e == LER)
    printf("Erro ao fechar arquivo\n");
  
  e = carregarE(extratoC, TOTAL_EXTRATO, &posE);
  if(e == ABRIR)
    printf("Erro ao abrir arquivo\n");
  else if(e == LER)
    printf("Erro ao ler arquivo\n");
  else if(e == LER)
    printf("Erro ao fechar arquivo\n");

  int opcao;

  do{
    printf("\nMenu principal\n");
    printf("1 - Adicionar cliente\n");
    printf("2 - Deletar cliente\n");
    printf("3 - Listar clientes\n");
    printf("4 - Débito\n");
    printf("5 - Deposito\n");
    printf("6 - Extrato\n");
    printf("7 - Transferência\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    printf("\n");
    clearBuffer();

    if(opcao > 7){
      printf("Opcao invalida\n");
    }else if (opcao == 1){
      e = adicionarC(clientes, &pos);
      if(e == MAX_CLIENTES)
        printf("Limite de clientes atingido\n");
      else if(e == OK){
        e = salvarC(clientes, TOTAL, pos);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");

        e = salvarE(extratoC, TOTAL_EXTRATO, posE);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");
      }
      
    }else if (opcao == 2){
      e = deletarC(clientes, &pos);
      if(e == SEM_CLIENTES)
        printf("Nao ha clientes cadastrados\n");
      else if(e == NAO_EXISTE)
        printf("Cliente nao encontrado\n");
      else if(e == OK){
        e = salvarC(clientes, TOTAL, pos);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");

        e = salvarE(extratoC, TOTAL_EXTRATO, posE);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");
      }
      
    }else if (opcao == 3){
      e = listarC(clientes, pos);
      if(e == SEM_CLIENTES)
        printf("Nao ha clientes cadastrados\n");
      
    }else if(opcao == 4) {
      e = debito(clientes, extratoC, &pos, &posE);
      if(e == SEM_CLIENTES)
        printf("Nao ha clientes cadastrados\n");
      else if(e == NAO_EXISTE)
        printf("Cliente nao encontrado\n");
      else if(e == SALDO_INSUFICIENTE)
        printf("Saldo insuficiente\n");
      else if(e == SENHA_INCORRETA)
        printf("Senha incorreta\n");
      else if(e == OK){
        e = salvarC(clientes, TOTAL, pos);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");

        e = salvarE(extratoC, TOTAL_EXTRATO, posE);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");
      }

    }else if (opcao == 5){
      e = deposito(clientes, extratoC, &pos, &posE);
      if(e == SEM_CLIENTES)
        printf("Nao ha clientes cadastrados\n");
      else if(e == NAO_EXISTE)
        printf("Cliente nao encontrado\n");
      else if(e == SENHA_INCORRETA)
        printf("Senha incorreta\n");
      else if(e == OK){
        e = salvarC(clientes, TOTAL, pos);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");

        e = salvarE(extratoC, TOTAL_EXTRATO, posE);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");
      }
        
        
    }else if (opcao == 6){
      e = extrato(clientes, extratoC, &pos, &posE);
      if(e == SEM_CLIENTES)
        printf("Nao ha clientes cadastrados\n");
      else if(e == NAO_EXISTE)
        printf("Cliente nao encontrado\n");
      else if(e == ABRIR)
        printf("Erro ao abrir arquivo\n");
      else if(e == SEM_OPERACOES)
        printf("Não existem operações nesta conta\n");
      else if(e == FECHAR)
        printf("Erro ao fechar arquivo\n");
      else if(e == SENHA_INCORRETA)
        printf("Senha incorreta\n");

        
    }else if (opcao == 7){
      e = transferencia(clientes, extratoC, &pos, &posE);
      if(e == SEM_CLIENTES)
        printf("Nao ha clientes cadastrados\n");
      else if(e == NAO_EXISTE)
        printf("Cliente nao encontrado\n");
      else if(e == SALDO_INSUFICIENTE)
        printf("Saldo insuficiente\n");
      else if(e == OK){
        e = salvarC(clientes, TOTAL, pos);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");

        e = salvarE(extratoC, TOTAL_EXTRATO, posE);
        if(e == ABRIR)
          printf("Erro ao abrir arquivo\n");
        else if(e == ESCREVER)
          printf("Erro ao escrever arquivo\n");
        else if(e == FECHAR)
          printf("Erro ao fechar arquivo\n");
      }
      
    }else if (opcao == 0){
      printf("Saindo...");
      e = salvarC(clientes, TOTAL, pos);
      if(e == ABRIR)
        printf("Erro ao abrir arquivo\n");
      else if(e == ESCREVER)
        printf("Erro ao escrever arquivo\n");
      else if(e == FECHAR)
        printf("Erro ao fechar arquivo\n");
      
      e = salvarE(extratoC, TOTAL_EXTRATO, posE);
      if(e == ABRIR)
        printf("Erro ao abrir arquivo\n");
      else if(e == ESCREVER)
        printf("Erro ao escrever arquivo\n");
      else if(e == FECHAR)
        printf("Erro ao fechar arquivo\n");
      break;
    }

  } while(opcao >= 0);
}