 
#include <stdio.h>
 
int main (void){
    int c;
 
    while ( (c = getchar()) != EOF){
        do {
            if ( c ==' '){
    			printf("%%20");
   			}else{ 
    			putchar(c);
    		}
  		} while ( (c = getchar()) != '\n');
  
  		printf ("\n");
 	}
 
 	return 0;

}
 