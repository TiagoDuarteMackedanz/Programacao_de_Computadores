/*
 Utilizando o programa anterior, fazer um novo programa que verifica se o aluno atingiu a
média 7. Caso positivo, o programa imprime a mensagem “aprovado por média”. Caso
contrário, o programa calcula e imprime o valor necessário na optativa, apresentando a
mensagem apropriada. (Lembre-se que a média dos trabalhos não pode ser substituída
pela optativa).
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
	
	if (media>=7) {
	printf("\nAprovado por media superior ou igual a 7!");
	}
	else {
	printf("\nReprovado!");
	}
	return 0;
}
