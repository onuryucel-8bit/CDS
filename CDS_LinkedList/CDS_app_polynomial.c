#include"CDS_app_polynomial.h"

/**
*  init polynom linked list
*/
cdst_linkedList_List* CDS_app_polynom_init(){
   return CDS_LinkedList_init();
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


}

static cds_app_polynom* to_polynomi(cdst_linkedList_Data* data){
    return (cds_app_polynom*)(data);
}

void CDS_app_polynom_sum(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t){

    if(poly_sum == NULL || poly_t == NULL)return;

    cdst_linkedList_Data* current = poly_sum;
    cdst_linkedList_Data* current_t = poly_t;

    while(current != NULL || current_t != NULL){
        if( to_polynomi(current)->exponent ) {

        }
    }
}

void CDS_app_polynom_sort_forExponent(cdst_linkedList_List* polynomian){

    if(polynomian == NULL)return;


}

void CDS_app_polynom_destroy(){}
