#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

log *primeiro = NULL, *ultimo = NULL;

void cadastrar_log(log dados) {
  log *auxiliar = malloc(sizeof(log));
  strcpy(auxiliar->nome_responsavel, dados.nome_responsavel);
  strcpy(auxiliar->cpf, dados.cpf);
  strcpy(auxiliar->senha, dados.senha);
  strcpy(auxiliar->funcao, dados.funcao);
  auxiliar->prox = NULL;

  if (primeiro == NULL) { // fila vazia
    primeiro = auxiliar;
    ultimo = auxiliar;

  } else { // adiciona no final da fila
    ultimo->prox = auxiliar;
    ultimo = auxiliar;
  }
}
void tela_estagiario(){
  VERTICE dados;
  printf("digite o nome do aluno ");
  scanf(" %[^\n]s",dados.nome_aluno);
  printf("digite o numero de matricula ");
  scanf("%d",&dados.matricula);
  printf("digite algumas informações sobre o livro como:\n nome do livo, autor, conteudo etc ");
  scanf(" %[^\n]s",dados.descricao);

  }
int verificar() {
  log *aux_da_lista = primeiro;
  log dados;
  printf("\ndigite o cpf: ");
  scanf(" %[^\n]s", dados.cpf);
  printf("digite a senha ");
  scanf(" %[^\n]s", dados.senha);

  do {
    int contador_de_carcteres_cpf = 0;
    int contador_de_carcteres_senha = 0;
    int tamanho_do_cpf = strlen(aux_da_lista->cpf);
    int tamanho_da_senha = strlen(aux_da_lista->senha);

    for (int i = 0; i < tamanho_do_cpf; i++) {
      if (dados.cpf[i] == aux_da_lista->cpf[i]) {
        contador_de_carcteres_cpf++;
      }
    }

    for (int i = 0; i < tamanho_da_senha; i++) {
      if (dados.senha[i] == aux_da_lista->senha[i]) {
        contador_de_carcteres_senha++;
      }
    }

    if (contador_de_carcteres_cpf == tamanho_do_cpf &&
        contador_de_carcteres_senha == tamanho_da_senha) {
      responsavel(aux_da_lista->nome_responsavel);
      return 1;
    }
    aux_da_lista = aux_da_lista->prox;
  } while (aux_da_lista != NULL);
  printf("\nerro! cpf ou senha invalido!\n");
  return 0;
}

int main() {
  int c = 0;

  log secretario[3] = {{"evanildo", "123", "456", "secretario"},{"silva", "321", "654", "secretario"},{"dean", "789", "987", "secretario"}};
  log transportador[3] = {{"rafael", "1234", "345", "transportador"},{"rebouças", "678", "876", "transportador"},{"rael", "543", "876", "transportador"}};
  for(int i=0;i<3;i++){
  cadastrar_log(secretario[i]);
  cadastrar_log(transportador[i]);
    }
  VERTICE dados[8]={{11, "evanildo", 511236, "li"},{29, "rafael", 511236, "li"},{6, "castiel", 511236, "li"},{15, "ezequiel", 511236, "li"},{3, "mael", 511236, "li"},{7, "ezequiel", 123, "e"},{14, "gadriel", 789, "anjo"},{31, "raelel", 789, "anjo"}};
    for(int i=0;i<8;i++){
  add_abb(dados[i]);
    }
  do {
    printf("\n 1 - Encomendar um livro.\n");
    printf(" 2 - Remover uma encomenda de livro.\n");
    printf(" 3 - Remover um pedido de livro.\n");
    printf(" 0 - Sair do sistema!\n");
    printf("Digite a funcionalidade desejada: ");
    scanf("%d", &c);
    switch (c) {

    case 1: {
      break;
    }
    case 2: {
      if (verificar()) {
           imprimir();
      }
      break;
    }
    case 3: {
      if (prin_fila()) {
        int remover;
        printf("digite 1 para remover ");
        scanf("%i", &remover);
        if (remover == 1) {
          if (verificar()) {
            remover_da_lista();
            printf("\npronto\n");
          }
        } else {
          printf("\nnada foi removido!\n");
        }
      }
      break;
    }
    case 0: {
      printf("saindo...");
      break;
    }
    default: {
      printf("\n\tcomando incorreto!\n");
      c = 4;
      break;
    }
    }

  } while (c != 0);
  return 0;
}

