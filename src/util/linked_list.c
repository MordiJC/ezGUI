#include "ezgui/util/linked_list.h"

#include <stddef.h>
#include <stdlib.h>

LinkedList* LinkedList_create() {
    LinkedList* list;

    list = (LinkedList*)malloc(sizeof(LinkedList));

    if (list == NULL) {
        return list;  // NULL
    }

    list->root = NULL;
    list->size = 0;

    return list;
}

LinkedListNode* LinkedListNode_create(void* data) {
    LinkedListNode* node;

    node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    if (node == NULL) {
        return node;  // NULL
    }

    node->data = data;
    node->prev = node->next = NULL;

    return node;
}

void LinkedListNode_destroy(LinkedListNode* node) { free(node); }

int LinkedList_add(LinkedList* restrict list, void* data) {
    if (list == NULL) {
        return -1;
    }

    LinkedListNode* newNode = LinkedListNode_create(data);

    // newNode->prev = NULL;

    if (newNode == NULL) {
        return -1;
    }

    LinkedListNode* rootNode = list->root;

    if (rootNode != NULL) {
        rootNode->prev = newNode;
        newNode->next = rootNode;
    }
    // else {
    //     newNode->next = NULL;
    // }

    list->root = newNode;

    list->size++;

    return 0;
}

/// Add element at the end of the list
int LinkedList_push(LinkedList* list, void* data) {
    if (list == NULL) {
        return -1;
    }

    if (list->root == NULL) {
        return LinkedList_add(list, data);
    }

    LinkedListNode* newNode = LinkedListNode_create(data);

    if (newNode == NULL) {
        return -1;
    }

    LinkedListNode* currentNode = list->root;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    list->size++;

    return 0;
}

int LinkedList_remove_at(LinkedList* list, unsigned int index) {
    if (list == NULL || list->root == NULL || index >= list->size) {
        return -1;
    }

    if (index == 0) {
        LinkedListNode* nodeToDestroy = list->root;

        list->root = nodeToDestroy->next;
        if (list->root != NULL) {
            list->root->prev = NULL;
        }

        LinkedListNode_destroy(nodeToDestroy);

        list->size--;
        return 0;
    }

    LinkedListNode* currentNode = list->root;
    unsigned int currentIndex = 0;

    while (currentNode->next != NULL && currentIndex != index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentIndex != index) {
        return -1;
    }

    LinkedListNode* nodeToDestroy = currentNode;

    nodeToDestroy->prev = nodeToDestroy->next;
    if(nodeToDestroy->next != NULL) {
        nodeToDestroy->next->prev = nodeToDestroy->prev;
    }

    LinkedListNode_destroy(nodeToDestroy);

    return 0;
}

int LinkedList_destroy(LinkedList* list) {
    if(list == NULL) {
        return 0;
    }

    if(list->root == NULL) {
        free(list);
        return 0;
    }

    LinkedListNode * currentNode = list->root;
    LinkedListNode * nextNode;

    while(currentNode != NULL) {
        nextNode = currentNode->next;
        LinkedListNode_destroy(currentNode);
        currentNode = nextNode;
    }

    free(list);

    return 0;
}

int LinkedList_move_to_top(LinkedList* list, unsigned int index) {
    if (list == NULL || list->root == NULL || index >= list->size) {
        return -1;
    }

    if(index == 0) {
        return 0;
    }

    LinkedListNode* currentNode = list->root;
    unsigned int currentIndex = 0;

    while (currentNode->next != NULL && currentIndex != index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentIndex != index) {
        return -1;
    }

    LinkedListNode* nodeToMove = currentNode;

    nodeToMove->prev = nodeToMove->next;
    if(nodeToMove->next != NULL) {
        nodeToMove->next->prev = nodeToMove->prev;
    }

    nodeToMove->next = list->root;
    nodeToMove->prev = NULL;
    list->root->prev = nodeToMove;
    list->root = nodeToMove;

    return 0;
}