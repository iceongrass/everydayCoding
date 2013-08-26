/***************************************************************
*
*   stack.c
*
****************************************************************
*
*   Decription:
*   
*   In this project we implememnt a stack which content int for  
*   element.
*
***************************************************************/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <memory.h>
#include "stack.h"

int main(void) {

    return 0;

}

void stackNew (stack * s) {
    
    s -> logicalLength = 0;
    s -> allocLength = 4;
    s -> elements = (int*) malloc (4 * sizeof(int));

    assert (s -> elements != NULL);

}

void stackDispose (stack * s) {
    
    s -> logicalLength = 0;
    s -> allocLength = 0;

    free (s -> elements);

    s -> elements = NULL;

}

void stackPush (stack * s, int data) {

    if (s -> logicalLength == s -> allocLength) {

        s -> allocLength *= 2;
        s -> elements = (int *)realloc (s -> elements, 
            (s -> allocLength) * sizeof (int));
        assert(s -> elements != NULL);

    }
    s -> elements[s -> logicalLength] = data;
    s -> logicalLength++;

}

int stackPop ( stack * s) {

    assert (s -> logicalLength > 0);
    s -> logicalLength;

    return s -> elements[s -> logicalLength];
    
}