#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"

void abrir_menu_abertura_conta()
{
  system("cls");
  int opcao = 0;
  printf("\n -=-=-=-= Menu Abertura de Conta -=-=-=-= \n \n");

  printf(" 1 - Conta Corrente \n 2 - Conta Poupança \n 3 - Sair \n");
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