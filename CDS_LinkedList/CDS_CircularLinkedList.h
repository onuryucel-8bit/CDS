#ifndef CDS_CIRCULAR_LINKED_LIST_H
#define CDS_CIRCULAR_LINKED_LIST_H

#include<stdlib.h>

typedef struct stdCircularLL_Node cdst_circ_lil_Data;

struct stdCircularLL_Node{
    void* data;
    cdst_circLL_Data* next;
};

typedef struct stdCircularLL_List cdst_circ_lil_List;

struct stdCircularLL_List{
    cdst_circLL_Data* head;
};

cdst_circ_lil_List* CDS_Circular_LinkedList_init();

//---------------ADD----------------//

void CDS_Circular_LinkedList_addLast();
void CDS_Circular_LinkedList_addFirst();
void CDS_Circular_LinkedList_addAfterIndex();
void CDS_Circular_LinkedList_addAfterData();

//---------------REMOVE-------------//

void CDS_Circular_LinkedList_removeLast();
void CDS_Circular_LinkedList_removeFirst();
void CDS_Circular_LinkedList_removeAfterIndex();
void CDS_Circular_LinkedList_removeAfterData();

//---------------UTILS--------------//

void CDS_Circular_LinkedList_isEmpty();
void CDS_Circular_LinkedList_getNode();
void CDS_Circular_LinkedList_getData();

void CDS_Circular_LinkedList_sort();

//calls client's sort function(merge,bubble,qsort.....)
void CDS_Circular_LinkedList_sortMySelf();

void CDS_Circular_LinkedList_getSize();

void CDS_Circular_Linked_List_destroy();

#endif // CDS_CIRCULAR_LINKED_LIST_H
