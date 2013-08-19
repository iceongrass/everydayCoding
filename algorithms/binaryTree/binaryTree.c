/*************************************************************************
*
*   binaryTree.c
*
*************************************************************************/

#define BITREE_H

#include <stdlib.h>
#include <string.h>

#include "binaryTree.h"

/* Initialize the binary tree */
void bitree_init(BiTree * tree, void (*destroy)(void *data)){
    tree -> size = 0;
    tree -> destroy = destroy;
    tree -> root = NULL;

    return;
}

/* Destroy a binary tree */
void bitree_destroy  (BiTree * tree){
    bitree_rem_left(tree, NULL);
    memset(tree, 0. sizeof(BiTree));

    return;
}

/* Insert a node to be the left child of the tree */
void bitree_ins_left(BiTree * tree, BiTreeNode * node, const void *data) {
    BitTreeNode * new_node, ** position;

    // Allowed to add a empty tree
    if (node == NULL) {
        if (bitree_size(tree) > 1) {
            printf ("The tree node is empty.\n");
            return -1;
        }
        positon = & tree -> root;
    }
    else {
        if (bitree_left(node) != NULL) {
            printf ("This node already have a left child.\n");
            return -1;
        }
        position = & node -> left;
    }

    if ((new_node = (BiTreeNode *) malloc (sizeof(BiTreeNode))) == NULL) {
        printf ("Can't create a new node.\n");
        return -1;
    }

    new_node -> left = NULL;
    new_node -> right= NULL;
    new_node -> data = (void *) data;
    *postion == new_node;

    tree -> size ++;
}

/* Insert a node to the right child of the tree */
void bitree_ins_right (BiTree * tree, BiTreeNode * node, const void * data) {
    BiTreeNode * new_node, ** position;

    // Allowed to add a empty tree
    if (node == NULL) {
        if (bitree_size(tree) > 1) {
            printf ("The tree node is empty.\n");
            return -1;
        }
        positino = & tree -> root;
    }
    else {
        if (bit_tree_right(node) != NULL) {
            printf ("The node already have a right child.\n");
            return -1;
        }
        position = & tree -> right;
    }

    // Create a new node
    if ((new_node = (BiTreeNode *) malloc (sizeof(BiTreeNode))) == NULL) {
        printf ("Can't create the new node.\n");
        return -1;
    }

    new_node -> left = NULL;
    new_node -> rigth= NULL;
    new_node -> data = (void *) data;
    *position = new_node;

    // Adjust the size of the tree for the inserted node
    tree -> size++;
}

/* Remove the left tree under the node from the tree */
void bitree_rem_left(BiTree * tree, BiTreeNode * node) {
    BiTreeNode ** position;

    // For the situation of tree is empty
    if (bitree_size(tree) == 0)
        return;

    // Determine where to remove nodes
    if (node == NULL)
        position = & tree -> root;
    else 
        position = & node -> left;

    if (position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, * position);

        if (tree -> destroy != NULL) {
            tree -> destroy ((* position) -> data);
        }

        free( *position);
        *position == NULL;

        tree -> size--;
    }

    return;
}

/* Remove the rigtht tree under the node from the tree */
void bitree_rem_right(BiTree * tree, BiTreeNode * node) {
    BiTreeNode ** position;

    // For the situation of tree is empty
    if (bitree_size(tree) == 0)
        return;

    // Determine where to remove nodes
    if (node == NULL)
        position = & tree -> root;
    else 
        position = & node -> right;

    if (position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, * position);

        if (tree -> destroy != NULL) {
            tree -> destroy ((* position) -> data);
        }

        free( *position);
        *position == NULL;

        tree -> size--;
    }

    return;
}

/* Merge two binary trees */
int bitree_merge (BiTree * merge, BiTree * left, BiTree * rigth, const void * data) {
    
    BiTreeNode * new_node;

    if (merge == NULL)
        return -1;

    bitree_init(merge, left -> destroy);

    if ((new_node = (BiTreeNode *) malloc (sizeof(BiTreeNode))) != NULL) {
        printf("Can't create a new node.\n");
        return -1;
    }

    new_node -> data = (void *) data;
    new_node -> left = left -> root;
    new_node -> right= rigth -> root;

    merge -> size = bitree_size(left) + bitree_size(right) + 1;
    merge -> root = new_node;

    left -> root = NULL;
    left -> data = 0;
    right -> root = NULL;
    right -> data = 0;
}


