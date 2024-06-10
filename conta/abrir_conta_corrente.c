#include <stdio.h>
#include <stdlib.h>
#include "../menus/menus.h"
#include "../gerenciador_de_arquivos.h"

int gravar_dados_int(char *nome, char *comando, Funcionario *funcionario) {
  printf("%s", comando);
  int dado;
  scanf("%d", &funcionario->agencia);
  // int qtd_contas = ler_campo_arquivo("arquivos.txt", "qtd_contas: %d");
  // char referencia[50];
  // char chave_valor[50];
  // sprintf(referencia, "Conta %d:", qtd_contas);
  // sprintf(chave_valor, "%s:%d", nome, dado);
  // gravar_com_referencia("arquivos.txt", referencia, chave_valor);
}

// void ler_qtd_contas() {
//   printf("Ler agencia");
//   FILE *arq = fopen("arquivos.txt", "r");
//   if (arq == NULL) {
//       printf("Erro ao abrir o arquivo.\n");
//       return;
//   }

//   printf("Scaneado agencia");
//   int qtd_contas;
//   while (fscanf(arq, "qtd_contas: 2", qtd_contas) == 1) {
//     printf("qtd_contas: %d\n", qtd_contas);
//   }
//   printf("Arquivo scaneado!");
//   fclose(arq);
// }

struct Funcionario {
  int agencia
}


void abrir_conta_corrente() {
  system("clear");
  int opcao;
  Funcionario funcionario;
  printf("\n 1 - Agência \n 16 - Finalizar");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1:
      // gravar_dados_int("agencia", "Insira o número da agência");

      abrir_conta_corrente("-> Agência salva!");
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


// void gravar_dados(char *nome, ) {
//   FILE *arq;

//   arq=fopen("arquivos.txt","a");

//   if(arq==NULL){
//     printf("Erro ao abrir o arquivo.\n");
//     exit(1);
//   } else {
//     printf("Insira os dados da (o) %d", nome);
//     int dado;
//     scanf("%s", );
//     fprintf(arq,"\n%d: %d", nome, dado);
//     // printf("Dados gravados com sucesso!\n");
//   }
  
//   fclose(arq);
// }