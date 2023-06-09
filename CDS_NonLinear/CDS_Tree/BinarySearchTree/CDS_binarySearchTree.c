#include "CDS_binarySearchTree.h"


static cdst_bst_Data* createBst_SearchData(void* data,cdst_bst_Data* right,cdst_bst_Data* left){

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

static void CDS_st_bst_recursiveAdd(cdst_bst_Data* root,void* data,int compare(void* data,void* cmpData)){


    if(compare(data,root)){

        if(root->right != NULL){
            CDS_st_bst_recursiveAdd(root->right,data,compare);
        }else{
            root->right = createBst_SearchData(data,NULL,NULL);
        }

    }else{

        if(root->left != NULL){
            CDS_st_bst_recursiveAdd(root->left,data,compare);
        }else{
            root->right = createBst_SearchData(data,NULL,NULL);
        }

    }
}

void CDS_bst_add_recursive(cdst_binaryStree_Holder* tree,void* data,int compare(void* data,void* cmpData2)){

    if(tree->root == NULL){
        cdst_bst_Data* newNode = createBst_SearchData(data,NULL,NULL);
        tree->root = newNode;
        return;
    }

    CDS_st_bst_recursiveAdd(tree->root,data,compare);
}

//------------------------------------------------------------//

void CDS_bst_remove(cdst_binaryStree_Holder* tree,void* data){
    if(tree == NULL)return;

    //cdst_bst_Data* root = tree->root;


}

//------------------------------------------------------------//

static void bst_inOrder(cdst_bst_Data* root){
    //printf(root->data);
}

void CDS_bst_traversal_inOrder(cdst_binaryStree_Holder* tree){
    bst_inOrder(tree->root);
}


