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
  if(*pos == 0)
    return 1;

  int pos_d;

  long long int numero_d;
  printf("Entre o CPF da conta que deseja deletar: ");
  scanf("%lld", &numero_d);

  int cont = 1;

  for(int i = 0; i<*pos; i++){
    if (numero_d == clientes[i].CPF){
      pos_d = i;
    }else{
      cont = 0;
    }
  }
  if(pos_d >= *pos)
    return 2;

  for(int i = pos_d; i<*pos; i++){
    clientes[i].CPF = clientes[i + 1].CPF;
    strcpy(clientes[i].nome, clientes[i + 1].nome);
    clientes[i].tipoConta = clientes[i + 1].tipoConta;
    clientes[i].valorInicial = clientes[i + 1].valorInicial;
    strcpy(clientes[i].senha, clientes[i + 1].senha);
  }

  *pos = *pos - 1;

  if(cont == 0)
    return 2;

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
int debito(Cliente clientes[], Extrato extratoC[], int *pos, int *posE){

  int posD;
  int cont = 0;
  long long int cpfDebito;
  char senhaDebito[100];
  long int valorDebito;
  int porc;

  printf("Digite o CPF: ");
  scanf("%lld", &cpfDebito);
  clearBuffer();

  for(int i = 0; i<*pos; i++){
    if (cpfDebito == clientes[i].CPF){
      posD = i;
      cont++;
    }
  }
  if (cont == 0)
    return 1;
  else{
    printf("Digite a senha: ");
    fgets(senhaDebito, 100, stdin);
    senhaDebito[strcspn(senhaDebito, "\n")] = 0;

    if (strcmp(clientes[posD].senha, senhaDebito) == 0) {
      printf("Digite o valor do débito: ");
      scanf("%ld", &valorDebito);

      int saldo = clientes[posD].valorInicial;

      if(clientes[posD].tipoConta == 1){
        if(clientes[posD].valorInicial - valorDebito <= -1001){
          printf("Saldo insuficiente\n");
          return 2;
        }else{
          int porc = valorDebito * 0.05;
          clientes[posD].valorInicial -= porc;
          clientes[posD].valorInicial -= valorDebito;
        }
      }else if(clientes[posD].tipoConta == 2){
        if(clientes[posD].valorInicial - valorDebito <= -5001){
          printf("Saldo insuficiente\n");
          return 2;
        }else{
          porc = valorDebito * 0.03;
          clientes[posD].valorInicial -= porc;
          clientes[posD].valorInicial -= valorDebito;
        }
      }
      printf("Saldo atual: %ld", clientes[posD].valorInicial);
      extratoC[*posE].CPF = clientes[posD].CPF;
      extratoC[*posE].saldo = clientes[posD].valorInicial;
      extratoC[*posE].taxa = (saldo - valorDebito) - clientes[posD].valorInicial;
      extratoC[*posE].valor = -valorDebito;

      *posE = *posE + 1;
    }else {
      printf("Senha incorreta");
      return 2;
    }
  }

  return 0;
}
int deposito(Cliente clientes[], Extrato extratoC[], int *pos, int *posE){

  long long cpfD;
  int posD;
  int cont = 0;
  char senhaD[100];
  long int valorDeposito;
  int porc = 0;

  printf("Digite seu CPF: ");
  scanf("%lld", &cpfD);
  clearBuffer();

  for(int i = 0; i<*pos; i++){
    if (cpfD == clientes[i].CPF){
      posD = i;
      cont++;
    }
  }
  if (cont == 0){
    return 1;
  }else{
    printf("Digite a senha: ");
    fgets(senhaD, 100, stdin);
    senhaD[strcspn(senhaD, "\n")] = 0;

    if (strcmp(clientes[posD].senha, senhaD) == 0) {
      printf("Digite o valor do deposito: ");
      scanf("%ld", &valorDeposito);
      clientes[posD].valorInicial += valorDeposito;
      printf("Saldo atual: %ld", clientes[posD].valorInicial);
      //adicionando dados no extrato
      extratoC[*posE].CPF = clientes[posD].CPF;
      extratoC[*posE].saldo = clientes[posD].valorInicial;
      extratoC[*posE].taxa = porc;
      extratoC[*posE].valor = valorDeposito;

      *posE = *posE + 1;
    }else{
      printf("Senha incorreta");
      return 2;
    }
  }

  return 0;
}
int extrato(Cliente clientes[], Extrato extratoC[], int *pos, int *posE){
  long long cpfE;
  int posExtrato;
  int cont = 0;
  char senhaE[100];
  long int valorDeposito;


  printf("Digite seu CPF: ");
  scanf("%lld", &cpfE);
  clearBuffer();

  for(int i = 0; i<*pos; i++){
    if (cpfE == clientes[i].CPF){
      posExtrato = i;
      cont++;
    }
  }
  if (cont == 0){
    return 1;
  }else{
    printf("Digite a senha: ");
    fgets(senhaE, 100, stdin);
    senhaE[strcspn(senhaE, "\n")] = 0;

    if (strcmp(clientes[posExtrato].senha, senhaE) == 0) {
      FILE *f = fopen("extrato.txt", "w"); 
      if(f == NULL)
          return 1;

      int qtd = 0;

      fprintf(f, "Nome: %s\t", clientes[posExtrato].nome);
      fprintf(f, "CPF: %lld\t", clientes[posExtrato].CPF);
      if(clientes[posExtrato].tipoConta == 1)
        fprintf(f, "Tipo da conta: Comum\n");
      else if(clientes[posExtrato].tipoConta == 2)
        fprintf(f, "Tipo da conta: Plus\n");

      for (int i = 0; i < *posE; i++) {
         if(cpfE == extratoC[i].CPF){
            if (extratoC[i].valor < 0)
              fprintf(f, "%d\t", extratoC[i].valor);
            else
              fprintf(f, "+%d\t", extratoC[i].valor);
            fprintf(f, "Taxa: %d\t", extratoC[i].taxa);
            fprintf(f, "Saldo: %ld\n", extratoC[i].saldo);

            qtd = qtd + 1;
         }
      }

      if (fclose(f) != 0)
          return 1;
    }else{
      printf("Senha incorreta");
      return 2;
    }
  }

  return 0;
}
int transferencia(Cliente clientes[], Extrato extrato[], int *pos, int *posE){
  long long cpfT;
  long long cpfT2;
  int posT;
  int posT2;
  int cont = 0;
  char senhaT[100];
  long int valorTrans;

  printf("Digite seu CPF: ");
  scanf("%lld", &cpfT);
  clearBuffer();

  for(int i = 0; i<*pos; i++){
    if (cpfT == clientes[i].CPF){
      posT = i;
      cont++;
    }
  }
  if (cont == 0){
    return 1;
  }else{
      cont = 0;
      printf("Digite a senha: ");
      fgets(senhaT, 100, stdin);
      senhaT[strcspn(senhaT, "\n")] = 0;

      if (strcmp(clientes[posT].senha, senhaT) == 0) 
        printf("Digite o CPF da conta que deseja transferir: ");
        scanf("%lld", &cpfT2);
        for(int i = 0; i<*pos; i++){
          if (cpfT2 == clientes[i].CPF){
            posT2 = i;
            cont++;
          }
        }
        if (cont == 0){
          return 1;
        }
        printf("Digite o valor da transfêrencia: ");
        scanf("%ld", &valorTrans);
        }
        if(clientes[posT].tipoConta == 1){
          if(clientes[posT].valorInicial - valorTrans <= -1001){
            printf("Saldo insuficiente\n");
            return 2;
          }else{
            clientes[posT].valorInicial -= valorTrans;
            clientes[posT2].valorInicial += valorTrans;
            printf("Saldo atual: %ld", clientes[posT].valorInicial);
          }
        }else if(clientes[posT].tipoConta == 2){
          if(clientes[posT].valorInicial - valorTrans <= -5001){
            printf("Saldo insuficiente\n");
            return 2;
          }else{
            clientes[posT].valorInicial -= valorTrans;
            clientes[posT2].valorInicial += valorTrans;
            printf("Saldo atual: %ld", clientes[posT].valorInicial);
          }
        }
        //adicionando dados no extrato
        extrato[*posE].CPF = clientes[posT].CPF;
        extrato[*posE].saldo = clientes[posT].valorInicial;
        extrato[*posE].taxa = 0;
        extrato[*posE].valor = -valorTrans;
        *posE = *posE + 1;
        extrato[*posE].CPF = clientes[posT2].CPF;
        extrato[*posE].saldo = clientes[posT2].valorInicial;
        extrato[*posE].taxa = 0;
        extrato[*posE].valor = valorTrans;
        *posE = *posE + 1;
    
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
int salvarE(Extrato extratoC[], int total_extrato, int posE){
  FILE *f = fopen("extrato", "wb");
  if(f == NULL)
    return 1;

  int e = fwrite(extratoC, total_extrato, sizeof(Extrato), f);
    if(e<=0)
      return 2;

  e = fwrite(&posE, 1, sizeof(int), f);
  if(e<=0)
    return 2;

  e = fclose(f);
  if(e!=0)
    return 3;

  return 0;
}
int carregarE(Extrato extratoC[], int total_extrato, int *posE){
  FILE *f = fopen("extrato", "rb");
  if(f == NULL)
    return 1;

  int e = fread(extratoC, total_extrato, sizeof(Extrato), f);
  if(e<=0)
    return 2;

  e = fread(posE, 1, sizeof(int), f);
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