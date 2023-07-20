#include"CDS_sort_algos.h"

void CDS_sort_insertion(int arr[],size_t size){

}

/**
* A->en buyuk eleman dizinin sonuna itilir
*
* j dizinin eleman karsilastirma siniri kisaltilip
* adim A tekrar ediliyor
*/
void CDS_sort_bubble(int arr[],unsigned int size_arr){

    int temp = 0;

    for(int i = 0;i < size_arr - 1; i++){

        for(int j = 0; j < size_arr - i - 1; j++){

            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }//for j end

    }//for i end
}

