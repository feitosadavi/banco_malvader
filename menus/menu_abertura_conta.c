#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"

void abrir_menu_abertura_conta()
{
  system("clear");
  int opcao = 0;
  printf("\n -=-=-=-= Menu Abertura de Conta -=-=-=-= \n \n");

  printf(" 1 - Abertura de Conta \n 2 - Encerramento de Conta \n 3 - Sair \n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    abrir_conta_corrente();
    break;

  case 2:
    abrir_conta_poupanca();
    break;

  case 3:
    abrir_menu_funcionario("");
    break;
  }
}