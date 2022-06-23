#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

VERTICE *apaga(VERTICE *no_da_arvore, int numero) {
  if (no_da_arvore == NULL) {
    printf("posição %i não encontrado!", numero);
    return NULL;
  } else {
    if (no_da_arvore->id == numero) {
      if (no_da_arvore->esq == NULL &&
          no_da_arvore->dir == NULL) { // apaga a folha
        free(no_da_arvore);
        return NULL;
      } else {
        if (no_da_arvore->esq != NULL && no_da_arvore->dir == NULL) {
          free(no_da_arvore);
          return no_da_arvore->esq;
        } else {
          if (no_da_arvore->dir != NULL && no_da_arvore->esq == NULL) {
            free(no_da_arvore);
            return no_da_arvore->dir;
          } else {
            VERTICE dados, *lixo = no_da_arvore->esq;
            dados.id = no_da_arvore->id;
            dados.matricula = no_da_arvore->matricula;
            strcpy(dados.nome_aluno, no_da_arvore->nome_aluno);
            strcpy(dados.descricao, no_da_arvore->descricao);
            while (lixo->dir != NULL) {
              lixo = lixo->dir;
            }
            no_da_arvore->id = lixo->id;
            no_da_arvore->matricula = lixo->matricula;
            strcpy(no_da_arvore->nome_aluno, lixo->nome_aluno);
            strcpy(no_da_arvore->descricao, lixo->descricao);

            lixo->id = dados.id;
            lixo->matricula = dados.matricula;
            strcpy(lixo->nome_aluno, dados.nome_aluno);
            strcpy(lixo->descricao, dados.descricao);

            return no_da_arvore->esq = apaga(no_da_arvore->esq, numero);
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
