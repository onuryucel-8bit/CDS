#ifndef CDS_DOUBLE_LINKED_LIST_H
#define CDS_DOUBLE_LINKED_LIST_H

#include<stdlib.h>

typedef struct stdDoubleLL_Node cdst_dou_lil_Data;

struct stdDoubleLL_Node{
    void* data;
    cdst_dou_lil_Data* next;
    cdst_dou_lil_Data* prev;
};

typedef struct stdDoubleLL_List cdst_dou_lil_List;

struct stdDoubleLL_List{
    cdst_dou_lil_Data* head;
};

//----------INIT----------//

cdst_dou_lil_List* CDS_Double_LinkedList_init();

//----------ADD-----------//

void CDS_Double_LinkedList_addLast(cdst_dou_lil_List* list,void* data);
void CDS_Double_LinkedList_addFirst(cdst_dou_lil_List* list,void* data);
void CDS_Double_LinkedList_addIndex(cdst_dou_lil_List* list,void* data,unsigned int index);

//----------REMOVE-------//

void CDS_Double_LinkedList_removeLast(cdst_dou_lil_List* list);
void CDS_Double_LinkedList_removeFirst(cdst_dou_lil_List* list);
void CDS_Double_LinkedList_removeIndex(cdst_dou_lil_Data* list ,unsigned int index);

//--------UTILS-------//

//destroy
void CDS_Double_LinkedList_destroy(cdst_dou_lil_List* list);

#endif // CDS_DOUBLE_LINKED_LIST_H
