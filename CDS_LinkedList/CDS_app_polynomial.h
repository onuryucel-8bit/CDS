#ifndef CDS_APP_POLYNOMIAL_H
#define CDS_APP_POLYNOMIAL_H

#include"CDS_LinkedList.h"

typedef struct stdpolynom cds_app_polynom;

struct stdpolynom{
    int coefficient;
    int exponent;
};

cdst_linkedList_List* CDS_app_polynom_init();

void CDS_app_polynom_addElement(cdst_linkedList_List* polynomian,int coefficient,int exponent);

void CDS_app_polynom_sum(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t);

void CDS_app_polynom_sub(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t);

void CDS_app_polynom_destroy(cdst_linkedList_List* polyniom);

#endif//CDS_APP_POLYNOMIAL_H
