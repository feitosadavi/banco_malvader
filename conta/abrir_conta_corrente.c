#include <stdio.h>
#include <stdlib.h>
#include "../menus/menus.h"

int gravar_dados_int(char *nome, char *comando) {
  FILE *arq;

  arq=fopen("arquivos.txt","a");

  if(arq==NULL){
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  } else {
    printf("%s", comando);
    int dado;
    scanf("%d", &dado);
    fprintf(arq,"\n%s: %d", nome, dado);
  }
  
  fclose(arq);
}

void ler_qtd_contas() {
  printf("Ler agencia");
  FILE *arq = fopen("arquivos.txt", "r");
  if (arq == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return;
  }

  printf("Scaneado agencia");
  int qtd_contas;
  while (fscanf(arq, "qtd_contas: 2", qtd_contas) == 1) {
    printf("qtd_contas: %d\n", qtd_contas);
  }
  printf("Arquivo scaneado!");
  fclose(arq);
}

void abrir_conta_corrente() {
  system("clear");
  int opcao;
  printf("\n 1 - Agência \n 16 - Finalizar");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1:
      ler_qtd_contas();
      // gravar_dados_int("Agência", "Insira o número da agência");
      // abrir_conta_corrente("-> Agência salva!");
      break;
    // case 2:
    //   gravar_dados_int("Número da conta", "Insira o número da conta");
    //   abrir_conta_corrente("-> Número da conta salvo!");
    //   break;
    // case 3:
    //   gravar_dados_int("Número da conta", "Insira o número da conta");
    //   abrir_conta_corrente("-> Número da conta salvo!");
      break;
    case 16:
      abrir_menu_abertura_conta();
      break;

    default:
      break;
  }

  abrir_menu_abertura_conta();
}


void gravar_dados(char *nome, ) {
  FILE *arq;

  arq=fopen("arquivos.txt","a");

  if(arq==NULL){
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  } else {
    printf("Insira os dados da (o) %d", nome);
    int dado;
    scanf("%s", );
    fprintf(arq,"\n%d: %d", nome, dado);
    // printf("Dados gravados com sucesso!\n");
  }
  
  fclose(arq);
}