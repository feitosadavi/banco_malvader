#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX_LINE_LENGTH 100

FILE *abrir_arquivo(const char *nome_do_arquivo, const char *modo) {
  FILE *arquivo = fopen(nome_do_arquivo, modo);
  if (arquivo == NULL) {
    printf("Arquivo: %s\n", nome_do_arquivo);
    perror("Erro ao abrir o arquivo");
  }
  return arquivo;
}

int gravar_com_referencia(const char *nome_arquivo, char *referencia, char *itens[], int tamanho) {
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r");
  FILE *arquivo_temp = abrir_arquivo("temp.txt", "w");
  if (arquivo_temp == NULL) {
    fclose(arquivo);
    return 1;
  }

  char linha[1000];
  int referencia_encontrada = 0;
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    fputs(linha, arquivo_temp);
    if (strncmp(linha, referencia, strlen(referencia)) == 0) {
      for (int i = 0; i < tamanho; i++) { 
        printf("Agência: %s", itens[0]);
        fprintf(arquivo_temp, "%s\n", itens[i]);
      }
      referencia_encontrada = 1;
    }
  }

  fclose(arquivo);
  fclose(arquivo_temp);

  if (referencia_encontrada) {
    if (remove(nome_arquivo) != 0) {
      perror("Erro ao remover o arquivo original");
      return 1;
    }
    if (rename("temp.txt", nome_arquivo) != 0) {
      perror("Erro ao renomear o arquivo temporário");
      return 1;
    }
  } else {
    remove("temp.txt");
    return 1;
  }
  return 0;
}

char* format_string(const char *format, ...) {
  va_list args;
  va_start(args, format);
  int size = vsnprintf(NULL, 0, format, args);
  va_end(args);

  if (size < 0) {
    return NULL;
  }

  char *formatted_string = (char *)malloc(size + 1);
  if (formatted_string == NULL) {
    return NULL;
  }

  va_start(args, format);
  vsnprintf(formatted_string, size + 1, format, args);
  va_end(args);

  return formatted_string;
}

void ler_dado(char *chave, char *comando, char **chave_valor) {
  char valor[256];

  // Lê a string de entrada e armazena em valor
  printf("Digite o valor: ");
  if (fgets(valor, sizeof(valor), stdin) == NULL) {
    fprintf(stderr, "Erro ao ler o valor.\n");
    return;
  }
  printf("Valor: %s", valor);

  // Remove o caractere de nova linha, se presente
  size_t len = strlen(valor);
  if (len > 0 && valor[len-1] == '\n') {
    valor[len-1] = '\0';
  }

  // Calcula o tamanho necessário para a string concatenada
  size_t tamanho_chave = strlen(chave);
  size_t tamanho_valor = strlen(valor);
  size_t tamanho_total = tamanho_chave + 1 + tamanho_valor + 1;

  // Aloca memória para a string concatenada
  *chave_valor = (char *)malloc(tamanho_total);
  if (*chave_valor == NULL) {
    fprintf(stderr, "Erro ao alocar memória.\n");
    return;
  }

  // Concatena a chave e o valor na forma "chave:valor"
  snprintf(*chave_valor, tamanho_total, "%s:%s", chave, valor);
}


void alterar_valor_arquivo(const char *nome_arquivo, const char *chave_alvo, const char *novo_valor) {
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r+");

  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    // separa a chave a valor da string que vem no formato "chave:valor"
    char *chave = strtok(linha, ":");
    char *valor = strtok(NULL, ":");

    if (chave != NULL && valor != NULL) {
      valor[strcspn(valor, "\n")] = 0;

      if (strcmp(chave, chave_alvo) == 0) {
        fseek(arquivo, -strlen(valor), SEEK_CUR);
        fprintf(arquivo, "%s", novo_valor);
        break;
      }
    }
  }

  fclose(arquivo);
}

void excluir_campo_arquivo(const char *nome_arquivo, const char *campo) {
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r");
  FILE *arquivo_temp = abrir_arquivo("temp.txt", "w");

  char linha[100];
  size_t campo_len = strlen(campo);

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (strncmp(linha, campo, campo_len) != 0) {
      fputs(linha, arquivo_temp);
    }
  }

  fclose(arquivo);
  fclose(arquivo_temp);

  if (remove(nome_arquivo) != 0) {
    perror("Erro ao remover o arquivo original.\n");
    return;
  }

  if (rename("temp.txt", nome_arquivo) != 0) {
    perror("Erro ao renomear o arquivo temporário.\n");
    return;
  }
}

int ler_campo_arquivo(const char *nome_arquivo, char *campo) {
	int dado;
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r");
	fscanf(arquivo, campo, &dado);
	fclose(arquivo);
	return dado;
}
