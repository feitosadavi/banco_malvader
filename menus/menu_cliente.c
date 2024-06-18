#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"
#include "../cliente/cliente.h"
#include "../relatorio_geral.h"

void abrir_menu_cliente()
{
  system("cls");
  printf("\n -=-=-=-= Menu Cliente -=-=-=-= \n \n");

  int opcao = 0;

  printf("1 - Saldo \n2 - Depósito \n3 - Saque \n4 - Extrato \n5 - Consultar limite \n6 - Sair \n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    consultar_saldo();
    break;

  case 2:
    realizar_deposito();
    break;

  case 3:
    realizar_saque();
    break;

  case 4:
    consultar_extrato();
    break;

  case 5:
    consultar_limite();
    break;

  case 6:
    abrir_menu_principal();
    break;
  }
}