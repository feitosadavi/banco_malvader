// #include <stdio.h>
// #include <stdlib.h>
// #include "../menus/menus.h"
// #include "../funcionario/funcionario.h"
// #include <stdarg.h>

// #define MAX_LINE_LENGTH 100

// FILE *abrir_arquivo(const char *nome_do_arquivo, const char *modo) {
//   FILE *arquivo;
//   arquivo = fopen(nome_do_arquivo, modo);
//   if (arquivo == NULL) {
//     printf("Arquivo: %s\n", nome_do_arquivo);
//     perror("Erro ao abrir o arquivo");
//   }
//   return arquivo;
// }

// int gravar_com_referencia(const char *nome_arquivo, char *referencia, char itens [1][50], Funcionario *funcionario) {
//   FILE *arquivo = abrir_arquivo(nome_arquivo, "r");
//   FILE *arquivo_temp = abrir_arquivo("temp.txt", "w");
//   char linha[1000];   
//   int referencia_encontrada = 0;
//   while (fgets(linha, sizeof(linha), arquivo) != NULL) {
//     printf("linha: %s", linha);
//     fputs(linha, arquivo_temp);
//     if (strncmp(linha, referencia, strlen(referencia)) == 0) {
//       int tamanho = sizeof(itens) / sizeof(itens[0]);
//       for (int i = tamanho; i < 1; i++) {
//         fprintf(arquivo_temp, "%s\n", itens[i]); 
//       }
//       referencia_encontrada = 1;
//     }
//   }

//   fclose(arquivo);
//   fclose(arquivo_temp);

//   if (referencia_encontrada) {
//     if (remove(nome_arquivo) != 0) {
//       perror("Erro ao remover o arquivo original");
//       return 1;
//     }
//     if (rename("temp.txt", nome_arquivo) != 0) {
//       perror("Erro ao renomear o arquivo temporário");
//       return 1;
//     }
//   } else {
//     remove("temp.txt");
//     return 1;
//   }
//   return 0;
// }

// void ler_dado(char *chave, char *comando, char **chave_valor) {
//     char *valor; // Buffer para armazenar a entrada do usuário

//     printf("%s", comando);
//     fflush(stdin);
//     // if (scanf("%49s", valor) != 1) { // Limita a leitura a 49 caracteres para evitar overflow
//     //     fprintf(stderr, "Erro ao ler a entrada.\n");
//     //     exit(EXIT_FAILURE);
//     // }

//     // // Alocando memória para chave_valor e formatando a string
//     // *chave_valor = (char *)malloc(strlen(chave) + strlen(valor) + 2); // +2 para ':' e '\0'
//     // if (*chave_valor == NULL) {
//     //     fprintf(stderr, "Erro ao alocar memória.\n");
//     //     exit(EXIT_FAILURE);
//     // }
//     // printf("%s", format_string("%s:%s", chave, valor));
// }

// // void ler_qtd_contas() {
// //   printf("Ler agencia");
// //   FILE *arq = fopen("arquivos.txt", "r");
// //   if (arq == NULL) {
// //       printf("Erro ao abrir o arquivo.\n");
// //       return;
// //   }

// //   printf("Scaneado agencia");
// //   int qtd_contas;
// //   while (fscanf(arq, "qtd_contas: 2", qtd_contas) == 1) {
// //     printf("qtd_contas: %d\n", qtd_contas);
// //   }
// //   printf("Arquivo scaneado!");
// //   fclose(arq);
// // }


// // void abrir_menu(Funcionario *funcionario) {
  
// // }

// // Function to format a string with variable arguments and return a dynamically allocated string
// char* format_string(const char *format, ...) {
//     // Variable argument list
//     va_list args;
    
//     // Initialize the argument list
//     va_start(args, format);
    
//     // Determine the size of the formatted string
//     int size = vsnprintf(NULL, 0, format, args);
    
//     // Clean up the argument list
//     va_end(args);
    
//     if (size < 0) {
//         return NULL;
//     }
    
//     // Allocate memory for the formatted string
//     char *formatted_string = (char *)malloc(size + 1);
//     if (formatted_string == NULL) {
//         return NULL;
//     }
    
//     // Initialize the argument list again for the actual formatting
//     va_start(args, format);
    
//     // Format the string
//     vsnprintf(formatted_string, size + 1, format, args);
    
//     // Clean up the argument list
//     va_end(args);
    
//     return formatted_string;
// }

// void abrir_menu (Funcionario *funcionario) {
//   int opcao = 0;
//   char *agencia;
//   do
//   {
//     // system("clear");
//     printf("\n 1 - Agência \n 16 - Finalizar\n");
//     printf("Insira a opção desejada: ");
//     scanf("%d", &opcao);
//     switch (opcao) {
//       case 1:
//         ler_dado("agencia", "Insira o número da agência: ", &agencia);
//         break;
//       // case 2:
//       //   gravar_dados_int("Número da conta", "Insira o número da conta");
//       //   abrir_conta_corrente("-> Número da conta salvo!");
//       //   break;
//       // case 3:
//       //   gravar_dados_int("Número da conta", "Insira o número da conta");
//       //   abrir_conta_corrente("-> Número da conta salvo!");
//         break;
//       case 16:
//         printf("Agencia: %s", agencia);
//         // goto Cleanup;
//         // Cleanup: ; //This is an empty statement.
//         // char *chave_valor[] = { agencia };
//         // gravar_com_referencia("arquivos.txt", format_string("Conta %d:", 1), chave_valor, funcionario);
//         // abrir_menu_abertura_conta();
//         break;

//       default:
//         printf("Opção inválida!\n");
//         break;
//     }
//   } while (opcao <= 16);
// }

// void abrir_conta_corrente(char *mensagem) {
//   printf("%s", mensagem);

//   system("clear");
//   fflush(stdin);
//   Funcionario funcionario = {agencia : ""};
//   abrir_menu(&funcionario);

//   abrir_menu_abertura_conta();
// }


// // void gravar_dados(char *nome, ) {
// //   FILE *arq;

// //   arq=fopen("arquivos.txt","a");

// //   if(arq==NULL){
// //     printf("Erro ao abrir o arquivo.\n");
// //     exit(1);
// //   } else {
// //     printf("Insira os dados da (o) %d", nome);
// //     int dado;
// //     scanf("%s", );
// //     fprintf(arq,"\n%d: %d", nome, dado);
// //     // printf("Dados gravados com sucesso!\n");
// //   }
  
// //   fclose(arq);
// // }