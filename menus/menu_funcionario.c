#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "../conta/conta.h"
#include "../funcionario/funcionario.h"
#include "../relatorio_geral.h"

void abrir_menu_funcionario(char *mensagem)
{
  system("cls");
  printf("%s", mensagem);

  int opcao;
  printf("\n -=-=-=-= Menu Funcionario -=-=-=-= \n \n");
  printf("1 - Abertura de Conta \n2 - Encerramento de Conta \n3 - Consultar Dados \n4 - Alterar Dados \n5 - Cadastro de Funcionarios \n6 - Gerar Relatorios \n7 - Sair \n");
  scanf("%d", &opcao);
  switch (opcao) {
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
      abrir_menu_principal("");
      break;
    default:
      abrir_menu_funcionario("-> Opção inválida\n");
      break;
  }
}