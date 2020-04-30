#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

// Define a structure for chained hash tables
typedef struct CHTbl {
    // Number of bucket
    int buckets;
    // User-defined hash function
    int (*h)(const void *key);
    // USer-defined match function
    int (*match)(const void *key1, const void *key2);
    // User-defined destroy function
    void (*destroy)(void *data);
    // Number of elements in the table
    int size;
    // Pointer to the chained hash table object
    List *table;

} CHTbl;

/* Public Interface */

// Initialize the hash table
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));

void chtbl_destroy(CHTbl *htbl);

int chtbl_insert(CHTbl *htbl, const void *data);

int chtbl_remove(CHTbl *htbl, void **data);

int chbtl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif