#include <stdio.h>
#include <stdlib.h>
#include "../menus/menus.h"
#include "../gerenciador_de_arquivos.h"

void encerrar_conta()
{
  char *n_conta;

  system("clear");
  printf("Encerrar conta: não implementado");
  printf("Digite o número da conta para encerrar: ");
  scanf("%s", n_conta);
  abrir_menu_funcionario();
}