#include <stdio.h>
#include "banco.h"

int main(){
  int pos = 0;
  Cliente clientes[TOTAL];

  carregarC(clientes, TOTAL, &pos);

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
    clearBuffer();
    
    if(opcao > 7){
      printf("Opcao invalida\n");
    }else if (opcao == 1){
      adicionarC(clientes, &pos);
    }else if (opcao == 2){
      deletarC(clientes, &pos);
    }else if (opcao == 3){
      listarC(clientes, pos);
    }else if(opcao == 4) {
      debito(clientes, pos);
    }else if (opcao == 5){
      deposito(clientes, pos);
    }else if (opcao == 6){
      extrato(clientes, pos);
    }else if (opcao == 7){
      transferencia(clientes, pos);
    }else if (opcao == 0){
      printf("Saindo...");
      salvarC(clientes, TOTAL, pos);
      break;
    }

  } while(opcao >= 0);
}