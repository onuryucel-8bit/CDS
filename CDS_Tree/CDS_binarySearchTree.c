#include "CDS_binarySearchTree.h"

///BST_remove-------
//TODO replace int data to void* data and use compare function 24.06.23
//TODO change name of deletedNode variable to something better 24.06.23
//TODO split code into functions 24.06.23

//--------------------------INIT-----------------------------//

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

//--------------------------ADD-----------------------------//

static void CDS_st_bst_recursiveAdd(cdst_bst_Data* root,int data){

    //go right subtree
    if(data >= root->data){

        if(root->right != NULL){
            CDS_st_bst_recursiveAdd(root->right,data);
        }else{

            root->right = createBst_SearchData(data,NULL,NULL);
            return;
        }

    }
    //go left subtree
    else if(data < root->data){

        if(root->left != NULL){
            CDS_st_bst_recursiveAdd(root->left,data);
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
void CDS_bst_add_recursive(cdst_binaryStree_Holder* tree,int data){

    //if tree is empty make input to root of tree
    if(tree->root == NULL){
        //create node
        cdst_bst_Data* newNode = createBst_SearchData(data,NULL,NULL);
        //make tree root
        tree->root = newNode;

        return;
    }

    //call recursive func
    CDS_st_bst_recursiveAdd(tree->root,data);
}

//------------------------REMOVE--------------------------------//

/**
*  int compare_move()
*       if a==b return 1;
*       if a>=b return 0;
*       if a<b return -1;previous->left = minNode->right;
*
*/
void CDS_bst_remove(cdst_binaryStree_Holder* tree,int data){

    //control
    if(tree == NULL || tree->root == NULL)return;

    cdst_bst_Data* root = tree->root;

    while(root != NULL){

        //go right node
        if(data >= root->data){

            //if data founded
            if(data == root->right->data){

                cdst_bst_Data* deletedNode = root->right;

                //case 1: two node
                if(deletedNode->right != NULL && deletedNode->left != NULL){

                    /*
                    * TREE
                    *  \
                    *   X <-deleted node
                    *  / \
                    * Y   B <-right subtree root
                    *      \
                    *       D
                    */
                    //if right subtree root doesnt have left node or subtree
                    if(deletedNode->right->left == NULL ){
                        //copy data of b to x and delete b node
                        cdst_bst_Data* minNode  = deletedNode->right;

                        //min node(B) have right subtree
                        if(minNode->right != NULL){

                            //copy data
                            deletedNode->data = minNode->data;
                            //take right_subtree
                            cdst_bst_Data* right_Subtree = minNode->right;
                            //free minNode
                            free(minNode);
                            //x will be point to d node
                            deletedNode->right = right_Subtree;
                        }else{
                            //copy data
                            deletedNode->data = minNode->data;
                            //free minNode
                            free(minNode);
                            //point to null
                            deletedNode->right = NULL;
                        }

                    }

                    //if right node has left subtree
                    else if(deletedNode->right->left != NULL){


                        cdst_bst_Data* minNode  = deletedNode->right;
                        cdst_bst_Data* previous = minNode;

                        //find min node(go left nodes)
                        while(minNode->left != NULL){
                            previous = minNode;
                            minNode  = minNode->left;
                        }


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
                        *   [subtree(aka min's right subtree)]
                        */


                        //if min node has right subtree or node
                        if(minNode->right != NULL){
                            //copy data
                            deletedNode->data = minNode->data;
                            //e->left = f->right(Subtree or node)
                            previous->left = minNode->right;
                            free(minNode);
                        }
                        //if min node doesn't have right subtree or node
                        else{

                            //copy data
                            deletedNode->data = minNode->data;
                            //freing node
                            free(minNode);
                            previous->left = NULL;
                        }

                    }//END node->right != NULL
                    return;
                }//END IF

                //case 2: one node
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

                    //free node
                    free(deletedNode);
                    //connect subTree to root->right
                    root->right = subTree;

                    return;
                }

                //case 3: leaf node
                else if(deletedNode->right == NULL && deletedNode->left == NULL){

                    //free deletedNode
                    free(deletedNode);
                    //make root->right null
                    root->right = NULL;
                    return;
                }
            }

            root = root->right;
        }//IF END

        //go left node
        else{

            //if data founded
            if(data == root->left->data){

                cdst_bst_Data* deletedNode = root->left;

                //FIX: for left nodes
                //case 1: if deletedNode have right AND left node
                if(deletedNode->right != NULL && deletedNode->left != NULL){
                    //find left node in left-subtree

                    /*
                    * TREE
                    *  \
                    *   X <-deleted node
                    *  / \
                    * Y   B <-min node (deleted->right)
                    *      \
                    *       D
                    */

                    //if right subtree root doesnt have left node or subtree
                    //Y->LEFT == NULL if theresn't  F node
                    if(deletedNode->right->left == NULL){

                        //node b
                        cdst_bst_Data* minNode  = deletedNode->right;

                        //if min node(B) have right subtree
                        if(minNode->right != NULL){
                            //copy data
                            deletedNode->data = minNode->data; //x->data = b->data
                            cdst_bst_Data* right_Subtree = minNode->right;//subtree = b->right(D)
                            free(minNode);
                            deletedNode->right = right_Subtree;//x->right = subtree
                        }else{
                            //copy data
                            deletedNode->data = minNode->data;
                            free(minNode);
                            deletedNode->right = NULL;
                        }
                    }

                    /*
                    *  delete(X);
                    *  [TREE]
                    *            T  <-root
                    *           /
                    *          X <-deletedNode(root->right)
                    *         / \
                    *        B   Y
                    *           / \
                    *          F   D
                    *         /
                    *        E
                    *         \
                    *          H
                    *         / \
                    *        P   M
                    *
                    */

                    //if right node has left subtree
                    //x->right->left is there F node
                    else if(deletedNode->right->left != NULL){

                        //node y
                        cdst_bst_Data* minNode  = deletedNode->right;
                        //node y
                        cdst_bst_Data* previous = minNode;

                        //find min node
                        while(minNode->left != NULL){
                            previous = minNode;
                            minNode  = minNode->left;
                        }

                        //if min node has right subtree
                        //E->right != NULL
                        if(minNode->right != NULL){
                            //copy data
                            deletedNode->data = minNode->data;//x->data = e->data
                            previous->left = minNode->right;//f->left = h(node or subtree)
                            free(minNode);
                        }else{
                            //copy data
                            deletedNode->data = minNode->data;
                            free(minNode);
                            previous->left = NULL;
                        }

                    }//END node->right != NULL

                    return;

                }//if END case 1:

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
        }//ELSE END
    }//WHILE(root != NULL) END
}

//------------------------UTILS----------------------------------//

//LEFT---ROOT---RIGHT
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

//ROOT---LEFT---RIGHT
static void sta_bst_preOrder(cdst_bst_Data* root){

    if(root == NULL)return;

    printf("%i \n",root->data);
    sta_bst_preOrder(root->left);
    sta_bst_preOrder(root->right);

}

void CDS_bst_traversal_preOrder(cdst_binaryStree_Holder* tree){

    //if(tree == NULL)return;

    sta_bst_preOrder(tree->root);
}

//LEFT---RIGHT---ROOT
static void sta_bst_postOrder(cdst_bst_Data* root){

    if(root == NULL)return;

    sta_bst_postOrder(root->left);
    sta_bst_postOrder(root->right);
    printf("%i \n",root->data);
}

void CDS_bst_traversal_postOrder(cdst_binaryStree_Holder* tree){
    sta_bst_postOrder(tree->root);
}

//BFS
void CDS_bst_traversal_bfs(cdst_binaryStree_Holder* tree){
    //cdst_queue_Holder* queue = CDS_Queue_lil_init();

    //code here

    //CDS_Queue_lil_destroy(queue);
}

/*
*  if data founded return 1
*  return -1
*/
int CDS_bst_searchData(cdst_binaryStree_Holder* tree,int data){
    cdst_bst_Data* root = tree->root;
    while(root != NULL){
        if(data == root->data){
            return 1;
        }
        else if(data >= root->right->data){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return -1;
}

int CDS_bst_findMin(cdst_binaryStree_Holder* tree){
    cdst_bst_Data* root = tree->root;
    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int CDS_bst_findMax(cdst_binaryStree_Holder* tree){
    cdst_bst_Data* root = tree->root;
    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
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

//------DESTROY----//

static void st_CDS_bst_freeMemory(cdst_bst_Data* node){

    if(node->left == NULL && node->right == NULL){
        free(node);
        return;
    }
    if(node == NULL){
        return;
    }

    st_CDS_bst_freeMemory(node->left);

    st_CDS_bst_freeMemory(node->right);

    free(node);
}

void CDS_bst_destroy(cdst_binaryStree_Holder* tree){

    if(tree == NULL)return;

    st_CDS_bst_freeMemory(tree->root);

    free(tree);
}
