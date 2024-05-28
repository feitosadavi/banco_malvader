#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"

void abrir_menu_alterar_dados()
{
  system("clear");

  int opcao = 0;

  printf(" 1 - Alterar Conta \n 2 - Alterar Funcionário \n 3 - Alterar Cliente \n 4 - Voltar\n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    alterar_dados(1);
    break;

  case 2:
    alterar_dados(2);
    break;

  case 3:
    alterar_dados(3);
    break;

  case 4:
    abrir_menu_funcionario();
    break;
  }
}