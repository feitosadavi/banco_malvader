#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define LINHA 100

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

  char linha[LINHA];
  int referencia_encontrada = 0;
  printf("Partiu fgtes\n");
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    fputs(linha, arquivo_temp);
  }

  fprintf(arquivo_temp, "\n%s\n", referencia);
  for (int i = 0; i < tamanho; i++) {
    fprintf(arquivo_temp, "%s\n", itens[i]);
  }

  fclose(arquivo);
  fclose(arquivo_temp);

  // Substituir o arquivo original pelo temporário
  if (remove(nome_arquivo) != 0) {
    perror("Erro ao deletar o arquivo original");
    return EXIT_FAILURE;
  }
  if (rename("temp.txt", nome_arquivo) != 0) {
    perror("Erro ao renomear o arquivo temporário");
    return EXIT_FAILURE;
  }
}

void ler_dado_e_gerar_token(char *comando, char *chave_token, char **token) {
  char valor[256];

  printf("%s: ", comando);
  if (fgets(valor, sizeof(valor), stdin) == NULL) {
    fprintf(stderr, "Erro ao ler o valor.\n");
    return;
  }

  size_t len = strlen(valor);
  if (len > 0 && valor[len-1] == '\n') {
    valor[len-1] = '\0';
  }

  // Calcula o tamanho necessário para a string concatenada
  size_t tamanho_chave = strlen(chave_token);
  size_t tamanho_valor = strlen(valor);
  size_t tamanho_total = tamanho_chave + 1 + tamanho_valor + 1;

  // Aloca memória para a string concatenada
  *token = (char *)malloc(tamanho_total);
  if (*token == NULL) {
    fprintf(stderr, "Erro ao alocar memória.\n");
    return;
  }

  snprintf(*token, tamanho_total, "%s:%s", chave_token, valor);
}


void alterar_valor_arquivo(const char *nome_arquivo, const char *chave_alvo, const char *novo_valor) {
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r+");

  char linha[LINHA];
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

  char linha[LINHA];
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

int deletar_com_referencia(const char *nome_arquivo, char *referencia) {
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r");
  FILE *arquivo_temp = abrir_arquivo("temp.txt", "w");

  char linha[1000];
  int referencia_encontrada = 0;
  int faz_parte_da_conta = 0;
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    printf("%d", strlen(linha));
    if (strlen(linha) > 1 && (strncmp(linha, referencia, strlen(referencia)) == 0 || faz_parte_da_conta == 1)) {
      referencia_encontrada = 1;
      faz_parte_da_conta = 1;
    } else if (strlen(linha) == 1) {
      faz_parte_da_conta=0;
    } else {
      fprintf(arquivo_temp, "%s", linha); 
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
