#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

VERTICE *raiz = NULL;
VERTICE *buscar(int id, VERTICE *aux) {

  if (aux != NULL) {
    if (aux->id == id) {
      return aux;
    } else if (id < aux->id) {
      if (aux->esq != NULL) {
        return buscar(id, aux->esq);
      } else {
        return aux;
      }
    } else if (id > aux->id) {
      if (aux->dir != NULL) {
        return buscar(id, aux->dir);
      } else {
        return aux;
      }
    }
  } else {
    return NULL;
  }
}

void add_abb(VERTICE dados) {

  VERTICE *aux = buscar(dados.id, raiz);

  if (aux != NULL && aux->id == dados.id) {
    dados.id++;
    add_abb(dados);
  } else {

    VERTICE *novo = malloc(sizeof(VERTICE));
    novo->id = dados.id;
    strcpy(novo->nome_aluno, dados.nome_aluno);
    novo->matricula = dados.matricula;
    strcpy(novo->descricao, dados.descricao);
    novo->esq = NULL;
    novo->dir = NULL;

    if (aux == NULL) {
      raiz = novo;
    } else {

      if (dados.id < aux->id) {
        aux->esq = novo;
      } else {
        aux->dir = novo;
      }
    }
  }
}

void delet(int numero) { raiz = apaga(raiz, numero); }

void imprimir() {
  if (raiz == NULL)
    printf("\nnão a pedidos!\n");
  else {
    in_ordem(raiz);
    int posicao;
    printf("\ndigite a posiçao ");
    scanf("%d", &posicao);
    delet(posicao);
  }
}
log *primeiro = NULL, *ultimo = NULL;

void cadastrar_log(log dados) {
  log *auxiliar = malloc(sizeof(log));
  strcpy(auxiliar->nome_responsavel, dados.nome_responsavel);
  strcpy(auxiliar->cpf, dados.cpf);
  strcpy(auxiliar->senha, dados.senha);
  strcpy(auxiliar->funcao, dados.funcao);
  auxiliar->prox = NULL;

  if (primeiro == NULL) {
    primeiro = auxiliar;
    ultimo = auxiliar;

  } else {
    ultimo->prox = auxiliar;
    ultimo = auxiliar;
  }
}

void tela_estagiario() {
  VERTICE dados;
  printf("\n***************************\n");
  printf("digite o nome do aluno ");
  scanf(" %[^\n]s", dados.nome_aluno);
  printf("digite o numero de matricula ");
  scanf("%d", &dados.matricula);
  printf("digite algumas informações sobre o livro como:\n nome do livo, "
         "autor, conteudo etc ");
  scanf(" %[^\n]s", dados.descricao);

  srand(time(NULL));
  dados.id = rand() % 100;
  add_abb(dados);
}
int verificar(int condicao) {
  log *aux_da_lista = primeiro;
  log dados;
  printf("\ndigite o cpf: ");
  scanf(" %[^\n]s", dados.cpf);
  printf("digite a senha ");
  scanf(" %[^\n]s", dados.senha);

  do {
    int tamanho_do_cpf = strlen(aux_da_lista->cpf);
    int tamanho_da_senha = strlen(aux_da_lista->senha);
    if (strlen(dados.cpf) == tamanho_do_cpf &&
        strlen(dados.senha) == tamanho_da_senha) {

      int senha = strncmp(dados.senha, aux_da_lista->senha, tamanho_da_senha);
      int cpf = strncmp(dados.cpf, aux_da_lista->cpf, tamanho_do_cpf);

      if (cpf == 0 && senha == 0) {
        if (condicao == 2) {
          if (aux_da_lista->funcao[0] == 's') {
            responsavel(aux_da_lista->nome_responsavel);
            return 1;
          } else {
            printf("\nvoce não tem acesso á esta função!\n");
            return 0;
          }

        } else if (condicao == 3) {
          if (aux_da_lista->funcao[0] == 't') {
            responsavel(aux_da_lista->nome_responsavel);
            return 1;
          } else {
            printf("\nvoce não tem acesso á esta função!\n");
            return 0;
          }
        }
      }
    }
    aux_da_lista = aux_da_lista->prox;
  } while (aux_da_lista != NULL);
  printf("\nerro! cpf ou senha invalido!\n");
  return 0;
}
