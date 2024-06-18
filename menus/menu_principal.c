#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../autenticacao/autenticacao.h"

void abrir_menu_principal(char *mensagem)
{
  system("cls");
  printf("%s", mensagem);

  int opcao;
    printf("\n -=-=-=-= Menu Principal -=-=-=-= \n \n");
    printf("1 - Menu Funcionario \n2 - Menu Cliente \n3 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        if (autorizar()) abrir_menu_funcionario();
        else abrir_menu_principal("-> Senha invalida");
        break;

      case 2:
        if (autorizar()) abrir_menu_cliente();
        else abrir_menu_principal("-> Senha invalida");
        break;

      case 3:
        printf("Encerrando programa");
        exit(1);

      default:
        abrir_menu_principal("-> Opção invalida");
        printf("\nOpção invalida\n");
        break;
    }
}