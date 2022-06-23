#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  }}

void add_abb(int id, char *nome_aluno, int matricula, char *descricao) {

  VERTICE *aux = buscar(id, raiz);

  if (aux != NULL && aux->id == id) {
    printf("Insercao invalida!\n");
  } else {

    VERTICE *novo = malloc(sizeof(VERTICE));
    novo->id = id;
    strcpy(novo->nome_aluno, nome_aluno);
    novo->matricula = matricula;
    strcpy(novo->descricao, descricao);
    novo->esq = NULL;
    novo->dir = NULL;

    if (aux == NULL) { // arvore esta vazia
      raiz = novo;
    } else {

      if (id < aux->id) {
        aux->esq = novo;
      } else {
        aux->dir = novo;
      }
    }
  }
}

void delet(int numero) { apaga(raiz, numero); }

void imprimir() { in_ordem(raiz); }
