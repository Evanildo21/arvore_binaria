#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VERTICE *inicio = NULL;
char nome_responsavel[50];

void in_ordem(VERTICE *aux) {

  if (aux->esq != NULL) {
    in_ordem(aux->esq);
  }
  printf("\n");
  printf(" %d ", aux->id);
  printf(" %s ", aux->nome_aluno);
  printf(" %d ", aux->matricula);
  printf(" %s ", aux->descricao);
  printf("\n");
  if (aux->dir != NULL) {
    in_ordem(aux->dir);
  }
}
void copia(VERTICE *aux, VERTICE *dados) {

  strcpy(aux->nome_aluno, dados->nome_aluno);
  strcpy(aux->descricao, dados->descricao);
  aux->id = dados->id;
  aux->matricula = dados->matricula;
}

VERTICE *prioridade(VERTICE *aux_da_lista, VERTICE *auxiliar) {
  if (aux_da_lista == NULL) {
    return auxiliar;
  } else {
    if (aux_da_lista->prioridade_do_pedido < auxiliar->prioridade_do_pedido) {
      auxiliar->prox = aux_da_lista;
      return auxiliar;
    } else {
      if (aux_da_lista->prioridade_do_pedido >=
          auxiliar->prioridade_do_pedido) {
        aux_da_lista->prox = prioridade(aux_da_lista->prox, auxiliar);
      }
    }
  }
  return aux_da_lista;
}

void lista_de_prioridade(VERTICE *dados) {
  VERTICE *auxiliar = malloc(sizeof(VERTICE));

  printf("\n**************************************\n");
  printf("aluno: %s \t matricula: %i\ndetalhes do livro: %s\n",
         dados->nome_aluno, dados->matricula, dados->descricao);
  printf("\n**************************************\n");

  copia(auxiliar, dados);
  strcpy(auxiliar->nome_do_responssavel, nome_responsavel);

  printf("\ndigite o nome do campus onde está o livro! ");
  scanf(" %[^\n]s", auxiliar->nome_do_campos_com_livro);
  printf("digite o nome do campus onde está o aluno! ");
  scanf(" %[^\n]s", auxiliar->nome_do_campos_com_aluno);
  do {
    printf("de 0 a 100 qual a prioridade desse pedido ");
    scanf("%i", &auxiliar->prioridade_do_pedido);
    if (auxiliar->prioridade_do_pedido > 100)
      printf("\na prioridade é de 0 a 100\nentão ");

  } while (auxiliar->prioridade_do_pedido > 100);
  auxiliar->prox = NULL;
  inicio = prioridade(inicio, auxiliar);
}

VERTICE *apaga(VERTICE *no_da_arvore, int numero) {

  if (no_da_arvore == NULL) {
    printf("posição %i não encontrado!", numero);
    return NULL;
  } else {
    if (no_da_arvore->id == numero) {
      if (no_da_arvore->esq == NULL &&
          no_da_arvore->dir == NULL) { 
        lista_de_prioridade(no_da_arvore);
        free(no_da_arvore);
        return NULL;
      } else {

        if (no_da_arvore->esq != NULL && no_da_arvore->dir == NULL) {
          lista_de_prioridade(no_da_arvore);
          free(no_da_arvore);
          return no_da_arvore->esq;
        } else {
          if (no_da_arvore->dir != NULL && no_da_arvore->esq == NULL) {
            VERTICE *aux = malloc(sizeof(VERTICE));
            copia(aux, no_da_arvore->dir);

            lista_de_prioridade(no_da_arvore);
            free(no_da_arvore);
            return aux;
          } else {
            VERTICE *dados = malloc(sizeof(VERTICE));
            VERTICE *lixo = no_da_arvore->esq;
            copia(dados, no_da_arvore);

            while (lixo->dir != NULL) {
              lixo = lixo->dir;
            }
            copia(no_da_arvore, lixo);

            copia(lixo, dados);
            free(dados);
            no_da_arvore->esq = apaga(no_da_arvore->esq, numero);
            return no_da_arvore;
          }
        }
      }
    } else {
      if (no_da_arvore->id > numero) {
        no_da_arvore->esq = apaga(no_da_arvore->esq, numero);
      } else {
        no_da_arvore->dir = apaga(no_da_arvore->dir, numero);
      }

      return no_da_arvore;
    }
  }
}

int prin_fila() {
  VERTICE *auxiliar = inicio;
  if (inicio == NULL) {
    printf("\nlista vazia! não ha pediods!\n");
    return 0;
  } else {
    int numero = 1;
    printf("\n\t--------lista de pedidos-------\n");
    printf("\n**************************************\n");
    while (auxiliar != NULL) {
      printf("\n**** pedido numero %i ****", numero);
      printf("\naluno: %s \t matricula: %i\n", auxiliar->nome_aluno,
             auxiliar->matricula);
      printf("informaçoes sobre o livro: %s\nnome do responssavel: %s\n",
             auxiliar->descricao, auxiliar->nome_do_responssavel);
      printf("campus onde está o livro: %s\n",
             auxiliar->nome_do_campos_com_livro);
      printf("campos onde está o aluno: %s\n",
             auxiliar->nome_do_campos_com_aluno);
      printf("\n**************************************\n");
      auxiliar = auxiliar->prox;
      numero++;
    }
    return 1;
  }
}
void responsavel(char *auxiliar) { strcpy(nome_responsavel, auxiliar); }

void remover_da_lista() {

  if (inicio == NULL) {
    printf("lista está vazia");
  } else {
    VERTICE *lixo = inicio;
    inicio = inicio->prox;
    free(lixo);
  }
}
