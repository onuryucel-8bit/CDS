#ifndef CDS_LINKED_LIST_H
#define CDS_LINKED_LIST_H

#include<stdlib.h>
#include<errno.h>

typedef struct stdLinkedList_Node cdst_linkedList_Data;

struct stdLinkedList_Node {
    void* data;
    cdst_linkedList_Data* next;
};

typedef struct stdLinkedList_List cdst_linkedList_List;

struct stdLinkedList_List {
     cdst_linkedList_Data* head;
};

//----------INIT----------//
cdst_linkedList_List* CDS_LinkedList_init();

//----------ADD-----------//
void CDS_LinkedList_addFirst(cdst_linkedList_List* list,void* data);
void CDS_LinkedList_addLast(cdst_linkedList_List* list,void* data);

void CDS_LinkedList_addAfterIndex(cdst_linkedList_List* list,void* data,unsigned int index);
void CDS_LinkedList_addAfterData(cdst_linkedList_List* list,void* data,void* indexData);

//----------REMOVE-------//
void CDS_LinkedList_removeFirst(cdst_linkedList_List* list);
void CDS_LinkedList_removeLast(cdst_linkedList_List* list);

void CDS_LinkedList_removeAfterIndex(cdst_linkedList_List* list,unsigned int index);
void CDS_LinkedList_removeAfterData(cdst_linkedList_List* list,void* data);

//----------UTILS-------//
int  CDS_LinkedList_isEmpty(cdst_linkedList_List* list);

//reverse list with recursive
void CDS_LinkedList_reverseRec(cdst_linkedList_List* list);

//reverse list with two pointers
void CDS_LinkedList_reverse(cdst_linkedList_List* list);

void CDS_LinkedList_Compare(cdst_linkedList_List* firstList, cdst_linkedList_List* secondList);
void* CDS_LinkedList_SearchElement(cdst_linkedList_List* list);
int  CDS_LinkedList_FindElement(cdst_linkedList_List* list);

//print data char format
//void CDS_LinkedList_toChar(cdst_linkedList_List* list,char translate() );

///yaklasik olarak [i] islemini yapar
void* CDS_LinkedList_GetData(cdst_linkedList_List* list,unsigned int index);

unsigned int CDS_LinkedList_countList(cdst_linkedList_List* list);

void CDS_LinkedList_destroy(cdst_linkedList_List* list);

#endif
