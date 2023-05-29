#ifndef  CDS_BINARY_SEARCH_TREE_H
#define  CDS_BINARY_SEARCH_TREE_H

#include<stdlib.h>

typedef struct stdBinaryTreeData cds_bstData;

struct stdBinaryTreeData{
    void* data;
    cds_bstData* right;
    cds_bstData* left;
};

typedef struct stdBinarySearchTree cds_binaryStree;

struct stdBinaryTreeData{
    cds_bstData* root;
    unsigned int numberOfElements;
    //unsigned int depth;
};

void CDS_init_bst();

void CDS_bst_add();
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
