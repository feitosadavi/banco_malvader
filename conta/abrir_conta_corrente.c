#include "../gerenciador_de_arquivos.c"
#include "../ferramentas.c"
#include "../menus/menus.h"

void abrir_conta_corrente(char *mensagem) {
  // system("clear");
  printf("%s\n", mensagem);
  int opcao = 16;
  char *agencia_token="", *n_conta_token="";
  char *val_agencia = "", *val_n_conta = "";
  do {
    system("clear");
    printf("\n 1 - Agência [%s] \n 2 - Nº da conta [%s] \n 16 - Finalizar\n", val_agencia, val_n_conta);
    printf("Insira a opção desejada: ");

    char opcao_str[10];
    if (fgets(opcao_str, sizeof(opcao_str), stdin) != NULL) {
      opcao = atoi(opcao_str);
    }
    switch (opcao) {
      case 1:
        ler_dado_e_gerar_token("Insira o número da agência: ", "agencia", &agencia_token);
        extrair_valor_do_token(agencia_token, &val_agencia);
        break;
      case 2:
        ler_dado_e_gerar_token("Insira o número da conta: ", "n_conta", &n_conta_token);
        extrair_valor_do_token(n_conta_token, &val_n_conta);
        break;
      case 16:
        goto Cleanup;
        Cleanup: ;
        char *tokens[] = { agencia_token };
        gravar_com_referencia("arquivos.txt", n_conta_token, tokens, 1);
        abrir_menu_funcionario("Conta gravada com sucesso! \n");
        break;
      default:
        printf("Opção inválida!\n");
        break;
    }
  } while (opcao != 16);
}
