/*
 1 Fazer um programa que lê as 3 notas de um aluno de Programação de Computadores (v1, v2
e MT, onde MT é a média dos trabalhos). O programa calcula e imprime a média do aluno,
usando a fórmula Média=(3*v1+3*v2+4*MT)/10.
 */

#include <stdio.h>
#include <math.h>

int main(){
	
	float nota1, nota2, mediatrabalhos, media;

	printf("Digite a primeira nota: ");
	scanf("%f", &nota1);
	printf("Digite a segunda nota: ");
	scanf("%f", &nota2);
	printf("Digite a media dos trabalhos: ");
	scanf("%f", &mediatrabalhos);
	
	media=(3*nota1+3*nota2+4*mediatrabalhos)/10;
	
	printf("A Media final: %.2f", media);
	
	return 0;
}

