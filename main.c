#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <locale.h>
#include "menus/menus.h"
int main() {
  setlocale(LC_ALL, "Portuguese");
  abrir_menu_principal("");
  return 0;
}

