#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************
*
*   swap2
*
****************************************************************
*
*   Generic method to implement swap, which could swap any kind 
*   of elements.
*
***************************************************************/

int swap2 (void * x, void * y, int elemSize) {

    void *temp;
    temp = (char *) malloc (elemSize);

    memcpy(temp, x, elemSize);
    memcpy(x, y, elemSize);
    memcpy(y, temp, elemSize);

    free(temp);

    return 0;

} //end swap2