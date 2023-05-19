#ifndef CDS_GE_LINKED_LIST_H
#define CDS_GE_LINKED_LIST_H


struct cdNode{
    void* data;
    struct cdNode* next;
};

struct cdGenList{
    struct cdNode* head;
    size_t data_size;
};

struct cdGenList* init_gen_linked_list(size_t data_size){
    struct cdGenList* list = malloc(sizeof(struct cdGenList));

    list->head = NULL;
    list->data_size = data_size;
    return list;
}

struct cdNode* create_geNode(void* data){
    struct cdNode* nwnode = malloc(sizeof(struct cdNode));

    nwnode->data = data;
    nwnode->next = NULL;
    return nwnode;
}

void ge_linkedList_add(struct cdGenList* list,void* data){
    struct cdNode* newnode = create_geNode(data);

    if(list->head == NULL){
        list->head = newnode;
        return;
    }

    struct cdNode* current = list->head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newnode;
}

#endif // CDS_GE_LINKED_LIST_H
