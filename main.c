#include <stdio.h>

int main(){
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
    printf("%d\n", opcao);
    if(opcao > 7){
      printf("Opcao invalida\n");
    }else if (opcao == 0){
      printf("Saindo...");
      break;
    }

  } while(opcao >= 0);
}