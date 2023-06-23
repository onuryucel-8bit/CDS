#include "CDS_binarySearchTree.h"

///FIX compare_move ifs(...)

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

static void CDS_st_bst_recursiveAdd(cdst_bst_Data* root,int data,int compare(void* data,void* cmpData)){

    //go right subtree
    if(data >= root->data){

        if(root->right != NULL){
            CDS_st_bst_recursiveAdd(root->right,data,compare);
        }else{

            root->right = createBst_SearchData(data,NULL,NULL);
            return;
        }

    }
    //go left subtree
    else if(data < root->data){

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
void CDS_bst_add_recursive(cdst_binaryStree_Holder* tree,int data,int compare(void* data,void* cmpData2)){

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
*       if a<b return -1;previous->left = minNode->right;
*
*/
void CDS_bst_remove(cdst_binaryStree_Holder* tree,int data,int compare(void* data,void* cmpData)){

    if(tree == NULL || tree->root == NULL)return;

    cdst_bst_Data* root = tree->root;
    while(root != NULL){

        //go right node
        if(data >= root->data){

            //if data founded
            if(data == root->right->data){

                cdst_bst_Data* deletedNode = root->right;

                printf("GOING RIGHT \n");

                //case 1:
                if(deletedNode->right != NULL && deletedNode->left != NULL){

                    /*
                    *  delete(X);
                    *  [TREE]
                    *    T  <-root
                    *     \
                    *      X <-deletedNode(root->right)
                    *     / \
                    *    Y   B
                    *       / \
                    *      C   D
                    *     /
                    *    E <-previous
                    *   /
                    *  F  <--MIN
                    *   \
                    *   [subtree(aka min right subtree)]
                    */

                    //TODO if theresn't left subtree
                    if(deletedNode->right->left == NULL ){
                        // x->data = b->data;
                        // t->right = b;
                        // free ,x

                        cdst_bst_Data* minNode  = deletedNode->right;

                        //min node(B) have right subtree
                        if(minNode->right != NULL){
                            //copy data
                            deletedNode->data = minNode->data;
                            cdst_bst_Data* right_Subtree = minNode->right;
                            free(minNode);
                            deletedNode->right = right_Subtree;
                        }else{
                            //copy data
                            deletedNode->data = minNode->data;
                            free(minNode);
                            deletedNode->right = NULL;
                        }
                        return;
                    }

                    //if right node has left subtree
                    if(deletedNode->right->left != NULL){

                        cdst_bst_Data* minNode  = deletedNode->right;
                        cdst_bst_Data* previous = minNode;

                        //find min node
                        while(minNode->left != NULL){
                            previous = minNode;
                            minNode  = minNode->left;
                        }
                        //printf("--- FOUND MIN NODE %i ---- \n",minNode->data);

                        //if min node has right subtree
                        if(minNode->right != NULL){
                            deletedNode->data = minNode->data;
                            previous->left = minNode->right;
                            free(minNode);
                        }else{
                            deletedNode->data = minNode->data;
                            free(minNode);
                            previous->left = NULL;
                        }

                    }//END node->right != NULL
                        return;
                }//END IF

                //case 2:
                else if(deletedNode->right != NULL || deletedNode->left != NULL){

                    cdst_bst_Data* subTree;

                    //theres is a right subtree
                    if(deletedNode->right != NULL){
                        subTree = deletedNode->right;
                    }
                    //theres is a left subtree
                    else if(deletedNode->left != NULL){
                        subTree = deletedNode->left;
                    }

                    free(deletedNode);
                    root->right = subTree;

                    return;
                }

                //case 3:
                else if(deletedNode->right == NULL && deletedNode->left == NULL){

                    free(deletedNode);
                    root->right = NULL;
                    return;
                }
            }

            root = root->right;
        }

        //go left node
        else{

            //if data founded
            if(data == root->left->data){

                cdst_bst_Data* deletedNode = root->left;


                //FIX: for left nodes
                //case 1: if deletedNode have right AND left node
                if(deletedNode->right != NULL && deletedNode->left != NULL){

                    /*
                    *  delete(X);
                    *  [TREE]
                    *            T  <-root
                    *           /
                    *          X <-deletedNode(root->right)
                    *         / \
                    *        B   Y
                    *       / \
                    *      C   D
                    *     /
                    *    E <-previous
                    *   /
                    *  F  <--MIN
                    *   \
                    *   [subtree(aka min right subtree)]
                    */

                    //if
                    if(deletedNode->right->left == NULL){
                        // x->data = b->data;
                        // t->right = b;
                        // free ,x

                        cdst_bst_Data* minNode  = deletedNode->right;

                        //min node(B) have right subtree
                        if(minNode->right != NULL){
                            //copy data
                            deletedNode->data = minNode->data;
                            cdst_bst_Data* right_Subtree = minNode->right;
                            free(minNode);
                            deletedNode->right = right_Subtree;
                        }else{
                            //copy data
                            deletedNode->data = minNode->data;
                            free(minNode);
                            deletedNode->right = NULL;
                        }
                    }

                    //if right node has left subtree
                    if(deletedNode->right->left != NULL){

                        cdst_bst_Data* minNode  = deletedNode->right;
                        cdst_bst_Data* previous = minNode;

                        //find min node
                        while(minNode->left != NULL){
                            previous = minNode;
                            minNode  = minNode->left;
                        }
                        //printf("--- FOUND MIN NODE %i ---- \n",minNode->data);

                        //if min node has right subtree
                        if(minNode->right != NULL){
                            deletedNode->data = minNode->data;
                            previous->left = minNode->right;
                            free(minNode);
                        }else{
                            deletedNode->data = minNode->data;
                            free(minNode);
                            previous->left = NULL;
                        }

                    }//END node->right != NULL
                    return;
                }//if END

                //case 2: if theres right OR left nodes
                else if(deletedNode->right != NULL || deletedNode->left != NULL){

                    cdst_bst_Data* subTree;

                    //theres is a right subtree
                    if(deletedNode->right != NULL){
                        subTree = deletedNode->right;

                    }
                    //theres is a left subtree
                    else if(deletedNode->left != NULL){
                        subTree = deletedNode->left;
                    }

                    free(deletedNode);
                    //connect subtree to root->left
                    root->left = subTree;

                    return;
                }

                //case 3:
                //check if node has left or right node if not delete the node  delete(LEAF NODE);
                else if(deletedNode->right == NULL && deletedNode->left == NULL){

                    free(deletedNode);
                    root->left = NULL;
                    return;
                }
            }

            root = root->left;
        }//IF END
    }
}

//------------------------------------------------------------//

//static unsigned int indexBST = -1;

//LEFT -- ROOT -- RIGHT
static void bst_inOrder(cdst_bst_Data* root){


    if(root == NULL)return;


    bst_inOrder(root->left);

    //printf("%i , adres = %p root adres = %p\n",*(int*)(root->data),(root->data),root);

    //segmentation ERROR [its for DEBUGGING]
    printf("data = %i my address = %p left address = %p  right address = %p ",root->data,root,(root->left),(root->right));

    if(root->left != NULL){
       printf(" :: left->data = %i",root->left->data);
    }
    if(root->right != NULL){
        printf(" :: right->data = %i",root->right->data);
    }


    printf("\n");
    bst_inOrder(root->right);
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
