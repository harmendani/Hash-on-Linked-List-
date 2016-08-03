/* Desenvolvido por Pedro Harmendani - 2016*/

/*INFO:
O programa foi testado, produzido e compilado em Microsoft Windows 10
 Dúvida? A biblioteca "interface.h" contém todos os protótipos das funções e procedimentos do programa.
 */

#include "menu.h"
#include <locale.h>



int main (){
	
	setlocale (LC_ALL, "Portuguese"); 	
    exibeMenu();
	puts("\n\n");
    system("\npause");
}
	
