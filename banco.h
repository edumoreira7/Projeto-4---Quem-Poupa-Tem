#define TOTAL 1000
#define TOTAL_EXTRATO 100

typedef struct Cliente {
  char nome[600];
  long long int CPF;
  int tipoConta;
  long int valorInicial;
  char senha[500];
} Cliente;

typedef struct Extrato {
  long long int CPF;
  long int saldo;
  int taxa;
  int valor;
} Extrato;

typedef enum Erros {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_EXISTE, SALDO_INSUFICIENTE, SENHA_INCORRETA, ABRIR, SEM_OPERACOES, FECHAR, ESCREVER, LER} Erro;

Erro adicionarC(Cliente clientes[], int *pos);
Erro deletarC(Cliente clientes[], int *pos);
Erro listarC(Cliente clientes[], int pos);
Erro debito(Cliente clientes[], Extrato extratoC[], int *pos, int *posE);
Erro deposito(Cliente clientes[], Extrato extratoC[], int *pos, int *posE);
Erro extrato(Cliente clientes[], Extrato extratoC[], int *pos, int *posE);
Erro transferencia(Cliente clientes[], Extrato extrato[], int *pos, int *posE);

Erro salvarC(Cliente clientes[], int total, int pos);
Erro carregarC(Cliente clientes[], int total, int *pos);
Erro salvarE(Extrato extratoC[], int total_extrato, int posE);
Erro carregarE(Extrato extratoC[], int total_extrato, int *posE);
void clearBuffer();