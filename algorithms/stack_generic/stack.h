/***************************************************************
*
*   stack.h
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

typedef struct stack_ {

    int logicalLength;
    int allocLength;
    int elemSize;
    void * elements;
//   void (*freefn)(void * , void *);

} stack;

void stackNew(stack * s, int elemSize);
//void stackNew(stack * s, int elemSize, void (*freefn)(void *, void *));

void stackDispose(stack *s);

void stackPush(stack * s, void * elemAddr);

void stackPop(stack * s, void * elemAddr);