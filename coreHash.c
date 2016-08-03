#include <stdio.h>
#include <stdlib.h>

int buscaChave(int, int, celula*);

celula* alocaTabela (int tamanho){	
  int i = 0;
  celula* _inicio;	
 _inicio  = (celula*) malloc (tamanho * sizeof(celula));
 celula* _init = _inicio; 
  while (tamanho > 0 ){
  	_inicio->indice = i;
  	_inicio->chave = -1;
	_inicio->prox = NULL;	
  	 tamanho--;
  	 i++;
  	_inicio++;
  }
  return _init;
}

celula* insereChave (int chave, int tamanho, celula* _inicio){	
    int controle = 0;
	int indice = hash (chave, tamanho);
	celula* _init = _inicio;	
	_inicio = _inicio + indice;	
	if (_inicio->chave == -1 ){
		_inicio->chave = chave;	
		printf("\nA chave [%d] foi INSERIDA na posição [%d] !\n", _inicio->chave, _inicio->indice);
	    	 		
	}
	else{
		
		    if(buscaChave(chave, tamanho, _init)){
		    	printf("\nA chave [%d] existe na posição [%d], TENTE OUTRA !\n", chave, indice);
		    	return _init;
			}
			else{
			
		    celula* novo = (celula*)  malloc (tamanho * sizeof(celula));
	        if(_inicio->prox == NULL){
			     novo->chave = chave;
	           	 novo->indice = indice;	
			     novo->prox = NULL;        	
	        	_inicio->prox = novo;
	        	
	        	printf("\nA chave [%d] foi INSERIDA na posição [%d] !\n", novo->chave, novo->indice);
	        	
			}
			else{
				while(_inicio->prox != NULL){
				 _inicio = _inicio->prox;
				}
				novo->chave = chave;
				novo->indice = indice;
				printf("\nA chave [%d] foi INSERIDA na posição [%d] !\n", novo->chave, novo->indice);
				_inicio->prox = novo;
				novo->prox = NULL;
			}
	}
}
	
	return _init;
}

int buscaChave (int chave, int tamanho, celula* _inicio){

int controle = 0;	
int indice = hash (chave, tamanho);
celula* _init = _inicio;	
_inicio = _inicio + indice;
if (_inicio->chave == chave){
	
		printf("\nA chave [%d] que você está procurando EXISTE na posição [%d] !\n", _inicio->chave, _inicio->indice); 		
	}
	else{		  
		  for (_inicio;_inicio != NULL;_inicio = _inicio->prox){
		  	if (_inicio->chave == chave){
			controle = 1;  
		  	printf ("\nA chave [%d] que você está procurando EXISTE na posição [%d] !\n", _inicio->chave, _inicio->indice);
		  	break;
		  	
		  }
		  
		  }
		  if (controle != 1){
		  	printf("\nA  chave [%d] não existe na tabela (SE você estiver inserindo e viu esta mensagem, houve Colisao da chave [%d])\n", chave, chave);
		  	return 0;
		  }
		  return 1;
	}
}


void removeChave (int chave, int tamanho, celula* _inicio){

int controle = 0;	
int indice = hash (chave, tamanho);
celula* _init = _inicio;	
_inicio = _inicio + indice;
if (_inicio->chave == chave){
	      printf ("\nA chave [%d] foi REMOVIDA da posição [%d] !\n", _inicio->chave, _inicio->indice); 
	    _inicio->chave = -1;
			
	}
	else{		
	      celula* anterior = NULL;
		  for (_inicio;_inicio != NULL;_inicio = _inicio->prox){		  	
		  	if (_inicio->chave == chave){
			controle = 1;
			anterior->prox = _inicio->prox;			
			printf ("\nA chave [%d] foi REMOVIDA da posição [%d] !\n", _inicio->chave, _inicio->indice);
			
			free(_inicio) ; 
		  	_inicio = NULL;		  	
		  	break;
		  }
		  anterior = _inicio;
		  }
		  if (controle != 1){
		  	printf("\nQue pena, a chave [%d] não existe na tabela !\n", chave);
		  }
	}
}

void imprime(int tamanho, celula* _inicio){
	celula* _init = _inicio;
	while (tamanho > 0 ){
	       printf("\nPOSIÇÃO [%d]\t", _init->indice);
	  	   if(_init->chave != -1){
	  	   	printf("Chave [%d]", _init->chave );
			 }
			 if(_init->prox != NULL){
			 
	  	    for (_inicio = _init->prox;_inicio != NULL;_inicio = _inicio->prox){
	  	    
	  	    printf("-> Chave [%d] ",  _inicio->chave );
	  	}
	  }
	  _init++;  
    
	tamanho--;	
	}
}
