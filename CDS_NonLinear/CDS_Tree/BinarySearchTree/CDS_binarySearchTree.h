#ifndef  CDS_BINARY_SEARCH_TREE_H
#define  CDS_BINARY_SEARCH_TREE_H

#include<stdlib.h>

typedef struct stdBinaryTreeData cds_bstData;

struct stdBinaryTreeData{
    //void* data;
    int data;
    cds_bstData* right;
    cds_bstData* left;
};

typedef struct stdBinarySearchTree cds_binaryStree;

struct stdBinarySearchTree{
    cds_bstData* root;
    unsigned int numberOfElements;
    //unsigned int depth;
};

cds_binaryStree* CDS_init_bst();

//void CDS_bst_add(cds_binaryStree* tree,void* data,int compare(void* idata,void* cmpData));
void CDS_bst_add(cds_binaryStree* tree,int data);
void CDS_bst_remove();


void CDS_bst_traversal_inOrder();
void CDS_bst_traversal_preOrder();
void CDS_bst_traversal_postOrder();

void CDS_bst_traversal_bfs();
void CDS_bst_traversal_dfs();

void CDS_bst_findMax();
void CDS_bst_findMin();

void CDS_bst_isEmpty();
void CDS_bst_search();

void CDS_bst_destroy();

#endif
