#include "CDS_binarySearchTree.h"

/*
static cdst_bst_Data* createBst_SearchData(void* data,cdst_bst_Data* right,cdst_bst_Data* left){

    cdst_bst_Data* newNode = malloc(sizeof(cdst_bst_Data));

    newNode->data = data;
    newNode->right = right;
    newNode->left = left;

    return newNode;
}

*/

static cdst_bst_Data* createBst_SearchData(int data,cdst_bst_Data* right,cdst_bst_Data* left){

    cdst_bst_Data* newNode = malloc(sizeof(cdst_bst_Data));

    newNode->data = data;
    newNode->right = right;
    newNode->left = left;

    return newNode;
}

cdst_binaryStree_Holder* CDS_init_bst(){
    cdst_binaryStree_Holder* newBST_Tree = malloc(sizeof(cdst_binaryStree_Holder));

    newBST_Tree->root = NULL;

    return newBST_Tree;
}

//------------------------------------------------------------//

void CDS_bst_add(cdst_binaryStree_Holder* tree,int data){

    cdst_bst_Data* newNode = createBst_SearchData(data,NULL,NULL);

    if(tree->root == NULL){
        tree->root = newNode;
        return;
    }

    //go right side
    cdst_bst_Data* current = tree->root;
    while(current != NULL){

        if(data >= current->data){
            current = current->right;
        }
        else //(data < current->data){
            current = current->left;
        }
}

//------------------------------------------------------------//

void CDS_bst_remove(cdst_binaryStree_Holder* tree, int data){
    if(tree == NULL)return;

    cdst_bst_Data* root = tree->root;

    while(root != NULL){

        if(data >= root->right->data){

            root = root->right;

        }else{
            root = root->left;
        }
    }
}

//------------------------------------------------------------//

static void bst_inOrder(cdst_bst_Data* root){
    //printf(root->data);
}

void CDS_bst_traversal_inOrder(cdst_binaryStree_Holder* tree){
    bst_inOrder(tree->root);
}


