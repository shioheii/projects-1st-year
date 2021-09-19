#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int contador, op, idade, aprovado, curso;
float nota, melhornotaE, melhornotaI, melhornotaA, porcentagem;
char nome[30], melhornomeE[30], melhornomeI[30], melhornomeA[30]; 

main(){
setlocale(LC_ALL, "Portuguese");	
	
	printf("\tVestibulinho");
	printf("\n\nDeseja come�ar verificar os alunos? 1-Sim / 2-N�o\n");
	scanf("%d", &op);
	fflush(stdin);
	while((op != 1) && (op != 2)){
		printf("\nDigite uma op��o v�lida!\nDeseja come�ar verificar os alunos? 1-Sim/2-N�o\n");
		scanf("%d", &op);
		fflush(stdin);
	}
	
	while (op == 1){
		
		contador++;
		printf("\n\nNome do candidato: ");
		gets(nome);
		fflush(stdin);
		
		printf("N�mero de inscri��o do(a) %s: %d\n", nome, contador);
		
		printf("Qual curso foi escolhido pelo candidato?\n1-Inform�tica / 2-Administra��o / 3-Eletr�nica\n");
		scanf("%d", &curso);
		fflush(stdin);
		while((curso != 1) && (curso != 2) && (curso != 3)){
			printf("\nDigite uma op��o v�lida!\n");
			printf("Qual curso foi escolhido pelo candidato?\n1-Inform�tica / 2-Administra��o / 3-Eletr�nica\n");
			scanf("%d", &curso);
			fflush(stdin);
		}
		
		printf("Idade do candidato: ");
		scanf("%d", &idade);
		fflush(stdin);
		
		printf("Nota obtida pelo participante: ");
		scanf("%f", &nota);
		fflush(stdin);
		while ((nota < 0) || (nota > 10)){
			printf("\nValores incorretos (digite entre 0 e 10)!\nNota obtida pelo participante: ");
			scanf("%f", &nota);
			fflush(stdin);
		}
		
		if((curso == 1) && (melhornotaI == 0)){
			melhornotaI = nota;
			strcpy(melhornomeI, nome);
		}else{
			if((curso == 1) && (nota >= melhornotaI)){
				melhornotaI = nota;
				strcpy(melhornomeI, nome);
			}
		}
		
		if((curso == 2) && (melhornotaA == 0)){
			melhornotaA = nota;
			strcpy(melhornomeA, nome);
		}else{
			if((curso == 2) && (nota >= melhornotaA)){
				melhornotaA = nota;
				strcpy(melhornomeA, nome);
			}
		}
		
		if((curso == 3) && (melhornotaE == 0)){
			melhornotaE = nota;
			strcpy(melhornomeE, nome);
		}else{
			if((curso == 3) && (nota >= melhornotaE)){
				melhornotaE = nota;
				strcpy(melhornomeE, nome);
			}
		}
		
		if((nota >= 7) && (idade > 18)){
			printf("Aluno aprovado!");
			aprovado++;
		}else{
			printf("Candidato reprovado!");
		}
		
		printf("\n\nDeseja verificar mais um aluno? 1-Sim / 2-N�o\n");
		scanf("%d", &op);
		fflush(stdin);
		while((op != 1) && (op != 2)){
			printf("\nDigite uma op��o v�lida!\nDeseja verificar mais um aluno? 1-Sim / 2-N�o\n");
			scanf("%d", &op);
			fflush(stdin);
		}	
	}
	if ((aprovado != 0) && (contador != 0)){
		porcentagem = (aprovado * 100) / contador;
	}	
	printf("Melhor aluno de inform�tica: %s - Nota: %.1f\n", melhornomeI, melhornotaI);
	printf("Melhor aluno de administra��o: %s - Nota: %.1f\n", melhornomeA, melhornotaA);
	printf("Melhor aluno de eletr�nica: %s - Nota: %.1f\n", melhornomeE, melhornotaE);
	printf("Total de participantes: %d\nN�mero de aprovados: %d\n", contador, aprovado);
	printf("Percentual de aprovados em rela��o ao n�mero de inscritos: %.1f%%\n", porcentagem);
}
