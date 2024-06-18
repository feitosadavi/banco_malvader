#ifndef GERENCIADOR_DE_ARQUIVOS_H
#define GERENCIADOR_DE_ARQUIVOS_H

FILE *abrir_arquivo();
void alterar_valor_arquivo(const char *nome_arquivo, const char *chave_alvo, const char *novo_valor);
void excluir_campo_arquivo(const char *nome_arquivo, const char *campo);
int ler_campo_arquivo(const char *nome_arquivo, char *campo);
int gravar_com_referencia(const char *nome_arquivo, char *referencia,char *chave_valor);
int deletar_com_referencia(const char *nome_arquivo, char *referencia);

#endif