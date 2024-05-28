#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"
#include "../funcionario/funcionario.h"
#include "../relatorio_geral.h"

void abrir_menu_funcionario()
{
  system("clear");

  int opcao = 0;
  printf("\n -=-=-=-= Menu Funcionário -=-=-=-= \n \n");

  printf("1 - Abertura de Conta \n2 - Encerramento de Conta \n3 - Consultar Dados \n4 - Alterar Dados \n5 - Cadastro de Funcionários \n6 - Gerar Relatórios \n7 - Sair \n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    abrir_menu_abertura_conta();
    break;

  case 2:
    encerrar_conta();
    break;

  case 3:
    abrir_menu_consultar_dados();
    break;

  case 4:
    abrir_menu_alterar_dados();
    break;

  case 5:
    cadastrar_funcionario();
    break;

  case 6:
    gerar_relatorio_geral();
    break;

  case 7:
    abrir_menu_principal();
    break;
  }
}