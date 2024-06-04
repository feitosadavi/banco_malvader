#include<stdio.h>
#include <stdlib.h>
#include "autenticacao.h"

#define SENHA_ADM "1234"
int autorizar () {
  char senha[10];
  printf("Digite a senha de administrador: ");
  scanf("%10s", senha);

  if (strcmp(senha, SENHA_ADM)==0) return 1;
  else return 0;
}