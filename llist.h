#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define PATH "ContactBook.lock"
#define WIDTH 30
#define HEIGHT 12
/*
Node Structure: A node in a linked list typically consists of two components:
@param
data: It holds the actual value or data associated with the node.
@param
next_ptr: It stores the memory address (reference) of the next node in the sequence.

The structure 'Node' is defined as 'node_t'.
*/
typedef struct Node
{
    void *data;
    struct Node *next;
} node_t;
/*
Creates and allocates new node with data.
@param
new_data node's data.
@returns
Allocated new node.
*/
void *create_node(void *new_data);
/*
Inserts a new allocated node to the beginning of the linked list.
@param
headref pointer to the head of the linked list.
@param
new_data node's data.
*/
void insertBeginning(node_t **headref, node_t *new_data);
/*
Inserts a new allocated node after a certain position.
@param
headref pointer to the head of the linked list.
@param
pos position to which after a node is inserted (One-based indexing). 0 is not a valid pos.
@param
new_data node's data.
*/
void insertAfter(node_t **headref, uint16_t pos, node_t *new_data);
/*
Inserts a new allocated node at the end of the linked list.
@param
headref pointer to the head of the linked list.
@param
new_data node's data.
*/
void insertEnd(node_t **headref, node_t *new_data);
/*
Removes an allocated node after a certain position.
@param
headref pointer to the head of the linked list.
@param
pos position for declaring which node has to be removed (One-based indexing). 0 is not a valid pos.
*/
void removeAfter(node_t **headref, uint16_t pos);
/*
Removes an allocated node at the beginning of the linked list.
@param
headref pointer to the head of the linked list.
*/
void removeBeginning(node_t **headref);
/*
Removes an allocated node in a certain position.
@param
headref pointer to the head of the linked list.
@param
pos position in which a node is removed (One-based indexing). 0 is not a valid pos.
*/
void removePos(node_t **headref, uint16_t pos);
/*
Returns the amount of nodes in the linked list.
@param
headref pointer to the head of the linked list.
@returns
Node count.
*/
uint16_t getNodeCount(node_t **headref);
/*
Reverses the linked list.
@param
headref pointer to the head of the linked list.
*/
void reverseList(node_t **headref);
/*
Deallocates all nodes in the linked list.
@param
headref pointer to the head of the linked list.
*/
void cleanup(node_t **headref);
