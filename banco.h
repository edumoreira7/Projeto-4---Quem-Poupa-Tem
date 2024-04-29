#define TOTAL 100

typedef struct Cliente {
  char nome[100];
  int CPF;
  int tipoConta[100];
  int valorInicial;
  char senha[100];
} Cliente;

int adicionarC(Cliente clientes[], int *pos);
int deletarC(Cliente clientes[], int *pos);
int listarC(Cliente clientes[], int pos);
int debito(Cliente clientes[], int pos);
int deposito(Cliente clientes[], int pos);
int extrato(Cliente clientes[], int pos);
int transferencia(Cliente clientes[], int pos);

int salvarC(Cliente clientes[], int total, int pos);
int carregarC(Cliente clientes[], int total, int pos);