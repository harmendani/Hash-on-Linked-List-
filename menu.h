/* Desenvolvido por Pedro Harmendani - 2016*/


/* Desenvolvido por Pedro Harmendani - 2016*/
	#include "interface.h"
	
void menu(){
puts("\n");
	printf ("\t || Desenvolvido por Pedro Harmendani - 2016 || \n ");
	printf ("\n 1. Criar tabela (Efetue operação primeiramente para manipular a Tabela de Chaves)");
	printf ("\n 2. Inserir Chave (Insira uma chave para poder BUSCAR, REMOVER E IMPRIMIR)");
	printf ("\n 3. Buscar Chave");
	printf ("\n 4. Remover Chave");	
	printf ("\n 5. Imprimir a Tabela de Chaves");
	printf ("\n 6. Exibe Menu");
	printf ("\n 0. SAIR DO PROGRAMA");
    printf ("\n \n  Selecione uma operação com base no número correspondente:\t");
}	 
	
    
void exibeMenu ()
{		
	int tamanho = 0;
	int chave = 0;	
	int busca;
    int chaveB;	
    int quant;
    int i = 0;
	celula* _init = NULL;
	int controleMenu = 0;
	menu();
	
	do {
		
     scanf ("%d", &controleMenu);
     
	    switch (controleMenu) {
	    	  	case 1: 
	    	  
				puts ("\n Digite o tamanho da tabela: ");
	            scanf ("%d", &tamanho);
	            _init = alocaTabela (tamanho);
	    	  	if(_init != NULL){
	    	  		puts ("\nTabela criada com Sucesso !\n");
				  }
				  puts("Selecione uma operação");
				break;
				case 2:
					puts ("\n Digite quantas chaves deseja inserir na Tabela: ");
					scanf ("%d", &quant);
					puts("\nDigite as chaves (Enter)");
					for(i=0;i<=quant;i++){
						scanf ("%d", &chave);
						_init = insereChave (chave,tamanho,_init);
					}
	                menu();
				    break;
				case 3:						
					puts ("\n Digite uma chave para ser buscada: ");
	                scanf ("%d", &chaveB);					
					busca = buscaChave(chaveB, tamanho, _init);
					puts("Selecione uma operação");
				    break;				    
				case 4:
				    puts ("\n Digite uma chave para remover da Tabela: ");
				    scanf ("%d", &chaveB);
				    removeChave(chaveB, tamanho, _init);
				    puts("Selecione uma operação");
				    break;
				    
				case 5:
					imprime(tamanho, _init);
					menu();				
					break;
					
				case 6:
					menu();
					break;					
			   
				case 0:
					puts("\n\nAté mais, você saiu do programa");
					break;
	 	        default:	 	        	
	 	        	puts("\n\nDigite a Opção Correta");
	 	        	break;
	    }
		
	} while (controleMenu!=0);
}
