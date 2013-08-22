/***************************************************************
*
*   dlist.h: double-linked list
*
****************************************************************
*
*   Description:
*
*   Doubly-linked lists are composed of elements linked by two
*   pointers. Each element of a doubly-linked list consists of 
*   three parts: in addition to the data and the next pointer, 
*   each element includes a pointer to the previous element,
*   called the prev pointer. A doubly-linked list is formed by 
*   composing a number of elements so that the next pointer of 
*   each element points to the ele- ment that follows it, and 
*   the prev pointer points to the element preceding it. To 
*   mark the head and tail of the list, we set the prev pointer
*   of the first element and the next pointer of the last 
*   element to NULL.
*
***************************************************************/

#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>

typedef struct DListElmt_ {
    
    void * data;

    struct DListElmt_ * prev;
    struct DListElmt_ * next;

} DListElmt;

typedef struct DList_ {
    
    int     size;

    Int     (*match)(const void *key1, const void *key2);
    void    (*destroy)(void * data);

    DListElmt  *head;
    DListElmt  *tail;

} DList;

/***************************************************************
*
*   Interfaces
*
***************************************************************/

void dlist_init (DList * list, void (destroy *)(void * data));

void dlist_destroy (DList * list);

int dlist_ins_next (DList * list, DListElmt * element, const void * data);

int dlist_ins_prev (DList * list, DListElmt * element, const void * data);

int dlist_remove (DList * list, DListElmt * element, void ** data);

#define dlist_size(list)     ((list)->size)

#define dlist_head(list)     ((list)->head)

#define dlist_tail(list)     ((list)->tail)

#define dlist_is_head(element)  ((element) -> prev == NULL ? 1 : 0)

#define dlist_is_tail(element)  ((element) -> next == NULL ? 1 : 0)

#define dlist_data(element)     ((element) -> data)

#define dlist_next(element)     ((element) -> next)

#define dlist_prev(element)     ((element) -> prev)

#endif


