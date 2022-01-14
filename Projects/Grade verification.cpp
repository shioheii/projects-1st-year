#include<stdio.h>
#include<string.h>
#include<locale.h>

char disciplinas[5];
float mediasBimestrais[5][4], totalPontosAno[5], notaExame;
int i, op;

// Procedimento sem passagem de parâmetro
void nomeDisciplinas(){
	
	for(i=0; i<5; i++){
		printf(" Digite o nome da %dª materia: ", i+1);
		fflush(stdin);
		scanf("%c", &disciplinas[i]);
	}
}

// Procedimento com passagem de parâmetro por valor
void digitarNotas(char nomeMateria, int posicao){
	
	printf("\n\n Matéria: %c\n\n", nomeMateria);
	for(int contador=0; contador<4; contador++){
		
		printf(" Digite a nota do %dº bimestre na materia de %c: ", contador+1, nomeMateria);
		scanf("%f", &mediasBimestrais[posicao][contador]);
		
		while((mediasBimestrais[posicao][contador]  > 10.0) || (mediasBimestrais[posicao][contador] < 0)){
			printf(" Digite uma nota válida (entre 0 e 10): ");
			scanf("%f", &mediasBimestrais[posicao][contador]);
		}
	}
}

// Função
float somaPontos(int indice){
	
	float soma=0;
	
	for(int cont=0; cont <4; cont++){
		soma += mediasBimestrais[indice][cont];
	}
	return soma;	
}

// Procedimento com passagem de parâmetro por referência
void notaExameFinal(float &notaNecessaria, int position){
	
	notaNecessaria = 10 - (notaNecessaria / 4);
}

main(){
setlocale(LC_ALL, "Portuguese");

	printf(" Deseja iniciar? (1-Sim / 2-Não): ");
	scanf("%d", &op);
	while((op != 1) && (op != 2)){
		printf(" Digite uma opção válida (1-Sim / 2-Não): ");
		scanf("%d", &op);
	}
	while(op == 1){
		
		// Chamando o procedimento para digitar o nome das disciplinas
		printf("\n *** Digitalização do nome das matérias *** \n\n");
		nomeDisciplinas();
		
		// Chamando o procedimento para digitar as notas de cada disciplina
		printf("\n *** Digitalização de notas ***");
		for(i=0; i<5; i++){
			digitarNotas(disciplinas[i], i);
		}
		
		// Chama a função para calcular o total de pontos de cada matéria
		for(i=0; i<5; i++){
			totalPontosAno[i] = somaPontos(i);
		}
		
		// Mostrando o resultado do aluno em cada matéria
		printf("\n\n *** Resultado do aluno *** \n");
		for(i=0; i<5; i++){
			if(totalPontosAno[i] >= 24.0){
				printf("\n APROVADO em %c\n Nota total obtida: %.1f\n", disciplinas[i], totalPontosAno[i]);
			}else{
				if(totalPontosAno[i] < 15.0){
					printf("\n RETIDO em %c\n Nota total obtida: %.1f\n", disciplinas[i], totalPontosAno[i]);
				}else{
					printf("\n EXAME FINAL em %c\n Nota total obtida: %.1f\n", disciplinas[i], totalPontosAno[i]);
					notaExameFinal(totalPontosAno[i], i);
					
					printf(" Digite a nota obtida pelo aluno no exame: ");
					scanf("%f", &notaExame);
					while((notaExame > 10.0) || (notaExame < 0)){
						printf(" Digite uma nota válida (entre 0 e 10): ");
						scanf("%f", &notaExame);
					}
					
					if(notaExame >= totalPontosAno[i]){
						printf("\n RESULTADO APÓS EXAME: APROVADO em %c\n", disciplinas[i]);
						printf(" Nota necessária: %.1f | Nota obtida no exame: %.1f\n", totalPontosAno[i], notaExame);
					}else{
						printf("\n RESULTADO APÓS EXAME: RETIDO em %c\n", disciplinas[i]);
						printf(" Nota necessária: %.1f | Nota obtida no exame: %.1f\n", totalPontosAno[i], notaExame);
					}
				}
			}
		}
		
		printf("\n Deseja verificar as notas de outro aluno? (1-Sim / 2-Não): ");
		scanf("%d", &op);
		while((op != 1) && (op != 2)){
			printf(" Digite uma opção válida (1-Sim / 2-Não): ");
			scanf("%d", &op);
		}
	}
}
