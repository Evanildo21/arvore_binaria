#ifndef crud
#define crud

typedef struct Vertice {

  int id; // identificador
  char nome_aluno[50];
  int matricula;
  char descricao[100];
  char nome_do_campos_com_livro[100];
  char nome_do_campos_com_aluno[50];
  char nome_do_responssavel[100];
  int prioridade_do_pedido;
  // mecanismo p/ unir nos!
  struct Vertice *esq;
  struct Vertice *dir;
  struct Vertice *prox;
  
} VERTICE;

typedef struct log {
    char nome_responsavel[50];
  char email[50];
  char senha[50];
  char funcao[20]; 
  struct log *prox;
} log;

VERTICE *buscar(int id, VERTICE *aux);
void add_abb(int id, char *nome_aluno, int matricula, char *descricao);
VERTICE *apaga(VERTICE *no_da_arvore, int numero);
void imprimir();
void in_ordem(VERTICE *aux);
void delet(int numero);
void prin_fila();

#endif
