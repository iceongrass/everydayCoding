/***************************************************************
*
*   stack.c
*
****************************************************************
*
*   Decription:
*   
*   In this project we implememnt a genericity stack. 
*
***************************************************************/


#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

static void stackGrow(stack * s); 

int main () {
    return 0;
}

void stackNew(stack * s, int elemSize) {

    assert (s != NULL);
    s -> allocLength = 4;
    s -> logicalLength = 0;
    s -> elemSize = elemSize;
    s -> elements = malloc (4 * elemSize);
    assert (s -> elements != NULL);

}

void stackDispose(stack *s) {

    free (s -> elements);

}

void stackPush(stack * s, void * elemAddr) {

    if (s -> logicalLength == s -> allocLength)
        stackGrow(s);

    void * target = (char *) s -> elements + 
                        s -> logicalLength * s -> elemSize;
    memcpy(target, elemAddr, s -> elemSize);
    s -> logicalLength++;

}

void stackPop(stack * s, void * elemAddr) {

    void * source = (char*) s -> elements + 
                        (s -> logicalLength -1) * s -> elemSize;
    memcpy(elemAddr, source, s -> elemSize);
    s -> logicalLength--;

}

static void stackGrow(stack * s) {

    s -> allocLength *= 2;
    s -> elements = realloc (s -> elements, s -> allocLength * s -> elemSize);
    assert(s -> elements != NULL);

}
