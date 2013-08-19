#include <stdio.h>
#define BUFF_SIZE 100

int main(void){

	long list[BUFF_SIZE];
	long i;

	while(scanf("%ld", list) != EOF){
		
		i = 1;

		if(list[0] < 0)
			break;

		do{
			scanf ("%ld", list + i);
			
		} while ( list[i++] >= 0 );

		while (i-- != 1){
			printf("%ld\n", list[i-1]);
		}
	
	}

	return 0;

}