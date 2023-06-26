#ifndef  CDS_BINARY_SEARCH_TREE_H
#define  CDS_BINARY_SEARCH_TREE_H

#include<stdlib.h>
#include<stdio.h>

#include"../CDS_Queue/CDS_QueueLL.h"

///TODO void CDS_bst_traversal_preOrder(cdst_binaryStree_Holder* tree);
///TODO void CDS_bst_traversal_postOrder(cdst_binaryStree_Holder* tree);
///TODO void CDS_bst_traversal_bfs();
///TODO void CDS_bst_traversal_dfs();

typedef struct stdBinaryTreeData cdst_bst_Data;

struct stdBinaryTreeData{
    int data;
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

void CDS_bst_add_recursive(cdst_binaryStree_Holder* tree,int data);
void CDS_bst_remove(cdst_binaryStree_Holder* tree,int data);

//Depth First Search
void CDS_bst_traversal_inOrder(cdst_binaryStree_Holder* tree);
void CDS_bst_traversal_preOrder(cdst_binaryStree_Holder* tree);
void CDS_bst_traversal_postOrder(cdst_binaryStree_Holder* tree);

//Level Order Traversal using Queue
void CDS_bst_traversal_bfs(cdst_binaryStree_Holder* tree);


int CDS_bst_findMax(cdst_binaryStree_Holder* tree);
int CDS_bst_findMin(cdst_binaryStree_Holder* tree);

int CDS_bst_searchData(cdst_binaryStree_Holder* tree,int data);


int CDS_bst_isEmpty(cdst_binaryStree_Holder* tree);

void CDS_bst_destroy(cdst_binaryStree_Holder* tree);

#endif
