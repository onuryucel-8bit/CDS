#include "CDS_binarySearchTree.h"

/*
static cds_bstData* createBst_SearchData(void* data,cds_bstData* right,cds_bstData* left){

    cds_bstData* newNode = malloc(sizeof(cds_bstData));

    newNode->data = data;
    newNode->right = right;
    newNode->left = left;

    return newNode;
}

*/

static cds_bstData* createBst_SearchData(int data,cds_bstData* right,cds_bstData* left){

    cds_bstData* newNode = malloc(sizeof(cds_bstData));

    newNode->data = data;
    newNode->right = right;
    newNode->left = left;

    return newNode;
}

cds_binaryStree* CDS_init_bst(){
    cds_binaryStree* newBST_Tree = malloc(sizeof(cds_binaryStree));

    newBST_Tree->root = NULL;

    return newBST_Tree;
}

void CDS_bst_add(cds_binaryStree* tree,int data){

    cds_bstData* newNode = createBst_SearchData(data,NULL,NULL);

    if(tree->root == NULL){
        tree->root = newNode;
        return;
    }

    //go right side
    cds_bstData* current = tree->root;
    while(current != NULL){

        if(data >= current->data){
            current = current->right;
        }
        else //(data <){
            current = current->left;
        }

}

