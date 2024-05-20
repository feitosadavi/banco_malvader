#include<stdio.h>
#include "menus/menus_funcionario.c"
#include "menus/menus_cliente.c"
#include "autorizar.c"

int main () {
	int opcao = 0;

  printf("1 - Menu Funcionário \n 2 - Menu Cliente \n");
  scanf ("%d", &opcao);

  char senha[10];
  printf("Digite a senha de administrador:  \n");
  fgets(senha, sizeof(senha), stdin); // Lê uma string usando fgets

	switch (opcao) {
		case 1:
      if (autorizar(senha)) {
        abrir_menu_funcionario();
      }
			break;
		
		case 2:
			if (autorizar(senha)) {
        abrir_menu_cliente();
      }
			break;
		
		case 3:
      printf("Encerrando programa");
			break;
	}
	return 0;
}