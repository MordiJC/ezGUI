#ifndef EZGUI_UTIL_LINKED_LIST_H_
#define EZGUI_UTIL_LINKED_LIST_H_

#include "../common.h"

typedef struct LinkedListNode_struct {
    void * data;
    struct LinkedListNode_struct * prev;
    struct LinkedListNode_struct * next;
} LinkedListNode;

typedef struct LinkedList_struct {
    LinkedListNode * root;
    unsigned int size;
} LinkedList;

LinkedList * LinkedList_create();

/// Add element at the beginning of the list
int LinkedList_add(LinkedList * restrict list, void * data);

/// Add element at the end of the list
int LinkedList_push(LinkedList * list, void * data);

int LinkedList_remove_at(LinkedList * list, unsigned int index);

int LinkedList_destroy(LinkedList * list);

int LinkedList_move_to_top(LinkedList * list, unsigned int index);

#endif /* EZGUI_UTIL_LINKED_LIST_H_ */