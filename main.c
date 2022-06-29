#include "crud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int c = 0;

  log secretario[3] = {{"evanildo", "123", "456", "secretario"},
                       {"silva", "321", "654", "secretario"},
                       {"dean", "789", "987", "secretario"}};
  log transportador[3] = {{"rafael", "1234", "345", "transportador"},
                          {"rebouças", "678", "876", "transportador"},
                          {"rael", "543", "876", "transportador"}};
  for (int i = 0; i < 3; i++) {
    cadastrar_log(secretario[i]);
    cadastrar_log(transportador[i]);
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
      tela_estagiario();
      break;
    }
    case 2: {
      if (verificar(2)) {

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
          if (verificar(3)) {
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

