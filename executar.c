#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e_d/crud.h"


log *primeiro = NULL, *ultimo= NULL;



void cadastrar_log(char *e_mail,char *senha){
  log *auxiliar = malloc(sizeof(log));
  strcpy(auxiliar->email,e_mail); 
  strcpy(auxiliar->senha,senha);
  auxiliar->prox = NULL;
  
  if (primeiro == NULL) { // fila vazia
    primeiro = auxiliar;
    ultimo = auxiliar;

  } else { // adiciona no final da fila
    ultimo->prox = auxiliar;
    ultimo = auxiliar;
  }
}
int verificar(char *auxiliar_email, char *auxiliar_senha){
  log *aux_da_lista = primeiro;
  do{
  int contador_de_carcteres_email = 0;
  int contador_de_carcteres_senha = 0;
  int tamanho_do_email = strlen(aux_da_lista->email);
  int tamanho_da_senha = strlen(aux_da_lista->senha);
  
  for (int i = 0; i < tamanho_do_email; i++) {
    if (auxiliar_email[i] == aux_da_lista->email[i]) {
      contador_de_carcteres_email++;
    }}

   for (int i = 0; i < tamanho_da_senha; i++) {
    if (auxiliar_senha[i] == aux_da_lista->senha[i]) {
      contador_de_carcteres_senha++;
    }}
 
  
  if (contador_de_carcteres_email == tamanho_do_email &&
      contador_de_carcteres_senha == tamanho_da_senha) {
    return 1;
  } 
    aux_da_lista=aux_da_lista->prox;
  }while(aux_da_lista!=NULL);
   printf("\nemail ou senha invalido!");
return 0;
  }
  
int main() {
  cadastrar_log("evanildo","123");
  cadastrar_log("rafael","345");
  add_abb(10,"evanildo",511236,"li");
  add_abb(29,"rafael",511236,"li");
  add_abb(6,"souza",511236,"li");
  add_abb(15,"soares",511236,"li");
  add_abb(3,"douglas",511236,"li");
  add_abb(7,"ezequiel",123,"e");
  add_abb(14,"gadriel",789,"anjo");
  add_abb(31,"gadriel",789,"anjo");
  
if(verificar("evanildo","123")){
 delet(29);
}
  
  printf("\n\nin ordem: ");
  imprimir();

  return 0;
}
