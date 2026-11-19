/*
 * Student Record Search using Binary Search Tree (BST)
 * Compile: gcc bst.c -o bst
 * Run:     ./bst
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int regNo;
    struct Node *left, *right;
} Node;

int comparisons = 0;

Node *newNode(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->regNo = key; n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->regNo) root->left = insert(root->left, key);
    else if (key > root->regNo) root->right = insert(root->right, key);
    return root; /* duplicate keys are ignored */
}

Node *search(Node *root, int key) {
    while (root != NULL) {
        comparisons++;
        if (key == root->regNo) return root;
        if (key < root->regNo) root = root->left;
        else root = root->right;
    }
    return NULL;
}

int height(Node *root) {
    if (!root) return 0;
    int lh = height(root->left), rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->regNo);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left); freeTree(root->right); free(root);
}

int main(void) {
    int data[] = {105,110,115,120,125,130,135,140,145,150,
                  155,160,165,170,175,180,185,190,195,200,
                  205,210,215,220,225,230,235,240,245,250};
    int n = sizeof(data)/sizeof(data[0]);
    Node *root = NULL;
    for (int i=0; i<n; i++) root = insert(root, data[i]);

    printf("BST - Student Record Search\n");
    printf("Records inserted: %d\n", n);
    printf("Inorder traversal: "); inorder(root); printf("\n");
    printf("Tree height (levels): %d\n", height(root));

    int key = 175;
    comparisons = 0;
    printf("Successful search %d: %s; comparisons = %d\n",
           key, search(root,key) ? "FOUND" : "NOT FOUND", comparisons);

    key = 999;
    comparisons = 0;
    printf("Unsuccessful search %d: %s; comparisons = %d\n",
           key, search(root,key) ? "FOUND" : "NOT FOUND", comparisons);

    root = insert(root, 252);
    printf("After inserting 252, search: ");
    comparisons = 0;
    printf("%s; comparisons = %d\n", search(root,252) ? "FOUND" : "NOT FOUND", comparisons);
    printf("Height after insertion (levels): %d\n", height(root));

    freeTree(root);
    return 0;
}
