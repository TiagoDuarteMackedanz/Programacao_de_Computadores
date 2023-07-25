//Tiago Duarte Mackedanz - Turma: M11 - Programação de Computadores

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define NUM_PALAVRAS 10
#define TAM 100

//Struct
typedef struct {
	char palavraEscolhida[TAM];
	char palavraImpressa[TAM];
	char dica[TAM];
	int letrasRestantes;
	int chancesRestantes;
} MatchData;

//Matriz de Palavras
char const tabelaDePalavras[NUM_PALAVRAS][TAM] = {
	"BATATA$E um tuberculo",
	"AIPIM$Usa-se para fazer sagu",
	"COMPUTACAO$Melhor curso do mundo",
	"CHIMARRAO$Se toma numa cuia",
	"LAGARTO$Lacoste de elo baixo",
	"MARACUJA$Parece sua cara quando acorda",
	"SOCORRO$Pedido de ajuda",
	"TATU$Tem na terra e no seu nariz",
	"FLORESTA$Amazonia",
	"ARARA$Papagaio vip"
};

//Declarando as Funcoes
//Funcao SortearPalavra
void sortearPalavra(MatchData *matchData);
//Funcao VerificarLetra
int verificarLetra(MatchData *matchData, char letra);
//Funcao ImprimirPalavra
void imprimirPalavra(MatchData *matchData);

//Main
int main () {
    
	srand(time(NULL));
    MatchData matchData;
    sortearPalavra(&matchData); 
    
    printf("Dica: %s\n", matchData.dica);
    imprimirPalavra(&matchData);
    matchData.chancesRestantes=6;
    while (matchData.chancesRestantes>0 && matchData.letrasRestantes>0) {
    	char letra;
        printf("Digite uma letra Maiuscula: ");
        scanf(" %c", &letra); 
    
    if (verificarLetra(&matchData, letra)) {
    	printf("Letra encontrada!\n");
    	imprimirPalavra(&matchData);
    } 
    else {
    	printf("Letra nao encontrada! Voce perdeu uma vida.\n");
    	matchData.chancesRestantes--;
    	printf("Vidas restantes: %d\n", matchData.chancesRestantes);
    }
}
    if (matchData.letrasRestantes == 0) {
    	printf("Parabens, voce acertou a palavra %s!\n", matchData.palavraEscolhida);
    }
    else {
    	printf("Suas chances acabaram. A palavra era %s.\n", matchData.palavraEscolhida);
    }
return 0;
}

//Funcao SortearPalavra
void sortearPalavra(MatchData *matchData) {
    
	int indice = rand() % NUM_PALAVRAS;
    char palavra[TAM];
    
    	strcpy(palavra, tabelaDePalavras[indice]);
        char *dica = strchr(palavra, '$');
        *dica = '\0';
        strcpy(matchData->palavraEscolhida, palavra);
        matchData->letrasRestantes = strlen(matchData->palavraEscolhida) -0;
        strcpy(matchData->dica, dica+1);
        memset(matchData->palavraImpressa, '_', matchData->letrasRestantes);
        matchData->chancesRestantes=6;
}

//Funcao VerificarLetra 
int verificarLetra (MatchData *matchData, char letra) {
    
	int i, encontrou=0;
	for (i = 0; i < strlen(matchData->palavraEscolhida); i++) {
        if (matchData->palavraEscolhida[i]==letra) {
            encontrou=1;
        if (matchData->palavraImpressa[i]=='_') {
        	matchData->palavraImpressa[i]=letra;
            matchData->letrasRestantes--;
            }
        }
    }
    if (!encontrou) 
    return encontrou;
}

//Funcao ImprimirPalavra
void imprimirPalavra(MatchData *matchData) {
    
	int i;
	printf("Palavra: ");
    for (i = 0; i < strlen(matchData->palavraImpressa); i++) {
        printf("%c ", matchData->palavraImpressa[i]);
    }
    printf("\n");
}