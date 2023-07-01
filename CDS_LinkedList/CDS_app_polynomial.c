#include"CDS_app_polynomial.h"

/**
*  init polynom linked list
*/
cdst_linkedList_List* CDS_app_polynom_init(){
   return CDS_LinkedList_init();
}

static int standart_compare_func(void* a,void* b){
    cds_app_polynom* poly_data = (cds_app_polynom*)(a);
    cds_app_polynom* cmp_poly_data = (cds_app_polynom*)(b);

    if(poly_data->exponent >= cmp_poly_data->exponent){
        return 1;
    }

    return 0;
}

static cds_app_polynom* to_polynomi(cdst_linkedList_Data* data){
    return (cds_app_polynom*)(data);
}

/**
*  add element to polynom list
*  it will sort when item added
*/
void CDS_app_polynom_addElement(cdst_linkedList_List* polynomian,int coefficient,int exponent){

    cds_app_polynom* poly = (cds_app_polynom*)malloc(sizeof(cds_app_polynom));

    if(poly == NULL)return;

    poly->coefficient = coefficient;
    poly->exponent = exponent;

    CDS_LinkedList_addLast(polynomian,poly);

    CDS_linkedlist_sort(polynomian,standart_compare_func);

}

void CDS_app_polynom_sum(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t){

    if(poly_sum == NULL || poly_t == NULL)return;

    cdst_linkedList_Data* current = poly_sum->head;
    cdst_linkedList_Data* current_t = poly_t->head;


    while(current != NULL || current_t != NULL){

        //translating void* data to polynom struct
        cds_app_polynom* poly_current = to_polynomi(current->data);
        cds_app_polynom* poly_current_t = to_polynomi(current_t->data);

        // ax + bx => a+b
        poly_current->coefficient = poly_current->coefficient + poly_current_t->coefficient;

        //moving to next nodes
        current_t = current_t->next;
        current = current->next;
    }

}

void CDS_app_polynom_sub(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t){

    if(poly_sum == NULL || poly_t == NULL)return;

    cdst_linkedList_Data* current = poly_sum->head;
    cdst_linkedList_Data* current_t = poly_t->head;


    while(current != NULL || current_t != NULL){

        //translating void* data to polynom struct
        cds_app_polynom* poly_current = to_polynomi(current->data);
        cds_app_polynom* poly_current_t = to_polynomi(current_t->data);

        // ax + bx => a+b
        poly_current->coefficient = poly_current->coefficient - poly_current_t->coefficient;

        //moving to next nodes
        current_t = current_t->next;
        current = current->next;
    }
}

void CDS_app_polynom_destroy(cdst_linkedList_List* polyniom){
    CDS_LinkedList_destroy(polyniom);
}
