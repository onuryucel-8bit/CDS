#ifndef  CDS_BINARY_SEARCH_TREE_H
#define  CDS_BINARY_SEARCH_TREE_H

#include<stdlib.h>
#include<stdio.h>

///TODO void CDS_bst_destroy();
///TODO void CDS_bst_traversal_preOrder(cdst_binaryStree_Holder* tree);
///TODO void CDS_bst_traversal_postOrder(cdst_binaryStree_Holder* tree);
///TODO void CDS_bst_traversal_bfs();
///TODO void CDS_bst_traversal_dfs();
///TODO void CDS_bst_findMax();
///TODO void CDS_bst_findMin();
///TODO void CDS_bst_search();


typedef struct stdBinaryTreeData cdst_bst_Data;

struct stdBinaryTreeData{
    void* data;
    cdst_bst_Data* right;
    cdst_bst_Data* left;
};

typedef struct stdBinarySearchTree cdst_binaryStree_Holder;

struct stdBinarySearchTree{
    cdst_bst_Data* root;
    unsigned int numberOfElements;
    //unsigned int depth;
};

cdst_binaryStree_Holder* CDS_init_bst();

void CDS_bst_add_recursive(cdst_binaryStree_Holder* tree,void* data,int compare(void* idata,void* cmpData));
void CDS_bst_remove(cdst_binaryStree_Holder* tree,void* data,int compare(void* data,void* cmpData),int compare_move(void* data,void* cmpData));


void CDS_bst_traversal_inOrder(cdst_binaryStree_Holder* tree);
void CDS_bst_traversal_preOrder(cdst_binaryStree_Holder* tree);
void CDS_bst_traversal_postOrder(cdst_binaryStree_Holder* tree);

void CDS_bst_traversal_bfs();
void CDS_bst_traversal_dfs();

void CDS_bst_findMax();
void CDS_bst_findMin();

int CDS_bst_isEmpty(cdst_binaryStree_Holder* tree);
void CDS_bst_search();

void CDS_bst_destroy(cdst_binaryStree_Holder* tree);

#endif
