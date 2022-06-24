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

void add_abb(VERTICE dados){

  VERTICE *aux = buscar(dados.id, raiz);

  if (aux != NULL && aux->id == dados.id) {
    printf("Insercao invalida!\n");
  } else {

    VERTICE *novo = malloc(sizeof(VERTICE));
    novo->id = dados.id;
    strcpy(novo->nome_aluno, dados.nome_aluno);
    novo->matricula = dados.matricula;
    strcpy(novo->descricao, dados.descricao);
    novo->esq = NULL;
    novo->dir = NULL;

    if (aux == NULL) { // arvore esta vazia
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
  if(raiz== NULL)
     printf("\nnão a pedidos!\n");
  else{
     in_ordem(raiz);
        int posicao;
        printf("\ndigite a posiçao ");
        scanf("%d", &posicao);
        delet(posicao);}
  }
