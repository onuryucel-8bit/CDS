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

//----------INIT----------//
List* CDS_LinkedList_init();

//----------ADD-----------//
void CDS_LinkedList_addFirst(List* list,void* data);
void CDS_LinkedList_addLast(List* list,void* data);

void CDS_LinkedList_addAfterIndex(List* list,unsigned int index);
void CDS_LinkedList_addAfterData(List* list,void* data);

//----------REMOVE-------//
void CDS_LinkedList_removeFirst(List* list);
void CDS_LinkedList_removeLast(List* list);

void CDS_LinkedList_removeAfterIndex(List* list,unsigned int index);
void CDS_LinkedList_removeAfterData(List* list,void* data);

//----------UTILS-------//
int  CDS_LinkedList_isEmpty(List* list);
void CDS_LinkedList_reverse(List* list);
void CDS_LinkedList_Compare(List* firstList, List* secondList);
void* CDS_LinkedList_SearchElement(List* list);
int  CDS_LinkedList_FindElement(List* list);

///yaklasik olarak [i] islemini yapar
void* CDS_LinkedList_GetData(List* list,unsigned int index);

void CDS_LinkedList_destroy(List* list);

#endif
