//Tiago Duarte Mackedanz - Turma: M11 - Programação de Computadores

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PALAVRAS 10
#define TAM 100

typedef struct {
	char palavraEscolhida[TAM];
	char palavraImpressa[TAM];
	char dica[TAM];
	int letrasRescentes;
	int chancesRescentes;
} MatchData;

char const tabelaDePalavras [NUM_PALAVRAS][TAM] = {
	"BATATA$É um tubérculo",
	"AIMPIM$Usa-se para fazer sagu",
	"COMPUTACAO$Melhor curso do mundo",
	"CHIMARRAO$Se toma numa cuia",
	"LAGARTO$Lacoste de elo baixo",
	"MARACUJA$Parece sua cara quando acorda",
	"SOCORRO$Pedido de ajuda",
	"TATU$Tem na terra e no seu nariz",
	"FLORESTA$Amazônia",
	"ARARA$Papagaio vip",
};

void inicializarDados(MatchData *dest);
void processarLetra(MatchData *data, char letra);

int main () {
	
}