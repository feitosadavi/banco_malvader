#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"

void abrir_menu_funcionario()
{
  system("clear");

  int opcao = 0;

  printf(" 1 - Abertura de Conta \n 2 - Encerramento de Conta \n 3 - Consultar Dados \n 4 - Alterar Dados \n 5 - Cadastro de Funcionários \n 6 - Gerar Relatórios \n 7 - Sair \n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    abrir_conta();
    break;

  case 2:
    encerrar_conta();
    break;

  case 3:
    abrir_menu_consultar_dados();
    break;

  case 4:
    // alterar_dados();
    break;

  case 5:
    // cadastro_de_funcionarios();
    break;

  case 6:
    // gerar_relatorios();
    break;

  case 7:
    abrir_menu_principal();
    break;
  }
}