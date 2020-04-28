#include <stdlib.h>
#include <string.h>

#include "list.h"

/* Initialize the list */
void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}

/* Destroy all nodes in list */
void list_destroy(List *list) {
    // Pointer to the removed node
    void *data;
    // Remove each nodes
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void**)&data) == 0 && list->destroy != NULL) {
            // Call a user-defined function to free dynamically allocated data
            list->destroy(data);
        }
    }

    // Clear the structure as a precaution
    // Copy 0 to the list memory from 0 to sizeof list
    memset(list, 0, sizeof(List));

    return;
}

/* Add node to list */
int list_ins_next(List *list, Node *node, const void *data) {
    Node *new_node;

    // Allocate storage for the node
    if ((new_node = (Node*)malloc(sizeof(Node))) == NULL) return -1;

    // Insert the node into the list
    new_node->data = (void*)data;

    if (node == NULL) {
        // Add new node at the head of the list
        if (list_size(list) == 0) list->tail = new_node;

        new_node->next = list->head;
        list->head = new_node;
    }
    else {
        // Add new node somewhere other than at the head
        if (node->next == NULL) list->tail = new_node;
        new_node->next = node->next;
        node->next = new_node;
    }

    list->size++;

    return 0;
}

/* Remove a node */
int list_rem_next(List *list, Node * node, void **data) {
    Node *old_node;

    // Don't do anything from an empty list
    if (list_size(list) == 0) return -1;

    // Remove the node
    if (node == NULL) {
        
        // Remove the node from the head of the list
        *data = list->head->data;
        
        old_node = list->head;
        list->head = list->head->next;
        
        if (list_size(list) == 1) list->tail = NULL;
    }
    else {
        if (node->next == NULL) return -1;

        // Remove the node somewhere other than the head
        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;

        if (node->next == NULL) list->tail = node;
    }

    // Free the storage allocated by the abstract datatype
    free(old_node);

    list->size--;
    
    return 0;
}

