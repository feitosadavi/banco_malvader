#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../autenticacao/autenticacao.h"

void abrir_menu_principal()
{
  system("clear");

  int opcao = 0;
  printf("\n -=-=-=-= Menu Principal -=-=-=-= \n \n");

  printf("1 - Menu Funcionário \n2 - Menu Cliente \n3 - Sair \n");
  scanf("%d", &opcao);

  if (opcao != 3)
  {
    char senha[10];
    printf("Digite a senha de administrador: ");
    scanf("%10s", senha);
    if (autorizar(senha))
    {
      switch (opcao)
      {
      case 1:
        abrir_menu_funcionario();
        break;

      case 2:
        abrir_menu_cliente();
        break;

      default:
        printf("Encerrando programa");
        exit(0);
        break;
      }
    }
  }
  else
  {
    printf("Encerrando programa");
    exit(1);
  }
}