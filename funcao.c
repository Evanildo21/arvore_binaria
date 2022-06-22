#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Vertice{
   
    //Dados iniciais da encomenda de um livro
    int id; //identificador
    char  nome_aluno[50];
    int matricula;
    char  descricao[100];
    
    //mecanismo p/ unir nos!
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;


VERTICE * raiz = NULL;

VERTICE* buscar(int id, VERTICE *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }
}


void add_abb(int id, char *nome_aluno, int matricula, char *descricao){

    VERTICE* aux = buscar(id, raiz);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");
    }else{
        
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->id = id;
        strcpy(novo->nome_aluno,nome_aluno);
        novo->matricula = matricula;
        strcpy(novo->descricao,descricao);
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(aux == NULL){//arvore esta vazia
            raiz = novo;
        }else{
            if(id < aux->id){
                aux->esq = novo;
            }else{
                aux->dir = novo;
            }
        }
    }
}


void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("\n");
    printf(" %d ", aux->id);
    printf(" %s ", aux->nome_aluno);
    printf(" %d ", aux->matricula);
    printf(" %s ", aux->descricao);
        printf("\n");
    if(aux->dir != NULL){
        in_ordem(aux->dir);
        }
}


VERTICE * apaga(VERTICE *no_da_arvore, int numero) {
  if (no_da_arvore == NULL) {
      printf("posição %i não encontrado!",numero);
    return NULL;}
  else {
      if (no_da_arvore->id == numero) {
          if (no_da_arvore->esq == NULL && no_da_arvore->dir == NULL){  //apaga a folha 
              free(no_da_arvore);
              return NULL;}
          else{ 
              if(no_da_arvore->esq != NULL && no_da_arvore ->dir == NULL){
                  free(no_da_arvore);
                  return no_da_arvore->esq;}
              else{
                  if(no_da_arvore->dir != NULL && no_da_arvore->esq == NULL){
                      free(no_da_arvore);
                      return no_da_arvore->dir;}
                  else{
                    VERTICE dados,*lixo = no_da_arvore->esq;
                    dados.id=no_da_arvore->id;
                    dados.matricula=no_da_arvore->matricula;
                    strcpy(dados.nome_aluno,no_da_arvore->nome_aluno);
                    strcpy(dados.descricao,no_da_arvore->descricao);
                    while(lixo->dir != NULL){
                           lixo=lixo->dir;
                      }
                    no_da_arvore->id=lixo->id;
                    no_da_arvore->matricula=lixo->matricula;
                    strcpy(no_da_arvore -> nome_aluno,lixo->nome_aluno);
                    strcpy(no_da_arvore->descricao,lixo->descricao);

                    lixo->id=dados.id;
                    lixo->matricula=dados.matricula;
                    strcpy(lixo-> nome_aluno,dados.nome_aluno);
                    strcpy(lixo->descricao,dados.descricao);
                    
                    return no_da_arvore->esq = apaga(no_da_arvore->esq,numero);
                    
                    }
                  }
                }
      } 
      else {
          if (no_da_arvore->id > numero){ 
              no_da_arvore->esq=apaga(no_da_arvore->esq, numero);}
          else{ 
              no_da_arvore->dir=apaga(no_da_arvore->dir, numero);}
          
        return no_da_arvore;}}
}
int main() {
 
  add_abb(10,"evanildo",511236,"li");
  add_abb(29,"rafael",511236,"li");
  add_abb(6,"souza",511236,"li");
  add_abb(15,"soares",511236,"li");
  add_abb(3,"douglas",511236,"li");
  add_abb(7,"ezequiel",123,"e");
  add_abb(14,"gadriel",789,"anjo");
   add_abb(31,"gadriel",789,"anjo");
  VERTICE *teste =apaga(raiz,10);
  printf("\n\nin ordem: ");
   in_ordem(raiz);

  return 0;
}
