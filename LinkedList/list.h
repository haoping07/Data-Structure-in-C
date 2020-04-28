#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/* Define a structure for LinkedList node */
typedef struct Node {
    // Node value
    void *data;

    // Pointer to the next node
    struct Node *next;

} Node;

/* Define a structure for Linked List */
typedef struct List {
    // List size
    int size;

    // match (not used)
    int (*match)(const void *key1, const void *key2);

    // Destroy all node in list
    void (*destroy)(void *data);

    // Pointer to the list head and tail
    Node *head;
    Node *tail;

} List;

/* Public Interface */
// Initialize the list
void list_init(List *list, void (*destroy)(void *data));

// Delete all nodes in list
void list_destroy(List *list);

// Insert a node
int list_ins_next(List *list, Node *node, const void *data);

// Remove a node
int list_rem_next(List *list, Node *node, void **data);

// Get list size
#define list_size(list) ((list)->size)
// Get list head
#define list_head(list) ((list)->head)
// Get list tail
#define list_tail(list) ((list)->tail)
// Get if the given node is list head
#define list_is_head(list, node) ((node) == (list)->head ? 1 : 0)
// Get if given node is list tail
#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)
// Get node's value
#define list_data(node) ((node)->data)
// Get the next node
#define list_next(node) ((node)->next)

#endif