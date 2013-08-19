/*************************************************************************
*
*   linkedList.h
*
*************************************************************************/
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct List_ {

    int     size;

    int     (* match)(const void *key1, const void * key2);
    void    (* destroy)(void * data);

    struct  ListElmt_ * head;
    struct  ListElmt_ * tail;

} List;

typedef struct ListElmt_ {

    void * data;
    struct ListElmt_ * next;

} ListElmt;

void list_init (List * list, void (*destroy)(void * data));

void list_destroy (List * list);

int list_ins_next (List * list, ListElmt *element, void **data);

int list_rem_next (List * list, ListElmt * element);

#define list_size(list) ((list) -> size)

#define list_head(list) ((list) -> head)

#define list_tail(list) ((list) -> tail)

#define list_is_head(list, element) (list_head(list) == (element) ? 1 : 0)

#define list_is_tail(elment) ((element) -> next == NULL ? 1 : 0)     

#define list_data(node) ((node) -> data)

#define list_next(node) ((node) -> next)

#endif