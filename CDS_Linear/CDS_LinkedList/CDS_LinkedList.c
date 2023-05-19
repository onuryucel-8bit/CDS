#include "CDS_LinkedList.h"


///initiliaze the list struct
List* CDS_LinkedList_init() {

    //memory allocetion for list
    List* list = malloc(sizeof(List));

    //eger bellekten yer alinamadiysa
    if (!list) {
        return NULL;
    }

    //listeyi bos olarak dondur
    list->head = NULL;
    return list;
}

void CDS_LinkedList_addAfterIndex(List* list,void* data,unsigned int index){}
void CDS_LinkedList_addAfterData(List* list,void* data,void* indexData){}

///remove first element from list
void CDS_LinkedList_removeFirst(List* list){

    //check first element
    if(list->head == NULL){

        //if head has next element
        if(list->head->next != NULL){
            Node* current = list->head->next;

            //free list head
            free(list->head);

            //make the next node head of list
            list->head = current;

            return;
        }

        free(list->head);
        list->head = NULL;

        return;
    }
}

///remove last element from list
void CDS_LinkedList_removeLast(List* list){

    //check list is null
    if(list->head == NULL){
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;

    if (current->next == NULL) {
        // Only one element in the list
        list->head = NULL;
        free(current);
        return;
    }

    //!!! HATA VAR !!!!//
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);


}

void CDS_LinkedList_removeAfterIndex(List* list,unsigned int index){}

///Checks if lisf of head empty
int CDS_LinkedList_isEmpty(List* list){
    if(list->head == NULL){
        return 1;
    }

    return 0;
}


///create node
static Node* createNode(void* data){

    //memory allocation for node
    Node* newNode = malloc(sizeof(Node));

    //error check
    if(!newNode){
       // perror("Failed to create newNode in CDS_LinkedList");
        return NULL;
    }

    //put the data inside of node
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

///adds Element to head of list
void CDS_LinkedList_addFirst(List* list,void* data){

    //if list empty make the element list of head
    if(list->head == NULL){
        list->head = createNode(data);
        return;
    }

    //create Nodes
    Node* newNode = createNode(data);

    //connect new node to list head
    newNode->next = list->head;

    //make list head newNode
    list->head = newNode;

}

///adds element to end of list
void CDS_LinkedList_addLast(List* list,void* data){

    //if list empty
    if(list->head == NULL){
        list->head = createNode(data);
        return;
    }

    //travelsing linked list
    Node* current = list->head;
    while(current->next != NULL){
        current = current->next;
    }

    //add element end of list
    current->next = createNode(data);
}

///it frees linked list
void CDS_LinkedList_destroy(List* list){

    Node* current = list->head;

    Node* nextNode = current;

    //free nodes
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    //free list
    free(list);
    list->head = NULL;
}

