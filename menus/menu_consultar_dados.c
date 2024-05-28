#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"

void abrir_menu_consultar_dados()
{
  system("clear");

  int opcao = 0;
  printf("\n -=-=-=-= Menu Consultar Dados -=-=-=-= \n \n");

  printf("1 - Consultar Conta \n2 - Consultar Funcionário \n3 - Consultar Cliente \n4 - Voltar\n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    consultar_dados(1);
    break;

  case 2:
    consultar_dados(2);
    break;

  case 3:
    consultar_dados(3);
    break;

  case 4:
    abrir_menu_funcionario();
    break;
  }
}