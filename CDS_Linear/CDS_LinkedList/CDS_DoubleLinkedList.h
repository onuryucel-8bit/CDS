#ifndef CDS_DOUBLE_LINKED_LIST_H
#define CDS_DOUBLE_LINKED_LIST_H

#include<stdlib.h>

//----------INIT----------//
List* CDS_Double_LinkedList_init();

//----------ADD-----------//
void CDS_Double_LinkedList_addFirst(List* list,void* data);
void CDS_Double_LinkedList_addLast(List* list,void* data);

void CDS_Double_LinkedList_addAfterIndex(List* list,void* data,unsigned int index);
void CDS_Double_LinkedList_addAfterData(List* list,void* data,void* indexData);

//----------REMOVE-------//
void CDS_Double_LinkedList_removeFirst(List* list);
void CDS_Double_LinkedList_removeLast(List* list);

void CDS_Double_LinkedList_removeAfterIndex(List* list,unsigned int index);
void CDS_Double_LinkedList_removeAfterData(List* list,void* data);

//----------UTILS-------//
int  CDS_Double_LinkedList_isEmpty(List* list);
void CDS_Double_LinkedList_reverse(List* list);
void CDS_Double_LinkedList_Compare(List* firstList, List* secondList);
void* CDS_Double_LinkedList_SearchElement(List* list);
int  CDS_Double_LinkedList_FindElement(List* list);

///yaklasik olarak [i] islemini yapar
void* CDS_Double_LinkedList_GetData(List* list,unsigned int index);

void CDS_Double_LinkedList_destroy(List* list);

#endif // CDS_DOUBLE_LINKED_LIST_H
