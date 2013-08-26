/***************************************************************
*
*   stack.h
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

typedef struct stack {

    int logicalLength;
    int allocLength;
    int * elements;

} stack;

void stackNew(stack * s);

void stackDispose(stack *s);

void stackPush(stack * s, int data);

int stackPop(stack * s);