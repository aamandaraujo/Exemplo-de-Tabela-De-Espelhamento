#include <stdio.h> // entrada e saída de dados
#include <stdlib.h> // funções de alocação de memória
#include <string.h> // operações de string

#define TAMANHO_TABELA 10 // define um macro(forma de realizar substituições automaticas que será o tamanho da sua tabela de espelhamento)

typedef struct Elemento {
char chave[50];
int valor;
struct Elemento* proximo;
} Elemento;

typedef struct TabelaEspelhamento{
Elemento* tabela[TAMANHO_TABELA];
}TabelaEspelhamento;

unsigned int calcular_hash(char* chave){
unsigned int hash = 0;
while(*chave){
    hash = (hash * 31)+ *chave;
    chave++;
}
return hash % TAMANHO_TABELA;
}

void adicionar_elemento(TabelaEspelhamento* tabela, char* chave, int valor){
unsigned int indice = calcular_hash(chave);
Elemento* novo_elemento = (Elemento*)malloc(sizeof(Elemento));
strcpy(novo_elemento ->chave, chave);
novo_elemento->valor = valor;
novo_elemento->proximo = tabela->tabela[indice];
tabela->tabela[indice] = novo_elemento;
}

int buscar_elemento(TabelaEspelhamento* tabela, char* chave){
unsigned int indice = calcular_hash(chave);
Elemento* elemento = tabela->tabela[indice];
while (elemento != NULL){
    if (strcmp(elemento->chave, chave) == 0){
        return elemento->valor;
    }
    elemento = elemento ->proximo;
}
return -1;
}
int main(){
TabelaEspelhamento tabela;
for(int i = 0; i< TAMANHO_TABELA; i++){
    tabela.tabela[i] = NULL;
}

adicionar_elemento(&tabela, "chave1", 10);
adicionar_elemento(&tabela, "chave2", 20);

printf("%d\n", buscar_elemento(&tabela, "chave1"));
printf("%d\n", buscar_elemento(&tabela,"chave2"));
remover_elemento(&tabela, "chave1");


return 0;
}
