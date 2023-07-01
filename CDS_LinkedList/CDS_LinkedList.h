#ifndef CDS_LINKED_LIST_H
#define CDS_LINKED_LIST_H

#include<stdlib.h>

///1.TEST 24.06.23

//TODO compare 24.06.23
//TODO sort 24.06.23
//TODO not IMPORTANT!! void CDS_LinkedList_addIndex(cdst_linkedList_List* list,void* data,void* indexData);

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

//void CDS_LinkedList_addIndex(cdst_linkedList_List* list,void* data,void* indexData);
//----------REMOVE-------//
void CDS_LinkedList_removeFirst(cdst_linkedList_List* list);
void CDS_LinkedList_removeLast(cdst_linkedList_List* list);

void CDS_LinkedList_removeIndex(cdst_linkedList_List* list,unsigned int index);

//----------UTILS-------//

//isEmpty
int  CDS_LinkedList_isEmpty(cdst_linkedList_List* list);

//reverse list with recursive
void CDS_LinkedList_reverseRec(cdst_linkedList_List* list);

//reverse list with two pointers
void CDS_LinkedList_reverse(cdst_linkedList_List* list);

//compare
int CDS_LinkedList_Compare();

//sort
void CDS_linkedlist_sort(cdst_linkedList_List* list,int (*compare)(void* data,void* cmp_data) );

//search
int CDS_LinkedList_SearchElement(cdst_linkedList_List* list,void* data,int (*compare)(void* data, void* nodeData));

//find
void*  CDS_LinkedList_FindElement(cdst_linkedList_List* list,void* data ,int (*compare)(void* data, void* nodeData));

//count
unsigned int CDS_LinkedList_countList(cdst_linkedList_List* list);

//destroy
void CDS_LinkedList_destroy(cdst_linkedList_List* list);

#endif
