/* Desenvolvido por Pedro Harmendani - 2016*/

// Estrutura basica da tabela e da Lista Encadeada

typedef struct tabela celula;

struct tabela{
	unsigned int chave, indice;
	celula *prox;		
};


// Funcao Hash [0 .. N-1];  N = Tamanho da Tabela

#define hash(k, T)  k % T;

// Inclui o m�dulo principal do programa
#include "coreHash.c"


// Esta fun��o aloca a tabela de acordo com o tamanho escolhido pelo Usuario e seta '-1' na vari�vel 'chave' para indicar o estado vazio da c�lula.
// O tamanho da tabela deve ser maior que 0
celula* alocaTabela(int);
/////////////////////////
// Esta funcao insere a chave na tabela realizado a Hash Fuction definida.
// A fun��o reconhece quando um elemento ja existe na tabela e informa ao usu�rio.
celula* insereChave(int, int, celula*);
//////////////////////////////////////
// Esta funcao � utilizada para buscar a chave que o usuario Solicita ao Programa.
// Ela indica se encontrou ou n�o e qual a posi��o
int buscaChave(int, int, celula*);
//////////////////////////////////////
/* Esta funcao remove a chave da tabela principal setando como '-1' a chave. 
No caso em que a chave est� na lista encadeada devido a colisao, ela apaga da mem�ra a celula e religa a lista apontando o anterior para o apagado->prox.
*/
void removeChave(int, int, celula*);
/////////////////////////////////////
// Esta funcao imprime todas as posi��es tanto da tabela principal quanto da respectiva colisao informando uma seta no caso de lista da colisao
// Ela imprime toda a tabela com as posi��es. Quando est� vazio('-1'), ela indica a posi��o, no entando n�o imprime este n�mero FLAG.
void imprime(int, celula*);
/////////////////////
