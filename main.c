/* Desenvolvido por Pedro Harmendani - 2016*/

/*INFO:
O programa foi testado, produzido e compilado em Microsoft Windows 10
 D�vida? A biblioteca "interface.h" cont�m todos os prot�tipos das fun��es e procedimentos do programa.
 */

#include "menu.h"
#include <locale.h>



int main (){
	
	setlocale (LC_ALL, "Portuguese"); 	
    exibeMenu();
	puts("\n\n");
    system("\npause");
}
	
