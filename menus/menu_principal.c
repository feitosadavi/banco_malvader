#include <stdio.h>
#include "menus.h"
#include "../autenticacao/autenticacao.h"

void abrir_menu_principal()
{
  system("clear");

  int opcao = 0;

  printf(" 1 - Menu Funcionário \n 2 - Menu Cliente \n");
  scanf("%d", &opcao);

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
      // abrir_menu_cliente();
      break;

    case 3:
      printf("Encerrando programa");
      break;
    }
  }
}