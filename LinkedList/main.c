#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char** argv) {
    List list;
    list_init(&list, NULL);

    const int val1 = 1;
    const int val2 = 2;
    const int val3 = 3;

    // Add a node with value 1 to the head of the list
    list_ins_next(&list, NULL, &val1);
    // Add a node with value 2 to the head of the list
    list_ins_next(&list, NULL, &val2);
    // Add a node with value 3 to the end of the list
    list_ins_next(&list, list_tail(&list), &val3);

    // List all nodes
    printf("After adding three nodes: \n");
    printf("List size: %d\n", list_size(&list));
    printf("Nodes in list: ");
    Node *ptr = list_head(&list);
    for (int i = 0; i < list_size(&list); i++) {
        printf("%d  ", *(int*)list_data(ptr));
        ptr = ptr->next;
    }
    printf("\n");
   
    // Delete a node from head
    Node *s;
    void **p = (void*)&s;
    list_rem_next(&list, NULL, p);
    
    // List all nodes
    printf("\nAfter delete head node in the list: \n");
    printf("List size: %d\n", list_size(&list));
    printf("Nodes in list: ");
    ptr = list_head(&list);
    for (int i = 0; i < list_size(&list); i++) {
        printf("%d  ", *(int*)list_data(ptr));
        ptr = ptr->next;
    }

    // Delete all element
    // Because we didn't pass in the user-defined destroy() in list_init(),
    // so calling list_destroy() just set the list memory to all 0
    list_destroy(&list);

    printf("\n\nAfter delete all nodes in list: \n");
    printf("List size: %d\n", list_size(&list));

    return 0;
}