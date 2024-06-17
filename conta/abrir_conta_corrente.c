#include "../gerenciador_de_arquivos.c"

void abrir_conta_corrente(char *mensagem) {
  system("clear");
  printf("%s\n", mensagem);
  int opcao = 0;
  do {
    char *agencia = NULL;    
    // system("clear");
    printf("\n 1 - Agência \n 16 - Finalizar\n");
    printf("Insira a opção desejada: ");

    char opcao_str[10];
    if (fgets(opcao_str, sizeof(opcao_str), stdin) != NULL) {
      opcao = atoi(opcao_str);
    }
    switch (opcao) {
      case 1:
        ler_dado("agencia", "Insira o número da agência: ", &agencia);
        break;
      case 16:
        goto Cleanup;
        Cleanup: ;

        char *chave_valor[] = { agencia };
        gravar_com_referencia("arquivos.txt", format_string("Conta %d:", 1), chave_valor, 1);
        break;
      default:
        printf("Opção inválida!\n");
        break;
    }
  } while (opcao != 16);
}
