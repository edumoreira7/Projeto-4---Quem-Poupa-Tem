#include "banco.h"
#include <stdio.h>
#include <string.h>

int adicionarC(Cliente clientes[], int *pos){
  if (*pos >= TOTAL)
    return 1;

  printf("Digite o CPF: ");
  scanf("%lld", &clientes[*pos].CPF);
  clearBuffer();

  printf("Digite o nome: ");
  fgets(clientes[*pos].nome, 100, stdin);
  clientes[*pos].nome[strcspn(clientes[*pos].nome, "\n")] = '\0';

  printf("Opções:\n");
  printf("1 - Comum\n");
  printf("2 - Plus\n");
  printf("Digite o Tipo da conta: ");
  scanf("%d", &clientes[*pos].tipoConta);

  printf("Digite o valor inicial da conta: ");
  scanf("%ld", &clientes[*pos].valorInicial);
  clearBuffer();

  printf("Digite a senha: ");
  fgets(clientes[*pos].senha, 100, stdin);
  clientes[*pos].senha[strcspn(clientes[*pos].senha, "\n")] = '\0';

  *pos = *pos +1;

  return 0;
}
int deletarC(Cliente clientes[], int *pos){
  printf("funcao de deletar contato\n");
  return 0;
}
int listarC(Cliente clientes[], int pos){
  if(pos == 0)
    return 1;

  for(int i=0; i<pos; i++){
    printf("Nome: %s\n", clientes[i].nome);
    printf("CPF: %lld\n", clientes[i].CPF);
    printf("Tipo da conta: %d\n", clientes[i].tipoConta);
    printf("Saldo: %ld\n", clientes[i].valorInicial);
    printf("Senha: %s\n", clientes[i].senha);
    printf("------------------------\n");
  }

  return 0;
}
int debito(Cliente clientes[], int pos){
  printf("funcao de debito\n");
  return 0;
}
int deposito(Cliente clientes[], int pos){
  printf("funcao de deposito\n");
  return 0;
}
int extrato(Cliente clientes[], int pos){
  printf("funcao de extrato\n");
  return 0;
}
int transferencia(Cliente clientes[], int pos){
  printf("funcao de transferencia\n");
  return 0;
}

int salvarC(Cliente clientes[], int total, int pos){
  FILE *f = fopen("clientes", "wb");
  if(f == NULL)
    return 1;

  int e = fwrite(clientes, total, sizeof(Cliente), f);
    if(e<=0)
      return 2;

  e = fwrite(&pos, 1, sizeof(int), f);
  if(e<=0)
    return 2;

  e = fclose(f);
  if(e!=0)
    return 3;

  return 0;
}
int carregarC(Cliente clientes[], int total, int *pos){
  FILE *f = fopen("clientes", "rb");
  if(f == NULL)
    return 1;

  int e = fread(clientes, total, sizeof(Cliente), f);
  if(e<=0)
    return 2;

  e = fread(pos, 1, sizeof(int), f);
  if(e<=0)
    return 2;

  e = fclose(f);
  if(e!=0)
    return 3;

  return 0;
}
void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}