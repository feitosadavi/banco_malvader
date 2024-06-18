#include "../gerenciador_de_arquivos.c"
#include "../ferramentas.c"
#include "../menus/menus.h"

void abrir_conta_corrente(char *mensagem) {
  printf("%s\n", mensagem);

  int opcao = 0;
  char *tokens[14] = { NULL };
  char *valores[14] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
  char *comandos[14] = {
    "Insira o numero da agencia: ",
    "Insira o numero da conta: ",
    "Insira o nome do cliente: ",
    "Insira o CPF do cliente: ",
    "Insira a data de nascimento: ",
    "Insira o telefone de contato: ",
    "Insira o endereço do cliente: ",
    "Insira o CEP: ",
    "Insira o local: ",
    "Insira o numero da casa: ",
    "Insira o bairro: ",
    "Insira a cidade: ",
    "Insira o estado: ",
    "Insira a senha do cliente: "
  };
  char *chaves[14] = {
    "agencia", "n_conta", "nome_cliente", "cpf_cliente", "data_nascimento",
    "telefone_contato", "endereco_cliente", "cep", "local", "n_casa",
    "bairro", "cidade", "estado", "senha_cliente"
  };

  do {
    system("cls");
    printf("\n1 - Agencia [%s] \n2 - Numero da conta [%s] \n3 - Nome do cliente [%s] \n4 - CPF do cliente [%s] \n5 - Data de nascimento [%s] \n6 - Telefone de contato [%s] \n7 - Endereco do cliente [%s] \n8 - CEP [%s] \n9 - Local [%s] \n10 - Numero da casa [%s] \n11 - Bairro [%s] \n12 - Cidade [%s] \n13 - Estado [%s] \n14 - Senha do cliente [%s] \n15 - Finalizar\n",
    valores[0], valores[1], valores[2], valores[3], valores[4], valores[5], valores[6], valores[7], valores[8], valores[9], valores[10], valores[11], valores[12], valores[13]);
    printf("Insira a opcao desejada: ");

    char opcao_str[10];
    if (fgets(opcao_str, sizeof(opcao_str), stdin) != NULL) {
      opcao = atoi(opcao_str);
    }

    if (opcao >= 1 && opcao <= 14) {
      ler_dado_e_gerar_token(comandos[opcao - 1], chaves[opcao - 1], &tokens[opcao - 1]);
      extrair_valor_do_token(tokens[opcao - 1], &valores[opcao - 1]);
    } else if (opcao != 16) {
      printf("Opcao invalida!\n");
    }
  } while (opcao != 15);

  Cleanup:
  // Verificar se o numero da conta foi fornecido
  if (tokens[1] != NULL) {
    gravar_com_referencia("arquivos.txt", tokens[1], tokens, 14);
    abrir_menu_funcionario("Conta gravada com sucesso! \n");
  } else {
    printf("Numero da conta eh obrigatorio para finalizar o cadastro.\n");
  }
}