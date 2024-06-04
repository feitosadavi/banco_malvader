#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

FILE *abrir_arquivo(const char *nome_do_arquivo, const char *modo) {
  FILE *arquivo;
  arquivo = fopen(nome_do_arquivo, modo);
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
  }
  return arquivo;
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

int gravar_com_referencia(const char *nome_arquivo, char *referencia,char *chave_valor) {
  FILE *arquivo = abrir_arquivo(nome_arquivo, "r");
  FILE *arquivo_temp = abrir_arquivo("temp.txt", "w");

  char linha[1000];
  int referencia_encontrada = 0;
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    fputs(linha, arquivo_temp);
    if (strncmp(linha, referencia, strlen(referencia)) == 0) {
      fprintf(arquivo_temp, "%s\n", chave_valor); 
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

typedef void (*callback_t)(int);
// executa uma função de maneira segura 
int operacao_segura(callback_t callback, int value) {
  callback();
}

int gravar_com_referencia(const char *nome_arquivo, char *referencia,char *chave_valor) {


  return 0;
}


int main() {
  // char linha[MAX_LINE_LENGTH];
  // int quantidade = ler_campo_arquivo("arquivos.txt", "qtd_contas: %d");
  // printf("qtd: %d\n", quantidade);
  // alterar_valor_arquivo("arquivos.txt", "qtd_contas", "10");
	// quantidade = ler_campo_arquivo("arquivos.txt", "qtd: %d");
  // printf("qtd: %d\n", quantidade);
	// excluir_campo_arquivo("arquivos.txt", "Conta 1:");
	// quantidade = ler_campo_arquivo("arquivos.txt", "qtd: %d");
	// printf("qtd: %d\n", quantidade);
  gravar_com_referencia("arquivos.txt", "Conta 1:", "Agencia:1324");
  deletar_com_referencia("arquivos.txt", "Conta 1:");

  return 0;
}
