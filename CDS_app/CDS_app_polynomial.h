#ifndef CDS_APP_POLYNOMIAL_H
#define CDS_APP_POLYNOMIAL_H

#include"../CDS_LinkedList/CDS_LinkedList.h"

#include<stdio.h>
#include<math.h>

//TODO void CDS_app_polynom_mult 03.07.23

typedef struct stdpolynom cds_app_polynom;

struct stdpolynom{
    float coefficient;
    float exponent;
};

cdst_linkedList_List* CDS_app_polynom_init();

void CDS_app_polynom_addElement(cdst_linkedList_List* polynomian,float coefficient,float exponent);

void CDS_app_polynom_sum(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t);

void CDS_app_polynom_sub(cdst_linkedList_List* poly_sum,cdst_linkedList_List* poly_t);

void CDS_app_polynom_mult_scaler(cdst_linkedList_List* poly,float m);

void CDS_app_polynom_mult(cdst_linkedList_List* poly,cdst_linkedList_List* poly_t);

float CDS_app_polynom_evaluation(cdst_linkedList_List* poly, float x);

void CDS_app_polynom_print(cdst_linkedList_List* polynomian);

void CDS_app_polynom_destroy(cdst_linkedList_List* polyniom);

#endif//CDS_APP_POLYNOMIAL_H
