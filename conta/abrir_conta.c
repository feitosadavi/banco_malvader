#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "../menus/menus.h"

void abrir_conta()
{
  system("clear");
  int opcao = 0;

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
    // menu_funcionario();
    break;
  }
}