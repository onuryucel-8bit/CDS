#include "CDS_binarySearchTree.h"

///FIX compare_move ifs(...)

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

    //go right subtree
    if(compare(data,root) == 0){

        if(root->right != NULL){
            CDS_st_bst_recursiveAdd(root->right,data,compare);
        }else{
            root->right = createBst_SearchData(data,NULL,NULL);
            return;
        }

    }
    //go left subtree
    else if(compare(data,root) == -1){

        if(root->left != NULL){
            CDS_st_bst_recursiveAdd(root->left,data,compare);
        }else{
            root->left = createBst_SearchData(data,NULL,NULL);
            return;
        }

    }
}

/**
*   params:
*       tree
*       data
*       compare function()
*          if a==b return 1;
*          if a>=b return 0;
*          if a<b return -1;
*/
void CDS_bst_add_recursive(cdst_binaryStree_Holder* tree,void* data,int compare(void* data,void* cmpData2)){

    //if tree is empty make input to root of tree
    if(tree->root == NULL){
        //create node
        cdst_bst_Data* newNode = createBst_SearchData(data,NULL,NULL);
        //make tree root
        tree->root = newNode;
        return;
    }

    //call recursive func
    CDS_st_bst_recursiveAdd(tree->root,data,compare);
}

//------------------------REMOVE--------------------------------//



/**
*  int compare_move()
*       if a==b return 1;
*       if a>=b return 0;
*       if a<b return -1;
*
*/
void CDS_bst_remove(cdst_binaryStree_Holder* tree,void* data,int compare(void* data,void* cmpData),int compare_move(void* data,void* cmpData)){

    if(tree == NULL || tree->root == NULL)return;

    cdst_bst_Data* root = tree->root;
    while(root != NULL){

        if(compare(data,root->data) == 0){
            //case 1:
            if(data == root->right->data && root->right->left != NULL && root->right->right != NULL){


            }
            //case 2:
            else if(data == root->right->data && (root->right->left != NULL || root->right->right != NULL ) ){

                //is it left or right node
                cdst_bst_Data* subTree;
                if(root->right->right != NULL)
                    subTree = root->right;
                else
                    subTree = root->left;

                //delete
                free(root->right);
                root->right = subTree;

                return;
            }
            //case 3:
            else if(data == root->right->data && root->right->left == NULL && root->right->right == NULL){

                free(root->right);
                root->right = NULL;
                return;

            }

            root = root->right;
        }
    }
}

//------------------------------------------------------------//

static void bst_inOrder(cdst_bst_Data* root){

    if(root == NULL)return;
    bst_inOrder(root->right);
    bst_inOrder(root->left);
    printf("%i \n",*(int*)(root->data));
}

void CDS_bst_traversal_inOrder(cdst_binaryStree_Holder* tree){
    bst_inOrder(tree->root);
}

/**
*  if empty return 1
*  else return 0
*/
int CDS_bst_isEmpty(cdst_binaryStree_Holder* tree){
    if(tree->root == NULL){
        return 1;
    }
    return 0;
}

void CDS_bst_destroy(cdst_binaryStree_Holder* tree){

    //go to leaf nodes

    //need recursive

    free(tree);
}
