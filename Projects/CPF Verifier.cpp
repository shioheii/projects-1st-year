#include<stdio.h>
#include<locale.h>

int cpf[11], resultadoMulti1[9], resultadoMulti2[10], matrizMulti1[2][9], matrizMulti2[2][10];
int restoSoma, total, totalValido, totalInvalido, opcao, soma, x, digito1, digito2;
float pvalido, pinvalido;

main(){
setlocale(LC_ALL, "Portuguese");
	
	printf("\tValidador de CPF");
	
	printf("\n\nDeseja come�ar a verificar os cpfs? 1-Sim / 2-N�o\n");
	scanf("%d", &opcao);
	while((opcao != 1) && (opcao != 2)){
		printf("\nAten��o! Digite uma op��o v�lida: ");
		scanf("%d", &opcao);
	}
	
	while(opcao == 1){
		
		total++;
		printf("\n\n");
		
		for(x=0;x<11;x++){
			
			printf("Digite o %d� digito do cpf: ", x+1);
			scanf("%d", &cpf[x]);
			while((cpf[x] > 9) || (cpf[x] < 0)){
				printf("Aten��o! Um digito deve estar entre 0 e 9: ");
				scanf("%d", &cpf[x]);
			}
			
		}
		
		// Primeiro digito
		soma = 0;		
		for(x=0;x<9;x++){
							
			matrizMulti1[0][x] = cpf[x];
			matrizMulti1[1][x] = 10 - x;
			resultadoMulti1[x] = matrizMulti1[0][x] * matrizMulti1[1][x];
			soma += resultadoMulti1[x]; 
								
		}
								
		restoSoma = soma % 11;		
		if(restoSoma < 2){
			
			digito1 = 0;
		
		}else{
		
			digito1 = 11 - restoSoma;
		
		}
		
		// Segundo digito		
		soma = 0;		
		for(x=0; x<9; x++){
			matrizMulti2[0][x] = cpf[x];
		}
		matrizMulti2[0][9] = digito1;
		
		for(x=0;x<10;x++){
			
			matrizMulti2[1][x] = 11 - x;
			resultadoMulti2[x] = matrizMulti2[0][x] * matrizMulti2[1][x];
			soma += resultadoMulti2[x]; 
								
		}
		
		restoSoma = soma % 11;		
		if(restoSoma < 2){
			
			digito2 = 0;
		
		}else{
		
			digito2 = 11 - restoSoma;
		
		}
		
		// Comparando os digitos gerados com os do CPF informado
		if((digito1 == cpf[9]) && (digito2 == cpf[10])){
			
			printf("\nCPF v�lido!\n\n");
			totalValido++;
			
		}else{
			
			printf("\nCPF inv�lido!\n\n");
			totalInvalido++;
			
		}
				
		printf("Deseja validar outro CPF? 1-Sim / 2-N�o\n");
		scanf("%d", &opcao);
		while((opcao != 1) && (opcao != 2)){
			printf("\nAten��o! Digite uma op��o v�lida: ");
			scanf("%d", &opcao);
		}
	}
	
	if(total != 0){
	
		pvalido = (totalValido * 100) / total;
		pinvalido = (totalInvalido * 100) / total;
		printf("\n\tEstat�sticas finais:\n\n");
		printf("Total de CPFs testados: %d\nTotal de CPFs v�lidos: %d\nTotal de CPFs inv�lidos: %d\n", total, totalValido, totalInvalido);
		printf("Percentual de CPFs v�lidos: %.1f%%\nPercentual de CPFs inv�lidos: %.1f%%\n", pvalido, pinvalido);
	
	}else{
		
		printf("\n\nNenhum CPF foi testado!\n");		
	}
	
}
