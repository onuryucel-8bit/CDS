#ifndef CDS_LINKED_LIST_H
#define CDS_LINKED_LIST_H

#include<stdlib.h>
#include<errno.h>

typedef struct stdNode Node;

struct stdNode {
    void* data;
    Node* next;
};

typedef struct stdList List;

struct stdList {
     Node* head;
};


List* CDS_LinkedList_init();

//static Node* createNode(int data);

void CDS_LinkedList_addFirst(List* list,void* data);
void CDS_LinkedList_addLast(List* list,void* data);

void CDS_LinkedList_addAfterIndex(List* list,void* data,int index);
void CDS_LinkedList_addAfterData();

void CDS_LinkedList_removeFirst(List* list);
void CDS_LinkedList_removeLast(List* list);
void CDS_LinkedList_removeAfterIndex();

int CDS_LinkedList_isEmpty();

void CDS_LinkedList_destroy(List* list);

#endif
