#include <stdio.h>
#include <string.h>
 
int main (void){
    char* tmp = NULL;
    char* output = NULL;
    char* i   = NULL;
	char* input = (char*) malloc (sizeof(char)*500);
	int length;

	memset(input , 0, sizeof(char)*500);
	printf("Please input the text you want to change:\n");
	
	tmp = input;
	//gets(input);
	while ((*tmp = getchar()) != EOF && *tmp != '\n'){
		tmp++;
	}

    if (input == NULL){
		printf("You forget to input the sentence. Please try again.\n");
		return 1;
	}

    length = strlen(input);
	i = input;

	output = (char*) malloc ( length * 3 * sizeof(char));
	memset (output, 0, length * 3 * sizeof(char));
													 
    tmp = output;
														  
    while(*i != NULL){
        if (*i != ' '){
            *tmp++ = *i;
        }else{
            strcpy(tmp, "\%20");
            tmp = tmp + 3;
        }
		i++;
    }

	printf ("%s", output);

	return 0;
}
