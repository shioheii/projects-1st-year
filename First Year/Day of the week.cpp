#include <stdio.h>
#include <stdlib.h>

main (){
	
int dia, mes, ano, anob1, anob2, anob3, semana;	
int A, B , C, D;
	
	printf("Digite o dia que voce nasceu: ");
	scanf ("%d", &dia);
	printf("\nDigite o mes que voce nasceu: ");
	scanf ("%d", &mes);
	printf("\nDigite o ano que voce nasceu: ");
	scanf ("%d", &ano);

	A = ano - 1900;
	B = A / 4;
	D = dia - 1;
	anob1 = ano % 4;
	anob2 = ano % 100;
	anob3 = ano % 400;
	
	if((anob1 == 0 && anob2 != 0) || (anob1 == 0 && anob2 == 0 && anob3 == 0) && dia <= 29 && mes <= 2){
		B = B - 1;
		// Ano bissexto.
	}
		
	if(mes == 1 || mes == 10){
		C = 0;
	}else{
		
		if(mes == 2 || mes == 3 || mes == 11){
			C = 3;
		}else{
			
			if(mes == 4 || mes == 7){
				C = 6;
			}else{
				
				if(mes == 5){
					C = 1;
				}else{
					
					if(mes == 6){
						C = 4;
					}else{
					
						if(mes == 8){
					 		C = 2;
						}else{
							
							if(mes == 9 || mes == 12){
								C = 5;
							}else{
								
								printf("\nNao existe mes %d\n", mes);
							}
						}
					}
				}
			}
		}
	}
	
	semana = (A + B + C + D) % 7;
	
	if (semana == 0){
		printf("\nSEGUNDA FEIRA\n\n");
	}else{
		
		if(semana == 1){
			printf("\nTERCA FEIRA\n\n");
		}else{
			
			if(semana == 2){
				printf("\nQUARTA FEIRA\n\n");
			}else{
				
				if(semana == 3){
					printf("\nQUINTA FEIRA\n\n");
				}else{
					
					if(semana == 4){
						printf("\nSEXTA FEIRA\n\n");
					}else{
						
						if(semana == 5){
							printf("\nSABADO\n\n");
						}else{
							
							printf("\nDOMINGO\n\n");
						}
					}
				}
			}
		}
	}
	
	system ("pause");
	
}
