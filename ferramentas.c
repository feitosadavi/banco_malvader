void extrair_valor_do_token(const char *token, char **valor) {
  if (token != NULL) {
    // por algum motivo, o token do escopo acima estava sendo alterado,
    // então eu tive que fazer uma cópia dele para que seu valor não fosse modificado no outro escopo
    char *token_copy = strdup(token);

    // Usar strtok para separar a chave do valor
    char *chave = strtok(token_copy, ":");
    char *valor_extraido = strtok(NULL, ":");

    // Verificar se o valor foi extraído corretamente
    if (valor_extraido != NULL) {
      *valor = strdup(valor_extraido); // Alocar memória e copiar o valor
      if (*valor == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o valor.\n");
      }
    } else {
      *valor = NULL;
    }
  } else {
    *valor = "4512";
  }
}