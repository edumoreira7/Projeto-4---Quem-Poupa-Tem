#define TOTAL 100
#define TOTAL_EXTRATO 100

typedef struct Cliente {
  char nome[100];
  long long int CPF;
  int tipoConta;
  long int valorInicial;
  char senha[100];
} Cliente;

typedef struct Extrato {
  long long int CPF;
  long int saldo;
  int taxa;
  int valor;
} Extrato;


int adicionarC(Cliente clientes[], int *pos);
int deletarC(Cliente clientes[], int *pos);
int listarC(Cliente clientes[], int pos);
int debito(Cliente clientes[], Extrato extratoC[], int *pos, int *posE);
int deposito(Cliente clientes[], Extrato extratoC[], int *pos, int *posE);
int extrato(Cliente clientes[], Extrato extratoC[], int *pos, int *posE);
int transferencia(Cliente clientes[], Extrato extrato[], int pos, int *posE);

int salvarC(Cliente clientes[], int total, int pos);
int carregarC(Cliente clientes[], int total, int *pos);
void clearBuffer();