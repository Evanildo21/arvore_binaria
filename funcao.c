#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VERTICE *inicio= NULL;

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


VERTICE * prioridade(VERTICE *aux,VERTICE *x){
if(aux == NULL){
  return  x;
}else{
  if(aux->prioridade_do_pedido < x->prioridade_do_pedido){
    x->prox = aux;
    return x;
    }else{
        if(aux->prioridade_do_pedido >= x->prioridade_do_pedido){
               aux->prox = prioridade(aux->prox, x);
        }
    }
}
return aux;
}


void lista_de_prioridade(VERTICE *dados){
  VERTICE *auxiliar = malloc(sizeof(VERTICE));
  printf("aluno: %s \t matricula: %i\ndetalhes do livro: %s",dados->nome_aluno,dados->matricula,dados->descricao);
  auxiliar->id = dados->id;
  auxiliar->matricula = dados->matricula;
  strcpy(auxiliar->nome_aluno,dados->nome_aluno);
  strcpy(auxiliar->descricao,dados->descricao);
  printf("\ndigite o nome do campus onde está o livro! ");
  scanf(" %[^\n]s",auxiliar->nome_do_campos_com_livro);
  printf("digite o nome do campus onde está o aluno! ");
  scanf(" %[^\n]s",auxiliar->nome_do_campos_com_aluno);
  printf("digite o nome do reponsavel pelo pedido ");
  scanf(" %[^\n]s",auxiliar->nome_do_responssavel);
  printf("de 0 a 100 qual a prioridade desse pedido ");
  scanf("%i",&auxiliar->prioridade_do_pedido);
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
          no_da_arvore->dir == NULL) { // apaga a folha   
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
            lista_de_prioridade(no_da_arvore);
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

void prin_fila(){
VERTICE *auxiliar=inicio;
   printf("fila ");
  while(auxiliar!=NULL){
  printf(" \n%s %i",auxiliar->nome_aluno,auxiliar->matricula);
    auxiliar=auxiliar->prox;
    }
  }
