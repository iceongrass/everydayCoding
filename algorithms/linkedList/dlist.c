/***************************************************************
*
*   dlist.c
*
***************************************************************/

#include <stdio.h>
#include <string.h>
#include "dlist.h"

/* Initialize the list. */
void dlist_init(DList * list, void (*destroy)(void * data)) {

    list -> size    =   0;
    list -> destroy =   destroy;
    list -> head    =   NULL;
    list -> tail    =   NULL;

    return;

}

/* Destroy the list. */
void dlist_destroy(DList * list) {
    void * data;

    while(dlist_size(list) != 0) {
        if ( dlist_remove(list, dist_tail(list)) == 0 && 
            list -> destroy != NULL){
            list -> destroy (data);
        }
    }

    memset(list, 0, sizeof(DList));
    return;

}

/* Insert data to the list next to a spcial element. */
int  dist_ins_next(DList * list, DListElmt * element, const void * data) {
    DListElmt   * new_element;

    if(element == NULL && dlist_size(list) != 0)
        return -1;

    if(new_element = (DListElmt *) malloc (sizeof(DListElmt)) != 0)
        return -1;

    new_element -> data = (void*) data;
    
    if(dlist_size(list) == 0) {

        new_element -> prev = NULL;
        new_element -> next = NULL;
        list -> head = new_element;
        list -> tail = new_element;
    
    } else {

        new_element -> next = element -> next;
        new_element -> prev = element;

        if(element -> next == NULL)
            list -> tail = new_element;
        else 
            element -> next -> prev = new_element;

        element -> next = new_element;
    
    }

    list -> size ++;

    return 0;

}

/* Insert data to the list next to a spcial element. */
int  dist_ins_prev(DList * list, DListElmt * element, const void * data) {
    
    DListElmt * new_element;

    if(element == NULL && dlist_size(list) != 0)
        return -1;
    
    if(new_element = (DListElmt *) malloc (sizeof(DListElmt)) != 0)
        return -1;

    new_element -> data = (void*) data;

    if(dlist_size(list) ==0) {

        new_element -> prev = NULL;
        new_element -> next = NULL;
        list -> head = new_element;
        list -> tail = new_element;
    
    } else {

        new_element -> next = element;
        new_element -> prev = element -> prev;

        if(element -> prev == NULL)
            list -> head = new_element;
        else 
            element -> prev -> next = new_element;

        element -> prev = new_element;
    
    }

    list -> size ++;

    return 0;

    }

}

/* Remove element from list. */
int dlist_remove (DList * list, DListElmt * element, void ** data) {

    if(element == NULL && dlist_size(list) == 0)
        return -1;

    *data = element -> data;

    if(element == list -> head) {
        list -> head = element -> next;
        
        if(list -> head == NULL)
            list -> tail == NULL;
        else
            element -> next -> prev = NULL;

    } else {

        element -> prev -> next = element -> next;

        if(element -> next == NULL)
            list -> tail = element -> prev;
        else
            element -> next -> prev = element -> prev;

    }

    free (element);

    list -> size --;

    return 0;
}